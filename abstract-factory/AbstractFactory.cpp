
#include <iostream>
#include <string>
/*
 * Product A
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class ProductA
{
public:
  virtual ~ProductA() {}
  
  virtual std::string getName() = 0;
  // ...
};

/*
 * ConcreteProductAX and ConcreteProductAY
 * define objects to be created by concrete factory
 */
class ConcreteProductAX : public ProductA
{
public:
  ~ConcreteProductAX() {}
  
  std::string getName()
  {
    return "A-X";
  }
  // ...
};

class ConcreteProductAY : public ProductA
{
public:
  ~ConcreteProductAY() {}
  
  std::string getName()
  {
    return "A-Y";
  }
  // ...
};

/*
 * Product B
 * same as Product A, Product B declares interface for concrete products
 * where each can produce an entire set of products
 */
class ProductB
{
public:
  virtual ~ProductB() {}
  
  virtual std::string getName() = 0;
  // ...
};

/*
 * ConcreteProductBX and ConcreteProductBY
 * same as previous concrete product classes
 */
class ConcreteProductBX : public ProductB
{
public:
  ~ConcreteProductBX() {}
  
  std::string getName()
  {
    return "B-X";
  }
  // ...
};

class ConcreteProductBY : public ProductB
{
public:
  ~ConcreteProductBY() {}
  
  std::string getName()
  {
    return "B-Y";
  }
  // ...
};

/*
 * Abstract Factory
 * provides an abstract interface for creating a family of products
 */
class Factory
{
public:
  virtual ~Factory() {}
  
  virtual ProductA *createProductA() = 0;
  virtual ProductB *createProductB() = 0;
};

/*
 * Concrete Factory X and Y
 * each concrete factory create a family of products and client uses
 * one of these factories so it never has to instantiate a product object
 */
class ConcreteFactoryX : public Factory
{
public:
  ~ConcreteFactoryX() {}
  
  ProductA *createProductA()
  {
    return new ConcreteProductAX();
  }
  ProductB *createProductB()
  {
    return new ConcreteProductBX();
  }
  // ...
};

class ConcreteFactoryY : public Factory
{
public:
  ~ConcreteFactoryY() {}

  ProductA *createProductA()
  {
    return new ConcreteProductAY();
  }
  ProductB *createProductB()
  {
    return new ConcreteProductBY();
  }
  // ...
};


int main()
{
  Factory *factoryX = new ConcreteFactoryX();
  Factory *factoryY = new ConcreteFactoryY();

  ProductA *p1 = factoryX->createProductA();
  std::cout << "Product: " << p1->getName() << std::endl;
  
  ProductA *p2 = factoryY->createProductA();
  std::cout << "Product: " << p2->getName() << std::endl;
  
  delete p1;
  delete p2;
  
  delete factoryX;
  delete factoryY;
  
  return 0;
}
