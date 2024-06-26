#include<iostream>
using namespace std;
#define key 5
void printMat(int row,int col,char mat[][key]) {
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col ; j++)  {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main() {
    string pt1,pt,ct;    system("cls");
    cout<<"Enter P.T : ";
    getline(cin,pt1);
    int n = pt1.size();
    // cout<<"\n n = "<<n;
    for(int i = 0 ; i < n ; i++)
    {
        if(pt1[i]==' ')
            continue;
        pt.push_back(pt1[i]);
    }

    cout<<"\nPT = "<<pt;
    n=pt.size();
    int pkey[key];
    int row = (n/key)+1;
    // cout<<"\nrow = "<<row<<"\tcol = "<<key<<endl;
    char mat[row][key];
    char EncMat[row][key];
    cout<<"\nEnter Permutaion key (key) : ";
    for(int i = 0 ; i < key ; i++)
    {
        cin>>pkey[i];
    }
    cout<<"\nP.T : "<<pt;
    cout<<"\nPermutaion key : \n";
    for(int i = 0 ; i < key ; i++)
    {
        cout<<pkey[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0 ; i < key ; i++)
    {
        cout<<"| ";
    }
    cout<<"\n";
    for(int i = 0 ; i < key ; i++)
    {
        cout<<i<<" ";
    }

    for(int i = 0 ; i<row*key ; i++)
    {
        if(i<n)
            mat[i/key][i%key] = pt[i];
        else    
            mat[i/key][i%key] = '-';
            
    }
    cout<<"\nMatrix after PT : \n";
    printMat(row,key,mat);
    // for(int i = 0 ; i < row ; i++)
    // {
    //     for(int j = 0 ; j < key ; j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int k = 0;
    for(int i : pkey)
    {
        i--;
        for(int j = 0 ; j < key ; j++)
        {
            EncMat[j][k] = mat[j][i];
        }
        k++;
    }
    cout<<"\nMatrix after Encryption is : \n";
    printMat(row,key,EncMat);

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < row ; j++)
        {
            ct.push_back(EncMat[i][j]);
        }
    }
    cout<<"\nC.T : "<<ct;
    return 0;
}


/*
The Simple Columnar Transposition Cipher is a classical encryption method that
 rearranges plaintext characters into a grid based on a user-defined key, which
  determines the column order. The ciphertext is generated by reading the columns
   in the specified key order. Although easy to understand and implement, it offers
    limited security due to vulnerability to frequency analysis. Longer keys enhance 
    security but can be less practical. This cipher has historical significance in military
     and diplomatic communications but is not recommended for modern secure communication.

     The Hybrid Transposition Technique is a cryptographic method that combines
      transposition and substitution operations. It uses a permutation key to 
      rearrange matrix columns, enhancing security. While offering complexity
       and customization, it is primarily suited for educational or custom
        encryption needs, not providing the same security as modern 
        encryption methods.
*/