#pragma once
#include <string>
#include <vector>
#include "expression.h"


enum LType{
  VarT, LAndT, LOrT, LNotT   //var type, LAnd type, etc.
};

string nameOfValue(TriValue v);

struct LVAR : Exp
{
  TriValue value;
  LVAR(string c);
  void setValue(TriValue v);
  TriValue evaluate();
  void getVars();
  //bool was_called;
};

ostream & operator << (ostream & os, Exp & v);
ostream & operator << (ostream & os, TriValue val);
