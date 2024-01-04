
#include <iostream>
#include <stack>

class Receiver //concrete
{
public:
  void action()
  {
    std::cout << "Receiver:  action" << std::endl;
  }
  // ...
};

class Command // abstract
{
public:
  virtual ~Command() {}
  virtual void execute() = 0;
  virtual void undo() = 0;

protected:
  Command() {}
};

class ConcreteCommand : public Command   //has receiver pointers
{
public:
  ConcreteCommand( Receiver *r ) : receiver( r ) {}
  
  ~ConcreteCommand()
  {
    if ( receiver )
    {
      delete receiver;
    }
  }
  
  void execute()
  {
    receiver->action();
  }
  void undo(){
    receiver->action();
  }
  // ...
  
private:
  Receiver *receiver;
  // ...
};

class Invoker //has a command pointer
{
  private:
  Command *command;
  std::stack <Command *> history;
  // ...
public:
  void set( Command *c )
  {
    command = c;
  }
  
  void confirm()
  {
    if ( command )
    {
      command->execute(); 
      history.push(command); 
    }
  }
  // ...

  void undo () {
    if (!history.empty()) {
      Command * ptr = history.top();
      history.pop();
      ptr->undo();
    }
  }


};


int main()
{
  ConcreteCommand command( new Receiver() );
  
  Invoker invoker;
  invoker.set( &command );
  invoker.confirm();
  invoker.undo();
  
  return 0;
}
