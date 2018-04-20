///// for testing peurpeuseuz
#include <iostream>
#include <string>
using namespace std;

#include "expression.h"
#include "var.h"
#include "land.h"
#include "lor.h"
#include "lnot.h"

struct dummyOR : Exp
{
  dummyOR(Exp * left, Exp * right)
  {
    // leftExp = (Exp*)left;
    // rightExp = (Exp*)right;
    leftExp = left;
    rightExp = right;
  }

  TriValue evaluate()
  {
    TriValue lval = uu;
    TriValue rval = uu;

    cout<<"evaluating left side of OR: \n";
    lval = leftExp->evaluate();
    cout<<"evaluating right side of OR: \n";
    rval = rightExp->evaluate();

    if (lval == tt || rval == tt) {
      cout<<"tt\n";
      return tt;
    }
    if (lval == uu || rval == uu) {
      cout<<"uu\n";
      return uu;
    }
    cout<<"ff\n";
    return ff;
  }
};

struct dummyAND : Exp
{
  dummyAND(Exp * left, Exp * right)
  {
    // leftExp = (Exp*)left;
    // rightExp = (Exp*)right;
    leftExp = left;
    rightExp = right;

  }

  TriValue evaluate()
  {
    TriValue lval = uu;
    TriValue rval = uu;

    cout<<"evaluating left side of AND: \n";
    lval = leftExp->evaluate();
    cout<<"evaluating right side of AND: \n";
    rval = rightExp->evaluate();

    if (lval == ff || rval == ff) {
      cout<<"ff\n";
      return ff;
    }
    if (lval == uu || rval == uu) {
      cout<<"uu\n";
      return uu;
    }
    cout<<"tt\n";
    return tt;
  }
};

int main(int argc, char ** argv)
{

  Var v1("x0");
  Var v2("x1");

  dummyOR e1(&v1, &v2);
  dummyAND e2(&v1, &e1);

  v1.setValue(tt);
  v2.setValue(ff);

  TriValue val = e2.evaluate();

}
