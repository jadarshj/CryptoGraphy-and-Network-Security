#include<iostream>
using namespace std;

void printarr(char *arr,int n){
	int i = 0;
	printf("\nThe array is : \n");
	for(i = 0 ; i < n ;  i++)
		printf("%c  ",arr[i]);
	printf("\n\n");
	for(i = 0 ; i < n ; i++) {
		if(i>22)
			printf("%c  ",arr[i%22]);
		else
			printf("%c  ",arr[i+3]);
	}
}
void AdditiveCaesorCipher() {
	char arr[26]; 		//creating a character array
	char st[100];		//creating string
	int i=0,key;		//declaring variables and key
	printf("\nPr_01 :Additive Caesor Cipher (With Variable Key and bruteforce)\n\n");
	printf("\nEnter the Plain Text : ");
	scanf("%s",&st);

	// printf("\nEnter the Key : ");
	// scanf("%d",&key);
	// if(key<0||key>25){
	// 	printf("\nInvalid Range \n");
	// 	exit(0);
	// }
for(key = 1;key<26 ; key++)
{
    cout<<endl<<key<<"\t";
	for(i = 0 ; st[i]!='\0';i++){
		if(st[i]<=90 && st[i]>=65)
			printf("%c",65+(st[i]-65+key)%26);
		else if(st[i]<=122 && st[i]>=97)
			printf("%c",97+(st[i]-97+key)%26);
	}
}
	// for(i = 0 ; i < 26 ;  i++)
	// 	arr[i]=65+i;
}


int main()
{
    AdditiveCaesorCipher();
    return 0;
}