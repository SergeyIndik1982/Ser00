#include "Contact.h" // Подключение заголовочного файла Contact.h

// Определение конструктора класса Contact
Contact::Contact(const QString &name, const QString &phone, const QString &email)
    : name_(name), phone_(phone), email_(email) {}

// Определение метода getName() для получения имени контакта
QString Contact::getName() const {
    return name_;
}

// Определение метода setName() для установки имени контакта
void Contact::setName(const QString &name) {
    name_ = name;
}

// Определение метода getPhone() для получения номера телефона контакта
QString Contact::getPhone() const {
    return phone_;
}

// Определение метода setPhone() для установки номера телефона контакта
void Contact::setPhone(const QString &phone) {
    phone_ = phone;
}

// Определение метода getEmail() для получения email контакта
QString Contact::getEmail() const {
    return email_;
}

// Определение метода setEmail() для установки email контакта
void Contact::setEmail(const QString &email) {
    email_ = email;
}
