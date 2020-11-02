//Write a recursive program to find factorial of a given number
#include <iostream>

using namespace std;
int fact(int n)
{
    if(n==1)
        return 1;
    else
        return(n*fact(n-1));
}
int main()
{
   int n;
   cout<<"******* To find the factorial of a given number *******"<<endl<<endl;
   cout<<"Enter a positive integer "<<endl;
   cin>>n;
   cout<<"factorial number of "<<n<<" is "<<fact(n)<<endl;
}
