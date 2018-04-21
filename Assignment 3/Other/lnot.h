#pragma once
#include "var.h"

struct LNot : Exp
{
  LNot(Exp * left);
  TriValue evaluate();
};
