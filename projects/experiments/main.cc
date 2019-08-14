#include "foo.h"

Foo::Foo() {}

inline int
Foo::Bar() {  //< No undefined external refrence error.
  return 1;
}

int main(int argv, char** args) {
  Foo foo;
  std::cout << "Hello StackOverflow. foo is " << foo.Bar();
  while (1)
    ;
}
