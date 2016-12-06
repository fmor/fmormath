### Find fmormath

find_path( fmormath_INCLUDE_DIR NAMES "fmormath/fmormath.h" )
if( NOT fmormath_INCLUDE_DIR )
    message( FATAL_ERROR "fmormath includedir not found" )
endif( NOT fmormath_INCLUDE_DIR )

find_library( fmormath_LIBRARY NAMES fmormath  )
if( NOT fmormath_LIBRARY )
    message( FATAL_ERROR "fmormath library not found" )
endif( NOT fmormath_LIBRARY )

