### Statefull Lambda Expressions

[ caputured_variables ], (), -> return_type, specifiers, { return; }

the compiler generates a closure for the Lambda with a parameterized constructor 
that takes as its parameter the variable y and assigns it to the closure's member variable y.
the generated closure has an operator function implementing the logic of the Lambda

### Lambda Definition

int y { 10 };<br/>
auto lambda = [y] (int x) { std::cout << x + y; };

### Compiler-generated closure

class CompiterGenaretedName {<br/>
private:<br/>
&emsp;int y;

public:<br/>
&emsp;CompiterGenaretedName(int y) : y{ y } {};<br/>
&emsp;// all variables captured by value are captured by const value (default).<br/>
&emsp;void operator() (int x) const {;<br/>
&emsp;&emsp;std::cout << x + y;<br/>
&emsp;};<br/>
}
