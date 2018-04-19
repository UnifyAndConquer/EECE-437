#include <iostream>
#include <string>
using namespace std; 
#include <land.h>
#include <lor.h>
#include <lnot.h>

ostream & operator << (ostream & os, LNot & v) {
  os << "( !"; // print left parenthesis
  if (v.leftV) {
    cout << *v.leftV; 
  } else if (v.leftAnd) {
    cout << *v.leftAnd; 
  } else if (v.leftOr) {
    cout << *v.leftOr; 
  } else if (v.leftNot) {
    cout << *v.leftNot; 
  }
  os << " )"; 
  return os; 
}

LNot::LNot(void * left, LType lType)
  :
  leftV(NULL), 
  leftAnd(NULL), 
  leftOr(NULL),
  leftNot(NULL)
{
  // set the operand pointer 
  if (lType == VarT) {
    leftV = (Var*)left; 
  }else if (lType == LAndT) {
    leftAnd = (LAnd*)left;
  }else if (lType == LOrT) {
    leftOr = (LOr*)left;
  } else if (lType == LNotT){
    leftNot = (LNot *)left;
  }
}

TriValue LNot :: evaluate() {
  TriValue lval = uu; 
  // call the operand evaluate
  if (leftV) {
    lval = leftV->evaluate(); 
  } else if (leftAnd) {
    lval = leftAnd->evaluate(); 
  } else if (leftOr) {
    lval = leftOr->evaluate(); 
  } else if (leftNot) {
    lval = leftNot->evaluate(); 
  }

  //apply truth table of logical not. 
  if (lval == tt) {
    return ff;
  }
  if (lval == ff) {
    return tt; 
  }
  return uu; 

}
