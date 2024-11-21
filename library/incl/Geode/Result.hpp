#pragma once
#ifndef GEODE_RESULT_HPP
    #define GEODE_RESULT_HPP

    #include <concepts>
    #include <optional>
    #include <sstream>
    #include <stdexcept>
    #include <string>
    #include <utility>
    #include <variant>

    #if !defined(GEODE_CONCAT)
        #define GEODE_CONCAT2(x, y) x##y
        #define GEODE_CONCAT(x, y) GEODE_CONCAT2(x, y)
    #endif

    #if !defined(GEODE_UNWRAP)
        // Use gcc's scope expression feature, which makes this macro
        // really nice to use. Unfortunately not available on MSVC
        #if defined(__GNUC__) || defined(__clang__)
            #define GEODE_UNWRAP(...)                                                          \
                ({                                                                             \
                    auto GEODE_CONCAT(res, __LINE__) = __VA_ARGS__;                            \
                    if (GEODE_CONCAT(res, __LINE__).isErr())                                   \
                        return geode::Err(std::move(GEODE_CONCAT(res, __LINE__)).unwrapErr()); \
                    std::move(GEODE_CONCAT(res, __LINE__)).unwrap();                           \
                })
        #else
            #define GEODE_UNWRAP(...) \
                if (auto res = __VA_ARGS__; res.isErr()) return geode::Err(res.unwrapErr())
        #endif
    #endif

    #if !defined(GEODE_UNWRAP_INTO)
        #define GEODE_UNWRAP_INTO(variable, ...)                                       \
            auto GEODE_CONCAT(res, __LINE__) = __VA_ARGS__;                            \
            if (GEODE_CONCAT(res, __LINE__).isErr())                                   \
                return geode::Err(std::move(GEODE_CONCAT(res, __LINE__)).unwrapErr()); \
            variable = std::move(GEODE_CONCAT(res, __LINE__)).unwrap()
    #endif

namespace geode {
    template <class OkType, class ErrType>
    class Result;

    namespace impl {
        template <class OkType>
        class OkContainer;

        template <class ErrType>
        class ErrContainer;

        template <class OkType, class ErrType>
        class ResultData;

        template <class OkType, class ErrType>
        class ResultDataWrapper;
    }

    template <class OkType>
    constexpr inline impl::OkContainer<OkType> Ok(OkType&& ok);

    template <class ErrType>
    constexpr inline impl::ErrContainer<ErrType> Err(ErrType&& err);

    template <class OkType>
    constexpr inline impl::OkContainer<OkType&> Ok(OkType& ok);

    template <class ErrType>
    constexpr inline impl::ErrContainer<ErrType&> Err(ErrType& err);

    constexpr inline impl::OkContainer<void> Ok();

    constexpr inline impl::ErrContainer<void> Err();

    namespace impl {
        template <class OkType>
        class OkContainer final {
        protected:
            OkType m_ok;

            constexpr explicit OkContainer(OkType&& ok
            ) noexcept(std::is_nothrow_move_constructible_v<OkType>) : m_ok(std::move(ok)) {}

            constexpr explicit OkContainer(OkType const& ok
            ) noexcept(std::is_nothrow_copy_constructible_v<OkType>) : m_ok(ok) {}

        public:
            constexpr OkType&& unwrap() && noexcept {
                return std::move(m_ok);
            }

            constexpr OkType const& unwrap() const& noexcept {
                return m_ok;
            }

            constexpr OkType& unwrap() & noexcept {
                return m_ok;
            }

            friend constexpr impl::OkContainer<OkType> geode::Ok<OkType>(OkType&& ok);

            template <class OkType2, class ErrType2>
            friend class geode::Result;
        };

        template <class OkType>
        class OkContainer<OkType&> final {
        protected:
            OkType& m_ok;

            constexpr explicit OkContainer(OkType& ok) noexcept : m_ok(ok) {}

        public:
            constexpr std::reference_wrapper<OkType> unwrap() && noexcept {
                return m_ok;
            }

            constexpr std::reference_wrapper<OkType> unwrap() const& noexcept {
                return m_ok;
            }

            friend constexpr impl::OkContainer<OkType&> geode::Ok<OkType>(OkType& ok);

            template <class OkType2, class ErrType2>
            friend class geode::Result;
        };

        template <>
        class OkContainer<void> final {
        protected:
            std::monostate m_ok;

            constexpr explicit OkContainer() {}

            friend constexpr impl::OkContainer<void> geode::Ok();

            template <class OkType2, class ErrType2>
            friend class geode::Result;
        };

        template <class ErrType>
        class ErrContainer final {
        protected:
            ErrType m_err;

            constexpr explicit ErrContainer(ErrType&& err
            ) noexcept(std::is_nothrow_move_constructible_v<ErrType>) : m_err(std::move(err)) {}

            constexpr explicit ErrContainer(ErrType const& err
            ) noexcept(std::is_nothrow_copy_constructible_v<ErrType>) : m_err(err) {}

        public:
            constexpr ErrType&& unwrap() && noexcept {
                return std::move(m_err);
            }

            constexpr ErrType const& unwrap() const& noexcept {
                return m_err;
            }

            constexpr ErrType& unwrap() & noexcept {
                return m_err;
            }

            friend constexpr impl::ErrContainer<ErrType> geode::Err<ErrType>(ErrType&& err);

            template <class OkType2, class ErrType2>
            friend class geode::Result;
        };

        template <class ErrType>
        class ErrContainer<ErrType&> final {
        protected:
            ErrType& m_err;

            constexpr explicit ErrContainer(ErrType& err) noexcept : m_err(err) {}

        public:
            constexpr std::reference_wrapper<ErrType> unwrap() && noexcept {
                return m_err;
            }

            constexpr std::reference_wrapper<ErrType> unwrap() const& noexcept {
                return m_err;
            }

            friend constexpr impl::ErrContainer<ErrType&> geode::Err<ErrType>(ErrType& err);

            template <class OkType2, class ErrType2>
            friend class geode::Result;
        };

        template <>
        class ErrContainer<void> final {
        protected:
            std::monostate m_err;

            constexpr explicit ErrContainer() {}

            friend constexpr impl::ErrContainer<void> geode::Err();

            template <class OkType2, class ErrType2>
            friend class geode::Result;
        };

        template <class Type>
        struct IsOptionalImpl : std::false_type {
            using type = void;
        };

        template <class Type>
        struct IsOptionalImpl<std::optional<Type>> : std::true_type {
            using type = Type;
        };

        template <class Type>
        concept IsOptional = IsOptionalImpl<Type>::value;

        template <class Type>
        using OptionalType = typename IsOptionalImpl<Type>::type;

        template <class Type>
        struct IsResultImpl : std::false_type {
            using OkType = void;
            using ErrType = void;
        };

        template <class OkType2, class ErrType2>
        struct IsResultImpl<Result<OkType2, ErrType2>> : std::true_type {
            using OkType = OkType2;
            using ErrType = ErrType2;
        };

        template <class Type>
        concept IsResult = IsResultImpl<Type>::value;

        template <class Type>
        using ResultOkType = typename IsResultImpl<Type>::OkType;

        template <class Type>
        using ResultErrType = typename IsResultImpl<Type>::ErrType;

        struct OkTag {};

        struct ErrTag {};

        template <class Type>
        concept IsStringStreamable = requires(std::stringstream ss, Type t) { ss << t; };
    }

    /// @brief Constructs a new Ok value
    /// @param ok the value to wrap in an Ok
    /// @return a new Ok value
    template <class OkType>
    constexpr impl::OkContainer<OkType> Ok(OkType&& ok) {
        return impl::OkContainer<OkType>(std::forward<OkType>(ok));
    }

    /// @brief Constructs a new Err value
    /// @param err the value to wrap in an Err
    /// @return a new Err value
    template <class ErrType>
    constexpr impl::ErrContainer<ErrType> Err(ErrType&& err) {
        return impl::ErrContainer<ErrType>(std::forward<ErrType>(err));
    }

    /// @brief Constructs a new Ok value
    /// @param ok the reference to wrap in an Ok
    /// @return a new Ok value
    template <class OkType>
    constexpr impl::OkContainer<OkType&> Ok(OkType& ok) {
        return impl::OkContainer<OkType&>(ok);
    }

    /// @brief Constructs a new Err value
    /// @param err the reference to wrap in an Err
    /// @return a new Err value
    template <class ErrType>
    constexpr impl::ErrContainer<ErrType&> Err(ErrType& err) {
        return impl::ErrContainer<ErrType&>(err);
    }

    /// @brief Constructs a new void Ok value
    /// @return a new void Ok value
    constexpr impl::OkContainer<void> Ok() {
        return impl::OkContainer<void>();
    }

    /// @brief Constructs a new void Err value
    /// @return a new void Err value
    constexpr impl::ErrContainer<void> Err() {
        return impl::ErrContainer<void>();
    }

    class UnwrapException : public std::runtime_error {
    public:
        template <class T>
            requires(impl::IsStringStreamable<T>)
        UnwrapException(impl::ErrTag, T&& err) :
            std::runtime_error(
                (std::stringstream{} << "Called unwrap on an Err Result: " << std::forward<T>(err)).str()
            ) {}

        template <class T>
            requires(!impl::IsStringStreamable<T>)
        UnwrapException(impl::ErrTag, T&& err) :
            std::runtime_error("Called unwrap on an Err Result") {}

        template <class T>
            requires(impl::IsStringStreamable<T>)
        UnwrapException(impl::OkTag, T&& ok) :
            std::runtime_error(
                (std::stringstream{} << "Called unwrapErr on an Ok Result: " << std::forward<T>(ok)).str()
            ) {}

        template <class T>
            requires(!impl::IsStringStreamable<T>)
        UnwrapException(impl::OkTag, T&& ok) :
            std::runtime_error("Called unwrapErr on an Ok Result") {}

        UnwrapException(UnwrapException const&) = default;
        UnwrapException(UnwrapException&&) = default;
        ~UnwrapException() = default;

        template <class OkType, class ErrType>
        friend class ResultData;
    };

    namespace impl {

        template <class OkType, class ErrType>
        class ResultData {
        protected:
            using ProtectedOkType = std::conditional_t<
                std::is_reference_v<OkType>,
                std::reference_wrapper<std::remove_reference_t<OkType>>, OkType>;
            using ProtectedErrType = std::conditional_t<
                std::is_reference_v<ErrType>,
                std::reference_wrapper<std::remove_reference_t<ErrType>>, ErrType>;

            std::variant<ProtectedOkType, ProtectedErrType> m_data;

            template <std::size_t Index, class ClassType>
                requires(Index == 0 ? std::constructible_from<ProtectedOkType, ClassType> : std::constructible_from<ProtectedErrType, ClassType>)
            constexpr ResultData(
                std::in_place_index_t<Index> index, ClassType&& ok
            ) noexcept(Index == 0 ? std::is_nothrow_constructible_v<ProtectedOkType, ClassType> : std::is_nothrow_constructible_v<ProtectedErrType, ClassType>) :
                m_data(index, std::move(ok)) {}

            constexpr ResultData(ResultData&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ProtectedOkType> && std::is_nothrow_move_constructible_v<ProtectedErrType>) :
                m_data(std::move(other.m_data)) {}

            constexpr ResultData(ResultData const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ProtectedOkType> && std::is_nothrow_copy_constructible_v<ProtectedErrType>) :
                m_data(other.m_data) {}

            constexpr OkContainer<OkType> asOk() && noexcept
                requires(!std::is_reference_v<OkType>)
            {
                return Ok(std::get<0>(std::move(m_data)));
            }

            constexpr OkContainer<OkType> asOk() const& noexcept
                requires(!std::is_reference_v<OkType>)
            {
                return Ok(static_cast<OkType>(std::get<0>(m_data)));
            }

            constexpr OkContainer<OkType&> asOk() && noexcept
                requires(std::is_reference_v<OkType>)
            {
                return Ok(std::get<0>(m_data).get());
            }

            constexpr OkContainer<OkType&> asOk() const& noexcept
                requires(std::is_reference_v<OkType>)
            {
                return Ok(std::get<0>(m_data).get());
            }

            constexpr ErrContainer<ErrType> asErr() && noexcept
                requires(!std::is_reference_v<ErrType>)
            {
                return Err(std::get<1>(std::move(m_data)));
            }

            constexpr ErrContainer<ErrType> asErr() const& noexcept
                requires(!std::is_reference_v<ErrType>)
            {
                return Err(static_cast<ErrType>(std::get<1>(m_data)));
            }

            constexpr ErrContainer<ErrType&> asErr() && noexcept
                requires(std::is_reference_v<ErrType>)
            {
                return Err(std::get<1>(m_data).get());
            }

            constexpr ErrContainer<ErrType&> asErr() const& noexcept
                requires(std::is_reference_v<ErrType>)
            {
                return Err(std::get<1>(m_data).get());
            }

        public:
            /// @brief Returns true if the Result is Ok
            /// @return true if the Result is Ok
            constexpr bool isOk() const noexcept {
                return m_data.index() == 0;
            }

            /// @brief Returns true if the Result is Err
            /// @return true if the Result is Err
            constexpr bool isErr() const noexcept {
                return m_data.index() == 1;
            }

            /// @brief Unwraps the Ok value from the Result
            /// @throw UnwrapException if the Result is Err
            /// @return the Ok value
            constexpr OkType&& unwrap() && {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Ok value from the Result
            /// @throw UnwrapException if the Result is Err
            /// @return the Ok value
            constexpr OkType& unwrap() & {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Ok value from the Result
            /// @throw UnwrapException if the Result is Err
            /// @return the Ok value
            constexpr OkType const& unwrap() const& {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr ErrType&& unwrapErr() && {
                if (isErr()) {
                    return std::get<1>(std::move(m_data));
                }
                else {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr ErrType& unwrapErr() & {
                if (isErr()) {
                    return std::get<1>(m_data);
                }
                else {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr ErrType const& unwrapErr() const& {
                if (isErr()) {
                    return std::get<1>(m_data);
                }
                else {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Returns a Result with references to the underlying values
            /// @return a Result with references to the underlying values
            constexpr Result<OkType&, ErrType&> asRef() noexcept;

            /// @brief Returns a Result with const references to the underlying values
            /// @return a Result with const references to the underlying values
            constexpr Result<OkType const&, ErrType const&> asConst() const noexcept;

            /// @brief Unwraps the Ok value from the Result, default constructing if unavailable
            /// @return the Ok value if available, otherwise a default constructed Ok value
            constexpr OkType unwrapOrDefault(
            ) && noexcept(std::is_nothrow_default_constructible_v<OkType> && std::is_nothrow_move_constructible_v<OkType>)
                requires std::default_initializable<OkType>
            {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    return OkType();
                }
            }

            /// @brief Unwraps the Ok value from the Result, default constructing if unavailable
            /// @return the Ok value if available, otherwise a default constructed Ok value
            constexpr OkType unwrapOrDefault(
            ) const& noexcept(std::is_nothrow_default_constructible_v<OkType> && std::is_nothrow_move_constructible_v<OkType>)
                requires std::default_initializable<OkType>
            {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    return OkType();
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning a default value if unavailable
            /// @param defaultValue the default value to return if the Result is Err
            /// @return the Ok value if available, otherwise the default value
            constexpr OkType unwrapOr(auto&& defaultValue
            ) && noexcept(std::is_nothrow_move_constructible_v<OkType>)
                requires std::constructible_from<OkType, decltype(defaultValue)>
            {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    return defaultValue;
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning a default value if unavailable
            /// @param defaultValue the default value to return if the Result is Err
            /// @return the Ok value if available, otherwise the default value
            constexpr OkType unwrapOr(auto&& defaultValue
            ) const& noexcept(std::is_nothrow_move_constructible_v<OkType>)
                requires std::constructible_from<OkType, decltype(defaultValue)>
            {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    return defaultValue;
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning the result of an operation if unavailable
            /// @param operation the operation to perform if the Result is Err
            /// @return the Ok value if available, otherwise the result of the operation
            constexpr OkType unwrapOrElse(std::invocable auto&& operation
            ) && noexcept(std::is_nothrow_invocable_v<decltype(operation)>)
                requires std::constructible_from<OkType, std::invoke_result_t<decltype(operation)>>
            {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    return operation();
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning the result of an operation if unavailable
            /// @param operation the operation to perform if the Result is Err
            /// @return the Ok value if available, otherwise the result of the operation
            constexpr OkType unwrapOrElse(std::invocable auto&& operation
            ) const& noexcept(std::is_nothrow_invocable_v<decltype(operation)>)
                requires std::constructible_from<OkType, std::invoke_result_t<decltype(operation)>>
            {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    return operation();
                }
            }

            /// @brief Returns a Result with a copied Ok value
            /// @return a Result with a copied Ok value
            constexpr Result<std::remove_reference_t<OkType>, ErrType> copied() const
                noexcept(std::is_nothrow_copy_constructible_v<OkType>)
                requires(std::is_reference_v<OkType>);

        protected:
            constexpr void inspectInternal(std::invocable<OkType const&> auto&& operation) const
                noexcept(noexcept(operation(std::declval<OkType const&>()))) {
                if (this->isOk()) {
                    operation(std::get<0>(m_data));
                }
            }

            constexpr void inspectInternalErr(std::invocable<ErrType const&> auto&& operation) const
                noexcept(noexcept(operation(std::declval<ErrType const&>()))) {
                if (this->isErr()) {
                    operation(std::get<1>(m_data));
                }
            }
        };

        template <class ErrType>
        class ResultData<void, ErrType> {
        protected:
            using ProtectedErrType = std::conditional_t<
                std::is_reference_v<ErrType>,
                std::reference_wrapper<std::remove_reference_t<ErrType>>, ErrType>;
            std::variant<std::monostate, ProtectedErrType> m_data;

            template <std::size_t Index, class ClassType>
                requires std::constructible_from<ErrType, ClassType>
            constexpr ResultData(
                std::in_place_index_t<Index> index, ClassType&& err
            ) noexcept(std::is_nothrow_constructible_v<ProtectedErrType, ClassType>) :
                m_data(index, std::move(err)) {}

            template <std::size_t Index>
            constexpr ResultData(std::in_place_index_t<Index> index) noexcept : m_data(index) {}

            constexpr ResultData(ResultData&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ProtectedErrType>) :
                m_data(std::move(other.m_data)) {}

            constexpr ResultData(ResultData const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ProtectedErrType>) :
                m_data(other.m_data) {}

            constexpr OkContainer<void> asOk() const noexcept {
                return Ok();
            }

            constexpr ErrContainer<ErrType> asErr() && noexcept
                requires(!std::is_reference_v<ErrType>)
            {
                return Err(std::get<1>(std::move(m_data)));
            }

            constexpr ErrContainer<ErrType> asErr() const& noexcept
                requires(!std::is_reference_v<ErrType>)
            {
                return Err(static_cast<ErrType>(std::get<1>(m_data)));
            }

            constexpr ErrContainer<ErrType&> asErr() && noexcept
                requires(std::is_reference_v<ErrType>)
            {
                return Err(std::get<1>(m_data).get());
            }

            constexpr ErrContainer<ErrType&> asErr() const& noexcept
                requires(std::is_reference_v<ErrType>)
            {
                return Err(std::get<1>(m_data).get());
            }

        public:
            /// @brief Returns true if the Result is Ok
            /// @return true if the Result is Ok
            constexpr bool isOk() const noexcept {
                return m_data.index() == 0;
            }

            /// @brief Returns true if the Result is Err
            /// @return true if the Result is Err
            constexpr bool isErr() const noexcept {
                return m_data.index() == 1;
            }

            /// @brief Unwraps the Result
            /// @throw UnwrapException if the Result is Err
            constexpr void unwrap() {
                if (isErr()) {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr ErrType&& unwrapErr() && {
                if (isErr()) {
                    return std::get<1>(std::move(m_data));
                }
                else {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr ErrType& unwrapErr() & {
                if (isErr()) {
                    return std::get<1>(m_data);
                }
                else {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr ErrType const& unwrapErr() const& {
                if (isErr()) {
                    return std::get<1>(m_data);
                }
                else {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Returns a Result with references to the underlying values
            /// @return a Result with references to the underlying values
            constexpr Result<void, ErrType&> asRef() noexcept;

            /// @brief Returns a Result with const references to the underlying values
            /// @return a Result with const references to the underlying values
            constexpr Result<void, ErrType const&> asConst() const noexcept;

            /// @brief Returns a Result with a copied Ok value
            /// @return a Result with a copied Ok value
            constexpr Result<void, ErrType> copied() const noexcept;

        protected:
            constexpr void inspectInternalErr(std::invocable<ErrType const&> auto&& operation) const
                noexcept(noexcept(operation(std::declval<ErrType const&>()))) {
                if (this->isErr()) {
                    operation(std::get<1>(m_data));
                }
            }
        };

        template <class OkType>
        class ResultData<OkType, void> {
        protected:
            using ProtectedOkType = std::conditional_t<
                std::is_reference_v<OkType>,
                std::reference_wrapper<std::remove_reference_t<OkType>>, OkType>;
            std::variant<ProtectedOkType, std::monostate> m_data;

            template <std::size_t Index, class ClassType>
                requires std::constructible_from<OkType, ClassType>
            constexpr ResultData(
                std::in_place_index_t<Index> index, ClassType&& ok
            ) noexcept(std::is_nothrow_constructible_v<ProtectedOkType, ClassType>) :
                m_data(index, std::move(ok)) {}

            template <std::size_t Index>
            constexpr ResultData(std::in_place_index_t<Index> index) noexcept : m_data(index) {}

            constexpr ResultData(ResultData&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ProtectedOkType>) :
                m_data(std::move(other.m_data)) {}

            constexpr ResultData(ResultData const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ProtectedOkType>) :
                m_data(other.m_data) {}

            constexpr OkContainer<OkType> asOk() && noexcept
                requires(!std::is_reference_v<OkType>)
            {
                return Ok(std::get<0>(std::move(m_data)));
            }

            constexpr OkContainer<OkType> asOk() const& noexcept
                requires(!std::is_reference_v<OkType>)
            {
                return Ok(static_cast<OkType>(std::get<0>(m_data)));
            }

            constexpr OkContainer<OkType&> asOk() && noexcept
                requires(std::is_reference_v<OkType>)
            {
                return Ok(std::get<0>(m_data).get());
            }

            constexpr OkContainer<OkType&> asOk() const& noexcept
                requires(std::is_reference_v<OkType>)
            {
                return Ok(std::get<0>(m_data).get());
            }

            constexpr ErrContainer<void> asErr() const noexcept {
                return Err();
            }

        public:
            /// @brief Returns true if the Result is Ok
            /// @return true if the Result is Ok
            constexpr bool isOk() const noexcept {
                return m_data.index() == 0;
            }

            /// @brief Returns true if the Result is Err
            /// @return true if the Result is Err
            constexpr bool isErr() const noexcept {
                return m_data.index() == 1;
            }

            /// @brief Unwraps the Ok value from the Result
            /// @throw UnwrapException if the Result is Err
            /// @return the Ok value
            constexpr OkType&& unwrap() && {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Ok value from the Result
            /// @throw UnwrapException if the Result is Err
            /// @return the Ok value
            constexpr OkType& unwrap() & {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Ok value from the Result
            /// @throw UnwrapException if the Result is Err
            /// @return the Ok value
            constexpr OkType const& unwrap() const& {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr void unwrapErr() {
                if (isOk()) {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Returns a Result with references to the underlying values
            /// @return a Result with references to the underlying values
            constexpr Result<OkType&, void> asRef() noexcept;

            /// @brief Returns a Result with const references to the underlying values
            /// @return a Result with const references to the underlying values
            constexpr Result<OkType const&, void> asConst() const noexcept;

            /// @brief Unwraps the Ok value from the Result, default constructing if unavailable
            /// @return the Ok value if available, otherwise a default constructed Ok value
            constexpr OkType unwrapOrDefault(
            ) && noexcept(std::is_nothrow_default_constructible_v<OkType> && std::is_nothrow_move_constructible_v<OkType>)
                requires std::default_initializable<OkType>
            {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    return OkType();
                }
            }

            /// @brief Unwraps the Ok value from the Result, default constructing if unavailable
            /// @return the Ok value if available, otherwise a default constructed Ok value
            constexpr OkType unwrapOrDefault(
            ) const& noexcept(std::is_nothrow_default_constructible_v<OkType> && std::is_nothrow_move_constructible_v<OkType>)
                requires std::default_initializable<OkType>
            {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    return OkType();
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning a default value if unavailable
            /// @param defaultValue the default value to return if the Result is Err
            /// @return the Ok value if available, otherwise the default value
            constexpr OkType unwrapOr(auto&& defaultValue
            ) && noexcept(std::is_nothrow_move_constructible_v<OkType>)
                requires std::constructible_from<OkType, decltype(defaultValue)>
            {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    return defaultValue;
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning a default value if unavailable
            /// @param defaultValue the default value to return if the Result is Err
            /// @return the Ok value if available, otherwise the default value
            constexpr OkType unwrapOr(auto&& defaultValue
            ) const& noexcept(std::is_nothrow_move_constructible_v<OkType>)
                requires std::constructible_from<OkType, decltype(defaultValue)>
            {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    return defaultValue;
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning the result of an operation if unavailable
            /// @param operation the operation to perform if the Result is Err
            /// @return the Ok value if available, otherwise the result of the operation
            constexpr OkType unwrapOrElse(std::invocable auto&& operation
            ) && noexcept(std::is_nothrow_invocable_v<decltype(operation)>)
                requires std::constructible_from<OkType, std::invoke_result_t<decltype(operation)>>
            {
                if (isOk()) {
                    return std::get<0>(std::move(m_data));
                }
                else {
                    return operation();
                }
            }

            /// @brief Unwraps the Ok value from the Result, returning the result of an operation if unavailable
            /// @param operation the operation to perform if the Result is Err
            /// @return the Ok value if available, otherwise the result of the operation
            constexpr OkType unwrapOrElse(std::invocable auto&& operation
            ) const& noexcept(std::is_nothrow_invocable_v<decltype(operation)>)
                requires std::constructible_from<OkType, std::invoke_result_t<decltype(operation)>>
            {
                if (isOk()) {
                    return std::get<0>(m_data);
                }
                else {
                    return operation();
                }
            }

            /// @brief Returns a Result with a copied Ok value
            /// @return a Result with a copied Ok value
            constexpr Result<std::remove_reference_t<OkType>, void> copied() const
                noexcept(std::is_nothrow_copy_constructible_v<OkType>)
                requires(std::is_reference_v<OkType>);

        protected:
            constexpr void inspectInternal(std::invocable<OkType const&> auto&& operation) const
                noexcept(noexcept(operation(std::declval<OkType const&>()))) {
                if (this->isOk()) {
                    operation(std::get<0>(m_data));
                }
            }
        };

        template <>
        class ResultData<void, void> {
        protected:
            std::variant<std::monostate, std::monostate> m_data;

            template <std::size_t Index>
            constexpr inline ResultData(std::in_place_index_t<Index> index) noexcept :
                m_data(index) {}

            constexpr inline ResultData(ResultData&&) noexcept {}

            constexpr inline ResultData(ResultData const&) noexcept {}

            constexpr inline OkContainer<void> asOk() const noexcept {
                return Ok();
            }

            constexpr inline ErrContainer<void> asErr() const noexcept {
                return Err();
            }

        public:
            /// @brief Returns true if the Result is Ok
            /// @return true if the Result is Ok
            constexpr inline bool isOk() const noexcept {
                return m_data.index() == 0;
            }

            /// @brief Returns true if the Result is Err
            /// @return true if the Result is Err
            constexpr inline bool isErr() const noexcept {
                return m_data.index() == 1;
            }

            /// @brief Unwraps the Result
            /// @throw UnwrapException if the Result is Err
            constexpr void unwrap() {
                if (isErr()) {
                    throw UnwrapException(ErrTag{}, std::get<1>(m_data));
                }
            }

            /// @brief Unwraps the Err value from the Result
            /// @throw UnwrapException if the Result is Ok
            /// @return the Err value
            constexpr void unwrapErr() {
                if (isOk()) {
                    throw UnwrapException(OkTag{}, std::get<0>(m_data));
                }
            }

            /// @brief Returns a Result with references to the underlying values
            /// @return a Result with references to the underlying values
            constexpr inline Result<void, void> asRef() noexcept;

            /// @brief Returns a Result with const references to the underlying values
            /// @return a Result with const references to the underlying values
            constexpr inline Result<void, void> asConst() const noexcept;

            /// @brief Returns a Result with a copied Ok value
            /// @return a Result with a copied Ok value
            constexpr inline Result<void, void> copied() const noexcept;
        };

        template <class OkType, class ErrType>
        class ResultDataWrapper : public ResultData<OkType, ErrType> {
        public:
            template <class OkType2>
                requires std::constructible_from<OkType, OkType2>
            constexpr ResultDataWrapper(OkContainer<OkType2>&& ok
            ) noexcept(std::
                           is_nothrow_constructible_v<
                               ResultData<OkType, ErrType>, std::in_place_index_t<0>, OkType2>) :
                ResultData<OkType, ErrType>(std::in_place_index<0>, std::move(ok).unwrap()) {}

            template <class ErrType2>
                requires std::constructible_from<ErrType, ErrType2>
            constexpr ResultDataWrapper(ErrContainer<ErrType2>&& err
            ) noexcept(std::
                           is_nothrow_constructible_v<
                               ResultData<OkType, ErrType>, std::in_place_index_t<1>, ErrType2>) :
                ResultData<OkType, ErrType>(std::in_place_index<1>, std::move(err).unwrap()) {}

            constexpr ResultDataWrapper(ResultDataWrapper&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ResultData<OkType, ErrType>>) :
                ResultData<OkType, ErrType>(std::move(other)) {}

            constexpr ResultDataWrapper(ResultDataWrapper const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ResultData<OkType, ErrType>>) :
                ResultData<OkType, ErrType>(other) {}
        };

        template <class OkType>
        class ResultDataWrapper<OkType, void> : public ResultData<OkType, void> {
        public:
            template <class OkType2>
                requires std::constructible_from<OkType, OkType2>
            constexpr ResultDataWrapper(OkContainer<OkType2>&& ok
            ) noexcept(std::is_nothrow_constructible_v<ResultData<OkType, void>, std::in_place_index_t<0>, OkType2>) :
                ResultData<OkType, void>(std::in_place_index<0>, std::move(ok).unwrap()) {}

            constexpr ResultDataWrapper(ErrContainer<void>&&) noexcept(std::is_nothrow_constructible_v<
                                                                       ResultData<OkType, void>,
                                                                       std::in_place_index_t<1>>) :
                ResultData<OkType, void>(std::in_place_index<1>) {}

            constexpr ResultDataWrapper(ResultDataWrapper&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ResultData<OkType, void>>) :
                ResultData<OkType, void>(std::move(other)) {}

            constexpr ResultDataWrapper(ResultDataWrapper const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ResultData<OkType, void>>) :
                ResultData<OkType, void>(other) {}
        };

        template <class ErrType>
        class ResultDataWrapper<void, ErrType> : public ResultData<void, ErrType> {
        public:
            template <class ErrType2>
                requires std::constructible_from<ErrType, ErrType2>
            constexpr ResultDataWrapper(ErrContainer<ErrType2>&& err
            ) noexcept(std::
                           is_nothrow_constructible_v<
                               ResultData<void, ErrType>, std::in_place_index_t<1>, ErrType2>) :
                ResultData<void, ErrType>(std::in_place_index<1>, std::move(err).unwrap()) {}

            constexpr ResultDataWrapper(OkContainer<void>&&) noexcept(std::is_nothrow_constructible_v<
                                                                      ResultData<void, ErrType>,
                                                                      std::in_place_index_t<0>>) :
                ResultData<void, ErrType>(std::in_place_index<0>) {}

            constexpr ResultDataWrapper(ResultDataWrapper&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ResultData<void, ErrType>>) :
                ResultData<void, ErrType>(std::move(other)) {}

            constexpr ResultDataWrapper(ResultDataWrapper const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ResultData<void, ErrType>>) :
                ResultData<void, ErrType>(other) {}
        };

        template <>
        class ResultDataWrapper<void, void> : public ResultData<void, void> {
        public:
            constexpr inline ResultDataWrapper(OkContainer<void>&&) :
                ResultData<void, void>(std::in_place_index<0>) {}

            constexpr inline ResultDataWrapper(ErrContainer<void>&&) :
                ResultData<void, void>(std::in_place_index<1>) {}

            constexpr inline ResultDataWrapper(ResultDataWrapper&& other
            ) noexcept(std::is_nothrow_move_constructible_v<ResultData<void, void>>) :
                ResultData<void, void>(std::move(other)) {}

            constexpr inline ResultDataWrapper(ResultDataWrapper const& other
            ) noexcept(std::is_nothrow_copy_constructible_v<ResultData<void, void>>) :
                ResultData<void, void>(other) {}
        };
    }

    template <class OkType = void, class ErrType = std::string>
    class [[nodiscard]] Result final : public impl::ResultDataWrapper<OkType, ErrType> {
    public:
        using impl::ResultDataWrapper<OkType, ErrType>::ResultDataWrapper;

        Result() = delete;

        Result(Result const& other
        ) noexcept(std::is_nothrow_copy_constructible_v<impl::ResultData<OkType, ErrType>>) :
            impl::ResultDataWrapper<OkType, ErrType>(other) {}

        constexpr Result(Result&& other
        ) noexcept(std::is_nothrow_move_constructible_v<impl::ResultData<OkType, ErrType>>) :
            impl::ResultDataWrapper<OkType, ErrType>(std::move(other)) {}

        constexpr Result& operator=(Result&& other
        ) noexcept(std::is_nothrow_move_assignable_v<impl::ResultData<OkType, ErrType>>) {
            if (this != &other) {
                this->m_data = std::move(other.m_data);
            }

            return *this;
        }

        /// @brief Returns true if the Result is Ok
        /// @return true if the Result is Ok
        constexpr explicit operator bool() const noexcept {
            return this->isOk();
        }

        /// @brief Returns true if the Result is equal to another Result
        /// @param other the Result to compare against
        /// @return true if the Results are equal
        template <class OkType2, class ErrType2>
        constexpr bool operator==(Result<OkType2, ErrType2> const& other) const noexcept {
            if (this->isOk() && other.isOk()) {
                return std::get<0>(this->m_data) == std::get<0>(other.m_data);
            }
            else if (this->isErr() && other.isErr()) {
                return std::get<1>(this->m_data) == std::get<1>(other.m_data);
            }
            return false;
        }

        /// @brief Returns true if the Result is equal to an Ok value
        /// @param other the Ok value to compare against
        /// @return true if the Result is Ok and the Ok value is equal
        template <class OkType2>
        constexpr bool operator==(impl::OkContainer<OkType2> const& other) const noexcept {
            if (this->isOk()) {
                return std::get<0>(this->m_data) == other.m_ok;
            }
            return false;
        }

        /// @brief Returns true if the Result is equal to an Err value
        /// @param other the Err value to compare against
        /// @return true if the Result is Err and the Err value is equal
        template <class ErrType2>
        constexpr bool operator==(impl::ErrContainer<ErrType2> const& other) const noexcept {
            if (this->isErr()) {
                return std::get<1>(this->m_data) == other.m_err;
            }
            return false;
        }

        /// @brief Returns true if the Result is not equal to another Result
        /// @param other the Result to compare against
        /// @return true if the Results are not equal
        template <class OkType2, class ErrType2>
        constexpr bool operator!=(Result<OkType2, ErrType2> const& other) const noexcept {
            return !(*this == other);
        }

        /// @brief Returns true if the Result is not equal to an Ok value
        /// @param other the Ok value to compare against
        /// @return true if the Result is not Ok or the Ok value is not equal
        template <class OkType2>
        constexpr bool operator!=(impl::OkContainer<OkType2> const& other) const noexcept {
            return !(*this == other);
        }

        /// @brief Returns true if the Result is not equal to an Err value
        /// @param other the Err value to compare against
        /// @return true if the Result is not Err or the Err value is not equal
        template <class ErrType2>
        constexpr bool operator!=(impl::ErrContainer<ErrType2> const& other) const noexcept {
            return !(*this == other);
        }

        /// @brief Unwraps the Ok value from the Result
        /// @throw UnwrapException if the Result is Err
        /// @return the Ok value
        /// @note Same behavior as Result::unwrap()
        constexpr decltype(auto) operator*() && noexcept
            requires(!std::same_as<OkType, void>)
        {
            return std::move(*this).unwrap();
        }

        /// @brief Unwraps the Ok value from the Result
        /// @throw UnwrapException if the Result is Err
        /// @return the Ok value
        /// @note Same behavior as Result::unwrap()
        constexpr decltype(auto) operator*() & noexcept
            requires(!std::same_as<OkType, void>)
        {
            return this->unwrap();
        }

        /// @brief Unwraps the Ok value from the Result
        /// @throw UnwrapException if the Result is Err
        /// @return the Ok value
        /// @note Same behavior as Result::unwrap()
        constexpr decltype(auto) operator*() const& noexcept
            requires(!std::same_as<OkType, void>)
        {
            return this->unwrap();
        }

        /// @brief Returns true if the Result is Ok and the Ok value satisfies the predicate
        /// @param predicate the predicate to check the Ok value against
        /// @return true if the Result is Ok and the Ok value satisfies the predicate
        constexpr bool isOkAnd(std::invocable<OkType> auto&& predicate
        ) && noexcept(noexcept(predicate(std::declval<OkType>()))) {
            return this->isOk() && predicate(std::move(*this).unwrap());
        }

        /// @brief Returns true if the Result is Ok and the Ok value satisfies the predicate
        /// @param predicate the predicate to check the Ok value against
        /// @return true if the Result is Ok and the Ok value satisfies the predicate
        constexpr bool isOkAnd(std::invocable<OkType> auto&& predicate
        ) const& noexcept(noexcept(predicate(std::declval<OkType>()))) {
            return this->isOk() && predicate(this->unwrap());
        }

        /// @brief Returns true if the Result is Err and the Err value satisfies the predicate
        /// @param predicate the predicate to check the Err value against
        /// @return true if the Result is Err and the Err value satisfies the predicate
        constexpr bool isErrAnd(std::invocable<ErrType> auto&& predicate
        ) && noexcept(noexcept(predicate(std::declval<ErrType>()))) {
            return this->isErr() && predicate(std::move(*this).unwrapErr());
        }

        /// @brief Returns true if the Result is Err and the Err value satisfies the predicate
        /// @param predicate the predicate to check the Err value against
        /// @return true if the Result is Err and the Err value satisfies the predicate
        constexpr bool isErrAnd(std::invocable<ErrType> auto&& predicate
        ) const& noexcept(noexcept(predicate(std::declval<ErrType>()))) {
            return this->isErr() && predicate(this->unwrapErr());
        }

        /// @brief Returns an std::optional containing the Ok value
        /// @return an std::optional containing the Ok value if the Result is Ok, otherwise std::nullopt
        constexpr std::optional<OkType> ok() && noexcept {
            if (this->isOk()) {
                return std::move(*this).unwrap();
            }
            else {
                return std::nullopt;
            }
        }

        /// @brief Returns an std::optional containing the Ok value
        /// @return an std::optional containing the Ok value if the Result is Ok, otherwise std::nullopt
        constexpr std::optional<OkType> ok() const& noexcept {
            if (this->isOk()) {
                return this->unwrap();
            }
            else {
                return std::nullopt;
            }
        }

        /// @brief Returns an std::optional containing the Err value
        /// @return an std::optional containing the Err value if the Result is Err, otherwise std::nullopt
        constexpr std::optional<ErrType> err() && noexcept {
            if (this->isErr()) {
                return std::move(*this).unwrapErr();
            }
            else {
                return std::nullopt;
            }
        }

        /// @brief Returns an std::optional containing the Err value
        /// @return an std::optional containing the Err value if the Result is Err, otherwise std::nullopt
        constexpr std::optional<ErrType> err() const& noexcept {
            if (this->isErr()) {
                return this->unwrapErr();
            }
            else {
                return std::nullopt;
            }
        }

        /// @brief Maps the Ok value to a new Ok value using an operation
        /// @param operation the operation to map the Ok value with
        /// @return a new Result with the mapped Ok value if the Result is Ok, otherwise the Err value
        template <class Operation>
            requires std::invocable<Operation, OkType>
        constexpr Result<std::invoke_result_t<Operation, OkType>, ErrType> map(Operation&& operation
        ) && noexcept(noexcept(operation(std::declval<OkType>()))) {
            if (this->isOk()) {
                return Ok(operation(std::move(*this).unwrap()));
            }
            else {
                return (*this).asErr();
            }
        }

        /// @brief Maps the Ok value to a new Ok value using an operation
        /// @param operation the operation to map the Ok value with
        /// @return a new Result with the mapped Ok value if the Result is Ok, otherwise the Err value
        template <class Operation>
            requires std::invocable<Operation, OkType>
        constexpr Result<std::invoke_result_t<Operation, OkType>, ErrType> map(Operation&& operation
        ) const& noexcept(noexcept(operation(std::declval<OkType>()))) {
            if (this->isOk()) {
                return Ok(operation(this->unwrap()));
            }
            else {
                return this->asErr();
            }
        }

        /// @brief Maps the Ok value to a new Ok value using an operation
        /// @param operation the operation to map the Ok value with
        /// @return a new Result with the mapped Ok value if the Result is Ok, otherwise the Err value
        template <class Operation>
            requires std::invocable<Operation>
        constexpr Result<std::invoke_result_t<Operation>, ErrType> map(Operation&& operation
        ) && noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return Ok(operation());
            }
            else {
                return (*this).asErr();
            }
        }

        /// @brief Maps the Ok value to a new Ok value using an operation
        /// @param operation the operation to map the Ok value with
        /// @return a new Result with the mapped Ok value if the Result is Ok, otherwise the Err value
        template <class Operation>
            requires std::invocable<Operation>
        constexpr Result<std::invoke_result_t<Operation>, ErrType> map(Operation&& operation
        ) const& noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return Ok(operation());
            }
            else {
                return this->asErr();
            }
        }

        /// @brief Maps the Ok value to a new value using an operation
        /// @param defaultValue the default value to return if the Result is Err
        /// @param operation the operation to map the Ok value with
        /// @return the mapped Ok value if the Result is Ok, otherwise the default value
        template <class OkType2, class Operation>
            requires(std::invocable<Operation, OkType> && std::convertible_to<std::invoke_result_t<Operation, OkType>, OkType2>)
        constexpr OkType2 mapOr(OkType2&& defaultValue, Operation&& operation) && noexcept(
            noexcept(operation(std::declval<OkType>()))
        ) {
            if (this->isOk()) {
                return operation(std::move(*this).unwrap());
            }
            else {
                return std::move(defaultValue);
            }
        }

        /// @brief Maps the Ok value to a new value using an operation
        /// @param defaultValue the default value to return if the Result is Err
        /// @param operation the operation to map the Ok value with
        /// @return the mapped Ok value if the Result is Ok, otherwise the default value
        template <class OkType2, class Operation>
            requires(std::invocable<Operation, OkType> && std::convertible_to<std::invoke_result_t<Operation, OkType>, OkType2>)
        constexpr OkType2 mapOr(OkType2&& defaultValue, Operation&& operation)
            const& noexcept(noexcept(operation(std::declval<OkType>()))) {
            if (this->isOk()) {
                return operation(this->unwrap());
            }
            else {
                return std::move(defaultValue);
            }
        }

        /// @brief Maps the Ok value to a new value using an operation
        /// @param defaultValue the default value to return if the Result is Err
        /// @param operation the operation to map the Ok value with
        /// @return the mapped Ok value if the Result is Ok, otherwise the default value
        template <class OkType2, class Operation>
            requires(std::invocable<Operation> && std::convertible_to<std::invoke_result_t<Operation>, OkType2>)
        constexpr OkType2 mapOr(OkType2&& defaultValue, Operation&& operation) noexcept(
            noexcept(operation())
        ) {
            if (this->isOk()) {
                return operation();
            }
            else {
                return std::move(defaultValue);
            }
        }

        /// @brief Maps the Ok value to a new value using an operation
        /// @param defaultValue the operation to perform if the Result is Err
        /// @param operation the operation to map the Ok value with
        /// @return the mapped Ok value if the Result is Ok, otherwise the result of the operation
        template <class DefaultValue, class Operation>
            requires(std::invocable<DefaultValue> && std::invocable<Operation, OkType> && std::convertible_to<std::invoke_result_t<DefaultValue>, std::invoke_result_t<Operation, OkType>>)
        constexpr std::invoke_result_t<Operation, OkType> mapOrElse(
            DefaultValue&& defaultValue, Operation&& operation
        ) && noexcept(noexcept(operation(std::declval<OkType>())) && noexcept(defaultValue())) {
            if (this->isOk()) {
                return operation(std::move(*this).unwrap());
            }
            else {
                return defaultValue();
            }
        }

        /// @brief Maps the Ok value to a new value using an operation
        /// @param defaultValue the operation to perform if the Result is Err
        /// @param operation the operation to map the Ok value with
        /// @return the mapped Ok value if the Result is Ok, otherwise the result of the operation
        template <class DefaultValue, class Operation>
            requires(std::invocable<DefaultValue> && std::invocable<Operation, OkType> && std::convertible_to<std::invoke_result_t<DefaultValue>, std::invoke_result_t<Operation, OkType>>)
        constexpr std::invoke_result_t<Operation, OkType> mapOrElse(
            DefaultValue&& defaultValue, Operation&& operation
        ) const& noexcept(noexcept(operation(std::declval<OkType>())) && noexcept(defaultValue())) {
            if (this->isOk()) {
                return operation(this->unwrap());
            }
            else {
                return defaultValue();
            }
        }

        /// @brief Maps the Ok value to a new value using an operation
        /// @param defaultValue the operation to perform if the Result is Err
        /// @param operation the operation to map the Ok value with
        /// @return the mapped Ok value if the Result is Ok, otherwise the result of the operation
        template <class DefaultValue, class Operation>
            requires(std::invocable<DefaultValue> && std::invocable<Operation> && std::convertible_to<std::invoke_result_t<DefaultValue>, std::invoke_result_t<Operation>>)
        constexpr std::invoke_result_t<Operation> mapOrElse(
            DefaultValue&& defaultValue, Operation&& operation
        ) noexcept(noexcept(operation()) && noexcept(defaultValue())) {
            if (this->isOk()) {
                return operation();
            }
            else {
                return defaultValue();
            }
        }

        /// @brief Maps the Err value to a new Err value using an operation
        /// @param operation the operation to map the Err value with
        /// @return a new Result with the Ok value if the Result is Ok, otherwise the mapped Err value
        template <class Operation>
            requires std::invocable<Operation, ErrType>
        constexpr Result<OkType, std::invoke_result_t<Operation, ErrType>> mapErr(Operation&& operation
        ) && noexcept(noexcept(operation(std::declval<ErrType>()))) {
            if (this->isOk()) {
                return std::move(*this).asOk();
            }
            else {
                return Err(operation(std::move(*this).unwrapErr()));
            }
        }

        /// @brief Maps the Err value to a new Err value using an operation
        /// @param operation the operation to map the Err value with
        /// @return a new Result with the Ok value if the Result is Ok, otherwise the mapped Err value
        template <class Operation>
            requires std::invocable<Operation, ErrType>
        constexpr Result<OkType, std::invoke_result_t<Operation, ErrType>> mapErr(Operation&& operation
        ) const& noexcept(noexcept(operation(std::declval<ErrType>()))) {
            if (this->isOk()) {
                return this->asOk();
            }
            else {
                return Err(operation(this->unwrapErr()));
            }
        }

        /// @brief Maps the Err value to a new Err value using an operation
        /// @param operation the operation to map the Err value with
        /// @return a new Result with the Ok value if the Result is Ok, otherwise the mapped Err value
        template <class Operation>
            requires std::invocable<Operation>
        constexpr Result<OkType, std::invoke_result_t<Operation>> mapErr(Operation&& operation
        ) && noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return std::move(*this).asOk();
            }
            else {
                return Err(operation());
            }
        }

        /// @brief Maps the Err value to a new Err value using an operation
        /// @param operation the operation to map the Err value with
        /// @return a new Result with the Ok value if the Result is Ok, otherwise the mapped Err value
        template <class Operation>
            requires std::invocable<Operation>
        constexpr Result<OkType, std::invoke_result_t<Operation>> mapErr(Operation&& operation
        ) const& noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return this->asOk();
            }
            else {
                return Err(operation());
            }
        }

        /// @brief Inspects the Ok value with an operation
        /// @param operation the operation to call the Ok value with
        /// @return the Result itself
        template <class Fn>
            requires(!std::same_as<OkType, void> && std::invocable<Fn, OkType const&>)
        constexpr Result<OkType, ErrType>& inspect(Fn&& operation
        ) noexcept(noexcept(operation(std::declval<OkType const&>()))) {
            this->inspectInternal(operation);
            return *this;
        }

        /// @brief Inspects the Err value with an operation
        /// @param operation the operation to call the Err value with
        /// @return the Result itself
        template <class Fn>
            requires(!std::same_as<ErrType, void> && std::invocable<Fn, ErrType const&>)
        constexpr Result<OkType, ErrType>& inspectErr(Fn&& operation
        ) noexcept(noexcept(operation(std::declval<ErrType const&>()))) {
            this->inspectInternalErr(operation);
            return *this;
        }

        /// @brief Returns the other Result if this Result is Ok, otherwise returns this Result
        /// @param other the other Result to return if this Result is Ok
        /// @return the other Result if this Result is Ok, otherwise this Result
        template <class OkType2>
        constexpr Result<OkType2, ErrType> and_(Result<OkType2, ErrType>&& other) && noexcept {
            if (this->isOk()) {
                return std::move(other);
            }
            else {
                return (*this).asErr();
            }
        }

        /// @brief Returns the other Result if this Result is Ok, otherwise returns this Result
        /// @param other the other Result to return if this Result is Ok
        /// @return the other Result if this Result is Ok, otherwise this Result
        template <class OkType2>
        constexpr Result<OkType2, ErrType> and_(Result<OkType2, ErrType>&& other) const& noexcept {
            if (this->isOk()) {
                return std::move(other);
            }
            else {
                return this->asErr();
            }
        }

        /// @brief Returns the result of an operation if this Result is Ok, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Ok
        /// @return the result of the operation if this Result is Ok, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation, OkType> && impl::IsResult<std::invoke_result_t<Operation, OkType>> && std::convertible_to<ErrType, impl::ResultErrType<std::invoke_result_t<Operation, OkType>>>)
        constexpr std::invoke_result_t<Operation, OkType> andThen(Operation&& operation
        ) && noexcept(noexcept(operation(std::declval<OkType>()))) {
            if (this->isOk()) {
                return operation(std::move(*this).unwrap());
            }
            else {
                return (*this).asErr();
            }
        }

        /// @brief Returns the result of an operation if this Result is Ok, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Ok
        /// @return the result of the operation if this Result is Ok, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation, OkType> && impl::IsResult<std::invoke_result_t<Operation, OkType>> && std::convertible_to<ErrType, impl::ResultErrType<std::invoke_result_t<Operation, OkType>>>)
        constexpr std::invoke_result_t<Operation, OkType> andThen(Operation&& operation
        ) const& noexcept(noexcept(operation(std::declval<OkType>()))) {
            if (this->isOk()) {
                return operation(this->unwrap());
            }
            else {
                return this->asErr();
            }
        }

        /// @brief Returns the result of an operation if this Result is Ok, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Ok
        /// @return the result of the operation if this Result is Ok, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation> && impl::IsResult<std::invoke_result_t<Operation>> && std::convertible_to<ErrType, impl::ResultErrType<std::invoke_result_t<Operation>>>)
        constexpr std::invoke_result_t<Operation> andThen(Operation&& operation
        ) && noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return operation();
            }
            else {
                return (*this).asErr();
            }
        }

        /// @brief Returns the result of an operation if this Result is Ok, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Ok
        /// @return the result of the operation if this Result is Ok, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation> && impl::IsResult<std::invoke_result_t<Operation>> && std::convertible_to<ErrType, impl::ResultErrType<std::invoke_result_t<Operation>>>)
        constexpr std::invoke_result_t<Operation> andThen(Operation&& operation
        ) const& noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return operation();
            }
            else {
                return this->asErr();
            }
        }

        /// @brief Returns the other Result if this Result is Err, otherwise returns this Result
        /// @param other the other Result to return if this Result is Err
        /// @return the other Result if this Result is Err, otherwise this Result
        template <class ErrType2>
        constexpr Result<OkType, ErrType2> or_(Result<OkType, ErrType2>&& other) && noexcept {
            if (this->isOk()) {
                return std::move(*this).asOk();
            }
            else {
                return std::move(other);
            }
        }

        /// @brief Returns the other Result if this Result is Err, otherwise returns this Result
        /// @param other the other Result to return if this Result is Err
        /// @return the other Result if this Result is Err, otherwise this Result
        template <class ErrType2>
        constexpr Result<OkType, ErrType2> or_(Result<OkType, ErrType2>&& other) const& noexcept {
            if (this->isOk()) {
                return this->asOk();
            }
            else {
                return std::move(other);
            }
        }

        /// @brief Returns the result of an operation if this Result is Err, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Err
        /// @return the result of the operation if this Result is Err, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation, ErrType> && impl::IsResult<std::invoke_result_t<Operation, ErrType>> && std::convertible_to<OkType, impl::ResultOkType<std::invoke_result_t<Operation, ErrType>>>)
        constexpr std::invoke_result_t<Operation, ErrType> orElse(Operation&& operation
        ) && noexcept(noexcept(operation(std::declval<ErrType>()))) {
            if (this->isOk()) {
                return std::move(*this).asOk();
            }
            else {
                return operation(std::move(*this).unwrapErr());
            }
        }

        /// @brief Returns the result of an operation if this Result is Err, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Err
        /// @return the result of the operation if this Result is Err, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation, ErrType> && impl::IsResult<std::invoke_result_t<Operation, ErrType>> && std::convertible_to<OkType, impl::ResultOkType<std::invoke_result_t<Operation, ErrType>>>)
        constexpr std::invoke_result_t<Operation, ErrType> orElse(Operation&& operation
        ) const& noexcept(noexcept(operation(std::declval<ErrType>()))) {
            if (this->isOk()) {
                return this->asOk();
            }
            else {
                return operation(this->unwrapErr());
            }
        }

        /// @brief Returns the result of an operation if this Result is Err, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Err
        /// @return the result of the operation if this Result is Err, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation> && impl::IsResult<std::invoke_result_t<Operation>> && std::convertible_to<OkType, impl::ResultOkType<std::invoke_result_t<Operation>>>)
        constexpr std::invoke_result_t<Operation> orElse(Operation&& operation
        ) && noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return std::move(*this).asOk();
            }
            else {
                return operation();
            }
        }

        /// @brief Returns the result of an operation if this Result is Err, otherwise returns this Result
        /// @param operation the operation to perform if this Result is Err
        /// @return the result of the operation if this Result is Err, otherwise this Result
        template <class Operation>
            requires(std::invocable<Operation> && impl::IsResult<std::invoke_result_t<Operation>> && std::convertible_to<OkType, impl::ResultOkType<std::invoke_result_t<Operation>>>)
        constexpr std::invoke_result_t<Operation> orElse(Operation&& operation
        ) const& noexcept(noexcept(operation())) {
            if (this->isOk()) {
                return this->asOk();
            }
            else {
                return operation();
            }
        }

        /// @brief Transposes the Result from Result<std::optional<OkType>, ErrType> to
        /// std::optional<Result<OkType, ErrType>>
        /// @return std::nullopt if Ok value is empty, otherwise the Result wrapped in an optional
        constexpr std::optional<Result<impl::OptionalType<OkType>, ErrType>> transpose(
        ) && noexcept(std::is_nothrow_move_constructible_v<OkType> && std::is_nothrow_move_constructible_v<ErrType>)
            requires(impl::IsOptional<OkType>)
        {
            if (this->isOk()) {
                auto res = (*this).unwrap();
                if (res.has_value()) {
                    return Ok(std::move(res).value());
                }
                else {
                    return std::nullopt;
                }
            }
            else {
                return std::move(*this).asErr();
            }
        }

        /// @brief Transposes the Result from Result<std::optional<OkType>, ErrType> to
        /// std::optional<Result<OkType, ErrType>>
        /// @return std::nullopt if Ok value is empty, otherwise the Result wrapped in an optional
        constexpr std::optional<Result<impl::OptionalType<OkType>, ErrType>> transpose(
        ) const& noexcept(std::is_nothrow_move_constructible_v<OkType> && std::is_nothrow_move_constructible_v<ErrType>)
            requires(impl::IsOptional<OkType>)
        {
            if (this->isOk()) {
                auto res = this->unwrap();
                if (res.has_value()) {
                    return Ok(std::move(res).value());
                }
                else {
                    return std::nullopt;
                }
            }
            else {
                return this->asErr();
            }
        }

        /// @brief Flattens the Result from Result<Result<OkType, ErrType>, ErrType> to Result<OkType, ErrType>
        /// @return the inner Result if the Result is Ok, otherwise the outer Result
        constexpr Result<impl::ResultOkType<OkType>, ErrType> flatten(
        ) && noexcept(std::is_nothrow_move_constructible_v<OkType> && std::is_nothrow_move_constructible_v<ErrType>)
            requires(impl::IsResult<OkType> && std::same_as<ErrType, impl::ResultErrType<OkType>>)
        {
            if (this->isOk()) {
                return std::move(*this).unwrap();
            }
            else {
                return std::move(*this).asErr();
            }
        }

        /// @brief Flattens the Result from Result<Result<OkType, ErrType>, ErrType> to Result<OkType, ErrType>
        /// @return the inner Result if the Result is Ok, otherwise the outer Result
        constexpr Result<impl::ResultOkType<OkType>, ErrType> flatten(
        ) const& noexcept(std::is_nothrow_move_constructible_v<OkType> && std::is_nothrow_move_constructible_v<ErrType>)
            requires(impl::IsResult<OkType> && std::same_as<ErrType, impl::ResultErrType<OkType>>)
        {
            if (this->isOk()) {
                return this->unwrap();
            }
            else {
                return this->asErr();
            }
        }
    };

    namespace impl {
        /// @brief Returns true if the Result is equal to an Ok value
        /// @param ok the Ok value to compare against
        /// @param result the Result to compare against
        /// @return true if the Result is Ok and the Ok value is equal
        template <class OkType, class ErrType, class OkType2>
        constexpr bool operator==(
            OkContainer<OkType2> const& ok, Result<OkType, ErrType> const& result
        ) noexcept {
            return result == ok;
        }

        /// @brief Returns true if the Result is equal to an Err value
        /// @param err the Err value to compare against
        /// @param result the Result to compare against
        /// @return true if the Result is Err and the Err value is equal
        template <class OkType, class ErrType, class ErrType2>
        constexpr bool operator==(
            ErrContainer<ErrType2> const& err, Result<OkType, ErrType> const& result
        ) noexcept {
            return result == err;
        }

        /// @brief Returns true if the Result is not equal to an Ok value
        /// @param ok the Ok value to compare against
        /// @param result the Result to compare against
        /// @return true if the Result is not Ok or the Ok value is not equal
        template <class OkType, class ErrType, class OkType2>
        constexpr bool operator!=(
            OkContainer<OkType2> const& ok, Result<OkType, ErrType> const& result
        ) noexcept {
            return result != ok;
        }

        /// @brief Returns true if the Result is not equal to an Err value
        /// @param err the Err value to compare against
        /// @param result the Result to compare against
        /// @return true if the Result is not Err or the Err value is not equal
        template <class OkType, class ErrType, class ErrType2>
        constexpr bool operator!=(
            ErrContainer<ErrType2> const& err, Result<OkType, ErrType> const& result
        ) noexcept {
            return result != err;
        }

        template <class OkType, class ErrType>
        constexpr Result<OkType&, ErrType&> ResultData<OkType, ErrType>::asRef() noexcept {
            if (this->isOk()) {
                return Ok(std::get<0>(m_data));
            }
            else {
                return Err(std::get<1>(m_data));
            }
        }

        template <class ErrType>
        constexpr Result<void, ErrType&> ResultData<void, ErrType>::asRef() noexcept {
            if (this->isOk()) {
                return Ok();
            }
            else {
                return Err(std::get<1>(m_data));
            }
        }

        template <class OkType>
        constexpr Result<OkType&, void> ResultData<OkType, void>::asRef() noexcept {
            if (this->isOk()) {
                return Ok(std::get<0>(m_data));
            }
            else {
                return Err();
            }
        }

        constexpr Result<void, void> ResultData<void, void>::asRef() noexcept {
            if (this->isOk()) {
                return Ok();
            }
            else {
                return Err();
            }
        }

        template <class OkType, class ErrType>
        constexpr Result<OkType const&, ErrType const&> ResultData<OkType, ErrType>::asConst(
        ) const noexcept {
            if (this->isOk()) {
                return Ok(std::get<0>(m_data));
            }
            else {
                return Err(std::get<1>(m_data));
            }
        }

        template <class ErrType>
        constexpr Result<void, ErrType const&> ResultData<void, ErrType>::asConst() const noexcept {
            if (this->isOk()) {
                return Ok();
            }
            else {
                return Err(std::get<1>(m_data));
            }
        }

        template <class OkType>
        constexpr Result<OkType const&, void> ResultData<OkType, void>::asConst() const noexcept {
            if (this->isOk()) {
                return Ok(std::get<0>(m_data));
            }
            else {
                return Err();
            }
        }

        constexpr Result<void, void> ResultData<void, void>::asConst() const noexcept {
            if (this->isOk()) {
                return Ok();
            }
            else {
                return Err();
            }
        }

        template <class OkType, class ErrType>
        constexpr Result<std::remove_reference_t<OkType>, ErrType> ResultData<OkType, ErrType>::copied(
        ) const noexcept(std::is_nothrow_copy_constructible_v<OkType>)
            requires(std::is_reference_v<OkType>)
        {
            if (this->isOk()) {
                return Ok(std::get<0>(m_data).get());
            }
            else {
                return Err(std::get<1>(m_data));
            }
        }

        template <class ErrType>
        constexpr Result<void, ErrType> ResultData<void, ErrType>::copied() const noexcept {
            if (this->isOk()) {
                return Ok();
            }
            else {
                return Err(std::get<1>(m_data));
            }
        }

        template <class OkType>
        constexpr Result<std::remove_reference_t<OkType>, void> ResultData<OkType, void>::copied() const
            noexcept(std::is_nothrow_copy_constructible_v<OkType>)
            requires(std::is_reference_v<OkType>)
        {
            if (this->isOk()) {
                return Ok(std::get<0>(m_data).get());
            }
            else {
                return Err();
            }
        }

        constexpr Result<void, void> ResultData<void, void>::copied() const noexcept {
            if (this->isOk()) {
                return Ok();
            }
            else {
                return Err();
            }
        }
    }
}

#endif // GEODE_RESULT_HPP
