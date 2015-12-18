struct A {
    int a;
    int fun(int a, int d);
};

int
A::fun(int a, int d) {
    return 1;
}

int main() {
    struct A a1;
    int a = a1.fun(1, 2);
    return 0;
}
