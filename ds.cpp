#include<iostream>
using namespace std;
int main()
{
    int a=2, b=3 ,temp;
    cout<<"Before swapping: a="<<a<<" b="<<b<<endl;

    temp=a;
    a=b;
    b=temp;
    cout<<"After swapping: a="<<a<<" b="<<b<<endl;
    return 0;
}