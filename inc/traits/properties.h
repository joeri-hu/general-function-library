#ifndef GL_TS_TRAITS_PROPERTIES_H
#define GL_TS_TRAITS_PROPERTIES_H

#include <type_traits>

namespace ts {
//////////////////////// specifiers >>>>>>>>>>>>>>>>>>>>>>>>
//////////////////////// signed >>>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_signed_all
    : std::conjunction<std::is_signed<Ts>...> {};

template<typename T1, typename T2>
struct is_signed_both
    : is_signed_all<T1, T2> {};

template<typename... Ts>
struct is_signed_either
    : std::disjunction<std::is_signed<Ts>...> {};

template<typename... Ts>
struct is_signed_neither
    : std::negation<is_signed_either<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_signed_all_v
    = bool{is_signed_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_signed_both_v
    = bool{is_signed_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_signed_either_v
    = bool{is_signed_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_signed_neither_v
    = bool{is_signed_neither<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// signed <<<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// unsigned >>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_unsigned_all
    : std::conjunction<std::is_unsigned<Ts>...> {};

template<typename T1, typename T2>
struct is_unsigned_both
    : is_unsigned_all<T1, T2> {};

template<typename... Ts>
struct is_unsigned_either
    : std::disjunction<std::is_unsigned<Ts>...> {};

template<typename... Ts>
struct is_unsigned_neither
    : std::negation<is_unsigned_either<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_unsigned_all_v
    = bool{is_unsigned_all<Ts...>{}};

template<typename T1, typename T2>
inline constexpr auto is_unsigned_both_v
    = bool{is_unsigned_both<T1, T2>{}};

template<typename... Ts>
inline constexpr auto is_unsigned_either_v
    = bool{is_unsigned_either<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_unsigned_neither_v
    = bool{is_unsigned_neither<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// unsigned <<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// specifiers <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
