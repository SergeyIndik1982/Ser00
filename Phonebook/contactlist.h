#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <vector>
#include <QString>

class ContactList {
public:
    void addContact(const Contact &contact);
    void removeContact(const QString &name);
    Contact searchContact(const QString &name) const;

private:
    std::vector<Contact> contacts_;
};

#endif // CONTACTLIST_H
