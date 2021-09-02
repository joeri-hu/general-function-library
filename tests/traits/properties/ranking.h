#ifndef GFL_TESTS_TRAITS_PROPERTIES_RANKING_H
#define GFL_TESTS_TRAITS_PROPERTIES_RANKING_H

#include <traits/properties/ranking.h>

inline namespace gfl {
namespace ts::tests {

static_assert(common_type_matches_all_v<bool, bool, bool>);
static_assert(common_type_matches_all_v<char, char, char>);
static_assert(common_type_matches_all_v<int, int, int>);
static_assert(common_type_matches_all_v<double, double, double>);

static_assert(not common_type_matches_all_v<bool, bool, char>);
static_assert(not common_type_matches_all_v<char, char, int>);
static_assert(not common_type_matches_all_v<int, int, double>);
static_assert(not common_type_matches_all_v<double, double, bool>);

static_assert(common_type_matches_both_v<bool, bool>);
static_assert(common_type_matches_both_v<char, char>);
static_assert(common_type_matches_both_v<int, int>);
static_assert(common_type_matches_both_v<double, double>);

static_assert(not common_type_matches_both_v<bool, char>);
static_assert(not common_type_matches_both_v<char, int>);
static_assert(not common_type_matches_both_v<int, double>);
static_assert(not common_type_matches_both_v<double, bool>);

static_assert(common_type_matches_either_v<bool, bool, int>);
static_assert(common_type_matches_either_v<char, char, int>);
static_assert(common_type_matches_either_v<int, int, double>);
static_assert(common_type_matches_either_v<double, bool, bool>);

static_assert(not common_type_matches_either_v<bool, bool, char>);
static_assert(not common_type_matches_either_v<char, char, short>);
static_assert(not common_type_matches_either_v<short, short, bool>);
static_assert(not common_type_matches_either_v<bool, char, short>);

static_assert(common_type_matches_neither_v<bool, bool, char>);
static_assert(common_type_matches_neither_v<char, char, short>);
static_assert(common_type_matches_neither_v<short, short, bool>);
static_assert(common_type_matches_neither_v<bool, char, short>);

static_assert(not common_type_matches_neither_v<bool, bool, int>);
static_assert(not common_type_matches_neither_v<char, char, int>);
static_assert(not common_type_matches_neither_v<int, int, double>);
static_assert(not common_type_matches_neither_v<double, bool, bool>);

static_assert(common_type_matches_lhs_v<bool, bool>);
static_assert(common_type_matches_lhs_v<char, char>);
static_assert(common_type_matches_lhs_v<int, int>);
static_assert(common_type_matches_lhs_v<double, double>);
static_assert(common_type_matches_lhs_v<int, bool>);
static_assert(common_type_matches_lhs_v<long, char>);
static_assert(common_type_matches_lhs_v<float, int>);
static_assert(common_type_matches_lhs_v<long double, double>);

static_assert(not common_type_matches_lhs_v<bool, char>);
static_assert(not common_type_matches_lhs_v<char, bool>);
static_assert(not common_type_matches_lhs_v<bool, short>);
static_assert(not common_type_matches_lhs_v<char, short>);
static_assert(not common_type_matches_lhs_v<bool, int>);
static_assert(not common_type_matches_lhs_v<char, long>);
static_assert(not common_type_matches_lhs_v<int, float>);
static_assert(not common_type_matches_lhs_v<double, long double>);

static_assert(common_type_matches_rhs_v<bool, bool>);
static_assert(common_type_matches_rhs_v<char, char>);
static_assert(common_type_matches_rhs_v<int, int>);
static_assert(common_type_matches_rhs_v<double, double>);
static_assert(common_type_matches_rhs_v<bool, int>);
static_assert(common_type_matches_rhs_v<char, long>);
static_assert(common_type_matches_rhs_v<int, float>);
static_assert(common_type_matches_rhs_v<double, long double>);

static_assert(not common_type_matches_rhs_v<bool, char>);
static_assert(not common_type_matches_rhs_v<char, bool>);
static_assert(not common_type_matches_rhs_v<bool, short>);
static_assert(not common_type_matches_rhs_v<char, short>);
static_assert(not common_type_matches_rhs_v<int, bool>);
static_assert(not common_type_matches_rhs_v<long, char>);
static_assert(not common_type_matches_rhs_v<float, int>);
static_assert(not common_type_matches_rhs_v<long double, double>);

} // namespace ts::tests
} // namespace gfl

#endif
