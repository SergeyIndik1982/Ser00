#include <iostream>
#include <string>
#include <vector>

// Абстрактный базовый класс Car
class Car {
private:
    std::string make;  // Марка автомобиля
    std::string model; // Модель автомобиля
    int year;          // Год выпуска

public:
    // Конструктор по умолчанию
    Car() : make("Unknown"), model("Unknown"), year(0) {
        std::cout << "Default constructor called for Car\n";
    }

    // Параметризованный конструктор
    Car(const std::string& make, const std::string& model, int year) : make(make), model(model), year(year) {
        std::cout << "Parameterized constructor called for Car\n";
    }

    // Конструктор копирования
    Car(const Car& other) : make(other.make), model(other.model), year(other.year) {
        std::cout << "Copy constructor called for Car\n";
    }

    // Оператор присваивания копированием
    Car& operator=(const Car& other) {
        std::cout << "Copy assignment operator called for Car\n";
        if (this != &other) {
            make = other.make;
            model = other.model;
            year = other.year;
        }
        return *this;
    }

    // Виртуальный деструктор
    virtual ~Car() {
        std::cout << "Destructor called for Car\n";
    }

    // Чисто виртуальная функция drive делает Car абстрактным классом
    virtual void drive() const = 0;

    // Геттеры для make, model и year
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
};

// Производный класс SportsCar
class SportsCar : public Car {
private:
    int maxSpeed; // Максимальная скорость

public:
    // Конструктор по умолчанию
    SportsCar() : Car(), maxSpeed(0) {
        std::cout << "Default constructor called for SportsCar\n";
    }

    // Параметризованный конструктор
    SportsCar(const std::string& make, const std::string& model, int year, int maxSpeed)
        : Car(make, model, year), maxSpeed(maxSpeed) {
        std::cout << "Parameterized constructor called for SportsCar\n";
    }

    // Конструктор копирования
    SportsCar(const SportsCar& other) : Car(other), maxSpeed(other.maxSpeed) {
        std::cout << "Copy constructor called for SportsCar\n";
    }

    // Оператор присваивания копированием
    SportsCar& operator=(const SportsCar& other) {
        std::cout << "Copy assignment operator called for SportsCar\n";
        if (this != &other) {
            Car::operator=(other);
            maxSpeed = other.maxSpeed;
        }
        return *this;
    }

    // Деструктор
    ~SportsCar() {
        std::cout << "Destructor called for SportsCar\n";
    }

    // Переопределение функции drive
    void drive() const override {
        std::cout << "Driving " << getMake() << " " << getModel() << " " << getYear()
                  << " with a max speed of " << maxSpeed << " km/h\n";
    }
};

// Производный класс ElectricCar
class ElectricCar : public Car {
private:
    int batteryCapacity; // Ёмкость батареи

public:
    // Конструктор по умолчанию
    ElectricCar() : Car(), batteryCapacity(0) {
        std::cout << "Default constructor called for ElectricCar\n";
    }

    // Параметризованный конструктор
    ElectricCar(const std::string& make, const std::string& model, int year, int batteryCapacity)
        : Car(make, model, year), batteryCapacity(batteryCapacity) {
        std::cout << "Parameterized constructor called for ElectricCar\n";
    }

    // Конструктор копирования
    ElectricCar(const ElectricCar& other) : Car(other), batteryCapacity(other.batteryCapacity) {
        std::cout << "Copy constructor called for ElectricCar\n";
    }

    // Оператор присваивания копированием
    ElectricCar& operator=(const ElectricCar& other) {
        std::cout << "Copy assignment operator called for ElectricCar\n";
        if (this != &other) {
            Car::operator=(other);
            batteryCapacity = other.batteryCapacity;
        }
        return *this;
    }

    // Деструктор
    ~ElectricCar() {
        std::cout << "Destructor called for ElectricCar\n";
    }

    // Переопределение функции drive
    void drive() const override {
        std::cout << "Driving " << getMake() << " " << getModel() << " " << getYear()
                  << " with a battery capacity of " << batteryCapacity << " kWh\n";
    }
};

// Функция для тестирования полиморфизма
void testDrive(const Car& car) {
    car.drive(); // Вызов полиморфной функции drive
}

int main() {
    // Создание вектора указателей на объекты Car
    std::vector<Car*> garage;

    // Добавление различных машин в гараж
    garage.push_back(new SportsCar("Ferrari", "F8", 2022, 340));
    garage.push_back(new ElectricCar("Tesla", "Model S", 2021, 100));

    // Прохождение по гаражу и тестирование каждой машины
    for (const auto& car : garage) {
        testDrive(*car); // Вызов полиморфной функции drive
    }

    // Очистка памяти
    for (auto& car : garage) {
        delete car; // Вызов деструктора
    }

    return 0;
}
