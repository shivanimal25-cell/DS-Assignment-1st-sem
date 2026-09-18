#include <iostream> 
using namespace std;  
int main() 
{     
    int stack[5];     
    int top = -1;      
    
    cout << "Enter 5 cancelled order numbers:\n";
    for (int i = 0; i < 5; i++)     
    {         
        cin >> stack[++top];     
    }      
    cout << "\nRecently Cancelled Orders:\n";      
    while (top >= 0)     
    {         
        cout << stack[top] << endl;         
        top--;     
    }      
    return 0; 
}

Output:

Enter 5 cancelled order numbers:
564
543
354
633
666

Recently Cancelled Orders:
666
633
354
543
564
