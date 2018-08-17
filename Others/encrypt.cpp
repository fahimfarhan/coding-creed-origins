/* C++ Program - Encrypt File */
		
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	clrscr();
	char fname[20], ch, choice;
	fstream fps, fpt;
	cout<<"Enter file name (with extension like file.txt) to encrypt : ";
	gets(fname);
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening file..!!";
		cout<<"\nPress any key to exit...";
		getch();
		exit(1);
	}
	fpt.open("temp.txt")
	if(!fpt)
	{
		cout<<"Error in creating temp.txt file..!!";
		fps.close();
		cout<<"\nPress any key to exit...";
		getch();
		exit(2);
	}
	while(fps.eof()==0)
	{
		fps>>ch;
		ch=ch+100;
		fpt<<ch;
	}
	fps.close();
	fpt.close();
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening source file..!!";
		cout<<"\nPress any key to exit...";
		getch();
		exit(3);
	}
	fpt.open("temp.txt");
	if(!fpt)
	{
		cout<<"Error in opening temp.txt file...!!";
		fps.close();
		cout<<"\nPress any key to exit...";
		getch();
		exit(4);
	}
	while(fpt.eof()==0)
	{
		fpt>>ch;
		fps<<ch;
	}
	cout<<"File "<<fname<<" encrypted successfully..!!";
	cout<<"\nPress any key to exit...";
	fps.close();
	fpt.close();
	getch();
}
