#pragma once
#include <string>
#include <typeinfo>

enum TriValue {
  uu, tt, ff,
};

struct Exp    //expression object from which all logical operations inherit, including variables
{
  string name;
  Exp * leftExp;      //pointer to left side expression
  Exp * rightExp;     //pointer to right side expression

  virtual TriValue evaluate() = 0;
};

#define EXP_DECLARE(type)\
struct type : Exp {\
\
  TriValue value;\
\
  type(string n, Exp * left, Exp * right){\
\
    if(#type == "LVAR") {\
      rightExp == NULL;\
      leftExp == NULL;}\
\
    else if(#type == "LNOT") {\
      rightExp == NULL;\
      leftExp == left;}\
\
    else {\
      rightExp == right;\
      leftExp == left;}\
\
    name = n;\
    value = uu;}\
\
  void setValue(TriValue v){value = v;}\
\
  TriValue evaluate(){\
    if(#type == "LVAR")\
      return value;\
    else {\
      TriValue lval = uu;\
      TriValue rval = uu;\
\
      lval = leftExp->evaluate();\
      if(#type != "LNOT" || #type != "LEQ")\
        rval = rightExp->evaluate();\
\
      if (lval == ff || rval == ff) {\
        return ff;}\
\
      if (lval == uu || rval == uu) {\
        return uu;}\
\
      return tt;\
    }\
};\

string nameOfValue(TriValue v){
  static string nameOfValueTable[]={"uu", "tt", "ff"};
  return nameOfValueTable[v];
}

ostream & operator << (ostream & os, Exp & e){
  string typex = typeid(e).name();
  string type = typex.erase(0,1);

  if(type == "Var")
    os << e.name;
  else if(type == "LNot")
  {
    os << "( !";
    cout << *e.leftExp;
    os << " )";
  }
  else
  {
    os << "( ";
    cout << *e.leftExp;
    os << " & ";
    cout << *e.rightExp;
    os << " )";
  }
  return os;
}

ostream & operator << (ostream & os, TriValue val) {
  os << nameOfValue(val);
  return os;
}


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
