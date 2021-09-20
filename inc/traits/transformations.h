#ifndef GL_TS_TRAITS_TRANSFORMATIONS_H
#define GL_TS_TRAITS_TRANSFORMATIONS_H

#include <traits/constraints.h>

#include <type_traits>

namespace ts {
//////////////////////// identity ............. >>>>>>>>>>>>>>>>>>>>>>>>

template<typename T>
struct type_id
{ using type = T; };

template<typename T>
using type_id_t = typename type_id<T>::type;

//////////////////////// identity ............. <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// promotion ............ >>>>>>>>>>>>>>>>>>>>>>>>

template<typename T, typename = require<std::is_arithmetic<T>>>
using promote = decltype(+T{});

//////////////////////// promotion ............ <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// signatures ........... >>>>>>>>>>>>>>>>>>>>>>>>
//////////////////////// .. operators ......... >>>>>>>>>>>>>>>>>>>>>>>>

template<typename...>
struct compnd_op;

template<typename T1, typename T2>
struct compnd_op<T1, T2>
{ using type = T1 (&)(T1, T2); };

template<typename... Ts>
using compnd_op_t = typename compnd_op<Ts...>::type;

//////////////////////// .. operators ......... <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// signatures ........... <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
