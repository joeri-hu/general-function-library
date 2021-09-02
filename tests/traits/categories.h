#ifndef GFL_TESTS_TRAITS_CATEGORIES_H
#define GFL_TESTS_TRAITS_CATEGORIES_H

#include <traits/categories.h>

inline namespace gfl {
namespace ts::tests {
inline namespace fundamental {

struct not_arithmetic {};

static_assert(is_arithmetic_all_v<
    bool, char, short, int, long, long long, float, double, long double>);
static_assert(not is_arithmetic_all_v<
    bool, char, short, int, long, long long, float, double, long double,
    not_arithmetic>);

static_assert(is_arithmetic_any_v<not_arithmetic, int>);
static_assert(not is_arithmetic_any_v<not_arithmetic>);

static_assert(is_arithmetic_none_v<not_arithmetic>);
static_assert(not is_arithmetic_none_v<int>);

} // namespace fundamental
inline namespace templates {

template<typename>
struct template1 {};

template<typename>
struct template2 {};

static_assert(is_template_of_v<template1, template1<int>>);
static_assert(is_template_of_v<template2, template2<int>>);

static_assert(not is_template_of_v<template1, template2<int>>);
static_assert(not is_template_of_v<template2, template1<int>>);

static_assert(template_matches_v<template1, template1>);
static_assert(template_matches_v<template2, template2>);

static_assert(not template_matches_v<template1, template2>);
static_assert(not template_matches_v<template2, template1>);

} // namespace templates
} // namespace ts::tests
} // namespace gfl

#endif
