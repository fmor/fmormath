# fmormath

Personnal math library, graphic oriented, written for my needs.

## Contents

* square matrix 2x2 3x3 4x4
* up to vector 4
* lerp
* todo ...

## OpenGL

Matrix is row major, you need to set transpose flag when passed to opengl uniform :

glUniformMatrix4fv( uMVP, 1, **GL_TRUE**, mvp.getPtr() );

### OpenGL ES2

glUniformMatrix4fv( uMVP, 1, **GL_FALSE**, mvp.transpose().getPtr() );


## CMake Settings

|Variable                     |Desciption                                                                               |
|:----------------------------|:----------------------------------------------------------------------------------------|
| FMOR_ENABLE_TESTS           | Enable tests ( Require [goolge test](https://github.com/google/googletest) )            |
| FMOR_BUILD_STATIC           | Build static library                                                                    |
| FMOR_DEFINE_REAL_AS_DOUBLE  | Define Real as double instead of float (float is defaut)                                |


