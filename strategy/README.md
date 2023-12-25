## Strategy

Strategy defines a family of algorithms, encapsulates each one, and makes them 
interchangeable. It lets the algorithm vary independently from clients that use it. 
The pattern has behavioral purpose and applies to the objects.

## Siblings in inheretence: have different strategies -> don't duplicate code

### When to use

* many related classes differ only in their behavior
* you need different variants of an algorithm
* an algorithm uses data that clients shouldn't know about


## How

### Context
 * maintains a reference to a Strategy object
 * has A relationship with the strategy (strategy pointer)
 * we initialize the pointer in constructor (dependency injection)
 * and we call the algorithm interface in the context interface, acc to strategy


## Strategy
 * declares an interface common to all supported algorithms


## Concrete Strategies
 * implement the algorithm using the Strategy interface
 * 3 strategies: A,B,C