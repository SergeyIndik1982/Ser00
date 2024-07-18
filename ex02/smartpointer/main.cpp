#include <iostream> // Подключение библиотеки для ввода/вывода
#include <memory>   // Подключение библиотеки для работы с умными указателями
#include <vector>   // Подключение библиотеки для работы с контейнером вектор
#include <string>   // Подключение библиотеки для работы со строками

// Базовый класс Part, представляющий часть автомобиля
class Part {
public:
    virtual void print() = 0; // Чисто виртуальная функция для вывода информации о части
    virtual ~Part() = default; // Виртуальный деструктор для правильного удаления объектов производных классов
};

// Производный класс Engine, представляющий двигатель
class Engine : public Part {
public:
    void print() override { // Переопределение функции print() для вывода информации о двигателе
        std::cout << "Engine part\n";
    }
};

// Производный класс Wheel, представляющий колесо
class Wheel : public Part {
public:
    void print() override { // Переопределение функции print() для вывода информации о колесе
        std::cout << "Wheel part\n";
    }
};

// Производный класс Brake, представляющий тормоз
class Brake : public Part {
public:
    void print() override { // Переопределение функции print() для вывода информации о тормозе
        std::cout << "Brake part\n";
    }
};

// Производный класс Transmission, представляющий трансмиссию
class Transmission : public Part {
public:
    void print() override { // Переопределение функции print() для вывода информации о трансмиссии
        std::cout << "Transmission part\n";
    }
};

// Класс Car, представляющий автомобиль, содержащий части автомобиля
class Car {
public:
    // Конструктор класса Car, принимающий название модели автомобиля
    Car(std::string model) : model_(model) {
        engine_ = std::make_unique<Engine>(); // Инициализация умного указателя на двигатель
        for (int i = 0; i < 4; ++i) { // Инициализация 4-х колес и 4-х тормозов с помощью умных указателей
            wheels_.emplace_back(std::make_unique<Wheel>());
            brakes_.emplace_back(std::make_unique<Brake>());
        }
        transmission_ = std::make_unique<Transmission>(); // Инициализация умного указателя на трансмиссию
    }

    // Метод для вывода информации о всех частях автомобиля
    void printParts() {
        std::cout << "Car model: " << model_ << "\n"; // Вывод названия модели автомобиля
        engine_->print(); // Вывод информации о двигателе
        for (const auto& wheel : wheels_) { // Вывод информации о каждом колесе
            wheel->print();
        }
        for (const auto& brake : brakes_) { // Вывод информации о каждом тормозе
            brake->print();
        }
        transmission_->print(); // Вывод информации о трансмиссии
    }

private:
    std::string model_; // Название модели автомобиля
    std::unique_ptr<Engine> engine_; // Умный указатель на объект двигателя
    std::vector<std::unique_ptr<Wheel>> wheels_; // Вектор умных указателей на объекты колес
    std::vector<std::unique_ptr<Brake>> brakes_; // Вектор умных указателей на объекты тормозов
    std::unique_ptr<Transmission> transmission_; // Умный указатель на объект трансмиссии
};

int main() {
    Car myCar("Tesla Model S"); // Создание объекта автомобиля с названием модели "Tesla Model S"
    myCar.printParts(); // Вызов метода для вывода информации о частях автомобиля

    return 0; // Завершение программы
}
