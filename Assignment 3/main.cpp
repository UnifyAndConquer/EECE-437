#include <iostream>
#include <string>
using namespace std; 

#include <var.h>
#include <land.h>
#include <lor.h>
#include <lnot.h>

int 
main() {
  Var v1("x0"); 
  Var v2("x1"); 
  LAnd a1(&v1,&v2,VarT,VarT); 
  LAnd a2(&a1,&v2,LAndT,VarT); 
  LOr o1(&a2,&v1,LAndT,VarT); 
  LNot n1(&o1,LOrT); 
  cout << n1 << endl; 

  v1.setValue(tt);
  v2.setValue(ff);
  // the following works because I defined a streaming operator for TriValue in var.h and var.cpp
  cout << a1 << " " << a1.evaluate() << endl; 
  cout << a2 << " " << a2.evaluate() << endl; 
  cout << o1 << " " << o1.evaluate() << endl; 
  TriValue val = n1.evaluate(); 
  cout << n1 << "evaluates to " << val << endl; 

  v2.setValue(tt);
  val = n1.evaluate(); 
  cout << "now " << n1 << "evaluates to " << nameOfValue(val) << endl; 

  v1.setValue(uu);
  val = n1.evaluate(); 
  cout << "now " << n1 << "evaluates to " << nameOfValue(val) << endl; 
  // try also evaluating a1, a2 and o1. 
  // try your own formulae
  return 0;
}

