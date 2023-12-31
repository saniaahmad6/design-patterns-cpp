
#include <iostream>
#include <string>

/*
 * Product
 * the final object that will be created using Builder
 */
class Product
{
  private: //multiple attributes 
  std::string partA;
  std::string partB;
  std::string partC;
  
public:
  //setters
  void setA(std::string str) {
    partA=str;
  }
  void setB(std::string str) {
    partB=str; 
  }
  void setC(std::string str) {
    partC=str;
  }
  void print(){
    std::cout<<partA<<" "<<partB<<" "<<partC<<std::endl;
  }
};

/*
 * Builder
 * abstract interface for creating products
 */
class Builder
{
public:
  virtual ~Builder() {}
  //setters
  virtual void buildA(std::string str)=0;
  virtual void buildB(std::string str)=0;
  virtual void buildC(std::string str)=0;
  //build
  virtual Product * build()=0;

};

/*
 * Concrete Builder X and Y
 * create real products and stores them in the composite structure
 */
class ConcreteBuilderX : public Builder
{
  Product * product;
public:
  ConcreteBuilderX() {product = new Product();}
  ~ConcreteBuilderX() {delete  product;}
  void buildA(std::string str) {
    product->setA(str);
  }
  void buildB(std::string str) {
    product->setB(str);
  }
  void buildC(std::string str) {
    product->setC(str);
  }
  Product * build(){
    return this->product;
  }
};

class ConcreteBuilderY : public Builder
{
public:
  Product * product;
public:
  ConcreteBuilderY() {product = new Product();}
  ~ConcreteBuilderY() {delete  product;}
  
  void buildA(std::string str) {
    product->setA(str);
  }
  void buildB(std::string str) {
    product->setB(str);
  }
  void buildC(std::string str) {
    product->setC(str);
  }
  Product * build(){
    return this->product;
  }
};

/*
 * Director
 * responsible for managing the correct sequence of object creation
 */
class Director {
private:
  Builder *builder; //has A 
public:
  Director(Builder * builder) : builder(builder) {} // 2 concrete builders can have there place
  
  ~Director()
  {
    if ( builder )
    {
      delete builder;
    }
  }
 
  Product * createX () {
    builder->buildA("SANIA");
    builder->buildB("WOW");
    return builder->build();
  }

  Product * createY () {
    builder->buildA("SANIA");
    builder->buildB("WOW");
    builder->buildC("WOW");
    return builder->build();
  }
};


int main()
{
  Director directorRefX(new ConcreteBuilderX()); // x type product
  Director directorRefY(new ConcreteBuilderY()); // y type product
  
  Product * productX = directorRefX.createX();
  productX->print();

  ConcreteBuilderX a;
  a.buildA("SANIA");
  a.buildB("WOW");
  Product * ptr= a.build();
  ptr->print();
  
  return 0;
}
