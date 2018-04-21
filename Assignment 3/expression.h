#pragma once
#include <string>
#include <iostream>
using namespace std;

enum TriValue {
  uu, tt, ff,
};

struct Exp    //expression object from which all logical operations inherit, including variables
{
  string name;
  Exp * leftExp;      //pointer to left side expression
  Exp * rightExp;     //pointer to right side expression

  virtual TriValue evaluate() = 0;
};

#define EXP_DECLARE(type)\
struct type : Exp {\
  type(Exp * left, Exp * right = NULL){\
      rightExp = right;\
      leftExp = left;\
    }\
\
  TriValue evaluate(){\
    string code;\
\
    TriValue lval = uu;\
    TriValue rval = uu;\
\
    lval = leftExp->evaluate();\
    rval = rightExp->evaluate();\
\
    if(#type == "LAND")\
      code = "tfuffuuuu";\
    else if(#type == "LOR")\
      code = "ttutfuuuu";\
    else if(#type == "LNAND")\
      code = "ftuttuuuu";\
    else if(#type == "LNOR")\
      code = "ffuftuuuu";\
    else if(#type == "LXOR")\
      code = "ftutfuuuu";\
    else if(#type == "LXNOR")\
      code = "tfuftuuuu";\
    else if(#type == "LNOT")\
      code = "ffftttuuu";\
    else if(#type == "LEQ")\
      code = "tttfffuuu";\
    else if(#type == "LIMP")\
      code = "tfuttuuuu";\
    else\
      code = "xxxxxxxxx";\
    \
    int index = 0;\
    \
    if (lval == ff)\
      index += 3;\
    \
    else if (lval == uu)\
      index += 6;\
    \
    if(rval == ff)\
      index += 1;\
    \
    else if(rval == uu)\
      index += 2;\
    \
    char output = code[index];\
    \
    if(output == 't')\
      return tt;\
    else if(output == 'f')\
      return ff;\
    else\
      return uu;\
  }\
};\
