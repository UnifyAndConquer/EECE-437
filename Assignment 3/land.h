#pragma once
#include "var.h"
//#include "expression.h"
class LOr;
class LNot;
//class Exp;

struct LAnd //: Exp
{

  //////// replace all these with leftPointer & rightPointer only

  Var * leftV;
  Var * rightV;
  LAnd * leftAnd;
  LAnd * rightAnd;
  LOr * leftOr;
  LOr * rightOr;
  LNot * leftNot;
  LNot * rightNot;

  ///////// remove left & right since they are only used for typecasting, and one shouldn't need to specify their type (error prone)

  LAnd(void * left, void * right, LType lType, LType rType);  //ptr to left exp, ptr to right exp, type of left exp, type of right exp
  TriValue evaluate();
};

ostream & operator << (ostream & os, LAnd & v);
