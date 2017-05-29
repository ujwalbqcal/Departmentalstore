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
	int a=0,i=0;
	int j=6;
	int k;
	int PNO ;
	int prodID;	
	char user_input[20];		
	char pname[20];
	int length;	//length of the user input		
	float rate;
	double quantity;
	int flag=0;
	for(k=3;k<=9;k++)
	{
		gotoxy(25,k);cout<<("                                                                           ");
	}
	gotoxy(25,4);cout<<"Type 'end' to end the calculation";
	
	gotoxy(25,5);cout<<"S E A R C H:";
	cin>>user_input;
	gotoxy(25,j);cout<<"                                 ";
	fstream stock_file("cpp-home.txt",ios::app | ios::in |ios::out); //seek to the end of stream before each write
											   	 		 			 //open for reading
																	 //open for writing
	length=strlen(user_input);
	while(stock_file>>PNO>>pname>>rate>>quantity)
		{
			if(strcmp(user_input,"end")==0)
			return 1;
			else
			{
			
				for(i=0;i<strlen(pname);i++)
				{
					user_input[i]=toupper(user_input[i]);											//this loop is to capitalize the user given string and the string in the txt file so that there is no issue in finding the product
					pname[i]=toupper(pname[i]);
				}
				if(strncmp(user_input,pname,length)==0)						//comparing two string upto "length" character
					{
						flag=1;
						gotoxy(55,5);cout<<"                      ";
						int namelength=strlen(pname);
						if(namelength>6)
						{
							gotoxy(25,j);cout << PNO << "\t\t\t"<<pname<<"\t\t\t"<<rate<<"\t\t"<<quantity<<endl;							//if the character matches then they are displayed with all the info including prod ID
							j++;
						}
						else if(namelength<=6)
						{
							gotoxy(25,j);cout << PNO << "\t\t\t"<<pname<<"\t\t\t\t"<<rate<<"\t\t"<<quantity<<endl;
							j++;
						}
					}
				
			}
		}
		if(flag==1)
		{
			return 0;
		}
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
