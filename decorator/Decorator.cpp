
#include <iostream>

/*
 * Base
 * defines an interface for objects that can have responsibilities
 * added to them dynamically
 */
class Base
{
public:
  virtual ~Base() {}
  
  virtual void operation() = 0;
  // ...
};

/*
 * Concrete Base
 * defines an object to which additional responsibilities
 * can be attached (eg types of pizza)
 */
class ConcreteBase : public Base
{
public:
  ~ConcreteBase() {}
  
  void operation()
  {
    std::cout << "Concrete Base operation" << std::endl;
  }
  // ...
};

/*
 * Decorator
 * maintains a reference to a Base object and defines an interface
 * that conforms to Base's interface
 */
class Decorator : public Base  //is A
{
public:
  ~Decorator() {}
  
  Decorator( Base *c ) : component( c ) {}
  
  virtual void operation()
  {
    component->operation();
  }
  // ...

private:
  Base *component; //has A
};

/*
 * Concrete Decorators
 * add responsibilities to the component (can extend the state
 * of the component)
 */
class ConcreteDecoratorA : public Decorator
{
public:
  ConcreteDecoratorA( Base *c ) : Decorator( c ) {}
  
  void operation()
  {
    Decorator::operation();
    std::cout << "Decorator A" << std::endl;
  }
  // ...
};

class ConcreteDecoratorB : public Decorator
{
public:
  ConcreteDecoratorB( Base *c ) : Decorator( c ) {}
  
  void operation()
  {
    Decorator::operation();
    std::cout << "Decorator B" << std::endl;
  }
  // ...
};


int main()
{
  ConcreteBase  *cc = new ConcreteBase();
  ConcreteDecoratorB *db = new ConcreteDecoratorB( cc );
  ConcreteDecoratorA *da = new ConcreteDecoratorA( db );
  
  Base *component = da;
  component->operation();
  
  delete da;
  delete db;
  delete cc;
  
  return 0;
}
