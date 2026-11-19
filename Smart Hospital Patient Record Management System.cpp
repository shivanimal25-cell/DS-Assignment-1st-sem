
#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    Patient* next;
};

struct HashNode {
    int id;
    Patient* patient;
    HashNode* next;
};

Patient* head = NULL;
HashNode* table[10] = {NULL};

int hashFunction(int id) {
    return id % 10;
}

void registerPatient(int id, string name, int age) {
    Patient* p = new Patient{id, name, age, head};
    head = p;

    int index = hashFunction(id);
    HashNode* h = new HashNode{id, p, table[index]};
    table[index] = h;

    cout << "Patient registered successfully!\n";
}

void searchPatient(int id) {
    int index = hashFunction(id);
    HashNode* h = table[index];

    while (h != NULL) {
        if (h->id == id) {
            cout << "ID: " << h->patient->id
                 << "\nName: " << h->patient->name
                 << "\nAge: " << h->patient->age << endl;
            return;
        }
        h = h->next;
    }
    cout << "Patient not found!\n";
}

void updatePatient(int id, string name, int age) {
    int index = hashFunction(id);
    HashNode* h = table[index];

    while (h != NULL) {
        if (h->id == id) {
            h->patient->name = name;
            h->patient->age = age;
            cout << "Patient updated!\n";
            return;
        }
        h = h->next;
    }
    cout << "Patient not found!\n";
}

void dischargePatient(int id) {
    Patient* p = head;
    Patient* prev = NULL;

    while (p != NULL && p->id != id) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Patient not found!\n";
        return;
    }

    if (prev == NULL)
        head = p->next;
    else
        prev->next = p->next;

    int index = hashFunction(id);
    HashNode* h = table[index];
    HashNode* hp = NULL;

    while (h != NULL && h->id != id) {
        hp = h;
        h = h->next;
    }

    if (h != NULL) {
        if (hp == NULL)
            table[index] = h->next;
        else
            hp->next = h->next;
        delete h;
    }

    delete p;
    cout << "Patient discharged!\n";
}

void displayPatients() {
    Patient* p = head;

    while (p != NULL) {
        cout << "ID: " << p->id
             << " Name: " << p->name
             << " Age: " << p->age << endl;
        p = p->next;
    }
}

int main() {
    int choice, id, age;
    string name;

    do {
        cout << "\n1.Register Patient";
        cout << "\n2.Update Patient";
        cout << "\n3.Discharge Patient";
        cout << "\n4.Display Patients";
        cout << "\n5.Search Patient";
        cout << "\n0.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID, Name and Age: ";
            cin >> id >> name >> age;
            registerPatient(id, name, age);
            break;

        case 2:
            cout << "Enter ID, Name and Age: ";
            cin >> id >> name >> age;
            updatePatient(id, name, age);
            break;

        case 3:
            cout << "Enter Patient ID: ";
            cin >> id;
            dischargePatient(id);
            break;

        case 4:
            displayPatients();
            break;

        case 5:
            cout << "Enter Patient ID: ";
            cin >> id;
            searchPatient(id);
            break;
        }
    } while (choice != 0);

    return 0;
}
