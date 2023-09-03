#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

class Details{
	public:
	string firstName;
	string lastName;
	int age;
	string phone;
	string address;
	string adhaarNumber;
	public :
	Details(){}
	Details(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber)
	{
		firstName = _firstName;
		lastName = _lastName;
		age = _age;
		phone = _phone;
		address = _address;
		adhaarNumber = _adhaarNumber;
	}
	virtual void fn(){}
};

class details : public Details {
	public:
	details(){}
	details(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber) : Details(_firstName, _lastName, _age, _phone, _address, _adhaarNumber){}
};

class SavingAccount{
	private:
		details about;
		int accountNum;
		double balance;
	public:
		SavingAccount(){}
		SavingAccount(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber, int _accountNum, double _balance = 0){
			about = details(_firstName, _lastName, _age, _phone, _address, _adhaarNumber);
			accountNum = _accountNum;
			balance = _balance;
		}
		void print() {
			cout << char(186) << " " << accountNum << " | "
			<< about.firstName << setw(15-(int)about.firstName.size()) << " | "
			<< about.lastName << setw(15-(int)about.lastName.size()) << " | "
			<< about.age << " | "
			<< about.phone << " | "
			<< about.address << setw(30-(int)about.address.size()) << " | "
			<< about.adhaarNumber << " | "
			<< balance << " " << char(186) << endl;
		}
		int getAccountNum(){
			return accountNum;
		}
		void deposit(double amount){
			balance += amount;
			cout << endl << "\x1B[92m TRANSCATION SUCESSFULL : AMOUNT CREDITED SUCESSFULLY. \033[0m" << endl;
			cout << " CURRENT BALANCE : " << balance << endl << endl;
		}
		void withdraw(double amount){
			if(balance >= amount)
			{
				balance = balance - amount;
				cout << endl << "\x1B[92m TRANSCATION SUCESSFULL : MONEY HAS BEEN DEBITED FROM YOUR ACCOUNT AND DISBURSED AS CASH! \033[0m" << endl;
				cout << " CURRENT BALANCE : " << balance << endl << endl;
			}
			else
			{
				cout << endl << "\x1B[91m TRANSACTION FAILED : INSUFFICIENT BALANCE \033[0m" << endl;
				cout << " CURRENT BALANCE : " << balance << endl << endl;
			}
		}
};

class currentAccount : public SavingAccount
{
	private:
	double loanAmount = 0;
	float rate = 3.25;
	public:
	void loan(double amount)
	{
		loanAmount += amount;
	}
	void payInstallment(double amount)
	{
		loanAmount -= amount;
	}
};

class BankManagement{
	private:
		vector<SavingAccount> accounts;
		vector<currentAccount> currentAccounts;
		double turnover = 0; // assets + loans
		double assets = 0;
		void printHeaders(bool saving)
		{
			if(saving)
			{
				cout << char(201);
				for(int i=0; i<105; i++) cout << char(205);
				cout << char(187) << endl;
				cout << (char)186;
				cout << " ACC NO |  FIRST NAME  |  LAST NAME   | AG |   PHONE   |           ADDRESS           | AADHAAR  |   BAL  ";
				cout << char(186) << endl;
				printLine(1);
			}
			else
			{

			}
		}
		void printLine(bool saving)
		{
			if(saving)
			{
				cout << (char)199;
				for(int i=0; i<105; i++) cout << char(196);
				cout << char(182) << endl;

			}
			else
			{
				
			}
		}
		void printFooter(bool saving)
		{
			if(saving)
			{
				cout << char(200);
				for(int i=0; i<105; i++) cout << char(205);
				cout << char(188) << endl;
			}
			else
			{

			}
		}

	public:
		void printInterface()
		{

		} 
		void AddAccount(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber, int _accountNum, double _balance){
			accounts.push_back(SavingAccount(_firstName, _lastName, _age, _phone, _address, _adhaarNumber, _accountNum, _balance));
			turnover += _balance;
			assets += _balance;
		}
		double printTurnover() {
			return turnover;
		}
		double printAssets() {
			return assets;
		}

		void printDatabse() {
			cout << endl << "DETAILS OF SAVING ACCOUNTS THAT EXISTS IN OUR DATABASE : " << endl;
			printHeaders(1);
			for(int i=0; i<accounts.size(); i++)
			{
				accounts[i].print();
				if(i!=accounts.size()-1) printLine(1);
			}
			printFooter(1);
			cout << endl << "DETAILS OF CURREN ACCOUNTS THAT EXISTS IN OUR DATABASE : " << endl;
			for(int i=0; i<currentAccounts.size(); i++)
			{
				currentAccounts[i].print();
				if(i!=currentAccounts.size()-1) printLine(0);
			}
			printFooter(0);
		}
		void searchSavingAccount(int accountNum){
			auto find = findSavingAccount(accountNum);
			if(find)
			{
				printHeaders(1);
				find->print();
				printFooter(1);
			}
			else cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
		}
		SavingAccount* findSavingAccount(int accountNum)
		{
			for(auto &x:accounts)
			{
				if(x.getAccountNum() == accountNum)
				{
					return &x;
				}
			}
			return NULL;
		}
};

int main()
{
	BankManagement bank;
	int accountNumber = 800847;
	int choice, op=0;


	do{
		cout << endl << "WELCOME TO THE BANK OF ATLANTIC OCEAN" << endl << endl;
		cout << "HOW MAY I HELP YOU TODAY ?" << endl;
		cout << "1. CREATE A NEW ACCOUNT" << endl;
		cout << "2. PERFORM A TRANSACTION " << endl;
		cout << "3. PRINT DATABASE OF THE BANK "<<endl;
		cout << "4. CONFUSED? SEARCH FOR YOUR ACCOUNT" << endl;
		cout << "5. EXIT" << endl << endl;
		cout << "WHAT ARE WE DOING TODAY : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				string firstName, lastName, phone, address, adhaar;
				int accountNum, age;
				double balance;
				cout << "ENTER FIRST NAME OF THE APPLICANT : ";
				cin >> firstName;
				cout << "ENTER LAST NAME OF THE APPLICANT : ";
				cin >> lastName;
				ageCheck : 
				cout << "AGE OF THE APPLICANT : ";
				cin >> age;
				if(age < 18)
				{
					cout << "\x1B[91m AGE MUST BE GREATER THAN 18. \033[0m" << endl;
					goto ageCheck;
				}
				cout << "ENTER PHONE NUMBER : ";
				cin >> phone;
				cout << "ENTER THE CITY OF YOUR RESIDENCE : ";
				cin >> address;
				cout << "ENTER 8 DIGIT ADHAAR NUMBER : ";
				cin >> adhaar;
				balanceCheck:
				cout << "ENTER INITIAL BALANCE : ";
				cin >> balance;
				if(balance < 1000 || balance > 9999)
				{
					cout << "YOU NEED A MINIMUM OF 1000 TO OPEN A BANK ACCOUNT!";
					goto balanceCheck;
				}
				bank.AddAccount(firstName, lastName, age, phone, address, adhaar, accountNumber++, balance - 0.1);
			}
			case 2:
			{
				cout << "WHAT TRANSACTION YOU WISH TO PERFORM ? " << endl;
				cout << "1. DEPOSIT" << endl;
				cout << "2. WITHDRAWAL" << endl;
				cout << "3. APPLY FOR A LOAN" << endl;
				cout << "4. PAY LOAN INSTALLMENT" << endl;
				int operation;
				cin >> operation;
				switch(operation)
				{
					case 1:
					break;
				}
			}
			case 3:
			{
				bank.printDatabse();
				break;
			}
			case 4:
			{
				int accountNum;
				cout << "ENTER ACCOUNT NUMBER : ";
				cin >> accountNum;
				bank.searchSavingAccount(accountNum);
				break;

				// int accountNum;
				// double amount;
				// cout << "ENTER ACCOUNT NUMBER : ";
				// cin >> accountNum;
				// SavingAccount* account = bank.findSavingAccount(accountNum);
				// if(account != NULL)
				// {
				// 	fflush(stdin);
				// 	cout << "ENTER AMOUNT : ";
				// 	cin >> amount;
				// 	account->deposit(amount);
				// }
				// else
				// {
				// 	cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
				// }
				// break;
			}
			case 5:{
				int accountNum;
				double amount;
				cout << "ENTER ACCOUNT NUMBER : ";
				cin >> accountNum;
				SavingAccount* account = bank.findSavingAccount(accountNum);
				if(account != NULL)
				{
					fflush(stdin);
					cout << "ENTER AMOUNT : ";
					cin >> amount;
					account->withdraw(amount);
				}
				else
				{
					cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
				}
				break;
			}
			case 6:{
				exit(1);
				break;
			}
			system("cls");
	}
	cout << "DO YOU WISH TO CONTINUE? [Y/N] : ";
	cin >> op;
	if(op == 'N' || op == 'n')
	{
		cout << "ADIOS, SEE YOU AGAIN!" << endl;
		exit(1);
	}
	}while(op == 'y'||op =='Y');
	return 0;
}