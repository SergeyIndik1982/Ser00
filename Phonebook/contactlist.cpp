#include "ContactList.h" // Подключение заголовочного файла ContactList.h

// Определение метода addContact() для добавления контакта в список
void ContactList::addContact(const Contact &contact) {
    contacts_.push_back(contact); // Добавление контакта в конец вектора
}

// Определение метода removeContact() для удаления контакта из списка по имени
void ContactList::removeContact(const QString &name) {
    // Удаление контакта, если его имя совпадает с заданным
    contacts_.erase(std::remove_if(contacts_.begin(), contacts_.end(),
                                   [&name](const Contact &contact) { return contact.getName() == name; }),
                    contacts_.end());
}

// Определение метода searchContact() для поиска контакта в списке по имени
Contact ContactList::searchContact(const QString &name) const {
    // Поиск контакта с заданным именем
    auto it = std::find_if(contacts_.begin(), contacts_.end(),
                           [&name](const Contact &contact) { return contact.getName() == name; });

    // Если контакт найден, вернуть его, иначе вернуть пустой контакт
    return (it != contacts_.end()) ? *it : Contact();
}
