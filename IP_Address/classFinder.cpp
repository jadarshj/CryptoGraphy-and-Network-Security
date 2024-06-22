#include<bits/stdc++.h>
using namespace std;
char CheckDecimalClass(string st){
    int num=0;
    char ch='\0';
    for(int i=0 ; st[i]!='\0' ;i++)    {
        if(st[i]=='.')
            break;
        num = num*10+(st[i]-48);
    }
    if(num>0)    {
        if(num<128)        {
            cout<<"Class A (Unicast) bcoz range of "<<num<<" is [0,127]"<<endl;
            ch = 'A';
        }
        if(num>127 && num<192)        {
            cout<<"Class B (Unicast) bcoz range of "<<num<<" is [128,191]"<<endl;
            ch = 'B';
        }
        if(num>191 && num<224 )        {
            cout<<"Class C (Unicast) bcoz range of "<<num<<" is [192,223]"<<endl;
            ch = 'C';
        }
        if(num > 223 && num<239)        {
            cout<<"Class D (Multicast) bcoz range of "<<num<<" is [224,239]"<<endl;
            ch = 'D';
        }
        if(num > 238 && num<256)        {
            cout<<"Class E (BroadCast) bcoz range of "<<num<<" is [240,255]"<<endl;
            ch = 'E';
        }
        if(num>255)    
            cout<<"\nOut of Range in CheckDecimalClass "<<endl;
    }
    else
        cout<<"\nOut of Range in CheckDecimalClass"<<endl;
    return ch;
}
char CheckBinaryClass(string st)   { //1010
    char ch = '\0';
    if(st[0]=='0')    {
        cout<<"Class A (Unicast) Class Id bits : 0"<<endl;
        ch = 'A';
    }
    if(st[0]=='1' && st[1] == '0')    {
        cout<<"Class B (Unicast) Class Id bits : 10"<<endl;
        ch = 'B';
    }
    if(st[0]=='1' && st[1] == '1' && st[2]=='0')    {
        cout<<"Class C (Unicast) Class Id bits : 110"<<endl;
        ch = 'C';
    }
    if(st[0]=='1' && st[1] == '1' && st[2]=='1' && st[3]=='0')    {
        cout<<"Class D (Multicast) Class Id bits : 1110"<<endl;
        ch = 'D';
    }
    if(st[0]=='1' && st[1] == '1' && st[2]=='1' && st[3]=='1')    {
        cout<<"Class E (BroadCast) Class Id bits : 1111"<<endl;    
        ch = 'E';
    }
    return ch;
}
char findClass(int inp,string st)
{
    char cls='\0';  //cls = class or find class
    if(inp == 1)    
        cls = CheckDecimalClass(st);        
    else if(inp == 2)    
            cls = CheckBinaryClass(st);    
    else    
        cls = '\0';
    return cls;
}
void findNet(string ip)    { //192.168.1.1
    char cls;
    string netid,hostid;
    int nidb=0,count=0,i=0;     //nitb = net Id bytes
    cls = CheckDecimalClass(ip);
    nidb = cls-'A'+1;      //cls-65+1;
    if(nidb>=1 && nidb<=3)    {
        //while not getting nitb-1 dots(.) print until then is the net id 
        for(i=0;ip[i]!='\0';i++)        {
            if(count==nidb)            
                break;            
            if(ip[i]=='.' )            {
                count++;
                cout<<".";
                netid.push_back('.');
                continue;
            }
            if(count<nidb)            {
                cout<<ip[i];
                netid.push_back(ip[i]);                
            }
        }
        for(;ip[i]!='\0';i++)        {
            hostid.push_back(ip[i]);
            if(ip[i]=='.')            {
                cout<<".";
                netid.push_back('.');                
            }                
            else            {
                cout<<"0";
                netid.push_back('0');
            }
        }        
        cout<<endl<<"net_id = "<<netid<<endl;
        cout<<endl<<"host_id = "<<hostid<<endl<<endl;
    }
    else if(nidb==4 || nidb==5)
        cout<<"since this IP Address belongs to class "<<cls<<" therefore can't find netid and hostid \n";
}
string masking(string st){
    string ip;
    int i = 0,num=0,dc=0;
    while(st[i]!= '/' && st[i]!='\0')
        i++;
    i++;
    num = 0;
    while(st[i]!='\0')    {
        num = num*10+st[i]-48;
        i++;
    }
    for(int j = 1 ; j <= 32+3 ; j++)    {
        if(j%9==0)        {
            ip.push_back('.');
            num++;
        }
        else {
            if(j<=num)
                ip.push_back('1');
            else
                ip.push_back('0');
        }
    }
    return ip;
}
int *BNtoDDN(string st)
{
    int k = 0,num=0;
    int *arr;
    arr = new int[4];
    string *str  = new string[4];
    for(int i = 0 ; st[i]!='\0' ; i++)    {
        if(st[i] == '.')        
            k++;        
        else
            str[k].push_back(st[i]);        
    }
    for(int  i = 0 ; i < 4 ; i++)    {
        num=0;
        for(int j = 0 ; j < 8 ; j++)        
            num = num + (str[i][j]-'0')*pow(2,7-j);        
        arr[i] = num;
    }
    return arr;
}
int *StringToDecimal(string st){
    int k = 0,num=0;
    int *arr = new int[4];
    for(int i = 0 ; st[i]!= '\0' && k<4; i++)    {
        if(st[i]=='.' || st[i]=='/')        {
            arr[k] = num;
            k++;
            num=0;
        }
        else
            num=num*10+st[i]-'0';
    }
    return arr;
}

void printBinaryofArr(int arr[],int n){
    int x,r,k=0,count=0;
    string s[4];
    for(int i = 0 ; i < n ; i++)    {
        x = arr[i];
        count=0;
        while(x>0)        {
            r = x%2;
            x=x/2;
            s[k].push_back(r+48);
            count++;
        }
        while(count<8)        {
            s[k].push_back('0');
            count++;
        }
        for(int i = 0 ; i<s[k].length()/2 ; i++)
            swap(s[k][i],s[k][s[k].length()-1-i]);        
        k++;
    }
    cout<<endl<<"\t\t\t";
    for(int i = 0 ; i < 4 ; i++)
        cout<<s[i]<<".";    
}
int main(){
    string st;          //Taking String Input for IP Address
    string ip1;         //catching function returned IP Address
    int inp,ntn;
    char IP,cls;
    cout<<"1.Identify the class of the IPv4 Address .\n";        
    cout<<"2.Identify the Network Address, Net_Id, Host_ID  .\n";   //Decimal only 
    cout<<"3.Calculation of \\n masking value for classless IPv4 Address.\n";  //
    cout<<"4.Calculate the First Address, Last Address and Total No. of addresses for given IPv4 Address(Classful and Classless)\n";
    cin>>inp;
    switch (inp){
    case 1:
        cout<<"1.DDN (Dotted Binary Notation)"<<endl;
        cout<<"2.BN (Binary Notation)"<<endl;
        cin>>ntn;
        cout<<"Enter The IP Address : ";
        cin>>st;        //192.168.10.12
        cls = findClass(ntn,st);
        break;
    case 2:
        cout<<"Enter The IP Address : ";        //Decimal Only
        cin>>st;        //192.168.10.12
        findNet(st);
        break;
    case 3:
        cout<<"Enter The IP Address : with /n ";        //Decimal Only
        cin>>st;        //192.168.10.12/8
        st = masking(st);
        cout<<"Mask = "<<st<<endl;
        break;
    case 4:
        cout<<"Enter The IP Address : with /n ";        //Decimal Only
        cin>>st;        //192.168.10.12\8
        int *mask,*iparr;  //ips=> IP Address Array
        ip1 = masking(st);
        mask = BNtoDDN(ip1);  //String of Binary Digits into array of DDN     //int value of mask
                                //mask array => mask[0]=255,mask[1] = 255,....
        cout<<endl<<"IP Address is : "<<endl;
        iparr = StringToDecimal(st);
        cout<<"\t\t\t";
        for(int i = 0 ; i < 4 ; i++)
            cout<<iparr[i]<<".";
        printBinaryofArr(iparr,4);
        cout<<endl<<endl<<"Mask is : "<<endl;
        cout<<"\t\t\t";
        for(int i = 0 ; i < 4 ; i++)
            cout<<mask[i]<<".";
        cout<<endl<<"\t\t\t"<<ip1<<endl;
        cout<<"\nFirst Address is "<<endl<<"\t\t\t";
        int farr[4];
        for(int i = 0 ; i < 4 ; i++)        {
            int a = mask[i];
            int b = iparr[i];
            farr[i]=(a&b);
            cout<<(a&b)<<".";
        }
        printBinaryofArr(farr,4);
        cout<<"\n\nLast Address is "<<endl<<"\t\t\t";
        for(int i = 0 ; i < 4 ; i++)        { 
            int a = mask[i];
            int b = iparr[i];
            farr[i]=(a|b);
            cout<<(a|b)<<".";
        }
        printBinaryofArr(farr,4);
        break;    
    default:
        cout<<"Invalid Choice !"<<endl;
        break;
    }
    return 0;
}