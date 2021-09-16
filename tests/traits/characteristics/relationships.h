#ifndef GL_TS_TESTS_TRAITS_CHARACTERISTICS_RELATIONSHIPS_H
#define GL_TS_TESTS_TRAITS_CHARACTERISTICS_RELATIONSHIPS_H

#include <traits/characteristics/relationships.h>

namespace ts::tests {

static_assert(is_same_all_v<bool, bool, bool>);
static_assert(is_same_all_v<char, char, char>);
static_assert(is_same_all_v<int, int, int>);
static_assert(is_same_all_v<double, double, double>);

static_assert(not is_same_all_v<bool, bool, char>);
static_assert(not is_same_all_v<char, char, bool>);
static_assert(not is_same_all_v<int, int, double>);
static_assert(not is_same_all_v<double, double, bool>);

static_assert(is_same_any_v<int, int, bool, char, double>);
static_assert(is_same_any_v<int, bool, int, char, double>);
static_assert(is_same_any_v<int, bool, char, int, double>);
static_assert(is_same_any_v<int, bool, char, double, int>);

static_assert(is_same_any_v<int, bool, char, double, int>);
static_assert(is_same_any_v<bool, int, char, double, int>);
static_assert(is_same_any_v<bool, char, int, double, int>);
static_assert(is_same_any_v<bool, char, double, int, int>);

static_assert(not is_same_any_v<bool, char, int, double>);

static_assert(is_same_none_v<bool, char, int, double>);

static_assert(not is_same_none_v<int, int, bool, char, double>);
static_assert(not is_same_none_v<int, bool, int, char, double>);
static_assert(not is_same_none_v<int, bool, char, int, double>);
static_assert(not is_same_none_v<int, bool, char, double, int>);

static_assert(not is_same_none_v<int, bool, char, double, int>);
static_assert(not is_same_none_v<bool, int, char, double, int>);
static_assert(not is_same_none_v<bool, char, int, double, int>);
static_assert(not is_same_none_v<bool, char, double, int, int>);

} // namespace ts::tests

#endif
