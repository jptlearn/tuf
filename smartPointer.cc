// Smart pointers are wrapper classes that manage memory automatically. There are three main types:

// unique_ptr - Single ownership
// shared_ptr - Shared ownership
// weak_ptr - Non-owning reference

#include <memory>
#include <iostream>

class MyClass {
  public:
    MyClass() { std::cout << "Constructor called\n"; };
    ~MyClass() { std::cout << "Destructor called\n"; };
    void doSomething() {
      std::cout << "Doing Something\n";
    };
};

int main() {
  // Create a unique_ptr
  std::unique_ptr<MyClass> ptr1(new MyClass());

  // Better way using make_unique
  auto ptr2 = std::make_unique<MyClass>();

  // using pointer
  ptr2->doSomething();

  // Transform ownership
  std::unique_ptr<MyClass> ptr3 = std::move(ptr2);

  // ptr2 is now null
  if(!ptr2) {
    std::cout << "ptr2 is null\n";
  }

  // No need to delete - automatically handled

  return 0;
}