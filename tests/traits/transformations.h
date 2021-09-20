#ifndef GL_TS_TESTS_TRAITS_TRANSFORMATIONS_H
#define GL_TS_TESTS_TRAITS_TRANSFORMATIONS_H

#include <traits/transformations.h>

#include <type_traits>

namespace ts::tests {
//////////////////////// identity ............. >>>>>>>>>>>>>>>>>>>>>>>>

template<typename T>
constexpr auto deduce_last_argument(type_id_t<T>, T) noexcept -> T;

static_assert(std::is_same_v<type_id_t<int>, int>);
static_assert(not std::is_same_v<type_id_t<int>, float>);

static_assert(std::is_same_v<decltype(deduce_last_argument(float{}, int{})), int>);
static_assert(not std::is_same_v<decltype(deduce_last_argument(float{}, int{})), float>);

//////////////////////// identity ............. <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// promotion ............ >>>>>>>>>>>>>>>>>>>>>>>>

static_assert(std::is_same_v<promote<bool>, int>);
static_assert(std::is_same_v<promote<char>, int>);
static_assert(std::is_same_v<promote<short>, int>);
static_assert(std::is_same_v<promote<int>, int>);
static_assert(std::is_same_v<promote<long>, long>);
static_assert(std::is_same_v<promote<long long>, long long>);
static_assert(std::is_same_v<promote<float>, float>);
static_assert(std::is_same_v<promote<double>, double>);
static_assert(std::is_same_v<promote<long double>, long double>);

//////////////////////// promotion ............ <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// signatures ........... >>>>>>>>>>>>>>>>>>>>>>>>
//////////////////////// .. operators ......... >>>>>>>>>>>>>>>>>>>>>>>>

// note: add tests

//////////////////////// .. operators ......... <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// signatures ........... <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts::tests

#endif
