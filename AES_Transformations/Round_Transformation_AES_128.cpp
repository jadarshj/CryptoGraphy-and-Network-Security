#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
void printstate(int r , int c , string state[]) 
{
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cout<<state[i*r+j]<<" ";
        }
        cout<<endl;
    }
}
void rotate(string state[],int c,int s,int e)
{
    while(s<=e)
    {
        string temp = state[s];
        state[s] = state[e];
        state[e] = temp;
        s++;
        e--;
    }
}
void ShiftCol(string state[],int x,int c)
{
    int s = c*x;
    int e = c*(x+1)-1; //included
    rotate(state,c,s,s+x-1);
    rotate(state,c,s+x,e);
    rotate(state,c,s,e);    
}
void ShiftRows()
{
    int r,c;
    cout<<"\nEnter the No.of rows : ";
    cin>>r;
    cout<<"\nEnter the No.of cols : ";
    cin>>c;
    string state[r*c];
    cout<<"\nEnter the State Matrix : \n";
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cout<<"state["<<i<<"]["<<j<<"] = ";
            cin>>state[r*i+j];
        }
    }
    cout<<"\nState Matrix is : \n";
    printstate(r,c,state);
    for(int i = 1 ; i < c ; i++)
    {
        ShiftCol(state,i,c);
    }
    cout<<"\nTransformed : ShiftRows : \n";
    printstate(r,c,state);
}
char inttostr(int x);
string findBin4Bit(char ch)
{
    string s;
    int x=ch;
    if(x<58 && x>47)
    {
        x = x-48;
    }
    else
    {
        if(x>64 && x<71)
        {
            x = x-55;
        }
    }
    // cout<<"\n x = "<<x<<endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(x%2==0)
            s.push_back('0');
        else
            s.push_back('1');
        x/=2;
    }
    swap(s[0],s[3]);
    swap(s[1],s[2]);
    return s;
}
string RemoveDuplicates(string b,string temp)
{        
    string ans;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            int flag = 0;
            for(int j = 0 ; j < b.size() ; j++)
            {
                if(b[j]==temp[i])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                ans.push_back(temp[i]);
            }
        }
        // cout<<"\nIntermediate ans : "<<ans;
        for(int i = 0 ; i < b.size() ; i++)
        {
            int flag = 0;
            for(int j = 0 ; j < temp.size() ; j++)
            {
                if(temp[j]==b[i])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                ans.push_back(b[i]);
            }
        }
        return ans;
}
string transform(string m,string s)
{
    string a,st,b;
    st=findBin4Bit(s[0]);
    st.append(findBin4Bit(s[1]));
    // cout<<"\nst = "<<st<<endl;
    for(int i = 0 ; i < 8 ; i++)
    {
        if(st[i]=='1')
        {
            char c2 = 48+(7-i);
            b.push_back(c2);
        }
    }
    // cout<<"\nb = "<<b<<endl;
    if(m=="1")
    {
        
        // cout<<"\nm=1 , st = "<<st<<endl;
        return st;
        // a = "0";
    }
    if(m=="2")
    {
        a = "1";
        for(int i = 0 ; i < b.size() ; i++)
        {
            b[i]+=1;
        }
        // cout<<"\nm=2 , b = "<<b<<endl;

    }
    else if(m=="3")
    {
        a = "10";
        string temp = b;
        for(int i = 0 ; i < b.size() ; i++)
        {
            b[i]+=1;
        }
        // cout<<"\nm=3 , b = "<<b<<endl;
        b = RemoveDuplicates(b,temp);
    }
    sort(b.begin(),b.end(),greater<int>());
    if(b[0]=='8')
    {
        string temp = "84310";
        b = RemoveDuplicates(b,temp);
    }
    // cout<<"\nFinal Sorted b = "<<b<<endl;
    bool hash[]={0,0,0,0,0,0,0,0};
    int ns = b.size();
    // cout<<"\nns = "<<ns<<endl;
    for(int i = 0 ; i < ns ; i++)
    {        
        hash[7-(b[i]-48)]=1;        
    }
    string finalres;
    // cout<<"\n Hash = ";
    for(int i = 0 ; i < 8 ; i++)
    {
        // cout<<hash[i]<<" ";
        if(hash[i]==0)
            finalres.push_back('0');
        else
            finalres.push_back('1');
    }    
    // cout<<"\nfinalres : "<<finalres<<endl;
    return finalres;
}
string BinToHexa(string res)
{
    string ans;
    int a = 0,b = 0;
    for(int i = 3 ; i >= 0 ; i--)
    {
        if(res[i]=='1')
        {
            a+=pow(2,3-i);
        }
        if(res[4+i]=='1')
        {
            b+=pow(2,3-i);

        }
    }
    ans.push_back(inttostr(a));
    ans.push_back(inttostr(b));
    return ans;
}
string stringXor(string a,string b)
{
    string result;
    for (int i = 0; i < 8; ++i) {
        if (a[i] == '0' && b[i] == '0' || a[i] == '1' && b[i] == '1') {
            result += '0';
        } else {
            result += '1';
        }
    }
    return result;
}
void MixColumns()
{
    int r,c;
    cout<<"\nEnter the No.of rows : ";
    cin>>r;
    cout<<"\nEnter the No.of cols : ";
    cin>>c;
    string state[r*c];
    string mat[]={"2","3","1","1","1","2","3","1","1","1","2","3","3","1","1","2"};
    cout<<"\nEnter the State Matrix : \n";
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cout<<"state["<<i<<"]["<<j<<"] = ";
            cin>>state[r*i+j];
        }
    }
    cout<<"\nState Matrix is : \n";
    printstate(r,c,state);
    //code goes here
    string ans[16],res;
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            res="00000000";
            for(int k = 0 ; k < 4 ; k++)
            {
                string temp1 = transform(mat[4*i+k],state[r*k+j]);
                // cout<<"\ntemp1 = "<<temp1;
                res = stringXor(res,temp1);
                
            }
            // cout<<"\n res = "<<res<<endl;
            ans[4*i+j]=BinToHexa(res);
            // cout<<"\n ans[4*"<<i<<"+"<<j<<"] : "<<ans[4*i+j]<<endl;
        }
        
    }    
    cout<<"\n Ans Matrix is : \n";
    printstate(r,c,ans);
}
int strtoint(char ch)
{
    int i = ch;
    // cout<<"\n i = "<<i<<endl;
    if(i>47 && i<58)
    {
        // cout<<"\nBw 0 to 9 \n";
        return i-48;
    }
    if(ch>64 && ch<71)
    {
        // cout<<"\nBw 65 to 71 \n";
        return i-55;
    }
    return -1;
}
char inttostr(int x)
{
    if(x>=0 && x<=9)
    {
        return '0'+x;
    }
    if(x>=10 && x<=15)
    {
        return 55+x;
    }
    return '_';
}
void AddRoundKey()
{
    int r,c;
    cout<<"\nFor State Matrix : \n";
    cout<<"\nEnter the No.of rows : ";
    cin>>r;
    cout<<"\nEnter the No.of cols : ";
    cin>>c;
    string state[r*c];
    cout<<"\nEnter the State Matrix : \n";
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cout<<"state["<<i<<"]["<<j<<"] = ";
            cin>>state[r*i+j];
        }
    }
    cout<<"\nState Matrix is : \n";
    printstate(r,c,state);
    string Key[r*c];
    cout<<"\nEnter the Key Matrix : \n";
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cout<<"Key["<<i<<"]["<<j<<"] = ";
            cin>>Key[r*i+j];
        }
    }
    cout<<"\nKey Matrix is : \n";
    printstate(r,c,Key);
    //code goes here
    string ans[r*c];
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {            
            int a = strtoint(Key[r*i+j][0]);
            int b = strtoint(Key[r*i+j][1]);
            int c = strtoint(state[r*i+j][0]);
            int d = strtoint(state[r*i+j][1]);
            string temp;            
            temp.push_back(inttostr(a^c));
            temp.push_back(inttostr(b^d));
            ans[r*i+j] = temp;
        }
    }
    cout<<"\nAns Matrix is : \n";
    printstate(r,c,ans);
}
int main() {
    int ch;
    while(1)    {
        cout<<"\n1. ShiftRows Transformation.";
        cout<<"\n2. MixColumns Transformation.";
        cout<<"\n3. AddRoundKey Transformation.";
        cout<<"\n0. Exit .";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch (ch) {
        case 0:
            exit(0);        
        case 1:
            ShiftRows();
            break;

        case 2:
            MixColumns();
            break;

        case 3:
            AddRoundKey();
            break;
        default:
            cout<<"\nInvalid Choice !";
            break;
        }        
    }
    return 0;
}
/*
PS E:\7th SEM\CNS\PR_06> cd "e:\7th SEM\CNS\PR_06\" ; if ($?) { g++ pr_06.cpp -o pr_06 } ; if ($?) { .\pr_06 }

1. ShiftRows Transformation.
2. MixColumns Transformation.
3. AddRoundKey Transformation.
0. Exit .
Enter Your Choice : 1

Enter the No.of rows : 4

Enter the No.of cols : 4

Enter the State Matrix : 
state[0][0] = 87
state[0][1] = F2
state[0][2] = 4D
state[0][3] = 97
state[1][0] = 6E
state[1][1] = 4C
state[1][2] = 90
state[1][3] = EC
state[2][0] = 46
state[2][1] = E7
state[2][2] = 4A
state[2][3] = C3
state[3][0] = A6
state[3][1] = 8C
state[3][2] = D8
state[3][3] = 95

State Matrix is :
87 F2 4D 97
6E 4C 90 EC
46 E7 4A C3
A6 8C D8 95

Transformed : ShiftRows :
87 F2 4D 97
4C 90 EC 6E
4A C3 46 E7
95 A6 8C D8

*/
/*
PS E:\7th SEM\CNS\PR_06> cd "e:\7th SEM\CNS\PR_06\" ; if ($?) { g++ pr_06.cpp -o pr_06 } ; if ($?) { .\pr_06 }

1. ShiftRows Transformation.  
2. MixColumns Transformation. 
3. AddRoundKey Transformation.
0. Exit .
Enter Your Choice : 2

Enter the No.of rows : 4

Enter the No.of cols : 4

Enter the State Matrix :
state[0][0] = 87
state[0][1] = F2
state[0][2] = 4D
state[0][3] = 97
state[1][0] = 6E
state[1][1] = 4C
state[1][2] = 90
state[1][3] = EC
state[2][0] = 46
state[2][1] = E7
state[2][2] = 4A
state[2][3] = C3
state[3][0] = A6
state[3][1] = 8C
state[3][2] = D8
state[3][3] = 95

State Matrix is :
87 F2 4D 97
6E 4C 90 EC
46 E7 4A C3
A6 8C D8 95

 Ans Matrix is :
47 40 A3 4C
37 D4 70 9F
94 E4 3A 42
ED A5 A6 BC

*/
/*
PS E:\7th SEM\CNS\PR_06> cd "e:\7th SEM\CNS\PR_06\" ; if ($?) { g++ pr_06.cpp -o pr_06 } ; if ($?) { .\pr_06 }

1. ShiftRows Transformation.  
2. MixColumns Transformation. 
3. AddRoundKey Transformation.
0. Exit .
Enter Your Choice : 3

For State Matrix :     

Enter the No.of rows : 4

Enter the No.of cols : 4

Enter the State Matrix : 
state[0][0] = AC
state[0][1] = 19
state[0][2] = 28
state[0][3] = 37
state[1][0] = 77
state[1][1] = FA
state[1][2] = D1
state[1][3] = 5C
state[2][0] = 66
state[2][1] = DC
state[2][2] = 29
state[2][3] = 00
state[3][0] = F3
state[3][1] = 21
state[3][2] = 41
state[3][3] = 6A

State Matrix is :
AC 19 28 37
77 FA D1 5C
66 DC 29 00
F3 21 41 6A

Enter the Key Matrix :
Key[0][0] = 47
Key[0][1] = 40
Key[0][2] = A3
Key[0][3] = 4C
Key[1][0] = 37
Key[1][1] = D4
Key[1][2] = 70
Key[1][3] = 9F
Key[2][0] = 94
Key[2][1] = EF
Key[2][2] = 3A
Key[2][3] = 42
Key[3][0] = ED
Key[3][1] = A5
Key[3][2] = A6
Key[3][3] = BC

Key Matrix is : 
47 40 A3 4C
37 D4 70 9F
94 EF 3A 42
ED A5 A6 BC

Ans Matrix is :
EB 59 8B 7B
40 2E A1 C3
F2 33 13 42
1E 84 E7 D6

*/