#include <iostream>
#include <string>
using namespace std;
#include "land.h"

LAnd::LAnd(Exp * left, Exp * right)
{
  leftExp = left;
  rightExp = right;
}

TriValue LAnd::evaluate() {    //trivalue is just like bool, but with three values
  TriValue lval = uu;
  TriValue rval = uu;

  lval = leftExp->evaluate();
  rval = rightExp->evaluate();

  //apply truth table
  if (lval == ff || rval == ff) {
    return ff;
  }
  if (lval == uu || rval == uu) {
    return uu;
  }
  // only case left is both are tt
  return tt;
}
