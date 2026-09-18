#include<iostream>
using namespace std;
int main()
{
    int rollNo[5];
    int searchRoll;
    cout << "Enter Roll Numbers of 5 students:\n";
    
    for (int i = 0; i < 5; i++)
    {
       cin >> rollNo[i];
    }
     cout << "\nEnter Roll Number to search: ";
     cin >> searchRoll;

     bool found = false;

     for (int i = 0; i < 5; i++)
     {
        if (rollNo[i] == searchRoll)
        {
            found = true; 
        }
    }

    if (found)
    {
         cout << "Student Found!";
    }
    else
    {
         cout << "Student Not Found!";
    }

     return 0;
}

Output:                      
Enter Roll Numbers of 5 students:
925
567
001
961
333

Enter Roll Number to search: 001
Student Found!
                       
Enter Roll Numbers of 5 students:
925
567
001
961
333

Enter Roll Number to search: 999
Student Not Found!

