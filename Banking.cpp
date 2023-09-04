#include<iomanip>
#include <fstream>
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
	protected:
		details about;
		int accountNum;
		double balance;
	public:
		SavingAccount(){}
		SavingAccount(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber, int _accountNum, double _balance = 0){
			about = details(_firstName, _lastName, _age, _phone, _address, _adhaarNumber);
			accountNum = _accountNum;
			balance = _balance-0.1;
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
			cout << endl << "\x1B[92m TRANSACTION SUCESSFULL : AMOUNT CREDITED SUCESSFULLY. \033[0m" << endl;
			cout << " CURRENT BALANCE : " << balance << endl << endl;
		}
		void withdraw(double amount){
			if(balance >= amount)
			{
				balance = balance - amount;
				cout << endl << "\x1B[92m TRANSACTION SUCESSFULL : MONEY HAS BEEN DEBITED FROM YOUR ACCOUNT AND DISBURSED AS CASH! \033[0m" << endl;
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
	currentAccount(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber, int _accountNum, double _balance, double _loan) : SavingAccount(_firstName, _lastName, _age, _phone, _address, _adhaarNumber, _accountNum, _balance){
		loanAmount = _loan-0.1;
	}
	void print()
	{
		cout << char(186) << " " << accountNum << " | "
			<< about.firstName << setw(15-(int)about.firstName.size()) << " | "
			<< about.lastName << setw(15-(int)about.lastName.size()) << " | "
			<< about.age << " | "
			<< about.phone << " | "
			<< about.address << setw(30-(int)about.address.size()) << " | "
			<< about.adhaarNumber << " | "
			<< balance << " | " << loanAmount << " " << char(186) << endl;
	}
	void loan(double amount)
	{
		loanAmount += amount;
		cout << endl << "\x1B[92m TRANSACTION SUCESSFULL : YOU HAVE TAKEN A LOAN AGAINST YOUR CURRENT ACCOUNT. \033[0m" << endl;
		cout << " CURRENT LOAN AMOUNT : " << loanAmount << endl << endl;
	}
	void payInstallment(double amount)
	{
		cout << endl << "\x1B[92m TRANSACTION SUCESSFULL : YOU HAVE PAID AN INSTALLMENT FOR YOUR LOAN. \033[0m" << endl;
		cout << " CURRENT BALANCE : " << loanAmount << endl << endl;
		loanAmount -= amount;
	}
	void addIntrest()
	{
		cout << "INTREST OF THIS MONTH IS BEEN ADDED TO THE LOAN AMOUNT" << endl;
		loanAmount = loanAmount + (loanAmount*rate);
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
				cout << char(201);
				for(int i=0; i<113; i++) cout << char(205);
				cout << char(187) << endl;
				cout << (char)186;
				cout << " ACC NO |  FIRST NAME  |  LAST NAME   | AG |   PHONE   |           ADDRESS           | AADHAAR  |   BAL  | LOAN  ";
				cout << char(186) << endl;
				printLine(0);
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
				cout << (char)199;
				for(int i=0; i<113; i++) cout << char(196);
				cout << char(182) << endl;
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
				cout << char(200);
				for(int i=0; i<113; i++) cout << char(205);
				cout << char(188) << endl;
			}
		}

	public:
		void AddSavingAccount(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber, int _accountNum, double _balance){
			accounts.push_back(SavingAccount(_firstName, _lastName, _age, _phone, _address, _adhaarNumber, _accountNum, _balance));
			turnover += _balance;
			assets += _balance;
		}
		void AddCurrentAccount(string _firstName, string _lastName, int _age, string _phone, string _address, string _adhaarNumber, int _accountNum, double _balance, double _loan){
			currentAccounts.push_back(currentAccount(_firstName, _lastName, _age, _phone, _address, _adhaarNumber, _accountNum, _balance, _loan));
			turnover += _balance+_loan;
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
			printHeaders(0);
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
		void searchCurrentAccount(int accountNum){
			auto find = findCurrentAccount(accountNum);
			if(find)
			{
				printHeaders(0);
				find->print();
				printFooter(0);
			}
			else cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
		}
		currentAccount* findCurrentAccount(int accountNum)
		{
			for(auto &x:currentAccounts)
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
	int choice;
	char op=0;
	do
	{
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
				char acc;
				type : 
				cout << "SELECT ACCOUNT TYPE : SAVING(S) or CURRENT(C) : ";
				cin >> acc;
				if(acc == 'S' || acc=='s')
					bank.AddSavingAccount(firstName, lastName, age, phone, address, adhaar, accountNumber++, balance - 0.1);
				else if(acc == 'c' || acc == 'C')
					bank.AddCurrentAccount(firstName, lastName, age, phone, address, adhaar, accountNumber++, balance - 0.1, 0.2);
				else
				{
					cout << "INVALID KEY!" << endl;
					goto type;
				}
				break;
			}
			case 2:
			{
				cout << "WHAT TRANSACTION YOU WISH TO PERFORM ? " << endl;
				cout << "1. DEPOSIT" << endl;
				cout << "2. WITHDRAWAL" << endl;
				cout << "3. APPLY FOR A LOAN" << endl;
				cout << "4. PAY LOAN INSTALLMENT" << endl;
				cout << "5. ADD INTREST TO THE ACCOUNT" << endl;
				int operation;
				cin >> operation;
				switch(operation)
				{
					case 1:
					{
						int accountNum;
						double amount;
						cout << "ENTER ACCOUNT NUMBER : ";
						cin >> accountNum;
						SavingAccount* account = bank.findSavingAccount(accountNum);
						currentAccount* account_ = bank.findCurrentAccount(accountNum);
						if(account != NULL)
						{
							fflush(stdin);
							cout << "ENTER AMOUNT : ";
							cin >> amount;
							account->deposit(amount);
						}
						else if(account_ != NULL)
						{
							fflush(stdin);
							cout << "ENTER AMOUNT : ";
							cin >> amount;
							account->deposit(amount);
						}
						else
						{
							cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
						}
						break;
					}
					case 2:
					{
						int accountNum;
						double amount;
						cout << "ENTER ACCOUNT NUMBER : ";
						cin >> accountNum;
						SavingAccount* account = bank.findSavingAccount(accountNum);
						currentAccount* account_ = bank.findCurrentAccount(accountNum);
						if(account != NULL)
						{
							fflush(stdin);
							cout << "ENTER AMOUNT : ";
							cin >> amount;
							account->withdraw(amount);
						}
						else if(account_ != NULL)
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
					case 3:
					{
						int accountNum;
						double amount;
						cout << "ENTER ACCOUNT NUMBER : ";
						cin >> accountNum;
						currentAccount* account = bank.findCurrentAccount(accountNum);
						if(account != NULL)
						{
							fflush(stdin);
							cout << "ENTER AMOUNT : ";
							cin >> amount;
							account->loan(amount);
						}
						else
						{
							cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
						}
						break;
					}
					case 4:
					{
						int accountNum;
						double amount;
						cout << "ENTER ACCOUNT NUMBER : ";
						cin >> accountNum;
						currentAccount* account = bank.findCurrentAccount(accountNum);
						if(account != NULL)
						{
							fflush(stdin);
							cout << "ENTER AMOUNT : ";
							cin >> amount;
							account->payInstallment(amount);
						}
						else
						{
							cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
						}
						break;
					}
					case 5:
					{
						int accountNum;
						double amount;
						cout << "ENTER ACCOUNT NUMBER : ";
						cin >> accountNum;
						currentAccount* account = bank.findCurrentAccount(accountNum);
						if(account != NULL) account->addIntrest();
						else cout << endl << "\x1B[91m ACCOUNT DOSEN'T EXIST! \033[0m" << endl << endl;
						break;
					}
				}
				break;
			}
			case 3:
			{
				bank.printDatabse();
				break;
			}
			case 4:
			{
				char acc;
				here : 
				cout << "SELECT ACCOUNT TYPE : SAVING(S) or CURRENT(C) : ";
				cin >> acc;
				int accountNum;
				cout << "ENTER ACCOUNT NUMBER : ";
				cin >> accountNum;
				if(acc == 'S' || acc=='s')
					bank.searchSavingAccount(accountNum);
				else if(acc == 'c' || acc == 'C')
					bank.searchCurrentAccount(accountNum);
				else
				{
					cout << "INVALID KEY!" << endl;
					goto here;
				}
				break;
			}
			case 5:
			{
			 	ofstream database;
				database.open("Bank.txt", ios::app);
				database.write((char*)&bank,sizeof(bank));
				database.close();
				cout << "ADIOS, SEE YOU AGAIN!" << endl;
				exit(1);
				break;
			}
		}
		cout << "DO YOU WISH TO CONTINUE? [Y/N] : ";
		cin >> op;
		if(op == 'N' || op == 'n')
		{
			ofstream database;
			database.open("Bank.txt", ios::app);
			database.write((char*)&bank,sizeof(bank));
			database.close();
			cout << "ADIOS, SEE YOU AGAIN!" << endl;
			exit(1);
		}
		system("cls");
	}
	while(op == 'y'||op =='Y');
	return 0;
}