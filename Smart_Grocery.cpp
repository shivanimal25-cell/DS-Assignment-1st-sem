#include <iostream>
using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    float price;
    int quantity;
    int expiry;
};

int main()
{
    Product p[50];
    int n = 0;
    int choice;

    do
    {
        cout << "\n\n===== SMART GROCERY INVENTORY =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display Products";
        cout << "\n3. Search Product";
        cout << "\n4. Update Product";
        cout << "\n5. Delete Product";
        cout << "\n6. Sort by Price";
        cout << "\n7. Sort by Quantity";
        cout << "\n8. Sort by Expiry Date";
        cout << "\n9. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        // Add Product
        if (choice == 1)
        {
            cout << "\nEnter Product ID: ";
            cin >> p[n].id;

            cout << "Enter Product Name: ";
            cin >> p[n].name;

            cout << "Enter Category: ";
            cin >> p[n].category;

            cout << "Enter Price: ";
            cin >> p[n].price;

            cout << "Enter Quantity: ";
            cin >> p[n].quantity;

            cout << "Enter Expiry Date (YYYYMMDD): ";
            cin >> p[n].expiry;

            n++;

            cout << "Product Added!";
        }

        // Display Products
        else if (choice == 2)
        {
            cout << "\n===== PRODUCT RECORDS =====\n";

            for (int i = 0; i < n; i++)
            {
                cout << "\nProduct ID: " << p[i].id;
                cout << "\nName: " << p[i].name;
                cout << "\nCategory: " << p[i].category;
                cout << "\nPrice: " << p[i].price;
                cout << "\nQuantity: " << p[i].quantity;
                cout << "\nExpiry: " << p[i].expiry << endl;
            }
        }

        // Search Product
        else if (choice == 3)
        {
            int searchID;
            string searchName;
            bool found = false;

            cout << "\nEnter Product ID to search: ";
            cin >> searchID;

            for (int i = 0; i < n; i++)
            {
                if (p[i].id == searchID)
                {
                    cout << "\nProduct Found!";
                    cout << "\nName: " << p[i].name;
                    cout << "\nCategory: " << p[i].category;
                    cout << "\nPrice: " << p[i].price;
                    cout << "\nQuantity: " << p[i].quantity;
                    cout << "\nExpiry: " << p[i].expiry;

                    found = true;
                }
            }

            if (!found)
                cout << "\nProduct Not Found!";
        }

        // Update Product
        else if (choice == 4)
        {
            int id;
            bool found = false;

            cout << "\nEnter Product ID to update: ";
            cin >> id;

            for (int i = 0; i < n; i++)
            {
                if (p[i].id == id)
                {
                    cout << "Enter New Price: ";
                    cin >> p[i].price;

                    cout << "Enter New Quantity: ";
                    cin >> p[i].quantity;

                    cout << "Enter New Expiry Date: ";
                    cin >> p[i].expiry;

                    cout << "Product Updated!";
                    found = true;
                }
            }

            if (!found)
                cout << "Product Not Found!";
        }

        // Delete Product
        else if (choice == 5)
        {
            int id;
            bool found = false;

            cout << "\nEnter Product ID to delete: ";
            cin >> id;

            for (int i = 0; i < n; i++)
            {
                if (p[i].id == id)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        p[j] = p[j + 1];
                    }

                    n--;
                    cout << "Product Deleted!";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Product Not Found!";
        }

        // Sort by Price
        else if (choice == 6)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (p[j].price > p[j + 1].price)
                    {
                        Product temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
                    }
                }
            }

            cout << "\nProducts sorted by Price!";
        }

        // Sort by Quantity
        else if (choice == 7)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (p[j].quantity > p[j + 1].quantity)
                    {
                        Product temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
                    }
                }
            }

            cout << "\nProducts sorted by Quantity!";
        }

        // Sort by Expiry Date
        else if (choice == 8)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (p[j].expiry > p[j + 1].expiry)
                    {
                        Product temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
                    }
                }
            }

            cout << "\nProducts sorted by Expiry Date!";
        }

        // Exit
        else if (choice == 9)
        {
            cout << "\nThank you!";
        }

        else
        {
            cout << "\nInvalid Choice!";
        }

    } while (choice != 9);

    return 0;
}