#pragma once

enum TriValue {
  uu, tt, ff,
};

enum LType{
  VarT, LAndT, LOrT, LNotT   //var type, LAnd type, etc.
};

string nameOfValue(TriValue v);
struct Var{
  string name;
  TriValue value;
  Var(char n[]);
  void setValue(TriValue v);
  TriValue evaluate();
};
ostream & operator << (ostream & os, Var & v);
ostream & operator << (ostream & os, TriValue val);
