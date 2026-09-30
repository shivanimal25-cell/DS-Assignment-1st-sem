#include <iostream>
using namespace std;

// Normal Queue
int queueArr[10];
int front = 0;
int rear = 0;

// Stack for resolved requests
int stackArr[10];
int top = -1;

// Priority Queue
int priorityQueue[10];
int priority[10];
int pCount = 0;


// Recursive IVR Menu
void IVR()
{
    int choice;

    cout << "\n\n===== IVR SUPPORT =====";
    cout << "\n1. Billing Support";
    cout << "\n2. Technical Support";
    cout << "\n3. General Enquiry";
    cout << "\n4. Exit";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nBilling Support Selected.";
        IVR();
    }
    else if (choice == 2)
    {
        cout << "\nTechnical Support Selected.";
        IVR();
    }
    else if (choice == 3)
    {
        cout << "\nGeneral Enquiry Selected.";
        IVR();
    }
    else if (choice == 4)
    {
        cout << "\nIVR Ended.";
    }
    else
    {
        cout << "\nInvalid Choice!";
        IVR();
    }
}


int main()
{
    int choice;

    do
    {
        cout << "\n\n===== CUSTOMER SERVICE SYSTEM =====";
        cout << "\n1. Add Customer Call";
        cout << "\n2. Process Normal Call";
        cout << "\n3. Add Urgent Request";
        cout << "\n4. Process Urgent Request";
        cout << "\n5. Add Resolved Request to History";
        cout << "\n6. View Recent Resolved Request";
        cout << "\n7. Start IVR";
        cout << "\n8. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;


        // Normal Queue
        if (choice == 1)
        {
            if (rear < 10)
            {
                cout << "\nEnter Customer Call Number: ";
                cin >> queueArr[rear];

                rear++;

                cout << "Call Added to Queue!";
            }
            else
            {
                cout << "Queue is Full!";
            }
        }


        // Process Normal Call
        else if (choice == 2)
        {
            if (front < rear)
            {
                cout << "\nProcessing Call: "
                     << queueArr[front];

                front++;
            }
            else
            {
                cout << "\nNo Calls Waiting!";
            }
        }


        // Add Urgent Request
        else if (choice == 3)
        {
            if (pCount < 10)
            {
                cout << "\nEnter Request Number: ";
                cin >> priorityQueue[pCount];

                cout << "Enter Priority (1 = Highest): ";
                cin >> priority[pCount];

                pCount++;

                cout << "Urgent Request Added!";
            }
            else
            {
                cout << "Priority Queue is Full!";
            }
        }


        // Process Highest Priority Request
        else if (choice == 4)
        {
            if (pCount == 0)
            {
                cout << "\nNo Urgent Requests!";
            }
            else
            {
                int highest = 0;

                for (int i = 1; i < pCount; i++)
                {
                    if (priority[i] < priority[highest])
                    {
                        highest = i;
                    }
                }

                cout << "\nProcessing Urgent Request: "
                     << priorityQueue[highest];

                // Remove request
                for (int i = highest; i < pCount - 1; i++)
                {
                    priorityQueue[i] = priorityQueue[i + 1];
                    priority[i] = priority[i + 1];
                }

                pCount--;
            }
        }


        // Add Resolved Request to Stack
        else if (choice == 5)
        {
            if (top < 9)
            {
                cout << "\nEnter Resolved Request Number: ";
                cin >> stackArr[++top];

                cout << "Request Added to History!";
            }
            else
            {
                cout << "History Stack is Full!";
            }
        }


        // View Latest Resolved Request
        else if (choice == 6)
        {
            if (top >= 0)
            {
                cout << "\nLatest Resolved Request: "
                     << stackArr[top];
            }
            else
            {
                cout << "\nNo Resolved Requests!";
            }
        }


        // Recursive IVR
        else if (choice == 7)
        {
            IVR();
        }


        // Exit
        else if (choice == 8)
        {
            cout << "\nThank you!";
        }


        else
        {
            cout << "\nInvalid Choice!";
        }

    } while (choice != 8);

    return 0;
}