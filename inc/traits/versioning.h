#ifndef GFL_TRAITS_VERSIONING_H
#define GFL_TRAITS_VERSIONING_H

#include <type_traits>

inline namespace gfl {
namespace ts {

struct version {
    static constexpr auto cpp11 = 201103L;
    static constexpr auto cpp14 = 201402L;
    static constexpr auto cpp17 = 201703L;
    static constexpr auto cpp20 = 202002L;
    static constexpr auto current = __cplusplus + 0;

    template<decltype(current) V>
    using matches = std::integral_constant<bool, V == current>;
};

using is_cpp11_compliant = version::matches<version::cpp11>;
using is_cpp14_compliant = version::matches<version::cpp14>;
using is_cpp17_compliant = version::matches<version::cpp17>;
using is_cpp20_compliant = version::matches<version::cpp20>;

inline namespace helpers {

#if defined(__cplusplus) and (__cplusplus >= 201703L)
    inline constexpr auto is_cpp11_compliant_v = bool{is_cpp11_compliant{}};
    inline constexpr auto is_cpp14_compliant_v = bool{is_cpp14_compliant{}};
    inline constexpr auto is_cpp17_compliant_v = bool{is_cpp17_compliant{}};
    inline constexpr auto is_cpp20_compliant_v = bool{is_cpp20_compliant{}};
#else
    constexpr auto is_cpp11_compliant_v() noexcept -> bool
    { return is_cpp11_compliant{}; };

    constexpr auto is_cpp14_compliant_v() noexcept -> bool
    { return is_cpp14_compliant{}; };

    constexpr auto is_cpp17_compliant_v() noexcept -> bool
    { return is_cpp17_compliant{}; };

    constexpr auto is_cpp20_compliant_v() noexcept -> bool
    { return is_cpp20_compliant{}; };
#endif

} // namespace helpers
} // namespace ts
} // namespace gfl

#endif
