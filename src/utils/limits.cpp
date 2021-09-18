#include <utils/limits.h>
#include <traits/categories.h>
#include <traits/characteristics/conversions.h>
#include <traits/characteristics/properties.h>
#include <traits/constraints.h>

#include <limits>
#include <type_traits>

namespace gl {
//////////////////////// interface >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To, typename>
constexpr auto conversion_truncates(From src) noexcept -> bool
{ return src != static_cast<From>(static_cast<To>(src)); }

template<typename From, typename To>
constexpr auto is_out_of_range(From src) noexcept -> bool {
    if constexpr (ts::is_narrowing_v<From, To>) {
        return impl::is_out_of_range<From, To>(src);
    }
    return false;
}

//////////////////////// interface <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
namespace impl {
//////////////////////// integral >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To,
    ts::require_t<ts::is_integral_all<From, To>>,
    ts::require_either_t<
        ts::is_signed_all<From, To>,
        ts::is_unsigned_all<From, To>>>
constexpr auto is_out_of_range(From src) noexcept -> bool
{ return conversion_truncates<From, To>(src); }

template<typename From, typename To,
    ts::require_t<std::is_unsigned<From>>,
    ts::require_t<std::is_signed<To>>,
    ts::require_t<std::is_integral<To>>>
constexpr auto is_out_of_range(From src) noexcept -> bool {
    using comm_t = std::common_type_t<From, To>;

    if constexpr (std::is_same_v<To, std::make_signed_t<comm_t>>) {
        return static_cast<To>(src) < To{};
    }
    return static_cast<To>(src) < To{}
        or conversion_truncates<From, To>(src);
}

template<typename From, typename To,
    ts::require_t<std::is_integral<From>>,
    ts::require_t<std::is_signed<From>>,
    ts::require_t<std::is_unsigned<To>>>
constexpr auto is_out_of_range(From src) noexcept -> bool {
    if constexpr (std::is_same_v<From, std::common_type_t<From, To>>) {
        return src < From{}
            or conversion_truncates<From, To>(src);
    }
    return src < From{};
}

//////////////////////// integral <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// floating point >>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To,
    ts::require_t<std::is_floating_point<From>>,
    ts::require_t<std::is_arithmetic<To>>>
constexpr auto is_out_of_range(From src) noexcept -> bool {
    return src < static_cast<From>(std::numeric_limits<To>::lowest())
        or src > static_cast<From>(std::numeric_limits<To>::max());
}

template<typename From, typename To,
    ts::require_t<std::is_integral<From>>,
    ts::require_t<std::is_floating_point<To>>>
constexpr auto is_out_of_range(From) noexcept -> bool
{ return false; }

//////////////////////// floating point <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace impl
} // namespace gl
