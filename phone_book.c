#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone_number;
    Contact* next;
};

class Phonebook {
private:
    Contact* head;

public:
    Phonebook() {
        head = nullptr;
    }

    void add_contact(string name, string phone_number) {
        Contact* new_contact = new Contact;
        new_contact->name = name;
        new_contact->phone_number = phone_number;
        new_contact->next = nullptr;

        if (head == nullptr) {
            head = new_contact;
        }
        else {
            Contact* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_contact;
        }
        cout << "Contact added successfully!" << endl;
    }

    void delete_contact(string name) {
        if (head == nullptr) {
            cout << "Phonebook is empty!" << endl;
            return;
        }
        else if (head->name == name) {
            Contact* temp = head;
            head = head->next;
            delete temp;
            cout << "Contact deleted successfully!" << endl;
            return;
        }
        else {
            Contact* current = head;
            while (current->next != nullptr) {
                if (current->next->name == name) {
                    Contact* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    cout << "Contact deleted successfully!" << endl;
                    return;
                }
                current = current->next;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void update_contact(string name, string phone_number) {
        if (head == nullptr) {
            cout << "Phonebook is empty!" << endl;
            return;
        }
        else {
            Contact* current = head;
            while (current != nullptr) {
                if (current->name == name) {
                    current->phone_number = phone_number;
                    cout << "Contact updated successfully!" << endl;
                    return;
                }
                current = current->next;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void search_contact(string name) {
        if (head == nullptr) {
            cout << "Phonebook is empty!" << endl;
            return;
        }
        else {
            Contact* current = head;
            while (current != nullptr) {
                if (current->name == name) {
                    cout << "Name: " << current->name << endl;
                    cout << "Phone Number: " << current->phone_number << endl;
                    return;
                }
                current = current->next;
            }
        }
        cout << "Contact not found!" << endl;
    }
    void showw(){
            if (head == nullptr) {
            cout << "Phonebook is empty!" << endl;
            return;
        }
        else {
        Contact* current = head;
         while (current != nullptr){
             cout << "Name: " << current->name << " , ";
             cout << "Phone Number: " << current->phone_number << endl;
              current = current->next;}
     }

    }
};

int main() {
    Phonebook phonebook;
    string name, phone_number;
    int choice;

    do {
        cout << "Phonebook Application" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Search Contact" << endl;
        cout << "5. show list" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone_number;
                phonebook.add_contact(name, phone_number);
                break;

            case 2:
            cout << "Enter name: ";
            cin >> name;
            phonebook.delete_contact(name);
            break;

        case 3:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter new phone number: ";
            cin >> phone_number;
            phonebook.update_contact(name, phone_number);
            break;

        case 4:
            cout << "Enter name: ";
            cin >> name;
            phonebook.search_contact(name);
            break;
       case 5:
            phonebook.showw();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    cout << endl;

}while (choice != 6);
return 0;}

