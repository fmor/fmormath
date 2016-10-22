cmake_minimum_required(VERSION 3.0)
set( CMAKE_VERBOSE_MAKEFILE	 True	CACHE BOOL "Enable verbose makefile" FORCE )

project( fmormath )

set( FMOR_ENABLE_TESTS		False	CACHE BOOL 	"Enable tests" )
set( FMOR_BUILD_STATIC		True	CACHE BOOL 	"Build static library" )


#####################################
## Compilation
enable_language( CXX )

set( CMAKE_CXX_FLAGS             "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -Wall -fexceptions" )
set( CMAKE_CXX_FLAGS_DEBUG       "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -D_DEBUG_" )
set( CMAKE_CXX_FLAGS_RELEASE     "${CMAKE_CXX_FLAGS_RELEASE} -O3" )


#######################
# CI
add_custom_target( CI SOURCES
    build.xml
)



#######################
# Documentaion
set( DOC_FILES
    README.md
)
add_custom_target( doc SOURCES ${DOC_FILES} )


set( HEADERS
    src/aabb.h
    src/angle.h
    src/clamp.h
    src/common.h
    src/constants.h
    src/euler.h
    src/interpolation.h
    src/mathtypes.h
    src/matrix2x2.h
    src/matrix3x3.h
    src/matrix4x4.h
    src/plane.h
    src/random.h
    src/rectangle.h
    src/quaternion.h
    src/sorter.h
    src/spacemap.h
    src/spacemap3d.h
    src/vector2i.h
    src/vector2f.h
    src/vector3f.h
    src/vector4f.h
    src/fmormathvector.h
    src/fmormath.h
    src/nanoflann.hpp
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
    src/plane.cpp
    src/random.cpp
    src/rectangle.cpp
    src/quaternion.cpp
    src/sorter.cpp
    src/vector2i.cpp
    src/vector2f.cpp
    src/vector3f.cpp
    src/vector4f.cpp
)


set( TEST_SOURCES
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
    test/test_plane.cpp
)

add_custom_target( headers SOURCES ${HEADERS} ${EXTERNALS_HEADERS} ${SCRIPTS} )

add_library(     fmormath SHARED ${SOURCES}  )

install( FILES   ${HEADERS} DESTINATION "include/fmormath" )
install( TARGETS fmormath LIBRARY DESTINATION lib )


if( FMOR_BUILD_STATIC )
	add_library(     fmormath_static STATIC ${SOURCES}  )
	install( TARGETS fmormath_static ARCHIVE DESTINATION lib )
endif()


# Tests
if( FMOR_ENABLE_TESTS )
    find_package(GTest REQUIRED)
    add_executable( runtests ${TEST_SOURCES} )
    target_include_directories( runtests PUBLIC ${GTEST_INCLUDE_DIR} )
    target_link_libraries(runtests fmormath ${GTEST_BOTH_LIBRARIES} pthread )
endif()






