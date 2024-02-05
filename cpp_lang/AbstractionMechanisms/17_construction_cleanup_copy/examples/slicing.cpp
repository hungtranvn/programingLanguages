struct Base {
    int b;
    Base(const Base&);
}

struct Derived : Base {
    int d;
    Derived(const Derived&);
}

void naive(Base* p) {
    B b2 = *p; //may slice Base::Base(const Base&)
}

void user() {
    Derived d;
    naive(&d);
    Base bb = d; // slice Base::Base(const Base&)
}
// Avoid slicing
// Prohibit copyig of the base class
// Prevent conversion of a pointer tp a derived to a pointer to a base
int main() {
    user();
    return 0;
}