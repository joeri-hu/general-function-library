#ifndef GL_TS_TRAITS_RELATIONAL_RELATIONSHIPS_H
#define GL_TS_TRAITS_RELATIONAL_RELATIONSHIPS_H

#include <type_traits>

namespace ts {
//////////////////////// identity >>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename T, typename... Ts>
struct is_same_all
    : std::conjunction<std::is_same<T, Ts>...> {};

template<typename T, typename... Ts>
struct is_same_either
    : std::disjunction<
        is_same_either<Ts...>,
        std::is_same<T, Ts>...> {};

template<typename T1, typename T2>
struct is_same_either<T1, T2>
    : std::is_same<T1, T2> {};

template<typename... Ts>
struct is_same_neither
    : std::negation<is_same_either<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename T, typename... Ts>
inline constexpr auto is_same_all_v
    = bool{is_same_all<T, Ts...>{}};

template<typename... Ts>
inline constexpr auto is_same_either_v
    = bool{is_same_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_same_neither_v
    = bool{is_same_neither<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// identity <<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// conversion >>>>>>>>>>>>>>>>>>>>>>>>
namespace impl {

template<typename T, typename... Ts>
struct common_type_matches
    : std::is_same<T, std::common_type_t<Ts...>> {};

template<typename T, typename... Ts>
inline constexpr auto common_type_matches_v
    = bool{common_type_matches<T, Ts...>{}};

} // namespace impl

template<typename... Ts>
struct common_type_matches_all
    : std::conjunction<impl::common_type_matches<Ts, Ts...>...> {};

template<typename T1, typename T2>
struct common_type_matches_both
    : common_type_matches_all<T1, T2> {};

template<typename... Ts>
struct common_type_matches_either
    : std::disjunction<impl::common_type_matches<Ts, Ts...>...> {};

template<typename... Ts>
struct common_type_matches_neither
    : std::negation<common_type_matches_either<Ts...>> {};

template<typename T1, typename T2>
struct common_type_matches_lhs
    : impl::common_type_matches<T1, T1, T2> {};

template<typename T1, typename T2>
struct common_type_matches_rhs
    : impl::common_type_matches<T2, T1, T2> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>>>>

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

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// conversion <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
