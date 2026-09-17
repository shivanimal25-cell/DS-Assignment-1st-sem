//Search for a Book:

#include <iostream>
using namespace std;

int main()
{
   int book[5];
   int searchID;

    cout << "Enter 5 Book IDs:\n";

    for (int i = 0; i < 5; i++)
    {
       cin >> book[i];
    }
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    for (int i = 0; i < 5; i++)
    {
       if (book[i] == searchID)
       {
            cout << "Book Found!";
            return 0;
       }
   }
    cout << "Book Not Found!";

    return 0;
}

Output:                    
Enter 5 Book IDs:
920
100
234
456
999

Enter Book ID to search: 234
Book Found!
                     
Enter 5 Book IDs:
920
100
234
456
999

Enter Book ID to search: 111
Book Not Found!

