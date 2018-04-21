///// for testing peurpeuseuz

//made var inherit from Exp so that i could call evaluate only once
//make dummyAND and dummyOR classes to test constructor automatic typecasting and evaluate

#include <string>
#include <typeinfo>
#include "var.h"

int main(int argc, char ** argv)
{
  LVAR v1("x0");
  LVAR v2("x1");

  EXP_DECLARE(LOR);
  LOR o1(&v1, &v2);
  EXP_DECLARE(LAND);
  LAND o2(&v1, &v2);

  LOR o3(&o1, &o2);

  v1.setValue(ff);
  v2.setValue(ff);

  TriValue val = o3.evaluate();
  cout << o3 << "evaluates to " << val << endl;

  o3.getVars();

  o3.getVars();
}

// struct dummyOR : Exp
// {
//   dummyOR(Exp * left, Exp * right)
//   {
//     leftExp = left;
//     rightExp = right;
//   }
//
//   TriValue evaluate()
//   {
//     TriValue lval = uu;
//     TriValue rval = uu;
//
//     cout<<"evaluating left side of OR: \n";
//     lval = leftExp->evaluate();
//     cout<<"evaluating right side of OR: \n";
//     rval = rightExp->evaluate();
//
//     if (lval == tt || rval == tt) {
//       cout<<"tt\n";
//       return tt;
//     }
//     if (lval == uu || rval == uu) {
//       cout<<"uu\n";
//       return uu;
//     }
//     cout<<"ff\n";
//     return ff;
//   }
// };



// #define TEST(name)\
//  struct name {\
//    string code;\
//    TriValue evaluate(TriValue left, TriValue right = uu)\
//    {\
//      if(#name == "LAND")\
//        code = "tfuffuuuu";\
//      else if(#name == "LOR")\
//        code = "ttutfuuuu";\
//      else if(#name == "LNAND")\
//        code = "ftuttuuuu";\
//      else if(#name == "LNOR")\
//        code = "ffuftuuuu";\
//      else if(#name == "LXOR")\
//        code = "ftutfuuuu";\
//      else if(#name == "LXNOR")\
//        code = "tfuftuuuu";\
//      else if(#name == "LNOT")\
//        code = "ffftttuuu";\
//      else if(#name == "LEQ")\
//        code = "tttfffuuu";\
//      else if(#name == "LIMP")\
//        code = "tfuttuuuu";\
//      else\
//        code = "xxxxxxxxx";\
// \
//      int index = 0;\
// \
//      if (left == ff)\
//        index += 3;\
// \
//      else if (left == uu)\
//        index += 6;\
// \
//      if(right == ff)\
//        index += 1;\
// \
//      else if(right == uu)\
//        index += 2;\
// \
//      char output = code[index];\
// \
//      if(output == 't')\
//        return tt;\
//      else if(output == 'f')\
//        return ff;\
//      else\
//        return uu;\
//    }
//  };



// tt tt 0
// tt ff 1
// tt uu 2
// ff tt 3
// ff ff 4
// ff uu 5
// uu tt 6
// uu ff 7
// uu uu 8


// string n = #name;\
// switch(n){\
//   case "LAND":\
//     code = "tfuffuuuu";\
//     break;\
//   case "LOR":\
//     code = "ttutfuuuu";\
//     break;\
//   case "LNAND":\
//     code = "ftuttuuuu";\
//     break;\
//   case "LNOR":\
//     code = "ffuftuuuu";\
//     break;\
//   case "LXOR":\
//     code = "ftutfuuuu";\
//     break;\
//   case "LXNOR":\
//     code = "tfuftuuuu";\
//     break;\
//   case "LNOT":\
//     code = "ftu";\
//     break;\
//   case "LEQ":\
//     code = "tfu";\
//     break;\
//   case "LIMP":\
//     code = "tfuttuuuu";\
//     break;\
//   default:\
//     code = "xxxxxxxxx";\
//     break;\
// }\

// Var v1("x0");
// Var v2("x1");
//
// dummyOR e1(&v1, &v2);
// dummyAND e2(&v1, &e1);
//
// string type = typeid(v1).name();
//
// if(type == "3Var")
//   cout<<"ok"<<endl;




//
// struct dummyAND : Exp
// {
//   dummyAND(Exp * left, Exp * right)
//   {
//     leftExp = left;
//     rightExp = right;
//   }
//
//   TriValue evaluate()
//   {
//     TriValue lval = uu;
//     TriValue rval = uu;
//
//     cout<<"evaluating left side of AND: \n";
//     lval = leftExp->evaluate();
//     cout<<"evaluating right side of AND: \n";
//     rval = rightExp->evaluate();
//
//     if (lval == ff || rval == ff) {
//       cout<<"ff\n";
//       return ff;
//     }
//     if (lval == uu || rval == uu) {
//       cout<<"uu\n";
//       return uu;
//     }
//     cout<<"tt\n";
//     return tt;
//   }
// };
