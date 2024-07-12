#include <iostream> // Подключение библиотеки для работы с вводом и выводом
#include <string>   // Подключение библиотеки для работы с типом данных std::string

// Базовый класс Car
class Car {
private:
    std::string make;  // Поле для хранения марки автомобиля
    std::string model; // Поле для хранения модели автомобиля
    int year;          // Поле для хранения года выпуска

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
        if (this != &other) { // Проверка на самоприсваивание
            make = other.make;   // Копирование марки
            model = other.model; // Копирование модели
            year = other.year;   // Копирование года выпуска
        }
        return *this; // Возврат текущего объекта
    }

    // Деструктор
    virtual ~Car() {
        std::cout << "Destructor called for Car\n";
    }

    // Метод для вождения
    virtual void drive() const {
        std::cout << "Driving " << make << " " << model << " " << year << "\n";
    }

    // Геттеры для make, model, year (чтобы можно было использовать их в производном классе)
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
};

// Производный класс SportsCar, наследующий от Car
class SportsCar : public Car {
private:
    int maxSpeed; // Поле для хранения максимальной скорости

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
        if (this != &other) { // Проверка на самоприсваивание
            Car::operator=(other); // Вызов оператора присваивания базового класса
            maxSpeed = other.maxSpeed;
        }
        return *this; // Возврат текущего объекта
    }

    // Деструктор
    ~SportsCar() {
        std::cout << "Destructor called for SportsCar\n";
    }

    // Переопределение метода drive
    void drive() const override {
        Car::drive(); // Вызов метода drive базового класса
        std::cout << " with a max speed of " << maxSpeed << " km/h\n";
    }
};

int main() {
    // Создание объекта Car с использованием параметризованного конструктора
    Car car1("Toyota", "Camry", 2021);
    car1.drive(); // Вызов метода drive для объекта car1

    // Создание объекта SportsCar с использованием параметризованного конструктора
    SportsCar sportsCar1("Ferrari", "F8", 2022, 340);
    sportsCar1.drive(); // Вызов метода drive для объекта sportsCar1

    // Создание объекта SportsCar с использованием конструктора копирования
    SportsCar sportsCar2 = sportsCar1;
    sportsCar2.drive(); // Вызов метода drive для объекта sportsCar2

    // Использование оператора присваивания копированием
    SportsCar sportsCar3;
    sportsCar3 = sportsCar1;
    sportsCar3.drive(); // Вызов метода drive для объекта sportsCar3

    // Программа завершает выполнение, деструкторы вызываются автоматически
    return 0;
}
