#include <iostream>
#include <string>

/*
 * Product
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class Product
{
public:
  virtual ~Product() {}
  
  virtual std::string getName() = 0;
  // ...
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductA : public Product
{
public:
  ~ConcreteProductA() {}
  
  std::string getName()
  {
    return "type A";
  }
  // ...
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductB : public Product
{
public:
  ~ConcreteProductB() {}
  
  std::string getName()
  {
    return "type B";
  }
  // ...
};

/*
 * Factory
 * contains the implementation for all of the methods
 * to manipulate products except for the factory method
 */
class Factory
{
public:
  virtual ~Factory() {}
  
  virtual Product* createProduct(std::string type) = 0;
  
  virtual void removeProduct( Product *product ) = 0;
  
  // ...
};

/*
 * Concrete Factory
 * implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the products
 */
class ConcreteFactory : public Factory
{
public:
  ~ConcreteFactory() {}
  
  Product* createProduct(std::string type)
  {
    if (type=="type A"){
      return new ConcreteProductA();
    }else if (type=="type B"){
      return new ConcreteProductB();
    }
    return new ConcreteProductA();
  }
  
  void removeProduct( Product *product )
  {
    delete product;
  }
  // ...
};


int main()
{
  Factory *factory = new ConcreteFactory();
  
  Product *p1 = factory->createProduct("type A");
  std::cout << "Product: " << p1->getName() << std::endl;
  factory->removeProduct( p1 );
  
  Product *p2 = factory->createProduct("type B");
  std::cout << "Product: " << p2->getName() << std::endl;
  factory->removeProduct( p2 );
  
  delete factory;
  return 0;
}
