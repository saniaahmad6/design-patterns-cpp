#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
/*
 * Singleton - private static variable to hold one instance of the class
 * and method which gives us a way to instantiate the class
 */
class Singleton
{
private:
  static Singleton *instance;
  static std::mutex mtx;
  Singleton(); //defined later
  Singleton( Singleton const& ) ;
  Singleton& operator=( Singleton const& );
public:
  // The copy constructor and assignment operator
  // are defined as deleted, which means that you
  // can't make a copy of singleton.
  //
  // Note: you can achieve the same effect by declaring
  // the constructor and the operator as private
  

  static Singleton* getInstance()
  {

    if (instance==nullptr)
    {
      mtx.lock();
        if (instance==nullptr) {
          return instance = new Singleton();
        }
      mtx.unlock();
    }    
    else return instance;
  }
  
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

Singleton::Singleton(){
  std::cout<<"instance"<<endl;
}
int main()
{
  Singleton * instance=Singleton::getInstance(); //Singleton()
  Singleton * instance1=Singleton::getInstance(); //instance returned
  Singleton * instance2=Singleton::getInstance(); //instance returned
  
  return 0;
}
