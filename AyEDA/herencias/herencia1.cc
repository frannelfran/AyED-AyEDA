#include <iostream>

using namespace std;

class A {
 private:
  int a_;
 public:
  A(int x = 10) : a_(x) {}
  int f(int x) { return g(x * x); }
  virtual int g(int x) const { return x % a_; }
};

class B : public A {
 private:
  int b_;
 public:
  B(int x) : b_(x) {}
  virtual int f(int x) const { return g(x + x); }
  int g(int x) const { return x % b_; }
};

class C : public B {
 private:
  int c_;
 public:
  C(int x = 5) : B(x), c_(x) {}
  int f(int x) { return g(x * c_); }
};

int main() {
  A* a = new A;
  cout << a->f(5) << endl;

  A* b = new B(7);
  cout << b->f(4) << endl;

  B* c = new C;
  cout << c->f(3) << endl;
  return 0;
}