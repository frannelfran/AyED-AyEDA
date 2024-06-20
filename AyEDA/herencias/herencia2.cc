#include <iostream>

using namespace std;

class A {
 private:
  int a_;
 public:
  A(int x) : a_(x) {}
  virtual int f(int x) { return g(x * x); }
  virtual int g(int x) const { return x * a_; }
};

class B : public A {
 private:
  int b_;
 public:
  B(int x = 2) : A(x * x), b_(x) {}
  int f(int x) const { return g(x + b_); }
};

class C : public B {
 private:
  int f(int x) { return A::f(x + x); }
  int g(int x) const { return x; }
};

int main() {
  B* a = new B;
  cout << a->f(4) << endl;
  A* b = new B(5);
  cout << b->f(3) << endl;
  A* c = new C;
  cout << c->f(2) << endl;

  return 0;
}