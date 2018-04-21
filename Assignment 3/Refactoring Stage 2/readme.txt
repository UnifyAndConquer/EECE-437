REFACTORING STAGE 2

Automated the definition of new expressions using a macro like in assignment 2. just change the truth table with a macro. made printing function a member of exp, and added another one for variables.

Details:
- replaced char c[] with string in var constructor so compiler stops giving warning
- made name a Exp property to avoid conflicts with Var

Here are the truth tables for the implemented logical operations:

// LAND   tfuffuuuu
// LOR    ttutfuuuu
// LNAND  ftuttuuuu
// LNOR   ffuftuuuu
// LXOR   ftutfuuuu
// LXNOR  tfuftuuuu
// LNOT   ftu
// LEQ    tfu
// LIMP   tfuttuuuu
//
// type   x1  x2  y
// -----------------
// LAND   tt  tt  tt
//        tt  ff  ff
//        tt  uu  uu
//        ff  tt  ff
//        ff  ff  ff
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
//
// type   x1  x2  y
// -----------------
// LOR    tt  tt  tt
//        tt  ff  tt
//        tt  uu  uu
//        ff  tt  tt
//        ff  ff  ff
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
//
// type   x1  x2  y
// -----------------
// LNAND  tt  tt  ff
//        tt  ff  tt
//        tt  uu  uu
//        ff  tt  tt
//        ff  ff  tt
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
//
// type   x1  x2  y
// -----------------
// LNOR   tt  tt  ff
//        tt  ff  ff
//        tt  uu  uu
//        ff  tt  ff
//        ff  ff  tt
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
//
// type   x1  x2  y
// -----------------
// LXOR   tt  tt  ff
//        tt  ff  tt
//        tt  uu  uu
//        ff  tt  tt
//        ff  ff  ff
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
//
// type   x1  x2  y
// -----------------
// LXNOR  tt  tt  tt
//        tt  ff  ff
//        tt  uu  uu
//        ff  tt  ff
//        ff  ff  tt
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
//
// type   x1  x2  y
// -----------------
// LNOT   tt  xx  ff
//        ff  xx  tt
//        uu  xx  uu
//
// type   x1  x2  y
// -----------------
// LEQ    tt  xx  tt
//        ff  xx  ff
//        uu  xx  uu
//
// type   x1  x2  y
// -----------------
// LIMP   tt  tt  tt
//        tt  ff  ff
//        tt  uu  uu
//        ff  tt  tt
//        ff  ff  tt
//        ff  uu  uu
//        uu  tt  uu
//        uu  ff  uu
//        uu  uu  uu
