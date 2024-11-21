#pragma once

#include <algorithm>
#include <map>
#include <matjson.hpp>
#include <memory>
#include <optional>
#include <set>
#include <span>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace matjson {
    // allow converting parsing JSON directly to STL containers for convenience

    template <class T>
    struct Serialize<std::optional<T>> {
        static geode::Result<std::optional<T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<T>(); }
        {
            if (!value.isNull()) {
                return value.template as<T>().map([](T&& v) -> std::optional<T> {
                    return std::move(v);
                });
            }
            return geode::Ok(std::nullopt);
        }

        static Value toJson(std::optional<T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            if (value.has_value()) {
                return Value(value.value());
            }
            return Value(nullptr);
        }
    };

    template <class T>
    struct Serialize<std::vector<T>> {
        static geode::Result<std::vector<T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<T>(); }
        {
            if (!value.isArray()) return geode::Err("not an array");
            std::vector<T> res;
            res.reserve(value.size());
            for (auto const& entry : value) {
                GEODE_UNWRAP_INTO(auto vv, entry.template as<T>());
                res.emplace_back(std::move(vv));
            }
            return geode::Ok(res);
        }

        static Value toJson(std::vector<T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            std::vector<Value> res;
            res.reserve(value.size());
            std::transform(value.begin(), value.end(), std::back_inserter(res), [](T const& value) -> Value {
                return Value(value);
            });
            return res;
        }
    };

    template <class T>
    struct Serialize<std::span<T>> {
        static Value toJson(std::span<T const> value)
            requires requires(T const& value) { Value(value); }
        {
            std::vector<Value> res;
            res.reserve(value.size());
            std::transform(value.begin(), value.end(), std::back_inserter(res), [](T const& value) -> Value {
                return Value(value);
            });
            return res;
        }
    };

    template <class T>
    struct Serialize<std::unordered_set<T>> {
        static geode::Result<std::unordered_set<T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<std::decay_t<T>>(); }
        {
            if (!value.isArray()) return geode::Err("not an array");
            std::unordered_set<T> res;
            res.reserve(value.size());
            for (auto const& entry : value) {
                GEODE_UNWRAP_INTO(auto vv, entry.template as<T>());
                res.insert(std::move(vv));
            }
            return geode::Ok(res);
        }

        static Value toJson(std::unordered_set<T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            std::vector<Value> res;
            res.reserve(value.size());
            std::transform(value.begin(), value.end(), std::back_inserter(res), [](T const& value) -> Value {
                return Value(value);
            });
            return res;
        }
    };

    template <class T>
    struct Serialize<std::set<T>> {
        static geode::Result<std::set<T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<std::decay_t<T>>(); }
        {
            if (!value.isArray()) return geode::Err("not an array");
            std::set<T> res;
            for (auto const& entry : value) {
                GEODE_UNWRAP_INTO(auto vv, entry.template as<T>());
                res.insert(std::move(vv));
            }
            return geode::Ok(res);
        }

        static Value toJson(std::set<T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            std::vector<Value> res;
            res.reserve(value.size());
            std::transform(value.begin(), value.end(), std::back_inserter(res), [](T const& value) -> Value {
                return Value(value);
            });
            return res;
        }
    };

    template <class T>
    struct Serialize<std::map<std::string, T>> {
        static geode::Result<std::map<std::string, T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<std::decay_t<T>>(); }
        {
            if (!value.isObject()) return geode::Err("not an object");
            std::map<std::string, T> res;
            for (auto const& [k, v] : value) {
                GEODE_UNWRAP_INTO(auto vv, v.template as<std::decay_t<T>>());
                res.insert({k, vv});
            }
            return geode::Ok(res);
        }

        static Value toJson(std::map<std::string, T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            Value res;
            for (auto const& [k, v] : value) {
                res.set(k, Value(v));
            }
            return res;
        }
    };

    template <class T>
    struct Serialize<std::unordered_map<std::string, T>> {
        static geode::Result<std::unordered_map<std::string, T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<std::decay_t<T>>(); }
        {
            if (!value.isObject()) return geode::Err("not an object");
            std::unordered_map<std::string, T> res;
            for (auto const& [k, v] : value) {
                GEODE_UNWRAP_INTO(auto vv, v.template as<std::decay_t<T>>());
                res.insert({k, vv});
            }
            return geode::Ok(res);
        }

        static Value toJson(std::unordered_map<std::string, T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            Value res;
            for (auto const& [k, v] : value) {
                res.set(k, Value(v));
            }
            return res;
        }
    };

    template <class T>
    struct Serialize<std::shared_ptr<T>> {
        static geode::Result<std::shared_ptr<T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<T>(); }
        {
            if (!value.isNull()) {
                return value.template as<T>().map([](T&& v) {
                    return std::make_shared<T>(std::move(v));
                });
            }
            return geode::Ok(nullptr);
        }

        static Value toJson(std::shared_ptr<T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            if (value) {
                return Value(*value.get());
            }
            return Value(nullptr);
        }
    };

    template <class T>
    struct Serialize<std::unique_ptr<T>> {
        static geode::Result<std::unique_ptr<T>> fromJson(Value const& value)
            requires requires(Value const& value) { value.template as<T>(); }
        {
            if (!value.isNull()) {
                return value.template as<T>().map([](T&& v) {
                    return std::make_unique<T>(std::move(v));
                });
            }
            return geode::Ok(nullptr);
        }

        static Value toJson(std::unique_ptr<T> const& value)
            requires requires(T const& value) { Value(value); }
        {
            if (value) {
                return Value(*value.get());
            }
            return Value(nullptr);
        }
    };
}
