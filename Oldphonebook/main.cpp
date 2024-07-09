#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool bookmarked;

    Contact(std::string n, std::string p, std::string nn) : name(n), phoneNumber(p), nickname(nn), bookmarked(false) {}
};

class Phonebook {
private:
    std::vector<Contact> contacts;

public:
    void addContact() {
        std::string name, phoneNumber, nickname;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Phone Number (unique): ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickname);

        if (std::any_of(contacts.begin(), contacts.end(), [&phoneNumber](const Contact& c) { return c.phoneNumber == phoneNumber; })) {
            std::cerr << "Phone number already exists. Contact not added.\n";
            return;
        }

        contacts.emplace_back(name, phoneNumber, nickname);
        std::cout << "Contact added successfully.\n";
    }

    void listContacts() {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". " << contacts[i].name << " (" << contacts[i].nickname << ")\n";
        }
    }

    void searchContact() {
        listContacts();
        std::cout << "Enter contact index to view details: ";
        int index;

        if (index < 1 || index > contacts.size()) {
            std::cerr << "Invalid index.\n";
            return;
        }
        const Contact& c = contacts[index - 1];
        std::cout << "Name: " << c.name << "\nPhone Number: " << c.phoneNumber << "\nNickname: " << c.nickname << "\n";
        std::cout << "Do you want to bookmark this contact? (yes/no): ";
        std::string response;
        std::cin.ignore();
        std::getline(std::cin, response);
        if (response == "yes") {
            contacts[index - 1].bookmarked = true;
            std::cout << "Contact bookmarked.\n";
        }
    }

    void removeContact() {
        std::cout << "Remove by (1) Index or (2) Phone Number? Enter 1 or 2: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            listContacts();
            std::cout << "Enter contact index to remove: ";
            int index;
            std::cin >> index;
            if (index < 1 || index > contacts.size()) {
                std::cerr << "Invalid index.\n";
                return;
            }
            contacts.erase(contacts.begin() + index - 1);
            std::cout << "Contact removed.\n";
        } else if (choice == 2) {
            std::cout << "Enter phone number to remove: ";
            std::string phoneNumber;
            std::cin.ignore();
            std::getline(std::cin, phoneNumber);
            auto it = std::remove_if(contacts.begin(), contacts.end(), [&phoneNumber](const Contact& c) { return c.phoneNumber == phoneNumber; });
            if (it != contacts.end()) {
                contacts.erase(it, contacts.end());
                std::cout << "Contact removed.\n";
            } else {
                std::cerr << "Phone number not found.\n";
            }
        } else {
            std::cerr << "Invalid choice.\n";
        }
    }

    void listBookmarkedContacts() {
        bool anyBookmarked = false;
        for (const auto& c : contacts) {
            if (c.bookmarked) {
                std::cout << "Name: " << c.name << "\nPhone Number: " << c.phoneNumber << "\nNickname: " << c.nickname << "\n\n";
                anyBookmarked = true;
            }
        }
        if (!anyBookmarked) {
            std::cout << "No bookmarked contacts.\n";
        }
    }
};

int main() {
    Phonebook phonebook;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "REMOVE") {
            phonebook.removeContact();
        } else if (command == "BOOKMARK") {
            phonebook.listBookmarkedContacts();
        } else if (command == "EXIT") {
            break;
        } else if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        } else {
            std::cerr << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}
