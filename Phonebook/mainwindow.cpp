#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Подключение сигналов и слотов
    connect(ui->addcontactButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->deletecontactButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
    connect(ui->searchcontactButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);

    // Загрузка контактов из файла при запуске
    loadContacts();
}

MainWindow::~MainWindow() {
    // Сохранение контактов в файл перед закрытием приложения
    saveContacts();
    delete ui;
}

// Слот для обработки нажатия кнопки "Add Contact"
void MainWindow::on_addButton_clicked() {
    QString name = ui->Namearea->text();
    QString phone = ui->Numberarea->text();
    QString email = ui->emailarea->text();

    Contact contact(name, phone, email);
    contactList_.addContact(contact);

    // Добавление контакта в список отображения
    ui->contactList->addItem(contact.getName() + " - " + contact.getPhone() + " - " + contact.getEmail());

    // Очистка полей ввода
    ui->Namearea->clear();
    ui->Numberarea->clear();
    ui->emailarea->clear();
}

// Слот для обработки нажатия кнопки "Remove Contact"
void MainWindow::on_removeButton_clicked() {
    QString name = ui->Namearea->text();
    contactList_.removeContact(name);

    // Обновление списка отображения
    ui->contactList->clear();
    for (const auto &contact : contactList_) {
        ui->contactList->addItem(contact.getName() + " - " + contact.getPhone() + " - " + contact.getEmail());
    }

    // Очистка полей ввода
    ui->Namearea->clear();
    ui->Numberarea->clear();
    ui->emailarea->clear();
}

// Слот для обработки нажатия кнопки "Search Contact"
void MainWindow::on_searchButton_clicked() {
    QString name = ui->Namearea->text();
    Contact contact = contactList_.searchContact(name);

    if (!contact.getName().isEmpty()) {
        ui->Numberarea->setText(contact.getPhone());
        ui->emailarea->setText(contact.getEmail());
    } else {
        ui->Numberarea->clear();
        ui->emailarea->clear();
    }
}

// Метод для сохранения контактов в файл
void MainWindow::saveContacts() {
    QFile file("contacts.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const auto &contact : contactList_) {
            out << contact.getName() << "," << contact.getPhone() << "," << contact.getEmail() << "\n";
        }
    }
}

// Метод для загрузки контактов из файла
void MainWindow::loadContacts() {
    QFile file("contacts.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QStringList contactData = in.readLine().split(",");
            if (contactData.size() == 3) {
                Contact contact(contactData[0], contactData[1], contactData[2]);
                contactList_.addContact(contact);
                ui->contactListWidget->addItem(contact.getName() + " - " + contact.getPhone() + " - " + contact.getEmail());
            }
        }
    }
}

