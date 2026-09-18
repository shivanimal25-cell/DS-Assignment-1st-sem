#include <iostream> 
using namespace std;

int main() 
{     
    int stack[5];     
    int top = -1;   

    cout << "Enter 5 served customer token numbers:\n";

    for (int i = 0; i < 5; i++)     
    {         
        top++;
        cin >> stack[top];     
    }   

    cout << "\n===== SERVICE HISTORY =====\n";
          
    while (top >= 0)     
    {         
        cout << "Token: " << stack[top] << endl;         
        top--;     
    }      
    return 0; 
}

Output:
Enter 5 served customer token numbers:
9
7
5
5
3

===== SERVICE HISTORY =====
Token: 3
Token: 5
Token: 5
Token: 7
Token: 9
