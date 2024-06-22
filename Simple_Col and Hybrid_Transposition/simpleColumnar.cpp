#include <iostream>
using namespace std;
#define key 5

int main()
{
    string pt,ct;
    cout<<"\nEnter the PlainText : ";
    cin>>pt;
    int n = pt.size();
    int rows = n/key + 1;
    cout<<"\nrows = "<<rows<<"\tcol = "<<key<<endl;
    int cnt = 0,k=0;
    char mat[rows][key];
    for(int i = 0 ; i<n ; i++)
    {
        mat[i/key][i%key] = pt[i];
    }
    cnt = 0;
    cout<<"\nMatrix after init is : \n";
    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < key && cnt<n ; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    int m = (key*rows)-n;
    // int random[]={2,5,3,1,4};
    for(int i = 0 ; i < key ; i++)      //5
    // for(int i : random)
    {
        // i--;
        if(i==key-m)
        {
            rows--;
        }
        for(int j = 0 ; j < rows ; j++)     //4
        {
            ct.push_back(mat[j][i]);

        }
    }
    cout<<"CT : "<<ct;
    return 0;
}