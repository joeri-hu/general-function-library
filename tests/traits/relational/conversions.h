#ifndef GL_TS_TESTS_TRAITS_RELATIONAL_CONVERSIONS_H
#define GL_TS_TESTS_TRAITS_RELATIONAL_CONVERSIONS_H

#include <traits/relational/conversions.h>

#include <cstdint>

namespace ts::tests {
//////////////////////// conversions >>>>>>>>>>>>>>>>>>>>>>>>

static_assert(is_converting_all_v<bool, bool, char>);
static_assert(is_converting_all_v<char, char, short>);
static_assert(is_converting_all_v<short, short, bool>);
static_assert(is_converting_all_v<bool, char, short>);

static_assert(not is_converting_all_v<bool, bool, bool>);
static_assert(not is_converting_all_v<char, char, char>);
static_assert(not is_converting_all_v<short, short, short>);
static_assert(not is_converting_all_v<bool, char, short, int>);

static_assert(is_converting_both_v<bool, char>);
static_assert(is_converting_both_v<bool, short>);
static_assert(is_converting_both_v<char, short>);

static_assert(not is_converting_both_v<bool, int>);
static_assert(not is_converting_both_v<char, int>);
static_assert(not is_converting_both_v<short, int>);
static_assert(not is_converting_both_v<int, int>);
static_assert(not is_converting_both_v<long, int>);
static_assert(not is_converting_both_v<double, int>);

static_assert(is_converting_either_v<bool, bool, char>);
static_assert(is_converting_either_v<char, char, short>);
static_assert(is_converting_either_v<short, short, bool>);
static_assert(is_converting_either_v<bool, char, short>);
static_assert(is_converting_either_v<bool, bool, int>);
static_assert(is_converting_either_v<int, long, int>);
static_assert(is_converting_either_v<double, long, long>);
static_assert(is_converting_either_v<int, long, double>);

static_assert(not is_converting_either_v<bool, bool, bool>);
static_assert(not is_converting_either_v<char, char, char>);
static_assert(not is_converting_either_v<int, int, int>);
static_assert(not is_converting_either_v<double, double, double>);

static_assert(is_converting_neither_v<bool, bool, bool>);
static_assert(is_converting_neither_v<char, char, char>);
static_assert(is_converting_neither_v<int, int, int>);
static_assert(is_converting_neither_v<double, double, double>);

static_assert(not is_converting_neither_v<bool, bool, char>);
static_assert(not is_converting_neither_v<char, char, short>);
static_assert(not is_converting_neither_v<short, short, bool>);
static_assert(not is_converting_neither_v<bool, char, short>);
static_assert(not is_converting_neither_v<bool, bool, int>);
static_assert(not is_converting_neither_v<int, long, int>);
static_assert(not is_converting_neither_v<double, long, long>);
static_assert(not is_converting_neither_v<int, long, double>);

static_assert(is_converting_lhs_v<bool, char>);
static_assert(is_converting_lhs_v<char, short>);
static_assert(is_converting_lhs_v<bool, short>);
static_assert(is_converting_lhs_v<short, bool>);
static_assert(is_converting_lhs_v<bool, int>);
static_assert(is_converting_lhs_v<char, int>);
static_assert(is_converting_lhs_v<short, int>);
static_assert(is_converting_lhs_v<int, long>);
static_assert(is_converting_lhs_v<int, double>);
static_assert(is_converting_lhs_v<long, double>);

static_assert(not is_converting_lhs_v<bool, bool>);
static_assert(not is_converting_lhs_v<char, char>);
static_assert(not is_converting_lhs_v<int, int>);
static_assert(not is_converting_lhs_v<double, double>);
static_assert(not is_converting_lhs_v<int, bool>);
static_assert(not is_converting_lhs_v<int, char>);
static_assert(not is_converting_lhs_v<int, short>);
static_assert(not is_converting_lhs_v<long, int>);
static_assert(not is_converting_lhs_v<double, int>);
static_assert(not is_converting_lhs_v<double, long>);

static_assert(is_converting_rhs_v<char, bool>);
static_assert(is_converting_rhs_v<short, char>);
static_assert(is_converting_rhs_v<short, bool>);
static_assert(is_converting_rhs_v<bool, short>);
static_assert(is_converting_rhs_v<int, bool>);
static_assert(is_converting_rhs_v<int, char>);
static_assert(is_converting_rhs_v<int, short>);
static_assert(is_converting_rhs_v<long, int>);
static_assert(is_converting_rhs_v<double, int>);
static_assert(is_converting_rhs_v<double, long>);

static_assert(not is_converting_rhs_v<bool, bool>);
static_assert(not is_converting_rhs_v<char, char>);
static_assert(not is_converting_rhs_v<int, int>);
static_assert(not is_converting_lhs_v<double, double>);
static_assert(not is_converting_rhs_v<bool, int>);
static_assert(not is_converting_rhs_v<char, int>);
static_assert(not is_converting_rhs_v<short, int>);
static_assert(not is_converting_rhs_v<int, long>);
static_assert(not is_converting_rhs_v<int, double>);
static_assert(not is_converting_rhs_v<long, double>);

//////////////////////// conversions <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// promotions  >>>>>>>>>>>>>>>>>>>>>>>>

static_assert(is_promotable_v<bool>);
static_assert(is_promotable_v<char>);
static_assert(is_promotable_v<short>);

static_assert(not is_promotable_v<int>);
static_assert(not is_promotable_v<long>);
static_assert(not is_promotable_v<double>);

static_assert(is_promotable_all_v<bool, bool, bool>);
static_assert(is_promotable_all_v<char, char, char>);
static_assert(is_promotable_all_v<short, short, short>);
static_assert(is_promotable_all_v<bool, char, short>);

static_assert(not is_promotable_all_v<bool, bool, int>);
static_assert(not is_promotable_all_v<char, char, long>);
static_assert(not is_promotable_all_v<short, short, double>);
static_assert(not is_promotable_all_v<bool, char, short, int>);

static_assert(is_promotable_both_v<bool, bool>);
static_assert(is_promotable_both_v<char, char>);
static_assert(is_promotable_both_v<short, short>);
static_assert(is_promotable_both_v<bool, char>);
static_assert(is_promotable_both_v<char, short>);
static_assert(is_promotable_both_v<short, bool>);

static_assert(not is_promotable_both_v<int, int>);
static_assert(not is_promotable_both_v<long, long>);
static_assert(not is_promotable_both_v<double, double>);
static_assert(not is_promotable_both_v<bool, int>);
static_assert(not is_promotable_both_v<char, int>);
static_assert(not is_promotable_both_v<short, int>);

static_assert(is_promotable_either_v<int, long, double, bool>);
static_assert(is_promotable_either_v<int, long, char, double>);
static_assert(is_promotable_either_v<int, short, long, double>);
static_assert(is_promotable_either_v<bool, int, long, double>);

static_assert(not is_promotable_either_v<int, int, int>);
static_assert(not is_promotable_either_v<long, long, long>);
static_assert(not is_promotable_either_v<double, double, double>);
static_assert(not is_promotable_either_v<int, long, double>);

static_assert(is_promotable_neither_v<int, int, int>);
static_assert(is_promotable_neither_v<long, long, long>);
static_assert(is_promotable_neither_v<double, double, double>);
static_assert(is_promotable_neither_v<int, long, double>);

static_assert(not is_promotable_neither_v<int, long, double, bool>);
static_assert(not is_promotable_neither_v<int, long, char, double>);
static_assert(not is_promotable_neither_v<int, short, long, double>);
static_assert(not is_promotable_neither_v<bool, int, long, double>);

//////////////////////// promotions  <<<<<<<<<<<<<<<<<<<<<<<<
//////////////////////// precision > >>>>>>>>>>>>>>>>>>>>>>>>

static_assert(is_narrowing_v<std::int64_t, std::int32_t>);
static_assert(is_narrowing_v<std::int64_t, std::int16_t>);
static_assert(is_narrowing_v<std::int64_t, std::int8_t>);
static_assert(is_narrowing_v<std::int32_t, std::int16_t>);
static_assert(is_narrowing_v<std::int32_t, std::int8_t>);
static_assert(is_narrowing_v<std::int16_t, std::int8_t>);

static_assert(is_narrowing_v<std::uint64_t, std::uint32_t>);
static_assert(is_narrowing_v<std::uint64_t, std::uint16_t>);
static_assert(is_narrowing_v<std::uint64_t, std::uint8_t>);
static_assert(is_narrowing_v<std::uint32_t, std::uint16_t>);
static_assert(is_narrowing_v<std::uint32_t, std::uint8_t>);
static_assert(is_narrowing_v<std::uint16_t, std::uint8_t>);

static_assert(not is_narrowing_v<std::int8_t, std::int8_t>);
static_assert(not is_narrowing_v<std::int8_t, std::int16_t>);
static_assert(not is_narrowing_v<std::int8_t, std::int32_t>);
static_assert(not is_narrowing_v<std::int8_t, std::int64_t>);
static_assert(not is_narrowing_v<std::int16_t, std::int16_t>);
static_assert(not is_narrowing_v<std::int16_t, std::int32_t>);
static_assert(not is_narrowing_v<std::int16_t, std::int64_t>);
static_assert(not is_narrowing_v<std::int32_t, std::int32_t>);
static_assert(not is_narrowing_v<std::int32_t, std::int64_t>);
static_assert(not is_narrowing_v<std::int64_t, std::int64_t>);

static_assert(not is_narrowing_v<std::uint8_t, std::uint8_t>);
static_assert(not is_narrowing_v<std::uint8_t, std::uint16_t>);
static_assert(not is_narrowing_v<std::uint8_t, std::uint32_t>);
static_assert(not is_narrowing_v<std::uint8_t, std::uint64_t>);
static_assert(not is_narrowing_v<std::uint16_t, std::uint16_t>);
static_assert(not is_narrowing_v<std::uint16_t, std::uint32_t>);
static_assert(not is_narrowing_v<std::uint16_t, std::uint64_t>);
static_assert(not is_narrowing_v<std::uint32_t, std::uint32_t>);
static_assert(not is_narrowing_v<std::uint32_t, std::uint64_t>);
static_assert(not is_narrowing_v<std::uint64_t, std::uint64_t>);

//////////////////////// precision < <<<<<<<<<<<<<<<<<<<<<<<<
} // namespace ts::tests

#endif
