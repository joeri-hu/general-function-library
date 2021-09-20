#ifndef GL_TS_TRAITS_CATEGORIES_H
#define GL_TS_TRAITS_CATEGORIES_H

#include <type_traits>

namespace ts {
//////////////////////// fundamental . >>>>>>>>>>>>>>>>>>>>>>>>
//////////////////////// .. arithmetic >>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_arithmetic_all
    : std::conjunction<std::is_arithmetic<Ts>...> {};

template<typename T1, typename T2>
struct is_arithmetic_both
    : is_arithmetic_all<T1, T2> {};

template<typename... Ts>
struct is_arithmetic_either
    : std::disjunction<std::is_arithmetic<Ts>...> {};

template<typename... Ts>
struct is_arithmetic_neither
    : std::negation<is_arithmetic_either<Ts>...> {};

//////////////////////// ..... helpers >>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_arithmetic_all_v
    = bool{is_arithmetic_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_arithmetic_both_v
    = bool{is_arithmetic_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_arithmetic_either_v
    = bool{is_arithmetic_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_arithmetic_neither_v
    = bool{is_arithmetic_neither<Ts...>{}};

//////////////////////// ..... helpers <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// .. arithmetic <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// .. integral . >>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_integral_all
    : std::conjunction<std::is_integral<Ts>...> {};

template<typename T1, typename T2>
struct is_integral_both
    : is_integral_all<T1, T2> {};

template<typename... Ts>
struct is_integral_either
    : std::disjunction<std::is_integral<Ts>...> {};

template<typename... Ts>
struct is_integral_neither
    : std::negation<is_integral_either<Ts>...> {};

//////////////////////// ..... helpers >>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_integral_all_v
    = bool{is_integral_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_integral_both_v
    = bool{is_integral_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_integral_either_v
    = bool{is_integral_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_integral_neither_v
    = bool{is_integral_neither<Ts...>{}};

//////////////////////// ..... helpers <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// .. integral . <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// fundamental . <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// templates ... >>>>>>>>>>>>>>>>>>>>>>>>

template<template<typename...> typename, typename...>
struct is_template_of : std::false_type {};

template<template<typename...> typename T, typename... Ts>
struct is_template_of<T, T<Ts...>> : std::true_type {};

template<
    template<typename...> typename T1,
    template<typename...> typename T2, typename... Ts>
struct is_template_of<T1, T2<Ts...>>
    : std::is_same<T1<Ts...>, T2<Ts...>> {};

template<template<typename...> typename, template<typename...> typename>
struct template_matches : std::false_type {};

template<template<typename...> typename T>
struct template_matches<T, T> : std::true_type {};

//////////////////////// .. helpers .. >>>>>>>>>>>>>>>>>>>>>>>>

template<template<typename...> typename T, typename S>
inline constexpr auto is_template_of_v
    = bool{is_template_of<T, S>{}};

template<template<typename...> typename... Ts>
inline constexpr auto template_matches_v
    = bool{template_matches<Ts...>{}};

//////////////////////// .. helpers .. <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// templates ... <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
