#include <iostream>

/*
 * Handler
 * defines an interface for handling requests and
 * optionally implements the successor link
 */
class Handler
{
public:
  virtual ~Handler() {}
  
  Handler( Handler *s )
  {
    next = s;
  }
  
  virtual void handleRequest(int requestNo)
  {
    if (next != nullptr)
    {
      next->handleRequest(requestNo);
    }
  }

private:
  Handler *next;
protected:
  int Priority1 = 1;
  int Priority2 = 2;
};

/*
 * Concrete Handlers
 * handle requests they are responsible for
 */
class ConcreteHandler1 : public Handler
{
public:
  ~ConcreteHandler1() {}
  ConcreteHandler1(Handler * next) : Handler(next) {}
    
  virtual void handleRequest(int requestNo)
  {
    if (requestNo==Priority1)
    {
      std::cout << "Handled by Concrete Handler 1" << std::endl;
    }
    else
    {
      std::cout << "Not Handled by Concrete Handler 1" << std::endl;
      Handler::handleRequest(requestNo);
    }
    // ...
  }
  // ...
};

class ConcreteHandler2 : public Handler
{
public:
  ~ConcreteHandler2() {}
  ConcreteHandler2(Handler * next) : Handler(next) {}
  virtual void handleRequest(int requestNo)
  {
    if (requestNo==Priority2)
    {
      std::cout << "Handled by Concrete Handler 2" << std::endl;
    }
    else
    {
      std::cout << "Not Handled by Concrete Handler 2" << std::endl;
      Handler::handleRequest(requestNo);
    }
    // ...
  }
  // ...
};


int main()
{
  Handler * client = new ConcreteHandler1(new ConcreteHandler2(nullptr));
  client->handleRequest(2);
  
  return 0;
}
