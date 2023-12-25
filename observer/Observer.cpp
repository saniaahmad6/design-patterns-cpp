

#include <iostream>
#include <vector>

class Observable;

/*
 * Observer
 * defines an updating interface for objects that should be notified
 * of changes in a observable
 */
class Observer
{
public:
  virtual ~Observer() {}
  virtual void update() = 0;
  // ...
};

/*
 * Concrete Observer
 * stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes
 */
class ConcreteObserver : public Observer
{
public:
  
  
  ~ConcreteObserver() {}
  ConcreteObserver(Observable * observable) {
    this->observable = observable;
  }

  
  void update()
  {
    std::cout << "Email Received." << std::endl;

  }
private:
  Observable * observable;  // strategy pattern 

};

/*
 * Observable
 * knows its observers and provides an interface for attaching
 * and detaching observers
 */
class Observable
{
public:
  virtual ~Observable() {}
  
  virtual void attach( Observer *observer ) = 0;
  
  virtual void detach( const int index ) = 0 ;
  
  virtual void notify() = 0;
  
  virtual int getState() = 0;
  virtual void setState( const int s ) = 0;

};

/*
 * Concrete Observable
 * stores state that should stay consistent with the observable's
 */
class ConcreteObservable : public Observable
{
public:
  ~ConcreteObservable() {}

   void attach( Observer *observer )
  {
    observers.push_back(observer);
  }
  
  void detach( const int index )
  {
    observers.erase( observers.begin() + index );
  }
  
  void notify()
  {
    for ( unsigned int i = 0; i < observers.size(); i++ )
    {
      observers.at( i )->update();
    }
  }
  
  int getState()
  {
    return observable_state;
  }
  
  void setState( const int s )
  {
    observable_state = s;
    notify();
  }
  // ...
  
private:
  int observable_state;
  std::vector<Observer*> observers;
  // ...
};




int main()
{
  Observable *observable = new ConcreteObservable();

  ConcreteObserver * observer1= new ConcreteObserver(observable);
  ConcreteObserver * observer2 = new ConcreteObserver(observable);

  
  observable->attach( observer1 );
  observable->attach( observer2 );
  
  observable->setState( 10 ); //notified to all observers
  // observable->notify();
 
  std::cout<<observable->getState()<<std::endl;
  delete observable;
  return 0;
}