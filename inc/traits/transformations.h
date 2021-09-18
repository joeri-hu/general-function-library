#ifndef GL_TS_TRAITS_TRANSFORMATIONS_H
#define GL_TS_TRAITS_TRANSFORMATIONS_H

#include <traits/constraints.h>

#include <type_traits>

namespace ts {
//////////////////////// identity >>>>>>>>>>>>>>>>>>>>>>>>>

template<typename T>
struct type_id
{ using type = T; };

template<typename T>
using type_id_t = typename type_id<T>::type;

//////////////////////// identity <<<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// promotion >>>>>>>>>>>>>>>>>>>>>>>>

template<typename T, typename = require<std::is_arithmetic<T>>>
using promote = decltype(+T{});

//////////////////////// promotion <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
