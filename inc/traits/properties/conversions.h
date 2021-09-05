#ifndef GL_TRAITS_PROPERTIES_CONVERSIONS_H
#define GL_TRAITS_PROPERTIES_CONVERSIONS_H

#include <traits/transformations.h>
#include <traits/properties/ranking.h>

#include <limits>
#include <type_traits>

inline namespace gl {
namespace ts {
inline namespace conversions {

template<typename... Ts>
using is_converting_all = common_type_matches_neither<Ts...>;

template<typename T1, typename T2>
using is_converting_both = is_converting_all<T1, T2>;

template<typename... Ts>
using is_converting_either = std::negation<common_type_matches_all<Ts...>>;

template<typename... Ts>
using is_converting_neither = std::negation<is_converting_either<Ts...>>;

template<typename T1, typename T2>
using is_converting_lhs = std::negation<common_type_matches_lhs<T1, T2>>;

template<typename T1, typename T2>
using is_converting_rhs = std::negation<common_type_matches_rhs<T1, T2>>;

inline namespace helpers {

template<typename... Ts>
inline constexpr auto is_converting_all_v = bool{is_converting_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_converting_both_v = bool{is_converting_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_converting_either_v = bool{is_converting_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_converting_neither_v = bool{is_converting_neither<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_converting_lhs_v = bool{is_converting_lhs<T1, T2>{}};

template<typename T1, typename T2>
inline constexpr auto is_converting_rhs_v = bool{is_converting_rhs<T1, T2>{}};

} // namespace helpers
inline namespace limits {

template<typename From, typename To>
using is_narrowing = std::bool_constant<
    (std::numeric_limits<From>::max() > std::numeric_limits<To>::max())>;

template<typename From, typename To>
inline constexpr auto is_narrowing_v = bool{is_narrowing<From, To>{}};

} // namespace limits
} // namespace conversions
inline namespace promotions {

template<typename T>
using is_promotable = std::negation<std::is_same<T, promote<T>>>;

template<typename... Ts>
using is_promotable_all = std::conjunction<is_promotable<Ts>...>;

template<typename T1, typename T2>
using is_promotable_both = is_promotable_all<T1, T2>;

template<typename... Ts>
using is_promotable_either = std::disjunction<is_promotable<Ts>...>;

template<typename... Ts>
using is_promotable_neither = std::negation<is_promotable_either<Ts...>>;

inline namespace helpers {

template<typename T>
inline constexpr auto is_promotable_v = bool{is_promotable<T>{}};

template<typename... Ts>
inline constexpr auto is_promotable_all_v = bool{is_promotable_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_promotable_both_v = bool{is_promotable_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_promotable_either_v = bool{is_promotable_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_promotable_neither_v = bool{is_promotable_neither<Ts...>{}};

} // namespace helpers
} // namespace promotions
} // namespace ts
} // namespace gl

#endif
