#ifndef GL_TRAITS_VERSIONING_H
#define GL_TRAITS_VERSIONING_H

#include <type_traits>

inline namespace gl {
namespace ts {
namespace version {
namespace internal {

template<long N>
struct id {
    static constexpr auto value = N;

    using is_current = std::integral_constant<bool,
        N != 0 and N == __cplusplus + 0>;
};

} // namespace internal

struct cpp11 : internal::id<201103L> {};
struct cpp14 : internal::id<201402L> {};
struct cpp17 : internal::id<201703L> {};
struct cpp20 : internal::id<202002L> {};

} // namespace version
inline namespace helpers {

using is_cpp11_compliant = version::cpp11::is_current;
using is_cpp14_compliant = version::cpp14::is_current;
using is_cpp17_compliant = version::cpp17::is_current;
using is_cpp20_compliant = version::cpp20::is_current;

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
