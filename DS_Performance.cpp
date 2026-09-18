// Student Performance & Ranking Management System:

#include <iostream>
 using namespace std;

  int main()
   {
     int rollNo[5];
      cout << "Enter Roll Numbers of 5 students:\n";
       for (int i = 0; i < 5; i++)
        {
             cin >> rollNo[i];
        }
        cout << "\nStudent Roll Numbers:\n";

        for (int i = 0; i < 5; i++)
       {
            cout << rollNo[i] << endl;
    }
    return 0;
} 
Output:
Enter Roll Numbers of 5 students:
21
11
08
41
16

Student Roll Numbers:
21
11
8
41
16
