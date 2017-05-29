#include<iostream>
#include<fstream>
#include<string.h>

#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<math.h>

using namespace std;

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int search()
{
	int i;
	char user[20];
	char pname[20];
	int PNO;
	int prodID;
	int flag=0;
	int length;
	float rate;
	double quantity;
	cout<<"enter end to exit"<<endl;
	cout<<"SEARCH :"<<endl;
	cin>>user;
	fstream stock_file("cpp-home.txt",ios::app | ios::in | ios::out);
	length=strlen(user);
	while(stock_file>>PNO>>pname>>rate>>quantity)
	{
		if(strcmp(user,"end")==0)
		{
		
		   return 1;
	     }
	     else
	     {
	     for(i=0;i<strlen(pname);i++)
	     {
	     	user[i]=toupper (user[i]);
	     	pname[i]=toupper (pname[i]);
	     	
		 }
		 if(strncmp(user,pname,length)==0)
		 {
		 	flag=1;
		 	int namelength=strlen (pname);
		 	if(namelength<6)
		 	{
		 
		 	cout<<endl<<PNO<<endl<<pname<<rate<<quantity;
		 }
		 }
	     }
	}


if(flag==1)
return 0;
else
{
	return search();
}
}

int main()
{
	search();
	return 0;
}
