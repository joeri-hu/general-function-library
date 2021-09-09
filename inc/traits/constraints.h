#ifndef GL_TS_TRAITS_CONSTRAINTS_H
#define GL_TS_TRAITS_CONSTRAINTS_H

#include <type_traits>

namespace ts {

template<typename T>
struct require : std::enable_if_t<T{}> {};

template<typename T>
struct require_not : require<std::negation<T>> {};

template<typename... Ts>
struct require_all : require<std::conjunction<Ts...>> {};

template<typename T1, typename T2>
struct require_both : require_all<T1, T2> {};

template<typename... Ts>
struct require_either : require<std::disjunction<Ts...>> {};

template<typename... Ts>
struct require_neither : require_not<std::disjunction<Ts...>> {};

} // namespace ts

#endif
