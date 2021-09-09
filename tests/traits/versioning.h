#ifndef GL_TS_TESTS_TRAITS_VERSIONING_H
#define GL_TS_TESTS_TRAITS_VERSIONING_H

#include <traits/versioning.h>

namespace ts {
namespace tests {

static_assert(
    is_cpp11_compliant_v() or
    is_cpp14_compliant_v() or
    is_cpp17_compliant_v() or
    is_cpp20_compliant_v(),
"");

} // namespace tests
} // namespace ts

#endif
