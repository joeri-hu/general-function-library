#ifndef GL_TRAITS_VERSIONING_H
#define GL_TRAITS_VERSIONING_H

#include <type_traits>

inline namespace gl {
namespace ts {

enum class std_version {
    unknown,
    cpp11 = 201103L,
    cpp14 = 201402L,
    cpp17 = 201703L,
    cpp20 = 202002L,
    current = __cplusplus + unknown
};

template<version V>
using std_matches = std::integral_constant<bool,
    V != version::unknown and V == version::current>;

inline namespace helpers {

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

} // namespace helpers
} // namespace ts
} // namespace gl

#endif
