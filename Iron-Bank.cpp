// Iron Bank.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "accounts.h"
#include"customer.h"
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

	int id_;
	char password[30], c = ' ';
	cout << " _____________________________\n";
	cout << " Enter ID : ";
	cin >> id_;
	cout << " Enter Pin(4-digit) : ";
	int i = 0;
	while (c != 13)
	{
		c = _getch();
		cout << "*";
		//c = getchar();
		password[i] = c;
		i++;
		//fflush(stdin);
	}
	password[i] = '\0';
	int pin = atoi(password);

	fflush(stdin);
	cin.clear();
	employee Employee;
	bool flag = false;
	fstream infile;
	infile.open("employee.dat", ios::binary | ios::app | ios::in);
	if (!infile)
	{
		cout << "employee file could not be opened !!" << endl;
		return;
	}

	while (infile.read(reinterpret_cast<char*>(&Employee), sizeof employee))
	{
		int id = Employee.get_id();
		int pin_ =Employee.get_pin();
		cout << id << " " << id_ << " " << pin << " " << pin_ << endl;
		if (id == id_ && pin == pin_)
		{
			//cout << "found" << endl;
			flag = true;
			break;
		}


	}
	//system("pause");
	//cout << "finished Searching\n";
	infile << flush;
	infile.close();
	if (!flag)    //return;
	{
		cout << "Username or password is Wrong ! -_-\n";
		return;
	}
	int c_idd;
	int e_idd;
	int a_idd;

	bool q = false;
	while (1) {
		system("cls");
		cout << "\n\t== Welcome " << Employee.get_name() << " .....\n";
		cout << " _______________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Customer\n";
		cout << " 2. Delete Customer\n";
		cout << " 3. Show Transaction\n";
		cout << " 4. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;

		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		
		switch (cc) {
	
		case 1:
			c_idd = idGenC.get_id();
			Employee.create_customer(c_idd);
			break;
		case 2:
			cout << " Enter the ID of the Customer to be Deleted : ";
			cin >> c_idd;
			Employee.delete_customer(c_idd);
			break;
		case 3:
			//show all transactions
		case 4:
			q = true;
			break;

		}

		if (q) {
			//cin.clear();
			break;
		}

	}



}
void customer_access()
{
	//clear screen 
	//enter using customer id and pass
	//options create account, enter into account,transactions
	//he can delete accounts and stuff
	int id_;
	char password[30], c = ' ';
	cout << " _____________________________\n";
	cout << " Enter ID : ";
	cin >> id_;
	cout << " Enter Pin(4-digit) : ";
	int i = 0;
	while (c != 13)
	{
		c = _getch();
		cout << "*";
		password[i] = c;
		i++;
	}
	password[i] = '\0';
	int pin = atoi(password);
	fflush(stdin);
	cin.clear();
	customer Customer;
	bool flag = false;
	fstream infile;
	infile.open("customer.dat", ios::binary | ios::app | ios::in);
	if (!infile)
	{
		cout << "customer file could not be opened !!" << endl;
		return;
	}

	while (infile.read(reinterpret_cast<char*>(&Customer), sizeof Customer))
	{
		int id = Customer.get_id();
		int pin_ = Customer.get_pin();
		//cout << id << " " << id_ << " " << pin << " " << pin_ << endl;
		if (id == id_ && pin == pin_)
		{
			flag = true;
			break;
		}


	}
	infile << flush;
	infile.close();
	if (!flag)  
	{
		cout << "Username or password is Wrong ! -_-\n";
		return;
	}
	bool q = false;
	while (1) {
		system("cls");
		cout << "\n\t== Welcome  " << Customer.get_name() << " .....\n";
		cout << " _______________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Account\n";
		cout << " 2. Delete Account\n";
		cout << " 3. Perform Transaction\n";
		cout << " 4. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;

		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		int a_id,c_id;
		switch (cc) {
		case 1:
			c_id = Customer.get_id();
		    a_id = idGenA.get_id();
			//cout << "c_id " << c_id << " a_id " << a_id << endl;
			Customer.create_account( c_id, a_id);
			break;
		case 2:
	
			cout << " Enter the ID of the account to be Deleted : ";
			cin >> a_id;
			Customer.delete_account( a_id);
			break;
		case 3:
			Customer.access_account();
			break;
		case 4:
			q = true;
			break;

		}

		if (q) {
			break;
		}

	}
}
void admin_access()
{
	int id_;
	char password[30],c=' ';
	cout << " _____________________________\n";
	cout << " Enter ID : ";
	cin >> id_;
	cout << " Enter Pin(4-digit) : ";
	int i = 0;
	while (c != 13)
	{
		c = _getch();
		cout << "*";
		//c = getchar();
		password[i] = c;
		i++;
		//fflush(stdin);
	}
	password[i] = '\0';
	int pin = atoi(password);

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

	while (infile.read(reinterpret_cast<char*>(&Admin), sizeof admin))
	{
		int id = Admin.get_id(); 
		int pin_ = Admin.get_pin();
		cout << id << " " << id_ << " " << pin << " " << pin_ << endl;
		if (id == id_ && pin == pin_)
		{
			//cout << "found" << endl;
			flag = true;
			break;
		}
		

	}
	//system("pause");
	//cout << "finished Searching\n";
	infile << flush;
	infile.close();
	if (!flag)    //return;
	{
		cout << "Username or password is Wrong ! -_-\n";
		return;
	}
	

	bool q = false;
	while (1) {
		system("cls");
		cout << "\n\t== Welcome " << Admin.get_name() << " .....\n";
		cout << " _______________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Admin\n";
		cout << " 2. Add Employee\n";
		cout << " 3. Add Customer\n";
		cout << " 4. Delete Employee\n";
		cout << " 5. Delete Customer\n";
		cout << " 6. Show Transaction\n";
		cout << " 7. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;
		
		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		int c_id,e_id,a_id;
		switch (cc) {
		case 1:
			a_id = idGenE.get_id();
			Admin.create_admin(a_id);
			break;
		case 2:
			e_id = idGenE.get_id();
			Admin.create_employee(e_id);
			break;
		case 3:
			c_id = idGenC.get_id();
			Admin.create_customer( c_id);
			break;
		case 4:
			cout << " Enter the ID of the Employee to be Deleted : ";
			cin >> e_id;
			Admin.delete_employee(e_id);
			break;
		case 5:
			cout << " Enter the ID of the Customer to be Deleted : ";
			cin >> c_id;
			Admin.delete_customer(c_id);
			break;
		case 6: 
			//show all transactions
		case 7:
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
			//cout << "admin nai \n";
			flag = true;
		}
	}
	infile<<flush;
	infile.close();
	if (flag)   
	{
		
		return; 
	}
	//cout << "admin nai \n";
	int id = 1234;
	char name[] = "system";
	int pin = 1234;
	char phone[] = "";
	admin system(1234, pin ,name ,phone);
	fstream outfile;
	outfile.open("admin.dat", ios::binary|ios::out);
	outfile.write(reinterpret_cast<char *>(&system), sizeof(admin) );
	outfile.flush();
	outfile.close();
	

}
void id_GenC()
{
	fstream infile;
	infile.open("idgenC.dat", ios::binary | ios::in|ios::app);
	if (!infile)
	{
		cout << "idgenC File could not be open !!"<<endl;
		return;
	}
	bool flag = true;
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&idGenC), sizeof idGenC);
	}
	infile.close();
}
void id_GenA()
{
	fstream infile;
	infile.open("idgenA.dat", ios::binary | ios::in|ios::app);
	if (!infile)
	{
		cout << "idgenA File could not be open !!" << endl;
		return;
	}
	bool flag = true;
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&idGenA), sizeof idGenA);
	}
	infile.close();
}
void id_GenE()
{
	fstream infile;
	infile.open("idgenE.dat", ios::binary | ios::in |ios::app);
	if (!infile)
	{
		cout << "idgenE File could not be open !!" << endl;
		return;
	}
	bool flag = true;
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&idGenE), sizeof idGenE);
	}
	infile.close();
}
void see_everything()
{
	cout << "accounts...........\n";
	fstream infile1;
	infile1.open("accounts.dat", ios::binary | ios::in|ios::app);
	accounts Account;
	while (infile1.read(reinterpret_cast<char *>(&Account), sizeof Account))
	{
		cout << "=======\n";
		cout << Account.get_id() << " " << Account.get_c_id() << " " << Account.get_amount() << endl;
		cout << "========\n";
	}
	infile1.close();
	cout << endl << endl;
	cout << "Customers....\n";
	fstream infile2;
	infile2.open("customer.dat", ios::binary | ios::in |ios::app);
	customer Customer;
	while (infile2.read(reinterpret_cast<char *>(&Customer), sizeof Customer))
	{
		cout << "=======\n";
		cout << Customer.get_id() << " " << Customer.get_pin() << " " << Customer.get_name() << endl;
		cout << "========\n";
	}
	infile2.close();

	cout << endl << endl;
	cout << "Admins....\n";
	fstream infile3;
	infile3.open("admin.dat", ios::binary | ios::in | ios::app);
	admin Admin;
	while (infile3.read(reinterpret_cast<char *>(&Admin), sizeof Admin))
	{
		cout << "=======\n";
		cout << Admin.get_id() << " " << Admin.get_pin() << " " << Admin.get_name() << endl;
		cout << "========\n";
	}
	infile3.close();

	cout << endl << endl;
	cout << "Employees....\n";
	fstream infile4;
	infile4.open("employee.dat", ios::binary | ios::in | ios::app);
	employee Employee;
	while (infile4.read(reinterpret_cast<char *>(&Employee), sizeof Employee))
	{
		cout << "=======\n";
		cout << Employee.get_id() << " " << Employee.get_pin() << " " << Employee.get_name() << endl;
		cout << "========\n";
	}
	infile4.close();
	cout << "_________________________________________\n";
	cout << "___________________________________________\n";
}

int main()
{
	systemAdminGen();
	id_GenC();
	id_GenE();
	id_GenA();
	see_everything();
	system("pause");
	//return 0;
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