#pragma once
#include <string>
//#include "var.h"

enum TriValue {
  uu, tt, ff,
};

struct Exp
{
  string name;
  Exp * leftExp;      //pointer to left side expression
  Exp * rightExp;     //pointer to right side expression

  virtual TriValue evaluate() = 0;
};
