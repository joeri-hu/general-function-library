#ifndef GL_TESTS_TRAITS_VERSIONING_H
#define GL_TESTS_TRAITS_VERSIONING_H

#include <traits/versioning.h>

inline namespace gl {
namespace ts::tests {

#if defined(__cplusplus) and (__cplusplus >= 201703L)
    static_assert(is_cpp_compliant_v);
#else
    static_assert(is_cpp_compliant_v(), "");
#endif

} // namespace ts::tests
} // namespace gl

#endif
