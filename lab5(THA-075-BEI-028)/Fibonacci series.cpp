// Write a recursive program to find N terms Fibonacci series
#include <iostream>

using namespace std;
int fibo(int n)
{
    if(n==1)
        return 0;
    else if (n==2)
        return 1;
    else
        return (fibo(n-2)+fibo(n-1));
}
int main()
{
    int n;
    cout<<"******* To find the fibonacci series *******"<<endl<<endl;
    cout << "Enter the number of term you want "<<endl;
    cin>>n;
    cout<<"The fibonacci serious upto "<<n <<" terms are " <<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<fibo(i)<<endl;
    }
}
