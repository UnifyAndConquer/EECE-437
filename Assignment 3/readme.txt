REFACTORING EXERCICE

This is a refactoring exercice with three-valued boolean formulas. Commits are roughly equivalent to “refactoring stages”

Refactoring Stages:

1 - constructors: Make two pointers of type Exp in base class Exp: leftExp and rightExp, to replace the list of pointers each of a different type. Constructor now takes two arguments: left and right, of type Exp. This way you can omit giving the constructor the types of the objects that you passed, because they get cast to the appropriate derived type automatically. evaluate function: Make base class' evaluate function virtual, all gates inherit from this function. Then the appropriate evaluate() function will be called automatically. printing functions also save on unnecessary if statements. Made printing a separate function that works for any object derived from Exp (uses typeid, which can be improved)

2 - you can automate the definition of new expressions using a macro like in assignment 2

Details:
- replaced char c[] with string in var constructor so compiler stops giving warning
