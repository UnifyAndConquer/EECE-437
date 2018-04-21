REFACTORING STAGE 1

1 - Constructors: Make two pointers of type Exp in base class Exp: leftExp and rightExp, to replace the list of pointers each of a different type. Constructor now takes two arguments: left and right, of type Exp. This way you can omit giving the constructor the types of the objects that you passed, because they get cast to the appropriate derived type automatically. 

2 - Evaluate function: Make base class' evaluate function virtual, all gates inherit from this function. Then the appropriate evaluate() function will be called automatically. printing functions also save on unnecessary if statements. 

3 - Printing function: made printing a separate function that works for any object derived from Exp (uses typeid and conditionals, which can be improved)