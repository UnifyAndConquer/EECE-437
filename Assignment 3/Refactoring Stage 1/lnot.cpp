#include <iostream>
#include <string>
using namespace std;
#include "lnot.h"

LNot::LNot(Exp * left)
{
  leftExp = left;
  rightExp = NULL;
}

TriValue LNot::evaluate() {
  TriValue lval = uu;
  lval = leftExp->evaluate();

  //apply truth table of logical not.
  if (lval == tt) {
    return ff;
  }
  if (lval == ff) {
    return tt;
  }
  return uu;
}