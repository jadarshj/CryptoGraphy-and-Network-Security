#include<iostream>
using namespace std;
int main() {
    int r1,r2,n1,n2;
    cout<<"\nEnter Two Numbers : ";
    cin>>n1>>n2;
    if(n1>n2)    {
        r1 = n1;
        r2 = n2;
    }
    else    {
        r1 = n2;
        r2 = n1;
    }
    cout<<"\nq\tr1\tr2\tr";
    while(r2>0)
    {
        int q = r1/r2;
        int r = r1%r2;
        r1 = r2;        r2 = r;
        cout<<"\n"<<q<<"\t"<<r1<<"\t"<<r2<<"\t"<<r;
    }
    cout<<"\nGCD("<<n1<<","<<n2<<") = "<<r1<<"\n";
    return 0;
}