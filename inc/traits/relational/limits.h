#ifndef GL_TS_TRAITS_RELATIONAL_LIMITS_H
#define GL_TS_TRAITS_RELATIONAL_LIMITS_H

#include <traits/transformations.h>

#include <type_traits>
#include <utility>

namespace ts {
//////////////////////// precision  >>>>>>>>>>>>>>>>>>>>>>>>
namespace internal {

// adaptation from proposal P0870R2
template<typename From, typename To>
using require_no_narrowing
    = std::void_t<decltype(type_id_t<To[]>{std::declval<From>()})>;

} // namespace internal

template<typename From, typename To, typename = void>
struct is_narrowing : std::true_type {};

template<typename From, typename To>
struct is_narrowing<From, To, internal::require_no_narrowing<From, To>>
    : std::false_type {};

//////////////////////// >> helpers >>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To>
inline constexpr auto is_narrowing_v = bool{is_narrowing<From, To>{}};

//////////////////////// << helpers <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// precision  <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// range >>>> >>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To>
struct is_within_range
    : std::disjunction<
        std::conjunction<
            std::is_integral<From>,
            std::is_floating_point<To>>,
        std::negation<is_narrowing<From, To>>> {};

//////////////////////// >> helpers  >>>>>>>>>>>>>>>>>>>>>>>>

template<typename From, typename To>
inline constexpr auto is_within_range_v = bool{is_within_range<From, To>{}};

//////////////////////// << helpers  <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// range <<<<< <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
