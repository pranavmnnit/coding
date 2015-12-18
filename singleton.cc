#include <iostream>
using namespace std;

class A {
    private:
	A() { }
	A(A const&) { }
	A& operator=(A const&) { }
	static A* pA;
	static int BB;
    public:
	static A* getInstance();
	int a, b;
};

class B {
    private:
	B() {}
	B(const B&) { }
	B& operator=(const B&) { }
	~B() { }
    public:
	static B& getInstance() {
	    static B b1;
	    return b1;
	}
	int a, b;
};

A* A::pA = NULL;
int A::BB = 1;

A* A::getInstance() {
    if (pA == NULL) {
	pA = new A();
    }
    return pA;
}

int main() {
    A* a1 = A::getInstance();
    A* a2 = A::getInstance();
    cout << a1 << "\t" << a2 << endl;
    A::getInstance()->a = 5;
    cout << a1->a << ", " << a2->a << endl;

    B* b1 = &B::getInstance();
    B* b2 = &B::getInstance();
    B::getInstance();
    cout << b1 << "\t" << b2 << endl;

    return 0;
}
