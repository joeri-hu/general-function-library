#ifndef GL_TS_TESTS_TRAITS_CONSTRAINTS_H
#define GL_TS_TESTS_TRAITS_CONSTRAINTS_H

#include <traits/constraints.h>

#include <type_traits>

namespace ts::tests {

static_assert(std::is_same_v<require<std::true_type>, void>);
static_assert(std::is_same_v<require_not<std::false_type>, void>);

static_assert(std::is_same_v<require_all<
    std::true_type, std::true_type, std::true_type>, void>);
static_assert(std::is_same_v<require_both<
    std::true_type, std::true_type>, void>);

static_assert(std::is_same_v<require_either<
    std::false_type, std::false_type, std::true_type>, void>);
static_assert(std::is_same_v<require_neither<
    std::false_type, std::false_type, std::false_type>, void>);

} // namespace ts::tests

#endif
