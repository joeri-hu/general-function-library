#ifndef GL_TRAITS_CONSTRAINTS_H
#define GL_TRAITS_CONSTRAINTS_H

#include <type_traits>

inline namespace gl {
namespace ts {

template<typename T>
using require = std::enable_if_t<T{}>;

template<typename T>
using require_not = require<std::negation<T>>;

template<typename... Ts>
using require_all = require<std::conjunction<Ts...>>;

template<typename T1, typename T2>
using require_both = require_all<T1, T2>;

template<typename... Ts>
using require_either = require<std::disjunction<Ts...>>;

template<typename... Ts>
using require_neither = require_not<std::disjunction<Ts...>>;

} // namespace ts
} // namespace gl

#endif
