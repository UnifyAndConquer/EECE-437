#pragma once
#include <var.h>
class LAnd; 
class LNot; 

struct LOr {
  Var * leftV; 
  Var * rightV; 
  LAnd * leftAnd; 
  LAnd * rightAnd; 
  LOr * leftOr;
  LOr * rightOr; 
  LNot * leftNot; 
  LNot * rightNot; 
  LOr(void * left, void * right, LType lType, LType rType); 
  TriValue evaluate(); 
}; 

ostream & operator << (ostream & os, LOr & v); 
