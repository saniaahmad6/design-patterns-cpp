
#include <iostream>

/*
 * Subject
 * defines the common interface for RealSubject and Proxy
 * so that a Proxy can be used anywhere a RealSubject is expected
 */
class Subject
{
public:
  virtual ~Subject() { /* ... */ }

  virtual void request() = 0;  //function declare 
  // ...
};

/*
 * Real Subject
 * defines the real object that the proxy represents
 */
class RealSubject : public Subject
{
public:
  void request() //implement function
  {
    std::cout << "Real Subject request" << std::endl;
  }
  // ...
};

/*
 * Proxy
 * maintains a reference that lets the proxy access the real subject
 */
class Proxy : public Subject
{
public:
  Proxy()
  {
    subject = new RealSubject();
  }
  
  ~Proxy()
  {
    delete subject;
  }
  
  void request()
  {
    //pre process
    subject->request();
    //post process
  }
  // ...

private:
  RealSubject *subject; //hasA to the concrete Subject 
};


int main()
{
  Subject * client = new Proxy();
  client->request();
  
  delete client;
  return 0;
}
