#ifndef GFL_TRAITS_CATEGORIES_H
#define GFL_TRAITS_CATEGORIES_H

#include <type_traits>

inline namespace gfl {
namespace ts {
inline namespace fundamental {

template<typename... Ts>
using is_arithmetic_all = std::conjunction<std::is_arithmetic<Ts>...>;

template<typename... Ts>
inline constexpr auto is_arithmetic_all_v = bool{is_arithmetic_all<Ts...>{}};

} // namespace fundamental
inline namespace templates {

template<template<typename...> typename, typename...>
struct is_template_of : std::false_type {};

template<template<typename...> typename T, typename... Ts>
struct is_template_of<T, T<Ts...>> : std::true_type {};

template<template<typename...> typename, template<typename...> typename>
struct template_matches : std::false_type {};

template<template<typename...> typename T>
struct template_matches<T, T> : std::true_type {};

inline namespace helpers {

template<template<typename...> typename T, typename S>
inline constexpr auto is_template_of_v = bool{is_template_of<T, S>{}};

template<template<typename...> typename... Ts>
inline constexpr auto template_matches_v = bool{template_matches<Ts...>{}};

} // namespace helpers
} // namespace templates
} // namespace ts
} // namespace gfl

#endif
