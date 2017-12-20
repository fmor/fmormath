cmake_minimum_required(VERSION 3.0)

project( fmormath )

set( FMOR_ENABLE_TESTS		false	CACHE BOOL "Enable tests" )
set( FMOR_BUILD_STATIC		true	CACHE BOOL "Build static library" )
set( FMOR_DEFINE_REAL_AS_DOUBLE false   CACHE BOOL "Define Real as double instead of float (float is defaut)")

set( CMAKE_VERBOSE_MAKEFILE	OFF )

#####################################
## Compilation
enable_language( CXX )

set( CMAKE_CXX_FLAGS             "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -Wall -fno-exceptions -fno-rtti" )
set( CMAKE_CXX_FLAGS_DEBUG       "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -D_DEBUG_" )
set( CMAKE_CXX_FLAGS_RELEASE     "${CMAKE_CXX_FLAGS_RELEASE} -O3" )
#set( CMAKE_DEBUG_POSTFIX         "_debug" )




if( FMOR_DEFINE_REAL_AS_DOUBLE )
    add_definitions( -DDEFINE_REAL_AS_DOUBLE )
endif()

include_directories( "externals" )


set( EXTERNALS_SOURCES
)
set( EXTERNALS_HEADERS
    externals/nanoflann.hpp
)

set( HEADERS
    src/aabb.h
    src/angle.h
    src/clamp.h
    src/common.h
    src/constants.h
    src/euler.h
    src/interpolation.h
    src/mathtypes.h
    src/mathvariant.h
    src/matrix2x2.h
    src/matrix3x3.h
    src/matrix4x4.h
    src/random.h
    src/rectangle.h
    src/quaternion.h
    src/sorter.h
    src/spacemap.h
    src/spacemap3d.h
    src/vector2f.h
    src/vector3f.h
    src/vector4f.h
    src/fmormathvector.h
    src/fmormath.h
    src/mortonnumber.h
)




set( SOURCES
    src/aabb.cpp
    src/angle.cpp
    src/clamp.cpp
    src/common.cpp
    src/constants.cpp
    src/euler.cpp
    src/interpolation.cpp
    src/matrix2x2.cpp
    src/matrix3x3.cpp
    src/matrix4x4.cpp
    src/mortonnumber.cpp
    src/random.cpp
    src/rectangle.cpp
    src/quaternion.cpp
    src/sorter.cpp
    src/vector2f.cpp
    src/vector3f.cpp
    src/vector4f.cpp
)



add_library(     fmormath SHARED ${SOURCES} ${EXTERNALS_SOURCES}  )

install( FILES   ${HEADERS} ${EXTERNALS_HEADERS} DESTINATION "include/fmormath" )
install( TARGETS fmormath LIBRARY DESTINATION lib )


if( FMOR_BUILD_STATIC )
        add_library(     fmormath_static STATIC ${SOURCES}  )
        install( TARGETS fmormath_static ARCHIVE DESTINATION lib )
endif()




################################
## Tests
if( FMOR_ENABLE_TESTS )

    set( TEST_SOURCES
        test/test_include.cpp
        test/test_quaternion.cpp
        test/test_vector2f.cpp
        test/test_vector3f.cpp
        test/test_vector4f.cpp
        test/test_aabb.cpp
        test/test_clamp.cpp
        test/test_euler.cpp
        test/test_matrix2x2.cpp
        test/test_matrix3x3.cpp
        test/test_matrix4x4.cpp
        test/test_interpolation.cpp
        test/test_random.cpp
        test/test_rectangle.cpp
        test/test_common.cpp
    )


    find_package(GTest REQUIRED)
    add_executable( runtests ${TEST_SOURCES} )
    target_include_directories( runtests PUBLIC ${GTEST_INCLUDE_DIR} )
    target_link_libraries(runtests fmormath ${GTEST_BOTH_LIBRARIES} pthread )
endif()

