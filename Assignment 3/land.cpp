#include <iostream>
#include <string>
using namespace std;
#include "land.h"
// #include "lor.h"
// #include "lnot.h"


// ostream & operator << (ostream & os, Exp & a){
//   os << "( "; // print left parenthesis
//   // if (v.leftV) {
//   //   cout << *v.leftV;
//   // } else if (v.leftAnd) {
//   //   cout << *v.leftAnd;
//   // } else if (v.leftOr) {
//   //   cout << *v.leftOr;
//   // } else if (v.leftNot) {
//   //   cout << *v.leftNot;
//   // }
//   cout << *a.leftExp;
//   os << " & ";
//   // if (v.rightV) {
//   //   cout << *v.rightV;
//   // } else if (v.rightAnd) {
//   //   cout << *v.rightAnd;
//   // } else if (v.rightOr) {
//   //   cout << *v.rightOr;
//   // } else if (v.rightNot) {
//   //   cout << *v.rightNot;
//   // }
//   cout << *a.rightExp;
//   os << " )";
//   return os;
// }

LAnd::LAnd(Exp * left, Exp * right)
  // :
  // leftV(NULL),
  // rightV(NULL),
  // leftAnd(NULL),
  // rightAnd(NULL),
  // leftOr(NULL),
  // rightOr(NULL),
  // leftNot(NULL),
  // rightNot(NULL)
 {
//   leftExp = left;
//   rightExp = right;

  // set the left operand pointer

  /////// replace conditions with enums (leftPointer = (enum(index)*)left)

  // if (lType == VarT) {
  //   leftV = (Var*)left;
  // }else if (lType == LAndT) {   //if leftType is LAndT (enum value), then leftAnd pointer is cast to LAnd type (logical AND)
  //   leftAnd = (LAnd*)left;
  // }else if (lType == LOrT) {
  //   leftOr = (LOr*)left;
  // } else if (lType == LNotT){
  //   leftNot = (LNot *)left;
  // }
  //set the right operand pointer
  // if (rType == VarT) {
  //   rightV = (Var*)right;
  // }else if (rType == LAndT) {
  //   rightAnd = (LAnd*)right;
  // }else if (rType == LOrT) {
  //   rightOr = (LOr*)right;
  // } else if (rType == LNotT){
  //   rightNot = (LNot *)right;
  // }
  leftExp = left;
  rightExp = right;
}

TriValue LAnd::evaluate() {    //trivalue is just like bool, but with three values
  TriValue lval = uu;
  TriValue rval = uu;
  // call the left operand evaluate
//   if (leftV) {   //if leftV isn't NULL, i.e. has been set in the constructor
//
// /////// remove redundant conditions. could use polymorphism? then i'd just call leftPointer->evaluate() and it would figure out
// /////// what function to call. can make all "gates" inherit from one class expression, which could be a var aslo
//
//     lval = leftV->evaluate();
//   } else if (leftAnd) {
//     lval = leftAnd->evaluate();
//   } else if (leftOr) {
//     lval = leftOr->evaluate();
//   } else if (leftNot) {
//     lval = leftNot->evaluate();
//   }
  lval = leftExp->evaluate();

  //call the right operand evaluate
  // if (rightV) {
  //   rval = rightV->evaluate();
  // } else if (rightAnd) {
  //   rval = rightAnd->evaluate();
  // } else if (rightOr) {
  //   rval = rightOr->evaluate();
  // } else if (rightNot) {
  //   rval = rightNot->evaluate();
  // }
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
