// Iron Bank.cpp : Defines the entry point for the console application.
//system("@echo off");
//************************
///whats new? fixed password bug.added a feature so that backsapce does not appear as * character and number of * on the console reduces with each deleted character
//**************************
#include "stdafx.h"
#include "accounts.h"
#include<Windows.h>
#include "admin.h"

#include "id_genC.h"
#include "id_genE.h"

#include "id_genA.h"
#include <cstdlib>

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
id_genC idGenC;
id_genA idGenA;
id_genE idGenE;
void employee_access()
{
	//clear screen
	//enter using employee id and pass 
	//options add customer,delete customer and his accounts,update customer
	system("cls");

}
void customer_access()
{
	//clear screen 
	//enter using customer id and pass
	//options create account, enter into account,transactions
	//he can delete accounts and stuff
	system("cls");
}


void admin_access()
{
	int id_;
	char password[30],c=' ';
	cout << " _____________________________\n";
	cout << " Enter ID : ";

	cin >> id_;
	system("cls");
	cout << " Enter Password : "<<endl;
	int i = 0;
	while (c != 13)
	{
		
		c=_getch();

		if (c == 13)
		{
			//cout << "done" << endl;
			break;
		}
		
		cin.clear();
		if (c == 127 || c == 8)
		{
			i--;
			system("cls");
			cout << " Enter Password : " <<endl;
			for (int var = 0; var < i; var++)
				cout << "*";
			continue;

		}
		cout << "*" ;
		password[i] = c;
		i++;
	}
	password[i] = '\0';
	//cout << password << endl;
	cout.clear();
	fflush(stdout);
	cin.clear();
	string p1 = password;
	fflush(stdin);
	cin.clear();
	admin Admin;
	bool flag = false;
	fstream infile;
	infile.open("admin.dat", ios::binary | ios::app | ios::in);
	if (!infile)
	{
		cout << "Admin file could not be opened !!" << endl;
		return;
	}
	//cout << "p1 final " << p1 << endl;
	string p2;
	while (infile.read(reinterpret_cast<char*>(&Admin), sizeof admin))
	{
		int id = Admin.get_id(); 
		char* password_ = Admin.get_pass();
		p2 = password_;
		if (id == id_&&p1==p2 )
		{
			flag = true;
			break;
		}

	}
	//cout << flag<<"flag" << endl;
	//system("pause");
	//cout << "finished Searching\n";
	infile << flush;
	infile.close();
	if (!flag)  
	{
		cout << "Username or password is Wrong ! -_-\n";
		system("pause");
		return;
	}
	
	cout << "  Welcome " << id_ << " .....\n\n";

	bool q = false;
	while (1) {
		system("cls");
		cout << " _____________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Admin\n";
		cout << " 2. Add Employee\n";
		cout << " 3. Add Customer\n";
		cout << " 4. Show Transaction\n";
		cout << " 5. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;
		
		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		switch (cc) {
		case 1:
			//addAdmin();
			break;
		case 2:
			//addEmployee();
			break;
		case 3:
			//addCustomer();
			break;
		case 4:
			//showTransaction();
			break;
		case 5:
			q = true;
			break;
		
		}

		if (q) {
			//cin.clear();
			
			break;
		}

	}
	

}
void welcome()
{
	//cin.clear();
	//fflush(stdin);
	cout << "\n\n\t\t===        THE IRON BANK      ===\n";
	cout << "\t\t=================================\n\n";
	//cout << " enter eny key to continue...\n";
	//fflush(stdin);
	getchar();
	
}
int  menu()
{
	cout << "Login as == >\n";
	cout << " 1. Admin\n";
	cout << " 2. Employee\n";
	cout << " 3. Customer\n";
	cout << " 4. Quit\n";
	cout<< "\n == enter a choice: \t";
	int c;
	cin >> c;
	return c;
}
void create_account()
{
	cout << "\n account is creating...\n";

}
void show_accounts()
{
	cout << "\n accounts are shown...\n";
}
void systemAdminGen()
{
	
	admin temp;
	bool flag = false;
	fstream infile;
	infile.open("admin.dat", ios::binary|ios::app|ios::in);
	if (!infile)
	{
		cout << "Admin file could not be opened !!" << endl;
		return;
	}
	while (infile.read(reinterpret_cast<char*>(&temp), sizeof admin))
	{
		if (temp.get_id() == 1234)
		{
			flag = true;
		}
	}
	infile<<flush;
	infile.close();
	if (flag)    //return;
	{
		//cout << "Hi";
		return; 
	}
	//system("pause");
	//int h;
	//cin >> h;
	int id = 1234;
	char name[] = "system";
	char password[] = "test1234";
	char phone[] = "";
	admin system(1234, password,name ,phone);
	fstream outfile;
	outfile.open("admin.dat", ios::binary|ios::out);
	outfile.write(reinterpret_cast<char *>(&system), sizeof(admin) );
	outfile.flush();
	outfile.close();
	

}
int main()
{
	systemAdminGen();
	bool q = false;
	while (1) {
		system("cls");
		welcome();
		int choice = menu();
		
		switch (choice) {
		case 3:
			customer_access();
			break;
		case 1:
			admin_access();
			break;
		case 2:
			employee_access();
			break;
		case 4:
			q = true;
			break;
		}
		
		if (q) {
			break;
		}

	}
	cout << "program ends here!" << endl;
	cout << "\n\n";
	system("pause");
	return 0;
}