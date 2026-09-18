#include<iostream>
using namespace std;
int main()
{     
    int queue[5];     
    int front = 0;     
    int rear = 0;           
    
    cout << "Enter 5 customer order numbers:\n";      
    
    for (int i = 0; i < 5; i++)     
    {         
        cin >> queue[rear];         
        rear++;     
    }           
    cout << "\nProcessing Orders:\n";      
    while (front < rear)     
    {         
        cout << "Processing Order: " << queue[front] << endl;         
        front++;     
    }      
    return 0; 
}

Output:

Enter 5 customer order numbers:
2546
57435
3574
548
534

Processing Orders:
Processing Order: 2546
Processing Order: 57435
Processing Order: 3574
Processing Order: 548
Processing Order: 534
