/* C++ Program - Decrypt File */
		
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
void main()
{
	clrscr();
	char ch, choice, fname[20];
	fstream fps, fpt;
	cout<<"Enter file name (with extension like file.txt) which you have encrypted earlier to decrypt : ";
	gets(fname);
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening source file..!!";
		cout<<"\nPress any key to exit...";
		getch();
		exit(7);
	}
	fpt.open("temp.txt");
	if(!fpt)
	{
		cout<<"Error in opening temp.txt file..!!";
		fps.close();
		cout<<"\nPress any key to exit...";
		getch();
		exit(9);
	}
	while(fpt.eof()==0)
	{
		fpt>>ch;
		ch=ch-100;
		fps<<ch;
	}
	cout<<"File "<<fname<<" decrypted successfully..!!";
	cout<<"\nPress any key to exit...";
	fps.close();
	fpt.close();
	getch();
}
