#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<ctime>

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


using namespace std;

//menusss
void mainmenu();
void adminmenu();
void usermenu();

//functions required by password option
void new_userpass_check();
int userpass_check();
void modify_userpass();
void setup_userpass();
//functions for admin password maintanence
void new_adminpass_check();
int adminpass_check();
void modify_adminpass();
void setup_adminpass();


//to delete products
void delete_products();

//to calculate bill
void calculate();
int search();					//to search for product by their product name
void dbill();											//to display the framework of bill	
int check_quantity(int,int);			//to check 
int check_prodID();
void update_txt(int a, int b);


//to add goods option
int add_goods();
int check_code();				//to check the availability of productid

//to display the boxes
void windowone(int,int,int,int);
void windowtwo(int,int,int,int);
void windowthree(int,int,int);

//to display goods
void viewgoods();	


//to delete goods from txt file
void deleteGoods();

//to edit goods from txt file
void editGoods();

//for displaying time
int time(int x, int y);

//for transaction
void transaction();
void deleterecord();

int main()
{
	mainmenu();
	return 0;
}
void mainmenu()
{
	system("CLS");
	system("COLOR FC");
	system("title DEPARTMENTAL STORE SYSTEM");
	int a;
	windowtwo(29,52,13,21);
	gotoxy(33,15);
	cout<<"1.ADMINISTRATOR"<<endl;
	gotoxy(33,16);
	cout<<"2.USER"<<endl;
	gotoxy(33,17);
	cout<<"3.EXIT"<<endl;
	gotoxy(33,19);
	cout<<"OPTION ::";
	cin>>a;
	switch(a)
	{
		case 1:
			{
				adminmenu();
			}
				
				
		case 2:
			{
				usermenu();
			}
		
		case 3:
			{
				exit(0);
			}
	}
}


//admin menuu

void adminmenu()
{
	system("cls");
	system("COLOR FC");
	int b;
	b=adminpass_check();
	if(b==1)
	{
		int c;
		while(c!=8)
		{
			system("cls");
			windowtwo(28,60,13,22);
			{
			gotoxy(30,14);
			cout<<"1.MODIFY ADMIN PASSWORD"<<endl;
			gotoxy(30,15);
			cout<<"2.ADD ITEM"<<endl;
			gotoxy(30,16);
			cout<<"3.DISPLAY ALL ITEM"<<endl;
			gotoxy(30,17);
			cout<<"4.EDIT ITEM"<<endl;
			gotoxy(30,18);
			cout<<"5.DELETE ITEM"<<endl;
			gotoxy(30,19);
			cout<<"6.TODAY'S TRANSACTION"<<endl;
			gotoxy(30,20);
			cout<<"7.DELETE RECORD"<<endl;
			gotoxy(30,21);
			cout<<"8.RETURN"<<endl;
			}
			gotoxy(30,23);
			cout<<"OPTION::";
			cin>>c;
			switch(c)
			{		
				case 1 :
					{
						modify_adminpass();
						break;
					}
				
				case 2 :
					{
						add_goods();
						break;
					}
				case 3 :
					{
						viewgoods();
						
						break;
					}
				case 4:
					{
						editGoods();
						
						break;
					}
				case 5:
					{
						deleteGoods();
						
						break;
					}
				case 6:
					{
						transaction();
						
						break;
					}
				case 7:
					{
						deleterecord();
						break;
					}
				case 8:
					{
						mainmenu();
					}
			}
		}
	}
	else
	{
		system("cls");
		system("COLOR 47");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong password!";
		getch();
		return adminmenu();
	}
}

//user menu

void usermenu()
{
	int e,f;
	e=userpass_check();
	if(e==1)
		{
		while(f!=4)
		{
			system("cls");
	     	windowtwo(30,53,13,21);
			gotoxy(32,15);
			cout<<"1.CALCULATE BILL"<<endl;
			gotoxy(32,16);
			cout<<"2.DISPLAY ALL ITEMS"<<endl;
			gotoxy(32,17);
			cout<<"3.MODIFY PASSWORD"<<endl;
			gotoxy(32,18);
			cout<<"4.SEARCH"<<endl;
			gotoxy(32,19);
			cout<<"5.RETURN"<<endl;
			cout<<"\n";
			gotoxy(32,20);
			cout<<"OPTION::";
			cin>>f;
			system("cls");
			switch(f)
				{
					 case 1:
						{
							calculate();
							break;
						}
							
					case 2:
						{
							viewgoods();
							break;
						}
							
					case 3:
						{
							modify_userpass();
							break;	
							
						}
								
					case 4:
						{
							search();
							break;
							getch();
						}	
				    case 5:
				    	{
				    		mainmenu();
						}
				}
		}
					
		}
		else
		{
			system("cls");
			system("COLOR 47");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong password!";
			getch();
			return usermenu();
		}
}

//to delete records
void deleterecord()
{
	system("cls");
	char check;
	gotoxy(25,8);cout<<"ARE YOU SURE YOU WANT TO DELETE TODAY'S RECORD?(Y/N):";
	cin>>check;
	if(toupper(check)=='Y')
	{
	remove("record.txt");
	gotoxy(25,10);cout<<"RECORD SUCCESSFULLY DELETED! ! !";
	getch();
	}
	else
	{
		gotoxy(25,10);cout<<"RECORD WAS NOT DELETED! ! !";
		getch();
	}
}

//to display today's transaction
void transaction()
{
	system("cls");
	ifstream record("record.txt");
	string name;
	double bill;
	float total=0;
	cout<<"CUSTOMER NAME    " << "TOTAL AMOUNT" <<endl;
	while(record>>name>>bill)
	{
		cout<<name<<"\t\t\t"<<bill<<endl;
		total+=bill;
	}
	cout<<"\n\nTODAY'S TOTAL TRANSACTION = "<<total;
	getch();
}


/*function to display box*/
void windowone(int a,int b,int c,int d)
{
    int i;
    system("cls");
    gotoxy(28,5);
    cout<<" $ DEPARTMENTAL  STORE  MANAGEMENT  SYSTEM $ ";
    cout<<"\n\n";
    gotoxy(36,8);
    cout<<" Quality is what you need ";

    for (i=a; i<=b; i++)
    {
        gotoxy(i,17);
        cout<<"\xcd";
        gotoxy(i,19);
        cout<<"\xcd";
    }
    
    gotoxy(a,17);
    cout<<"\xc9";
    gotoxy(a,18);
    cout<<"\xba";
    gotoxy(a,19);
    cout<<"\xc8";
    gotoxy(b,17);
    cout<<"\xbb";
    gotoxy(b,18);
    cout<<"\xba";
    gotoxy(b,19);
    cout<<"\xbc";
}

void windowtwo(int a,int b,int c,int d)
	 {
	 	int i;
       system("cls");
      gotoxy(20,07);
      cout<<" $ DEPARTMENTAL STORE MANAGEMENT SYSTEM $ ";
      cout<<"\n\n";
      gotoxy(24,10);
      cout<<" * Quality is what you need * ";
	 	
    for (i=a; i<=b; i++)
    {
        gotoxy(i,c);
        cout<<"\xcd";
        gotoxy(i,d);
        cout<<"\xcd";
    }
    
    for(i=c; i<=d; i++)
      {
        gotoxy(a,i);
        cout<<"\xba";
        gotoxy(b,i);
        cout<<"\xba";
      }
    gotoxy(a,c);
    cout<<"\xc9";
    gotoxy(a,d);
    cout<<"\xc8";
    gotoxy(b,c);
    cout<<"\xbb";
    gotoxy(b,d);
    cout<<"\xbc";
}


void windowthree(int a, int b, int c)
{
	int i;
	 for (i=a; i<=b; i++)
    {
        gotoxy(i,c-1);
        cout<<"\xcd";
        gotoxy(i,c+1);
        cout<<"\xcd";
    }
    
    gotoxy(a,c-1);
    cout<<"\xc9";
    gotoxy(a,c);
    cout<<"\xba";
    gotoxy(a,c+1);
    cout<<"\xc8";
    gotoxy(b,c-1);
    cout<<"\xbb";
    gotoxy(b,c);
    cout<<"\xba";
    gotoxy(b,c+1);
    cout<<"\xbc";
	

}

//to search the product by their name

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
					
int check_prodID()
{
		int PNO ;
	int prodID;			
	char pname[20];		
	float rate;
	double quantity;
	int flag=0;
	gotoxy(25,10);cout<<"Enter the PRODUCUTID:";
	cin>>prodID;
	gotoxy(60,10);cout<<"                  ";

	ifstream stock("cpp-home.txt");
	while(stock>>PNO>>pname>>rate>>quantity)
	{
		if(PNO==prodID)
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		return prodID;
	}
	else
	{
		gotoxy(60,10);cout<<"(NO PRODUCTID!!!)";
		gotoxy(25,10);cout<<"                          ";
		return check_prodID();
	}
}				

//to calculate bill

void calculate()
{
	system("cls");
	int i=18,j=0;
	int number1=0;
	int PNO ;
	float total=0;
	char cusname[10];
	
	int prodID;				//given by user		
	char pname[20];
	int length;	//length of the user input		
	float rate;
	float price[50];
	double quantity;
	ifstream stock("cpp-home.txt");
	gotoxy(25,3);cout<<"CUSTOMER NAME:";
	cin>>cusname;
	
		while(1)
		{
			float multiple=0;
			float number=0;
			int a=0;
			dbill();
			gotoxy(25,10);cout<<"                                                    ";
			gotoxy(25,11);cout<<"                                                    ";
			a=search();
			if(a==1)
			{
				break;
			}
			else
			{
				prodID = check_prodID();

					gotoxy(25,11);cout<<"Enter the Quantity of the Product:";
					cin>>number;
					number1=check_quantity(prodID,number);
					ifstream stock("cpp-home.txt");
					while(stock>>PNO>>pname>>rate>>quantity)
					{
						if(prodID==PNO)
						{
							int namelength=strlen(pname);
							multiple=rate*number1;
							total+=multiple;
							if(namelength>6)
							{
								gotoxy(25,i);cout<<++j<<"\t\t"<<pname<<"\t\t"<<number1<<"\t\t\t"<<rate<<"\t\t"<<multiple;
								i++;
							}
							else if(namelength<=6)
							{
								gotoxy(25,i);cout<<++j<<"\t\t"<<pname<<"\t\t\t"<<number1<<"\t\t\t"<<rate<<"\t\t"<<multiple;
								i++;
							}
							update_txt(prodID,number1);
							break; 
						}
						
					}
			}
		}
		
	gotoxy(25,i+1);cout<<"TOTAL\t\t\t\t\t\t\t\t\t        ="<<total;
	gotoxy(25,i+3);cout<<"CUSTOMER NAME:"<<cusname;
	gotoxy(25,i+2);cout<<"BILLING BY: CS GROUP";
	fstream record("record.txt",ios::app);
	record<<cusname<<"\t\t "<<total<<endl ;
	getch();
	
}



//to update the file in case of quantity

void update_txt(int a, int b )
{
int PNO;
int result;
char prodid[20];
float rate;
int quantity;
int PNO1;
char prodid1[20];			//to be copied to temp.txt
float rate1;
int quantity1;


ifstream stock("cpp-home.txt");
ofstream stock_file("temp.txt");
while(stock>>PNO>>prodid>>rate>>quantity)
{
	if(a==PNO){
		int diff = quantity-b;
		stock_file<<PNO<<"\t"<<prodid<<"\t"<<rate<<"\t"<<diff<<endl;}
	else{
		stock_file<<PNO<<"\t"<<prodid<<"\t"<<rate<<"\t"<<quantity<<endl;
		}

}
stock.close();
stock_file.close();
	ifstream read("temp.txt");
	ofstream write("cpp-home.txt");
	while (read >> PNO >> prodid >> rate >> quantity){
		write << PNO << "\t" << prodid << "\t" << rate << "\t" << quantity << endl;
	}
}



//to check if the quantity is within we have
int check_quantity(int id,int a)
{
int i=0;
double b=0;
int c;	
int PNO;
char prodid[20];
float rate;
double quantity;
ifstream stock("cpp-home.txt");
while(stock>>PNO>>prodid>>rate>>quantity)
{
	if(id==PNO)
	{
		if(a<=quantity && a>0){
			gotoxy(45,11);cout<<"                                                ";
			return a;
		}else {
			gotoxy(65,11);cout<<"(QUANTITY GREATER THAN STOCK!!"; 
			gotoxy(25,11);cout<<"Enter the Quantity of the Product:";
			gotoxy(59,11);cout<<"      ";
			gotoxy(59,11);
 			cin>>b;
 			gotoxy(65,11);cout<<"                                                ";
 			return check_quantity(id,b);
			}
		}
	}
	return 0;
}

int time(int x, int y)
{
	time_t t= time(0);
	struct tm * now = localtime(&t);
	gotoxy(x,y);
	cout<<"Date: "<<now->tm_mon+1<<"/"<<now->tm_mday<<"/"<<now->tm_year+1900<<endl;
	gotoxy(x+70,y);
	cout<<"Time: "<<now->tm_hour<<":"<<now->tm_min<<":"<<now->tm_sec;
}




//to display bill
void dbill()
{
 int i;
 int j;
 
 gotoxy(50,13);cout<<("\tCUSTOMER'S BILL") ;
 time(25,14);
  for (i=24; i<=108; i++)
    {
        gotoxy(i,15);
        cout<<"\xcd";
        gotoxy(i,17);
        cout<<"\xcd";
    }
   	gotoxy(25,16);
	cout<<("SN.\t\tItem Name\t\tQuantity\t\tRate\t\tTotal");
	for(j=15;j<=17;j++)
	{
		gotoxy(24,j);
		cout<<"\xba";
		gotoxy(29,j);
		cout<<"\xba";
		gotoxy(58,j);
		cout<<"\xba";
		gotoxy(80,j);
		cout<<"\xba";
		gotoxy(96,j);
		cout<<"\xba";
		gotoxy(109,j);
		cout<<"\xba";
	}	
    gotoxy(24,15);
    cout<<"\xc9";
    gotoxy(24,17);
    cout<<"\xc8";
    gotoxy(29,15);
    cout<<"\xc9";
    gotoxy(29,17);
    cout<<"\xc8";
    gotoxy(58,15);
    cout<<"\xc9";
    gotoxy(58,17);
    cout<<"\xc8";
    gotoxy(80,15);
    cout<<"\xc9";
    gotoxy(80,17);
    cout<<"\xc8";
    gotoxy(96,15);
    cout<<"\xc9";
    gotoxy(96,17);
    cout<<"\xc8";
    gotoxy(109,15);
    cout<<"\xbb";
    gotoxy(109,17);
    cout<<"\xbc";
}




//to set the password for the first time
	
void setup_userpass()
{
	system("cls");
	system("color fc");
		int j=0,k=0,l=0;
		char pass_setuped[4];
		char retype_pass[4];
		gotoxy(25,12);cout<<"                                                                 ";
		gotoxy(45,3);
		cout<<"$ $ USER PASSWORD SETUP $ $";
		windowthree(45,75,6);
		gotoxy(46,6);
		cout<<"PASSWORD:";
		windowthree(45,75,9);
		gotoxy(46,9);
		cout<<"CONFIRM PASSWORD:";
		
		gotoxy(55,6);
		for(j=0;j<4;++j)
			{
				pass_setuped[j]=getch();		//to get the input and also display the typed alphabet in * form
				cout<<"*";
			}
		
		
		gotoxy(63,9);
		for(k=0;k<4;++k)
			{
				retype_pass[k]=getch();
				cout<<"*";
			}
			if(strcmp(pass_setuped,retype_pass)==0)
			{
				ofstream pass_setup;
				pass_setup.open("userpass.txt");
				for(l=0;l<4;++l)
				{
					
					pass_setup<<retype_pass[l];
				}
		
			}
			else
			{
				gotoxy(45,12);	cout<<"PASSWORDS NOT MATCHING!!!";
				getch();
				return setup_userpass();
			}
}
//to check the password at the beginning of the program
int userpass_check()
{	
	ifstream password;					//opened a file in read mode
	password.open("userpass.txt");
	if(password.is_open())
	{
		system("cls");
		system("color fc");
		string inpass;
		char user_pass[4];
		int i=0;
		gotoxy(45,6);
		cout<<"$ $ USER LOGIN $ $";
		windowthree(45,75,9);	
		gotoxy(46,9);cout<<"PASSWORD:";
			for(i=0;i<4;++i)
				{
					user_pass[i]=getch();		//to get the input and also display the typed alphabet in * form
					cout<<"*";
				}
			while(password>>inpass)			//comparing the pass from the file and the input file
			{
				if(inpass==user_pass)
				{
					return 1;
				}
				else
					return 0;
				password.close();			//closing the file
			}
	}
	else
	{
		setup_userpass();
		gotoxy(45,12);cout<<"                                                                          ";
		gotoxy(45,12);cout<<"PASSWORD SETUP COMPLETE!!";
		getch();
		return 1;		
	}
}
	


// to modify the password if user feels so


void modify_userpass()
{
	system("CLS");
	system("COLOR FC");
	string passw;
	char pass[4];
	int i=0,flag=0,j;
	gotoxy(45,6);
	cout<<"$ $ MODIFY USER PASSWORD $ $";
	windowthree(45,75,9);	
	gotoxy(46,9);
	cout<<"OLD PASSWORD:";
	windowthree(45,75,12);	
	gotoxy(46,12);
	cout<<"NEW PASSWORD:";
	windowthree(45,75,15);	
	gotoxy(46,15);
	cout<<"CONFIRM NEW PASSWORD:";
	gotoxy(59,9);
		for(i=0;i<4;++i)
			{
				pass[i]=getch();
				cout<<"*";
			}
		
		
		ifstream inpassword;
		inpassword.open("userpass.txt");		//opened pass.txt in read mode
		
		
		while(inpassword>>passw)			//for getting the pass from txt file we use this loop and syntax
			{
			if(passw==pass)
			{ 
				inpassword.close();
				gotoxy(80,9);cout<<"                        ";
				new_userpass_check();
				gotoxy(46,18);cout<<"PASSWORD MODIFIED SUCCESSFULLY!!!";
				getch();
			}
			else
			{
				gotoxy(80,9);cout<<"(PASSWORD INCORRECT!!!)";
				getch();
				return modify_userpass();	
			}
			}
}
	
//to check if user is sure of the password he has given
	
	void new_userpass_check()
	{
		int i=0, j=0,k=0;
		char new_pass[4],retypepass[4];
		gotoxy(59,12);cout<<"     ";
		gotoxy(67,15);cout<<"     ";
		gotoxy(59,12);
		while(i<4)
		{
			new_pass[i]=getch();
			cout<<"*";
			++i;
		}
		gotoxy(80,13);cout<<"                           ";
		gotoxy(67,15);
		while(j<4)
		{
			retypepass[j]=getch();
			cout<<"*";
			++j;
		}
		if(strcmp(new_pass,retypepass)==0)
		{
			ofstream outpassword;
			outpassword.open("userpass.txt");
			while(k<4)
			{
				
				outpassword<<retypepass[k];
				++k;
			}
		}
		else 
		{
			gotoxy(80,13);cout<<"PASSWORD NOT MATCHED!!!";
			return new_userpass_check();
		}	
		
	}


//to display the goods
void viewgoods()
{
	system("cls");
	ifstream stock("cpp-home.txt");
	double PNO ;
	string pname;
	double rate;
	double quantity;
	cout<<"Product NO\t\t"<<"Product name\t\t\t"<<"Rate\t\t"<<"Quantity\t\t"<<endl;
	while (stock >> PNO>>pname>>rate>>quantity) 
	{
		int namelength=pname.size();
		if(namelength>6)
			cout << PNO << "\t\t\t"<<pname<<"\t\t\t"<<rate<<"\t\t"<<quantity<<"\n";
		else if(namelength<=6)
			cout << PNO << "\t\t\t"<<pname<<"\t\t\t\t"<<rate<<"\t\t"<<quantity<<"\n";
		
	}
	getch();
	
}


//check the avalability of the code

int check_code(int pId)
{
	int z[200],y,i=0,flag=0;
	double PNO ;
	string pname;
	double rate;
	double quantity;
	ifstream prod("cpp-home.txt");
	while(prod>>PNO>>pname>>rate>>quantity)
	{	
		z[i]=PNO;
		i++;
	}
	for(int j=0;j<i;j++)
		{
			if(z[j]==pId)
			{
				flag = 1;
			}
		}
		if(flag == 1)
		{
			gotoxy(67,9);
			cout<<"(PRODUCTID ALREADY EXISTS!!)"<<endl;
			getch();
			return 1;
		}
		else
		return 2;
}
	
	

	
//to add the goods

int add_goods()
{
	system("CLS");
	system("COLOR fc");
		int pId,p;
	char productName[30];
	double rate;
	int quantity;
	char check;
	windowthree(25,65,9);
    gotoxy(26,9);
	cout<<"Do you want to add new goods?(Y/N) :";
	cin>>check;
	while(toupper(check)=='Y')
	{
		fstream stock_file("cpp-home.txt", ios::app);
		system("cls");
		gotoxy(39,5);cout<<"$$ ADD GOODS $$";
		windowthree(25,65,9);
	    gotoxy(26,9);	
		cout << "PRODUCT NUMBER :: ";
		windowthree(25,65,12);
		gotoxy(26,12);
		cout << "PRODUCT NAME :: ";
		windowthree(25,65,15);
	    gotoxy(26,15);
	    cout << "RATE OF THE PRODUCT :: ";
	    windowthree(25,65,18);
	    gotoxy(26,18);
		cout << "QUANTITY OF THE PRODUCT :: ";
		gotoxy(43,9);
		cin >> pId;
		p=check_code(pId);
		if(p==1)
		{
			system("cls");
			continue;						//this cuts the current loop and moves to next loop
		}
		else if(p==2)
		{
	        gotoxy(41,12);
			cin >> productName;
	        gotoxy(48,15);
	        cin>>rate;
	        gotoxy(52,18);
			cin >> quantity;
			gotoxy(25,22);cout<<"PRODUCT ADDED SUCCESSFULLY ! ! !";
			getch();
			stock_file << pId<< "\t" << productName << "\t" << rate << "\t" << quantity << endl;
			windowone(25,65,25,45);
	        gotoxy(26,18);
			cout<<"Do you want to add more goods?(Y/N) :";
			cin>>check;	
		}
		
	}
	system("cls");
	return 0;
}

 	
//to edit goods


void editGoods(){
	system("cls");

	double productID=-1;
	string productName;
	double productRate;
	double productQuantity;


	double PNO;
	string pname;
	double rate,updaterate;
	double quantity,updatequantity;
	double id=0;

	int i = 0;

	ifstream stock("cpp-home.txt");

	windowthree(20,75,10);
	gotoxy(21,10);
	cout << "Enter the id of the product you want to update : : ";
	cin >> id;

	while(stock>>PNO>>pname>>rate>>quantity)
	{
			
			if(PNO==id)
			{
			productID = id;
			productName = pname;
		    }
		
	}
	if(productID==-1)
	{
		gotoxy(21,13);cout<<"PRODUCTID DOESNOT EXISTS!!!";
		getch();
		return editGoods();
	}
	else
	{
		system("cls");
		gotoxy(50,8);
	    cout <<" EDIT OF THE GOODS! "<<endl;
	    gotoxy(49,9);
	    cout<<"---------------------"<<endl;
	 	windowthree(45,75,12);	
		gotoxy(46,12);
		cout << "PRODUCT ID : : " <<productID << endl;
		windowthree(45,75,15);	
		gotoxy(46,15);
		cout << "PRODUCT NAME : : " << productName << endl;
		windowthree(45,75,18);	
		gotoxy(46,18);
		cout << "UPDATE RATE : : ";
		windowthree(45,75,21);	
		 gotoxy(46,21);
		cout << "Update QUANTITY : : ";
		gotoxy(61,18);
		cin >> updaterate;
		gotoxy(65,21);
		cin >> updatequantity;
				
		system("cls");
		cout << endl;
		windowtwo(23,63,13,21);
		gotoxy(24,15);
		cout << "PRODUCT UPDATED SUCCESSFULLY ! ! !" << endl;
		gotoxy(30,17);
		cout << "PRODUCT ID : : " << productID << endl;
		gotoxy(30,18);
		cout << "PRODUCT NAME : : " << productName << endl;
		gotoxy(30,19);
		cout << "RATE : : " <<updaterate << endl;
		gotoxy(30,20);
		cout << "QUANTITY : : " << updatequantity << endl;
	}

	ifstream cpphome("cpp-home.txt");
	ofstream temp("temp.txt");
	while(cpphome>>PNO>>pname>>rate>>quantity)
	{
		if(PNO==productID)
		{
			temp<<PNO<<"\t"<<pname<<"\t"<<updaterate<<"\t"<<updatequantity<<endl;
		}
		else
		{
			temp<<PNO<<"\t"<<pname<<"\t"<<rate<<"\t"<<quantity<<endl;
		}
	}
	cpphome.close();
	temp.close();
	ifstream read("temp.txt");
	ofstream write("cpp-home.txt");
	while (read >> PNO >> pname >> rate >> quantity){
		write << PNO << "\t" << pname << "\t" << rate << "\t" << quantity << endl;
	}
	getch();
}


//to delete goods
void deleteGoods(){
	system("cls");

	double PNO,prodid;
	string pname,prodname;
	double rate,prodrate;
	double quantity,prodquantity;
	double id = 0;

	int i = 0;

	ifstream stock("cpp-home.txt");
	ofstream temp("temp.txt");

	cout << endl;
    windowthree(20,75,18);
	gotoxy(21,18);
	cout << "Enter the id of the product you want to delete : : ";
	cin >> id;

	while (stock >> PNO >> pname >> rate >> quantity){
		if(PNO==id)
		{
			prodid=PNO;
			prodname=pname;
			prodrate=rate;
			prodquantity=quantity;
		}
		else
		{
			temp<<PNO<<"\t"<<pname<<"\t"<<rate<<"\t"<<quantity<<endl;
		}
	}
	

	windowtwo(22,61,13,22);
	gotoxy(24,15);
	cout << " : : Product Sucessfully Deleted : : " << endl;
	gotoxy(30,17);
	cout << "Product Id : : " << prodid;
	gotoxy(30,18);
	cout << "Product Name : : " <<prodname;
	gotoxy(30,19);
	cout << "Rate : : " <<prodrate << endl;
	gotoxy(30,20);
	cout << "Quantity : : " << prodquantity;

	ifstream read("temp.txt");
	ofstream write("cpp-home.txt");
	while (read >> PNO >> pname >> rate >> quantity){
		write << PNO << "\t" << pname << "\t" << rate << "\t" << quantity << endl;
	}
	getch();
}


//to setup admin pass
void setup_adminpass()
{
	system("cls");
	system("color fc");
		int j=0,k=0,l=0;
		char pass_setuped[4];
		char retype_pass[4];
		gotoxy(25,12);cout<<"                                                                 ";
		gotoxy(45,3);
		cout<<"$ $ ADMINISTRATOR PASSWORD SETUP $ $";
		windowthree(45,75,6);
		gotoxy(46,6);
		cout<<"PASSWORD:";
		windowthree(45,75,9);
		gotoxy(46,9);
		cout<<"CONFIRM PASSWORD:";
		
		gotoxy(55,6);
		for(j=0;j<4;++j)
			{
				pass_setuped[j]=getch();		//to get the input and also display the typed alphabet in * form
				cout<<"*";
			}
		
		
		gotoxy(63,9);
		for(k=0;k<4;++k)
			{
				retype_pass[k]=getch();
				cout<<"*";
			}
			if(strcmp(pass_setuped,retype_pass)==0)
			{
				ofstream pass_setup;
				pass_setup.open("adminpass.txt");
				for(l=0;l<4;++l)
				{
					
					pass_setup<<retype_pass[l];
				}
		
			}
			else
			{
				gotoxy(45,12);	cout<<"PASSWORDS NOT MATCHING!!!";
				getch();
				return setup_adminpass();
			}	
}



//to check the password at the beginning of the program
int adminpass_check()
{	
	system("cls");
	ifstream password1;					//opened a file in read mode
	password1.open("adminpass.txt");
	if(password1.is_open())
	{
		string inpass;
		char user_pass[4];
		int i=0;
		gotoxy(45,6);
		cout<<"$ $ ADMINISTRATOR LOGIN $ $";
		windowthree(45,75,9);	
		gotoxy(46,9);cout<<"PASSWORD:";
			for(i=0;i<4;++i)
				{
					user_pass[i]=getch();		//to get the input and also display the typed alphabet in * form
					cout<<"*";
				}
			while(password1>>inpass)			//comparing the pass from the file and the input file
			{
				if(inpass==user_pass)
				{
					return 1;
				}
				else
				{
					return 0;
				}			//closing the file
			}
	}
	else
	{
		setup_adminpass();
		gotoxy(45,12);cout<<"                                                                          ";
		gotoxy(45,12);cout<<"PASSWORD SETUP COMPLETE!!";
		getch();
		return 1;	
	}
}
	


// to modify the password if user feels so


void modify_adminpass()
{
	system("CLS");
	system("COLOR FC");
	string passw;
	char pass[4];
	int i=0,flag=0,j;
	gotoxy(45,6);
	cout<<"$ $ MODIFY ADMINISTRATOR PASSWORD $ $";
	windowthree(45,75,9);	
	gotoxy(46,9);
	cout<<"OLD PASSWORD:";
	windowthree(45,75,12);	
	gotoxy(46,12);
	cout<<"NEW PASSWORD:";
	windowthree(45,75,15);	
	gotoxy(46,15);
	cout<<"CONFIRM NEW PASSWORD:";
	gotoxy(59,9);
		for(i=0;i<4;++i)
			{
				pass[i]=getch();
				cout<<"*";
			}
		
		
		ifstream inpassword;
		inpassword.open("adminpass.txt");		//opened pass.txt in read mode
		
		
		while(inpassword>>passw)			//for getting the pass from txt file we use this loop and syntax
			{
			if(passw==pass)
			{ 
				inpassword.close();
				gotoxy(80,9);cout<<"                        ";
				new_adminpass_check();
				gotoxy(46,18);cout<<"PASSWORD MODIFIED SUCCESSFULLY!!!";
				getch();
			}
			else
			{
				gotoxy(80,9);cout<<"(PASSWORD INCORRECT!!!)";
				getch();
				return modify_adminpass();	
			}
			}
}
	
//to check if user is sure of the password he has given
	
	void new_adminpass_check()
	{
		int i=0, j=0,k=0;
		char new_pass[4],retypepass[4];
		gotoxy(59,12);cout<<"     ";
		gotoxy(67,15);cout<<"     ";
		gotoxy(59,12);
		while(i<4)
		{
			new_pass[i]=getch();
			cout<<"*";
			++i;
		}
		gotoxy(80,13);cout<<"                           ";
		gotoxy(67,15);
		while(j<4)
		{
			retypepass[j]=getch();
			cout<<"*";
			++j;
		}
		if(strcmp(new_pass,retypepass)==0)
		{
			ofstream outpassword;
			outpassword.open("adminpass.txt");
			while(k<4)
			{
				
				outpassword<<retypepass[k];
				++k;
			}
		}
		else 
		{
			gotoxy(80,13);cout<<"PASSWORD NOT MATCHED!!!";
			return new_adminpass_check();
		}	
		
	}



