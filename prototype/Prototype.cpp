
#include <iostream>
#include <string>

/*
 * Prototype
 * declares an interface for cloning itself
 */
class Prototype
{
public:
  virtual ~Prototype() {}
  
  virtual Prototype* clone() = 0;
  virtual std::string type() = 0;
  // ...
};

/*
 * Concrete Prototype A and B
 * implement an operation for cloning itself
 */
class ClassA : public Prototype
{
public:
  ~ClassA() {}
  
  Prototype* clone()
  {
    return new ClassA();
  }
  std::string type()
  {
    return "type A";
  }
  // ...
};

class ClassB : public Prototype
{
public:
  ~ClassB() {}
  
  Prototype* clone()
  {
    return new ClassB();
  }
  std::string type()
  {
    return "type B";
  }
  // ...
};

/*
 * Client
 * creates a new object by asking a prototype to clone itself 
 * client - > not important in terms of structure
 * look at class A and B which are of Prototype type
 */
class Client
{
public:
  static void init()
  {
    types[ 0 ] = new ClassA();
    types[ 1 ] = new ClassB();
  }
  
  static void remove()
  {
    delete types[ 0 ];
    delete types[ 1 ];
  }
  
  static Prototype* make( const int index )
  {
    if ( index >= n_types )
    {
      return nullptr;
    }    
    return types[ index ]->clone();
  }
  // ...

private:
  static Prototype* types[ 2 ];
  static int n_types;
};

Prototype* Client::types[ 2 ];
int Client::n_types = 2;

int main()
{
  Client::init();
  
  Prototype *prototype1 = Client::make( 0 );
  std::cout << "Prototype: " << prototype1->type() << std::endl;
  delete prototype1;
  
  Prototype *prototype2 = Client::make( 1 );
  std::cout << "Prototype: " << prototype2->type() << std::endl;
  delete prototype2;
  
  Client::remove();
  
  return 0;
}
