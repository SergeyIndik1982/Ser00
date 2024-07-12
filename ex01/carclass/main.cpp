#include <iostream>
#include <string>

class Car {  //class car
private:
    std::string name;
    int speed;

public:
    // Default constructor
    Car() : name("Unknown"), speed(0) {  // constructor
        std::cout << "Default constructor called\n";  //console out
    }

    // Parameterized constructor
    Car(const std::string& name, int speed) : name(name), speed(speed) { // constructor
        std::cout << "Parameterized constructor called\n";//console out
    }

    // Copy constructor
    Car(const Car& other) : name(other.name), speed(other.speed) {// constructor
        std::cout << "Copy constructor called\n";
    }

    // Copy assignment operator
    Car& operator=(const Car& other) {
        std::cout << "Copy assignment operator called\n";
        if (this != &other) {
            name = other.name;
            speed = other.speed;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        std::cout << "Destructor called for " << name << "\n";
    }

    // Member function to display car details
    void display() const {
        std::cout << "Car Name: " << name << ", Speed: " << speed << "\n";
    }
};

int main() {
    // Using default constructor
    Car car1("Toyota", 200);
    car1.display();

    // Using parameterized constructor
    Car car2("Toyota", 200);
    car2.display();

    // Using copy constructor
    Car car3 = car2;
    car3.display();

    // Using copy assignment operator
    Car car4;
    car4 = car2;
    car4.display();

    return 0;
}
