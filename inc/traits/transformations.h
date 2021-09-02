#ifndef GFL_TRAITS_TRANSFORMATIONS_H
#define GFL_TRAITS_TRANSFORMATIONS_H

#include <traits/constraints.h>

#include <type_traits>

inline namespace gfl {
namespace ts {
inline namespace identity {

template<typename T>
struct type_id
{ using type = T; };

template<typename T>
using type_id_t = typename type_id<T>::type;

} // namespace identity
inline namespace promotion {

template<typename T, typename = require<std::is_arithmetic<T>>>
using promote = decltype(+T{});

} // namespace promotion
} // namespace ts
} // namespace gfl

#endif
