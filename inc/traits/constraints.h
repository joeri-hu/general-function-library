#ifndef GL_TS_TRAITS_CONSTRAINTS_H
#define GL_TS_TRAITS_CONSTRAINTS_H

#include <type_traits>

namespace ts {

template<typename B, typename T = void>
using require = std::enable_if_t<B{}, T>;

template<typename B, typename T = void>
using require_not = require<std::negation<B, T>>;

template<typename... Bs>
using require_all = require<std::conjunction<Bs...>>;

template<typename B1, typename B2, typename T = void>
using require_both = require<std::conjunction<B1, B2>, T>;

template<typename... Bs>
using require_either = require<std::disjunction<Bs...>>;

template<typename... Bs>
using require_neither = require_not<std::disjunction<Bs...>>;

//////////////////////// types >>>>>>>>>>>>>>>>>>>>>>>>
namespace impl {

using tpl_type = int;

} // namespace impl

template<typename B>
using require_t = require<B, impl::tpl_type>;

template<typename B>
using require_not_t = require_not<B, impl::tpl_type>;

template<typename... Bs>
using require_all_t = require<std::conjunction<Bs...>, T>;

template<typename B1, typename B2>
using require_both_t = require_both<B1, B2, impl::tpl_type>;

template<typename... Bs>
using require_either_t = require<std::disjunction<Bs...>, impl::tpl_type>;

template<typename... Bs>
using require_neither_t = require_not<std::disjunction<Bs...>, impl::tpl_type>;

//////////////////////// types <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts

#endif
