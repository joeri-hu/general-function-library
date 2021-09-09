#ifndef GL_TS_TRAITS_PROPERTIES_CONVERSIONS_H
#define GL_TS_TRAITS_PROPERTIES_CONVERSIONS_H

#include <traits/transformations.h>
#include <traits/properties/ranking.h>

#include <limits>
#include <type_traits>

namespace ts {

//////////////////////// conversions >>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_converting_all
    : common_type_matches_neither<Ts...> {};

template<typename T1, typename T2>
struct is_converting_both
    : is_converting_all<T1, T2> {};

template<typename... Ts>
struct is_converting_either
    : std::negation<common_type_matches_all<Ts...>> {};

template<typename... Ts>
struct is_converting_neither
    : std::negation<is_converting_either<Ts...>> {};

template<typename T1, typename T2>
struct is_converting_lhs
    : std::negation<common_type_matches_lhs<T1, T2>> {};

template<typename T1, typename T2>
struct is_converting_rhs
    : std::negation<common_type_matches_rhs<T1, T2>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_converting_all_v
    = bool{is_converting_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_converting_both_v
    = bool{is_converting_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_converting_either_v
    = bool{is_converting_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_converting_neither_v
    = bool{is_converting_neither<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_converting_lhs_v
    = bool{is_converting_lhs<T1, T2>{}};

template<typename T1, typename T2>
inline constexpr auto is_converting_rhs_v
    = bool{is_converting_rhs<T1, T2>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// limits >>>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To>
struct is_narrowing : std::bool_constant<
    (std::numeric_limits<From>::max() > std::numeric_limits<To>::max())> {};

template<typename From, typename To>
inline constexpr auto is_narrowing_v = bool{is_narrowing<From, To>{}};

//////////////////////// limits <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// conversions <<<<<<<<<<<<<<<<<<<<<<<<

//////////////////////// promotions >>>>>>>>>>>>>>>>>>>>>>>>>

template<typename T>
struct is_promotable
    : std::negation<std::is_same<T, promote<T>>> {};

template<typename... Ts>
struct is_promotable_all
    : std::conjunction<is_promotable<Ts>...> {};

template<typename T1, typename T2>
struct is_promotable_both
    : is_promotable_all<T1, T2> {};

template<typename... Ts>
struct is_promotable_either
    : std::disjunction<is_promotable<Ts>...> {};

template<typename... Ts>
struct is_promotable_neither
    : std::negation<is_promotable_either<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>

template<typename T>
inline constexpr auto is_promotable_v
    = bool{is_promotable<T>{}};

template<typename... Ts>
inline constexpr auto is_promotable_all_v
    = bool{is_promotable_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_promotable_both_v
    = bool{is_promotable_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_promotable_either_v
    = bool{is_promotable_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_promotable_neither_v
    = bool{is_promotable_neither<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// promotions <<<<<<<<<<<<<<<<<<<<<<<<

} // namespace ts

#endif
