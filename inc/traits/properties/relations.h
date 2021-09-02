#ifndef GFL_TRAITS_PROPERTIES_RELATIONS_H
#define GFL_TRAITS_PROPERTIES_RELATIONS_H

#include <type_traits>

inline namespace gfl {
namespace ts {

template<typename T, typename... Ts>
using is_same_all = std::conjunction<std::is_same<T, Ts>...>;

template<typename...>
struct is_same_any;

template<typename T1, typename T2>
struct is_same_any<T1, T2> : std::is_same<T1, T2> {};

template<typename T, typename... Ts>
struct is_same_any<T, Ts...>
    : std::disjunction<is_same_any<Ts...>, std::is_same<T, Ts>...> {};

template<typename... Ts>
using is_same_none = std::negation<is_same_any<Ts...>>;

inline namespace helpers {

template<typename T, typename... Ts>
inline constexpr auto is_same_all_v = bool{is_same_all<T, Ts...>{}};

template<typename... Ts>
inline constexpr auto is_same_any_v = bool{is_same_any<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_same_none_v = bool{is_same_none<Ts...>{}};

} // namespace helpers
} // namespace ts
} // namespace gfl

#endif
