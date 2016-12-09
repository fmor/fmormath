# fmormath

Personnal math library, graphic oriented, written for my needs.

## Contents

* square matrix 2x2 3x3 4x4
* up to vector 4
* lerp
* ...

## OpenGL

Matrix is row major, you need to set transpose when passed to opengl uniform :

    glUniformMatrix4fv( uMVP, 1, GL_TRUE, mvp.getPtr() );


