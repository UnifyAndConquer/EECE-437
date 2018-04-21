REFACTORING EXERCICE

This is a refactoring exercice with three-valued boolean formulas. Commits are roughly equivalent to “refactoring stages”

Refactoring Stages:

1 - constructors: Make two pointers of type Exp in base class Exp: leftExp and rightExp, to replace the list of pointers each of a different type. Constructor now takes two arguments: left and right, of type Exp. This way you can omit giving the constructor the types of the objects that you passed, because they get cast to the appropriate derived type automatically. evaluate function: Make base class' evaluate function virtual, all gates inherit from this function. Then the appropriate evaluate() function will be called automatically. printing functions also save on unnecessary if statements. Made printing a separate function that works for any object derived from Exp (uses typeid and conditionals, which can be improved)

2 - automate the definition of new expressions using a macro like in assignment 2. just change the truth table with a macro. make printing function a member of exp, and add another one for variables.

Details:
- replaced char c[] with string in var constructor so compiler stops giving warning
- made name a Exp property to avoid conflicts with Var

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
