#pragma once
#include "var.h"
class LAnd;
class LOr;

struct LNot {
  Var * leftV;
  LAnd * leftAnd;
  LOr * leftOr;
  LNot * leftNot;
  LNot(void * left, LType lType);
  TriValue evaluate();
};

ostream & operator << (ostream & os, LNot & f);
