#include <iostream>

class Base {
private:
    static constexpr const char *def_name {"Base object's name"};
protected:
    std::string name;
public:
    Base(std::string name = def_name)
        : name{name} {
    }
    Base(const Base &src) 
        : name{src.name} {
            std::cout << "Base copy constructor called" << std::endl;
    }
    virtual void say_hello() const {
    //void say_hello() const {
        std::cout << "Hello, I'm a Base class" << std::endl;
    }
    virtual ~Base();
};

class Derived : public Base {
private:
    static constexpr const char *def_name {"Derived object's name"};
public:
    Derived(std::string name = def_name) 
        : Base{name} {
    }
    Derived(const Derived &src) 
        : Base{src} {
            std::cout << "Derived copy constructor called" << std::endl;
    }
    virtual void say_hello() const override {
    // void say_hello() const {
        std::cout << "Hello, I'm a Derived class" << std::endl;
    }
    virtual ~Derived();
};

void greetings(const Base &obj) {
    std::cout << "Greetings: " << std::endl;
    obj.say_hello();
}

int main() {
    
    std::cout << "== Static binding (Compile-time polymorphism) examples ==" << std::endl;
    Base b;
    b.say_hello();
    
    Derived d {};
    d.say_hello();

    greetings(b);

    Base *b_ptr {new Base{}};
    b_ptr->say_hello();
    greetings(*b_ptr);

    Derived *d_ptr {new Derived{}};
    d_ptr->say_hello();

    std::cout << '\n';
    std::cout << "== Dynamic binding (Run-time polymorphism) examples ==" << std::endl;
    greetings(d);       // Won't call derived say_hello() method unless base say_hello() method is virtual
    greetings(*d_ptr);  // Won't call derived say_hello() method unless base say_hello() method is virtual

    Base *ptr {nullptr};
    ptr = &b;
    ptr->say_hello();
    greetings(*ptr);

    ptr = &d;
    ptr->say_hello();
    greetings(*ptr);

    // Delete raw pointers
    delete b_ptr;
    delete d_ptr;

    return 0;
}