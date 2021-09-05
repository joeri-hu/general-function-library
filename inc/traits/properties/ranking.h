#ifndef GL_TRAITS_PROPERTIES_RANKING_H
#define GL_TRAITS_PROPERTIES_RANKING_H

#include <type_traits>

inline namespace gl {
namespace ts {
namespace internal {

template<typename T, typename... Ts>
using common_type_matches = std::is_same<T, std::common_type_t<Ts...>>;

template<typename T, typename... Ts>
inline constexpr auto common_type_matches_v = bool{common_type_matches<T, Ts...>{}};

} // namespace internal

template<typename... Ts>
using common_type_matches_all
    = std::conjunction<internal::common_type_matches<Ts, Ts...>...>;

template<typename T1, typename T2>
using common_type_matches_both = common_type_matches_all<T1, T2>;

template<typename... Ts>
using common_type_matches_either
    = std::disjunction<internal::common_type_matches<Ts, Ts...>...>;

template<typename... Ts>
using common_type_matches_neither = std::negation<common_type_matches_either<Ts...>>;

template<typename T1, typename T2>
using common_type_matches_lhs = internal::common_type_matches<T1, T1, T2>;

template<typename T1, typename T2>
using common_type_matches_rhs = internal::common_type_matches<T2, T1, T2>;

inline namespace helpers {

template<typename... Ts>
inline constexpr auto common_type_matches_all_v
    = bool{common_type_matches_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto common_type_matches_both_v
    = bool{common_type_matches_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto common_type_matches_either_v
    = bool{common_type_matches_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto common_type_matches_neither_v
    = bool{common_type_matches_neither<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto common_type_matches_lhs_v
    = bool{common_type_matches_lhs<T1, T2>{}};

template<typename T1, typename T2>
inline constexpr auto common_type_matches_rhs_v
    = bool{common_type_matches_rhs<T1, T2>{}};

} // namespace helpers
} // namespace ts
} // namespace gl

#endif
