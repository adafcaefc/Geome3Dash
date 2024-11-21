#pragma once

#include "external/reflect"

#include <matjson.hpp>

template <class T>
    requires(std::is_aggregate_v<T> && !std::is_array_v<T>)
struct matjson::Serialize<T> {
    static geode::Result<T> fromJson(matjson::Value const& json) {
        T value;
        std::optional<std::string> error;
        reflect::for_each<T>([&](auto N) {
            if (error) return;
            auto& field = reflect::get<N>(value);
            static constexpr auto fieldName = reflect::member_name<N>(value);

            if (!json.contains(fieldName)) {
                error = "field `" + std::string(fieldName) + "` is missing";
                return;
            }
            auto result = json[fieldName].template as<std::remove_cvref_t<decltype(field)>>();
            if (!result) {
                using ErrType = std::remove_cvref_t<decltype(result.unwrapErr())>;
                if constexpr (requires(std::string s, ErrType e) { s + e; }) {
                    // clang-format off
                    error = "failed to convert field `" + std::string(fieldName) + "`: " + result.unwrapErr();
                    // clang-format on
                }
                else {
                    error = "failed to convert field `" + std::string(fieldName) + "`";
                }
                return;
            }
            field = std::move(result).unwrap();
        });
        if (error) return geode::Err(*error);
        return geode::Ok(value);
    }

    static matjson::Value toJson(T const& value) {
        matjson::Value json;
        reflect::for_each<T>([&](auto N) {
            auto const& field = reflect::get<N>(value);
            json[reflect::member_name<N>(value)] = matjson::Value(field);
        });
        return json;
    }
};
