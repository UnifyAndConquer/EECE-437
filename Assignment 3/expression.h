#pragma once
//#include "var.h"

enum TriValue {
  uu, tt, ff,
};

struct Exp
{
  Exp * leftExp;
  Exp * rightExp;
  
  virtual TriValue evaluate() = 0;
  //virtual void print() = 0;
};
