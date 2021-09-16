#ifndef GL_TS_TRAITS_CHARACTERISTICS_PROPERTIES_H
#define GL_TS_TRAITS_CHARACTERISTICS_PROPERTIES_H

#include <type_traits>

namespace ts {

//////////////////////// specifiers >>>>>>>>>>>>>>>>>>>>>>>>
//////////////////////// signed >>>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_signed_all
    : std::conjunction<std::is_signed<Ts>...> {};

template<typename... Ts>
struct is_signed_any
    : std::disjunction<std::is_signed<Ts>...> {};

template<typename... Ts>
struct is_signed_none
    : std::negation<is_signed_any<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_signed_all_v = bool{is_signed_all<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_signed_any_v = bool{is_signed_any<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_signed_none_v = bool{is_signed_none<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// signed <<<<<<<<<<<<<<<<<<<<<<<<<<<<

//////////////////////// unsigned >>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
struct is_unsigned_all
    : std::conjunction<std::is_unsigned<Ts>...> {};

template<typename... Ts>
struct is_unsigned_any
    : std::disjunction<std::is_unsigned<Ts>...> {};

template<typename... Ts>
struct is_unsigned_none
    : std::negation<is_unsigned_any<Ts...>> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename... Ts>
inline constexpr auto is_unsigned_all_v = bool{is_unsigned_all<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_unsigned_any_v = bool{is_unsigned_any<Ts...>{}};

template<typename... Ts>
inline constexpr auto is_unsigned_none_v = bool{is_unsigned_none<Ts...>{}};

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// unsigned <<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// specifiers <<<<<<<<<<<<<<<<<<<<<<<<

} // namespace ts

#endif
