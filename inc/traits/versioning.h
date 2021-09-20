#ifndef GL_TS_TRAITS_VERSIONING_H
#define GL_TS_TRAITS_VERSIONING_H

#include <type_traits>

namespace ts {

enum class std_version {
    unknown,
    cpp11 = 201103L,
    cpp14 = 201402L,
    cpp17 = 201703L,
    cpp20 = 202002L,
    current = __cplusplus + unknown
};

template<std_version V>
struct std_matches : std::integral_constant<bool,
    V != std_version::unknown and
    V == std_version::current> {};

//////////////////////// helpers >>>>>>>>>>>>>>>>>>>>>>>>

using is_cpp11_compliant = std_matches<std_version::cpp11>;
using is_cpp14_compliant = std_matches<std_version::cpp14>;
using is_cpp17_compliant = std_matches<std_version::cpp17>;
using is_cpp20_compliant = std_matches<std_version::cpp20>;

constexpr auto is_cpp11_compliant_v() noexcept -> bool
{ return is_cpp11_compliant{}; }

constexpr auto is_cpp14_compliant_v() noexcept -> bool
{ return is_cpp14_compliant{}; }

constexpr auto is_cpp17_compliant_v() noexcept -> bool
{ return is_cpp17_compliant{}; }

constexpr auto is_cpp20_compliant_v() noexcept -> bool
{ return is_cpp20_compliant{}; }

//////////////////////// helpers <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
