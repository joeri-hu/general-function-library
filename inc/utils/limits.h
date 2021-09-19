#ifndef GL_UTILS_LIMITS_H
#define GL_UTILS_LIMITS_H

#include <traits/categories.h>
#include <traits/constraints.h>
#include <traits/properties.h>

#include <type_traits>

namespace gl {

template<typename From, typename To,
    typename = ts::require<ts::is_integral_both<From, To>>>
constexpr auto conversion_truncates(From src) noexcept -> bool;

template<typename From, typename To>
constexpr auto is_out_of_range(From src) noexcept -> bool;

namespace internal {
//////////////////////// integral >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To,
    ts::require_t<ts::is_integral_both<From, To>> = 0,
    ts::require_either_t<
        ts::is_signed_both<From, To>,
        ts::is_unsigned_both<From, To>> = 0>
constexpr auto is_out_of_range(From src) noexcept -> bool;

template<typename From, typename To,
    ts::require_t<std::is_unsigned<From>> = 0,
    ts::require_t<std::is_signed<To>> = 0,
    ts::require_t<std::is_integral<To>> = 0>
constexpr auto is_out_of_range(From src) noexcept -> bool;

template<typename From, typename To,
    ts::require_t<std::is_integral<From>> = 0,
    ts::require_t<std::is_signed<From>> = 0,
    ts::require_t<std::is_unsigned<To>> = 0>
constexpr auto is_out_of_range(From src) noexcept -> bool;

//////////////////////// integral <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// floating point >>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To,
    ts::require_t<std::is_floating_point<From>> = 0,
    ts::require_t<std::is_arithmetic<To>> = 0>
constexpr auto is_out_of_range(From src) noexcept -> bool;

template<typename From, typename To,
    ts::require_t<std::is_integral<From>> = 0,
    ts::require_t<std::is_floating_point<To>> = 0>
constexpr auto is_out_of_range(From) noexcept -> bool;

//////////////////////// floating point <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace internal
} // namespace gl

#include <utils/limits.inl>
#endif
