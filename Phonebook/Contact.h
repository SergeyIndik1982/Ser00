#ifndef CONTACT_H
#define CONTACT_H

#include <QString> // Подключение класса QString для работы со строками

// Класс Contact, представляющий контакт в телефонной книге
class Contact {
public:
    // Конструктор с параметрами по умолчанию
    Contact(const QString &name = "", const QString &phone = "", const QString &email = "");

    // Геттер для получения имени контакта
    QString getName() const;

    // Сеттер для установки имени контакта
    void setName(const QString &name);

    // Геттер для получения номера телефона контакта
    QString getPhone() const;

    // Сеттер для установки номера телефона контакта
    void setPhone(const QString &phone);

    // Геттер для получения email контакта
    QString getEmail() const;

    // Сеттер для установки email контакта
    void setEmail(const QString &email);

private:
    QString name_; // Переменная для хранения имени контакта
    QString phone_; // Переменная для хранения номера телефона контакта
    QString email_; // Переменная для хранения email контакта
};

#endif // CONTACT_H
