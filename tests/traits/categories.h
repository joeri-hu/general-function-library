#ifndef GL_TS_TESTS_TRAITS_CATEGORIES_H
#define GL_TS_TESTS_TRAITS_CATEGORIES_H

#include <traits/categories.h>

namespace ts::tests {

//////////////////////// fundamental >>>>>>>>>>>>>>>>>>>>>>>>

static_assert(is_arithmetic_all_v<
    bool, char, short, int, long, long long,
    float, double, long double>);
static_assert(not is_arithmetic_all_v<
    bool, char, short, int, long, long long,
    float, double, long double,
    void>);

static_assert(is_arithmetic_any_v<void, int>);
static_assert(not is_arithmetic_any_v<void>);

static_assert(is_arithmetic_none_v<void>);
static_assert(not is_arithmetic_none_v<int>);

//////////////////////// fundamental <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// templates >>>>>>>>>>>>>>>>>>>>>>>>>>

template<typename>
struct template1 {};

template<typename>
struct template2 {};

template<typename T>
using alias1 = template1<T>;

template<typename T>
using alias2 = template2<T>;

static_assert(is_template_of_v<template1, template1<int>>);
static_assert(is_template_of_v<template1, alias1<int>>);
static_assert(is_template_of_v<template2, template2<int>>);
static_assert(is_template_of_v<template2, alias2<int>>);
static_assert(is_template_of_v<alias1, template1<int>>);
static_assert(is_template_of_v<alias2, template2<int>>);

static_assert(not is_template_of_v<template1, template2<int>>);
static_assert(not is_template_of_v<template1, alias2<int>>);
static_assert(not is_template_of_v<template2, template1<int>>);
static_assert(not is_template_of_v<template2, alias1<int>>);
static_assert(not is_template_of_v<alias1, template2<int>>);
static_assert(not is_template_of_v<alias2, template1<int>>);

static_assert(template_matches_v<template1, template1>);
static_assert(template_matches_v<template2, template2>);

static_assert(not template_matches_v<template1, template2>);
static_assert(not template_matches_v<template2, template1>);

//////////////////////// templates <<<<<<<<<<<<<<<<<<<<<<<<

} // namespace ts::tests

#endif
