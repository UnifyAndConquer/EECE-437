#include <iostream>
#include <string>
using namespace std; 
#include <land.h>
#include <lor.h>
#include <lnot.h>

ostream & operator << (ostream & os, LOr & v) {
  os << "( "; // print left parenthesis
  if (v.leftV) {
    cout << *v.leftV; 
  } else if (v.leftAnd) {
    cout << *v.leftAnd; 
  } else if (v.leftOr) {
    cout << *v.leftOr; 
  } else if (v.leftNot) {
    cout << *v.leftNot; 
  }
  os << " | "; 
  if (v.rightV) {
    cout << *v.rightV; 
  } else if (v.rightAnd) {
    cout << *v.rightAnd; 
  } else if (v.rightOr) {
    cout << *v.rightOr; 
  } else if (v.rightNot) {
    cout << *v.rightNot; 
  }
  os << " )"; 
  return os; 
}

LOr::LOr(void * left, void * right, LType lType, LType rType)
  :
  leftV(NULL), 
  rightV(NULL), 
  leftAnd(NULL), 
  rightAnd(NULL), 
  leftOr(NULL),
  rightOr(NULL), 
  leftNot(NULL), 
  rightNot(NULL) 
{
  // set the left operand pointer 
  if (lType == VarT) {
    leftV = (Var*)left; 
  }else if (lType == LAndT) {
    leftAnd = (LAnd*)left;
  }else if (lType == LOrT) {
    leftOr = (LOr*)left;
  } else if (lType == LNotT){
    leftNot = (LNot *)left;
  }
  // set the right operand pointer 
  if (rType == VarT) {
    rightV = (Var*)right; 
  }else if (rType == LAndT) {
    rightAnd = (LAnd*)right;
  }else if (rType == LOrT) {
    rightOr = (LOr*)right;
  } else if (rType == LNotT){
    rightNot = (LNot *)right;
  }
}

TriValue LOr :: evaluate() {
  TriValue lval = uu; 
  TriValue rval = uu; 
  // call the left operand evaluate
  if (leftV) {
    lval = leftV->evaluate(); 
  } else if (leftAnd) {
    lval = leftAnd->evaluate(); 
  } else if (leftOr) {
    lval = leftOr->evaluate(); 
  } else if (leftNot) {
    lval = leftNot->evaluate(); 
  }

  // call the right operand evaluate
  if (rightV) {
    rval = rightV->evaluate(); 
  } else if (rightAnd) {
    rval = rightAnd->evaluate(); 
  } else if (rightOr) {
    rval = rightOr->evaluate(); 
  } else if (rightNot) {
    rval = rightNot->evaluate(); 
  }
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
