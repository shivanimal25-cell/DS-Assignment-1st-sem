
#include <iostream>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    Product* next;
};

struct HashNode {
    int id;
    Product* product;
    HashNode* next;
};

Product* head = NULL;
HashNode* table[10] = {NULL};

int hashFunction(int id) {
    return id % 10;
}

void addProduct(int id, string name, float price) {
    Product* p = new Product{id, name, price, head};
    head = p;

    int index = hashFunction(id);
    HashNode* h = new HashNode{id, p, table[index]};
    table[index] = h;

    cout << "Product added successfully!\n";
}

void searchProduct(int id) {
    int index = hashFunction(id);
    HashNode* h = table[index];

    while (h != NULL) {
        if (h->id == id) {
            cout << "ID: " << h->product->id
                 << "\nName: " << h->product->name
                 << "\nPrice: " << h->product->price << endl;
            return;
        }
        h = h->next;
    }
    cout << "Product not found!\n";
}

void updateProduct(int id, string name, float price) {
    int index = hashFunction(id);
    HashNode* h = table[index];

    while (h != NULL) {
        if (h->id == id) {
            h->product->name = name;
            h->product->price = price;
            cout << "Product updated!\n";
            return;
        }
        h = h->next;
    }
    cout << "Product not found!\n";
}

void removeProduct(int id) {
    Product* p = head;
    Product* prev = NULL;

    while (p != NULL && p->id != id) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Product not found!\n";
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
    cout << "Product removed!\n";
}

void displayProducts() {
    Product* p = head;

    while (p != NULL) {
        cout << "ID: " << p->id
             << " Name: " << p->name
             << " Price: " << p->price << endl;
        p = p->next;
    }
}

int main() {
    int choice, id;
    string name;
    float price;

    do {
        cout << "\n1.Add Product";
        cout << "\n2.Update Product";
        cout << "\n3.Remove Product";
        cout << "\n4.Display Products";
        cout << "\n5.Search Product";
        cout << "\n0.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID, Name and Price: ";
            cin >> id >> name >> price;
            addProduct(id, name, price);
            break;

        case 2:
            cout << "Enter ID, Name and Price: ";
            cin >> id >> name >> price;
            updateProduct(id, name, price);
            break;

        case 3:
            cout << "Enter Product ID: ";
            cin >> id;
            removeProduct(id);
            break;

        case 4:
            displayProducts();
            break;

        case 5:
            cout << "Enter Product ID: ";
            cin >> id;
            searchProduct(id);
            break;
        }
    } while (choice != 0);

    return 0;
}
