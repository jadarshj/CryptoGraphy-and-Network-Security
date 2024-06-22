#include<bits/stdc++.h>
using namespace std;

int CheckBinary(string st,int i , int j)
{
    int z=0,o=0;
    for(int k = i ; k < j ; k++)
    {
        if(st[k] == '0')
            z++;
        if(st[k] == '1')
            o++;
    }
    if(j-i == o+z && j-i > 3)
    {
        //cout<<"yes its binary :) "<<endl;
        return 1;
    }
    else
    {
        //cout<<"Its not a binary :( "<<endl;
        return 0;
    }
}
int ConvertDecimal(string st,int i , int j)
{
    
     int num = 0;
     for(;i<j;i++)
     {
        num = num*10+(st[i]-48);
     }
     return num;
}
int CheckValidation(string st,int i,int j,int count)
{
    int flag=0,b,num=0;
    if(st[i] == '0')
    {
        cout<<"Leading zero's exists at Cell-"<<count<<endl;
        return 1;
    }
    b = CheckBinary(st,i,j);
    if(b==1)
    {
        cout<<"Cell "<<count<<" is Binary Notation instead of Decimal Notaion"<<endl;
        flag = 1;
        return 2;
    }
    num = ConvertDecimal(st,i,j);
    if(num>255)
    {
        cout<<"Cell "<<count<<" is out of Range "<<endl;
        flag = 1;
        return 3;
    }
    if(flag == 0)
        return 0;
    else 
        return 1;
}

int main()
{   
    string IP;
    char x ;
    system("cls");
    cout<<"Name : Aadarsh Jain \t Roll No. : 17"<<endl<<"Batch : A2 \t Date : 03-02-2023"<<endl;
    cout<<"AIM : Implement a program to validate if it is IPv4 address or Not."<<endl<<endl;
    // cout<<"Case 4) IPv4 address string should have exactly 4 cells "<<endl<<endl;
    cout<<"Enter IP Address : ";
    cin>>IP;
    // cout<<"you Entered "<<IP<<endl;
    // cout<<"IP size = "<<IP.size()<<endl;
    int i=0,j=0,count=0,res,flag=0;
    for(i=0;IP[i]!='\0' && i<IP.size();i++)
    {
        j = i;
        //printf("IP[j] = %d\n",IP[j]-48);
        while(IP[j]<58 && IP[j]>47){
            j++;
        }
        //cout<<"(i,j) = ("<<i<<","<<j<<")"<<endl;
        if(IP[j]<48 || IP[j]>57)        //Valid
        {
            if(IP[j] == '.'  ||j == IP.size()){            
                count++;
                x = IP[j];
                //cout<<"count = "<<count<<endl;
            }
            else{       //Invalid
                x = IP[j];                
                count++;
                cout<<"IP Address is Seperated by "<<x<<" after Cell-"<<count;
                cout<<" at index = "<<j<<endl;            
                flag = 1;  //Invalid
            }
            res = CheckValidation(IP,i,j,count);    //0 => no error
        }        
        //cout<<"x = "<<x<<endl;
        while(IP[j]!=x)// || IP[j]!=x)  // || IP[j]<48 || IP[j]>57)
        {
            j++;
        }
        i = j;

        if(res == 1 || res == 2 || res == 3)
        {
            //cout<<"IP Address entered by the user is Invalid at cell No. "<<count<<endl;
            flag = 1;
        }
    }
        if(count>4)
        {
            cout<<"IP Address Contains more then 4 cells"<<endl;
            flag = 1;
        }
        if(count<4)
        {
            cout<<"IP Address Contains less then 4 cells"<<endl;
            flag = 1;
        }
        //cout<<"flag = "<<flag<<endl;
        if(flag == 0)
        {
            cout<<endl<<"VALID IP Address :)"<<endl<<endl;
            //cout<<count<<" th cell is Vaild Cell :)"<<endl;
        }
        
        if(flag == 1)
        {
            cout<<endl<<"INVALID IP Address :( "<<endl<<endl;
            //cout<<count<<" th cell is Vaild Cell :)"<<endl;
        }

        //cout<<"count = "<<count<<endl;
        
    return 0;
}