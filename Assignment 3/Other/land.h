#pragma once
#include "var.h"

struct LAnd : Exp
{
  LAnd(Exp * left, Exp * right);  //ptr to left exp, ptr to right exp, type of left exp, type of right exp
  TriValue evaluate();
};
