#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void print(char text[])
{
for(int i=0; text[i]!='\0'; i++)
	cout << text[i];
cout << endl;
}

void encrypt(char str[], char key[])
{
for(int i=0, j=0; str[i]!='\0'; i++,j++)
{
	int ascii = key[j]-40;
	if(str[i]==' ')
		str[i] = '*';
	else if(i%2==0)
		str[i] -= ascii;
	else
		str[i] += ascii;

	if(j==strlen(key)-1)
		j=-1;

}
}

void decrypt(char str[], char key[])
{
for(int i=0, j=0; str[i]!='\0'; i++,j++)
{
	int ascii = key[j]-40;
	if(str[i]=='*')
		str[i] = ' ';
	else if(i%2==0)
		str[i] += ascii;
	else
		str[i] -= ascii;

	if(j==strlen(key)-1)
		j = -1;

}
}

void main()
{
clrscr();
char istring[80], ostring[80], pass[80], spare[80], repeat;

int choice;
do
{
	clrscr();
	cout << "Choose: \n1. Encrypt \n2. Decrypt " << endl;
	cin >> choice;

	if(choice==1)
	{
		cout << "Enter the text : ";
		gets(istring);
		cout << "Enter the password : ";
		gets(pass);
		encrypt(istring, pass);
		strcpy(spare, istring);
		cout << "\n\nEncrypted text is : ";
		print(istring);
	}
	else if(choice==2)
	{
		decrypt(spare, pass);
		print(spare);
		cout << "Enter the text : ";
		gets(ostring);
		cout << "Enter the password : ";
		gets(pass);
		decrypt(ostring, pass);
		print(ostring);
	}

	cout << "Do you wish to continue? (y/n)";
	cin >> repeat;
}while(repeat=='y');

}