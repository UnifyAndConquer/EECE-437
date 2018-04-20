#pragma once
#include <string>
#include "expression.h"

// enum TriValue {
//   uu, tt, ff,
// };

enum LType{
  VarT, LAndT, LOrT, LNotT   //var type, LAnd type, etc.
};

string nameOfValue(TriValue v);
struct Var : Exp{
  string name;
  TriValue value;
  Var(string c);
  void setValue(TriValue v);
  TriValue evaluate();
};
ostream & operator << (ostream & os, Var & v);
ostream & operator << (ostream & os, TriValue val);
