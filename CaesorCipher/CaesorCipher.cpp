#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
	printf("\nPr_01 :Additive Caesor Cipher (With Variable Key)\n\n");
	printf("\nEnter the Plain Text : ");
	scanf("%s",&st);
	printf("\nEnter the Key : ");
	scanf("%d",&key);
	if(key<0||key>25){
		printf("\nInvalid Range \n");
		exit(0);
	}
	for(i = 0 ; st[i]!='\0';i++){
		if(st[i]<91 && st[i]>64)
			printf("%c",65+(st[i]-65+key)%26);
		else if(st[i]<123 && st[i]>96)
			printf("%c",97+(st[i]-97+key)%26);
	}
	for(i = 0 ; i < 26 ;  i++)
		arr[i]=65+i;
}
void CaesorCipher(){
	char arr[26],st[100];
	int i=0;
	printf("\nPr_01 : Caesor Cipher (With key k = 3)\n\n");
	for(i = 0 ; i < 26 ;  i++) 
		arr[i]=65+i;
	printf("\nEnter the Plain Text : ");
	scanf("%s",&st);
	printf("\nCipher Text = ");
	for(i = 0 ; st[i]!= '\0' ;i++){
		if(st[i]>87 && st[i]<91 || st[i]>119 && st[i]<123)
			printf("%c",st[i]-23);
		else
			printf("%c",st[i]+3);
	}
}
int main() {
	int choice;
	printf("Name : Aadarsh Jain\nRoll No.17 , Batch : A2\n\n");//\nDate : 07-08-2023\n\n");
	printf("\n1.Caesor Cipher \n2.Additive Caesor Cipher\n ");
	printf("Enter your choise : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			CaesorCipher();
			break;
		case 2:
			AdditiveCaesorCipher();
			break;
		default:
			printf("\nWrong Choise\n");
	}
	return 0;
}