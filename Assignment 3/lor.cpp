#include <iostream>
#include <string>
using namespace std;
#include "lor.h"

LOr::LOr(Exp * left, Exp * right)
{
  leftExp = left;
  rightExp = right;
}

TriValue LOr::evaluate() {
  TriValue lval = uu;
  TriValue rval = uu;

  lval = leftExp->evaluate();
  rval = rightExp->evaluate();

  //apply truth table of logical or.
  if (lval == tt || rval == tt) {
    return tt;
  }
  if (lval == uu || rval == uu) {
    return uu;
  }
  // only case left is both are ff
  return ff;
}
