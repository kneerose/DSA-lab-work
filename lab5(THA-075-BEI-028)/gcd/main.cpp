//Write a recursive program to find Greatest Common Division GCD of two numbers
#include <iostream>
int gcd(int n1,int n2)
{
    if(n2!=0)
        return gcd(n2,n1%n2);
    else
        return n1;
}
using namespace std;

int main()
{
    int n1,n2;
    cout<<"******* To find Greatest common divisor of two given number*******"<<endl<<endl;
    cout<<"Enter 1st number: \t";
    cin>>n1;
    cout<<"Enter 2nd number: \t";
    cin>>n2;
    cout<<"Greatest common divisor of "<<n1<<" and " <<n2 <<" is "<<gcd(n1,n2)<<endl;

}
