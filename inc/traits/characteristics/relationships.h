#ifndef GL_TS_TRAITS_CHARACTERISTICS_RELATIONSHIPS_H
#define GL_TS_TRAITS_CHARACTERISTICS_RELATIONSHIPS_H

#include <type_traits>

namespace ts {

template<typename T, typename... Ts>
struct is_same_all
    : std::conjunction<std::is_same<T, Ts>...> {};

template<typename T, typename... Ts>
struct is_same_any
    : std::disjunction<is_same_any<Ts...>, std::is_same<T, Ts>...> {};

template<typename T1, typename T2>
struct is_same_any<T1, T2>
    : std::is_same<T1, T2> {};

template<typename... Ts>
struct is_same_none
    : std::negation<is_same_any<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>

template<typename T, typename... Ts>
inline constexpr auto is_same_all_v = bool{is_same_all<T, Ts...>{}};

template<typename... Ts>
inline constexpr auto is_same_any_v = bool{is_same_any<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_same_none_v = bool{is_same_none<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<

} // namespace ts

#endif
