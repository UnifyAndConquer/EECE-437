#pragma once
#include <string>
#include "expression.h"

enum LType{
  VarT, LAndT, LOrT, LNotT   //var type, LAnd type, etc.
};

string nameOfValue(TriValue v);

struct Var : Exp
{
  TriValue value;
  Var(string c);
  void setValue(TriValue v);
  TriValue evaluate();
};

ostream & operator << (ostream & os, Exp & v);
ostream & operator << (ostream & os, TriValue val);
