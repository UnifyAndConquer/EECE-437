#pragma once
#include "var.h"

struct LOr : Exp
{
  LOr(Exp * left, Exp * right);
  TriValue evaluate();
};