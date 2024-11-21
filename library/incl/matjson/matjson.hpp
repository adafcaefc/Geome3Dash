#pragma once

#include <Geode/Result.hpp>
#include <istream>
#include <memory>
#include <type_traits>
#include <vector>

#ifdef MAT_JSON_DYNAMIC
    #if defined(_WIN32) && !defined(__CYGWIN__)
        #ifdef MAT_JSON_EXPORTING
            #define MAT_JSON_DLL __declspec(dllexport)
        #else
            #define MAT_JSON_DLL __declspec(dllimport)
        #endif
    #else
        #ifdef MAT_JSON_EXPORTING
            #define MAT_JSON_DLL [[gnu::visibility("default")]]
        #else
            #define MAT_JSON_DLL
        #endif
    #endif
#else
    #define MAT_JSON_DLL
#endif

namespace matjson {

    enum class Type {
        Object,
        Array,
        String,
        Number,
        Bool,
        Null,
    };

    class ValueImpl;

    class Value;

    struct ParseError {
        std::string message;
        int offset = 0, line = 0, column = 0;

        inline ParseError(std::string msg, int offset, int line, int column) :
            message(std::move(msg)), offset(offset), line(line), column(column) {}

        /// Returns a string representation of the error, useful for coercing into Result<T>
        /// methods, where the error type is a string. *Do not* rely on the format of this string,
        /// as it may change in the future. Instead, just access the fields directly.
        inline operator std::string() const {
            if (line) {
                return this->message + " at line " + std::to_string(this->line) + ", column " +
                    std::to_string(this->column);
            }
            return this->message;
        }
    };

    static constexpr int NO_INDENTATION = 0;
    static constexpr int TAB_INDENTATION = -1;

    /// Specialize this class and implement the following methods (not all required)
    /// static Result<T> fromJson(matjson::Value const&);
    /// static matjson::Value toJson(T const&);
    template <class T>
    struct Serialize;

    template <class T>
    concept CanSerialize = requires(matjson::Value const& value, T t) {
        { Serialize<std::remove_cvref_t<T>>::toJson(t) } -> std::same_as<matjson::Value>;
    };
    template <class T>
    concept CanDeserialize = requires(matjson::Value const& value, T t) {
        { Serialize<std::remove_cvref_t<T>>::fromJson(value) };
    };
    template <class T>
    concept CanSerde = CanSerialize<T> && CanDeserialize<T>;

    /// Creates a JSON object from a list of key-value pairs
    /// Example:
    /// > auto obj = makeObject({ {"key", 123}, {"key2", "value"} });
    /// @param entries List of key-value pairs
    /// @return The JSON object
    Value makeObject(std::initializer_list<std::pair<std::string, Value>>);

    class MAT_JSON_DLL Value {
        std::unique_ptr<ValueImpl> m_impl;
        friend ValueImpl;
        Value(std::unique_ptr<ValueImpl>);

        friend Value matjson::makeObject(std::initializer_list<std::pair<std::string, Value>>);
        void setKey_(std::string_view key);
        Value(std::vector<Value>, bool);

    public:
        /// Defaults to a JSON object, for convenience
        Value();
        Value(std::string value);
        Value(std::string_view value);
        Value(char const* value);
        Value(std::vector<Value> value);
        Value(std::nullptr_t);
        Value(double value);
        Value(bool value);
        explicit Value(std::intmax_t value);
        explicit Value(std::uintmax_t value);

        template <class T>
            requires std::is_integral_v<T> && std::is_signed_v<T>
        Value(T value) : Value(static_cast<std::intmax_t>(value)) {}

        template <class T>
            requires std::is_integral_v<T> && std::is_unsigned_v<T>
        Value(T value) : Value(static_cast<std::uintmax_t>(value)) {}

        template <CanSerialize T>
        Value(T&& value) :
            Value(Serialize<std::remove_cvref_t<T>>::toJson(std::forward<T>(value))) {}

        template <class T>
        // Prevents implicit conversion from pointer to bool
        Value(T*) = delete;

        Value(Value const&);
        Value(Value&&);
        ~Value();

        Value& operator=(Value);

        bool operator==(Value const&) const;
        bool operator<(Value const&) const;
        bool operator>(Value const&) const;

        /// Create an empty JSON object
        static Value object();
        /// Create an empty JSON array
        static Value array();

        /// Parses JSON from a string
        /// @param source The JSON string to parse
        /// @return The parsed JSON value or an error
        static geode::Result<Value, ParseError> parse(std::string_view source);

        /// Parses JSON from an input stream
        /// @param source Stream to parse
        /// @return The parsed JSON value or an error
        static geode::Result<Value, ParseError> parse(std::istream& source);

        /// Dumps the JSON value to a string, with a given indentation.
        /// If the given indentation is matjson::NO_INDENTATION, the json is compacted.
        /// If the given indentation is matjson::TAB_INDENTATION, the json is indented with tabs.
        /// @param indentationSize The number of spaces to use for indentation
        /// @return The JSON string
        /// @note Due to limitations in the JSON format, NaN and Infinity float values get converted to null.
        ///       This behavior is the same as many other JSON libraries.
        std::string dump(int indentationSize = 4) const;

        /// Returns the value associated with the given key
        /// @param key Object key
        /// @return The value associated with the key, or an error if it does not exist.
        geode::Result<Value&> get(std::string_view key);

        /// Returns the value associated with the given key
        /// @param key Object key
        /// @return The value associated with the key, or an error if it does not exist.
        geode::Result<Value const&> get(std::string_view key) const;

        /// Returns the value associated with the given index
        /// @param index Array index
        /// @return The value associated with the index, or an error if the index is out of bounds.
        geode::Result<Value&> get(std::size_t index);

        /// Returns the value associated with the given index
        /// @param index Array index
        /// @return The value associated with the index, or an error if the index is out of bounds.
        geode::Result<Value const&> get(std::size_t index) const;

        /// Returns the value associated with the given key
        /// @param key Object key
        /// @return The value associated with the key
        /// @note If the key does not exist, it is inserted into the object.
        ///       And if this is not an object, returns a null value
        Value& operator[](std::string_view key);

        /// Returns the value associated with the given key
        /// @param key Object key
        /// @return The value associated with the key
        /// @note If the key does not exist, or this is not an object,
        ///       returns a null value
        Value const& operator[](std::string_view key) const;

        /// Returns the value associated with the given index
        /// @param index Array index
        /// @return The value associated with the index
        /// @note If the index is out of bounds, or this is not an array,
        ///       returns a null value
        Value& operator[](std::size_t index);

        /// Returns the value associated with the given index
        /// @param index Array index
        /// @return The value associated with the index
        /// @note If the index is out of bounds, or this is not an array,
        ///       returns a null value
        Value const& operator[](std::size_t index) const;

        /// Sets the value associated with the given key
        /// @param key Object key
        /// @param value The value to set
        /// @note If this is not an object, nothing happens
        void set(std::string_view key, Value value);

        /// Adds a value to the end of the array
        /// @param value Value
        /// @note If this is not an array, nothing happens
        void push(Value value);

        /// Clears the array/object, removing all entries
        /// @note If this is not an array or object, nothing happens
        void clear();

        /// Removes the value associated with the given key
        /// @param key Object key
        /// @return true if the key was removed, false otherwise
        /// @note If this is not an object, nothing happens and returns false
        bool erase(std::string_view key);

        /// Checks if the key exists in the object
        /// @param key Object key
        /// @return true if the key exists, false otherwise
        /// @note If this is not an object, returns false
        bool contains(std::string_view key) const;

        /// Returns the number of entries in the array/object.
        /// @return The number of entries
        /// @note If this is not an array or object, returns 0
        std::size_t size() const;

        /// Returns the type of the JSON value
        Type type() const;

        /// Returns the key of the object entry, if it is one.
        /// If this is not an entry in an object, returns an empty optional.
        /// @return The key of the object entry
        std::optional<std::string> getKey() const;

        std::vector<Value>::iterator begin();
        std::vector<Value>::iterator end();

        std::vector<Value>::const_iterator begin() const;
        std::vector<Value>::const_iterator end() const;

        bool isNull() const {
            return this->type() == Type::Null;
        }

        bool isString() const {
            return this->type() == Type::String;
        }

        bool isNumber() const {
            return this->type() == Type::Number;
        }

        bool isBool() const {
            return this->type() == Type::Bool;
        }

        bool isArray() const {
            return this->type() == Type::Array;
        }

        bool isObject() const {
            return this->type() == Type::Object;
        }

        /// Returns the number as a boolean, if this is a boolean.
        /// If this is not a boolean, returns an error.
        geode::Result<bool> asBool() const;

        /// Returns the number as a string, if this is a string.
        /// If this is not a string, returns an error.
        geode::Result<std::string> asString() const;

        /// Returns the number as a signed integer, if this is a number.
        /// If this is not a number, returns an error.
        geode::Result<std::intmax_t> asInt() const;

        /// Returns the number as an unsigned integer, if this is a number.
        /// If this is not a number, returns an error.
        geode::Result<std::uintmax_t> asUInt() const;

        /// Returns the number as a double, if this is a number.
        /// If this is not a number, returns an error.
        geode::Result<double> asDouble() const;

        /// Returns a reference to the array, if this is an array.
        /// If this is not an array, returns an error.
        geode::Result<std::vector<Value>&> asArray() &;

        /// Returns the array, if this is an array.
        /// If this is not an array, returns an error.
        geode::Result<std::vector<Value>> asArray() &&;

        /// Returns a reference to the array, if this is an array.
        /// If this is not an array, returns an error.
        geode::Result<std::vector<Value> const&> asArray() const&;

        /// Converts the JSON value to a given type, possibly serializing to
        /// a custom type via the Serialize specialization
        /// @tparam T The type to convert to
        /// @return The converted value or an error
        template <class T>
        decltype(auto) as() const {
            if constexpr (std::is_same_v<T, bool>) {
                return this->asBool();
            }
            else if constexpr (std::is_integral_v<T>) {
                if constexpr (std::is_signed_v<T>) {
                    return this->asInt().map([](std::intmax_t v) -> T {
                        return static_cast<T>(v);
                    });
                }
                else {
                    return this->asUInt().map([](std::uintmax_t v) -> T {
                        return static_cast<T>(v);
                    });
                }
            }
            else if constexpr (std::is_floating_point_v<T>) {
                return this->asDouble().map([](double v) -> T {
                    return static_cast<T>(v);
                });
            }
            else if constexpr (CanDeserialize<T>) {
                return Serialize<std::remove_cvref_t<T>>::fromJson(*this);
            }
            else if constexpr (std::is_constructible_v<std::string, T>) {
                return this->asString();
            }
            else if constexpr (std::is_same_v<std::remove_cvref_t<T>, Value>) {
                return geode::Result<Value>(geode::Ok(*this));
            }
            else if constexpr (std::is_same_v<std::remove_cvref_t<T>, std::vector<Value>>) {
                return this->asArray();
            }
            else {
                static_assert(!std::is_same_v<T, T>, "no conversion found from matjson::Value to T");
            }
        }

        /// Gets the value from a key/index, and converts it to T
        /// @tparam T The type to convert to
        /// @param keyOrIndex The key or index to get the value from
        /// @return The converted value or an error
        /// @note Shorthand for get(key).as<T>()
        template <class T, class Key>
        decltype(auto) get(Key&& keyOrIndex) {
            return this->get(std::forward<Key>(keyOrIndex)).andThen([](Value& value) {
                return value.as<T>();
            });
        }

        /// Gets the value from a key/index, and converts it to T
        /// @tparam T The type to convert to
        /// @param keyOrIndex The key or index to get the value from
        /// @return The converted value or an error
        /// @note Shorthand for get(key).as<T>()
        template <class T, class Key>
        decltype(auto) get(Key&& keyOrIndex) const {
            return this->get(std::forward<Key>(keyOrIndex)).andThen([](Value const& value) {
                return value.as<T>();
            });
        }
    };

    /// Parses JSON from a string
    /// @param source The JSON string to parse
    /// @return The parsed JSON value or an error
    /// @note Shorthand for Value::parse
    inline geode::Result<Value, ParseError> parse(std::string_view source) {
        return Value::parse(source);
    }

    /// Parses JSON from an input stream
    /// @param source Stream to parse
    /// @return The parsed JSON value or an error
    /// @note Shorthand for Value::parse
    inline geode::Result<Value, ParseError> parse(std::istream& stream) {
        return Value::parse(stream);
    }

    /// Parses JSON from a string and tries to convert it to a given type
    /// @tparam T The type to convert to
    /// @param source The JSON string to parse
    /// @return The parsed struct or an error
    /// @note Shorthand for Value::parse(...).as<T>()
    template <class T>
    inline geode::Result<T> parseAs(std::string_view source) {
        GEODE_UNWRAP_INTO(auto parsed, Value::parse(source));
        return parsed.as<T>();
    }

    /// Parses JSON from an input stream and tries to convert it to a given type
    /// @tparam T The type to convert to
    /// @param source Stream to parse
    /// @return The parsed struct or an error
    /// @note Shorthand for Value::parse(...).as<T>()
    template <class T>
    inline geode::Result<T> parseAs(std::istream& stream) {
        GEODE_UNWRAP_INTO(auto parsed, Value::parse(stream));
        return parsed.as<T>();
    }

    // This is used internally by C++ when destructuring the value, useful for range for loops:
    // > for (auto const& [key, value] : object) { ... }
    template <std::size_t Index, class T>
        requires requires { std::is_same_v<std::decay_t<T>, Value>; }
    decltype(auto) get(T&& value) {
        if constexpr (Index == 0) {
            auto const opt = value.getKey();
            if (!opt) return std::string();
            return std::string(*opt);
        }
        else if constexpr (Index == 1) {
            return std::forward<T>(value);
        }
    }

    inline Value makeObject(std::initializer_list<std::pair<std::string, Value>> entries) {
        std::vector<Value> arr;
        for (auto const& [key, value] : entries) {
            arr.emplace_back(value).setKey_(key);
        }
        return Value(std::move(arr), true);
    }

    // For fmtlib, lol
    inline std::string format_as(matjson::Value const& value) {
        return value.dump(matjson::NO_INDENTATION);
    }

    inline std::string format_as(matjson::ParseError const& value) {
        return std::string(value);
    }
}

// allow destructuring
template <>
struct std::tuple_size<matjson::Value> : std::integral_constant<std::size_t, 2> {};

template <>
struct std::tuple_element<0, matjson::Value> {
    using type = std::string;
};

template <>
struct std::tuple_element<1, matjson::Value> {
    using type = matjson::Value;
};
