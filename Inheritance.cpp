/*
Create an inheritance hierarchy where BankAccount is the base class and CreditAccount and SavingAccount are two separate derived classes.
Create the CreditAccount class with methods: deposit()
     withdraw()
     display()
with attributes:
     name
     accountNumber
     balance
     overdraft_limit
Create the SavingAccount class with methods: deposit()
     withdraw()
     display()
     apply_interest()
with attributes:
     name
     accountNumber
     balance
     interest_rate
Some of the above attributes and methods can be hoisted to the base class - decide which.
Use a Money class to represent the balance in these classes. The CreditAccount must prevent account holders from exceeding their overdraft limit. The SavingAccount should apply interest to the current balance each year, so provide a Date class to keep track of time.
In the test harness create two accounts of each Derived class and simulate the passage of time in the Date class.
*/
#include <string>
using namespace std;

class Money
{
public:
	Money(int pounds=0, int pence=0): pounds(pounds), pence(pence) {}
private:
	int pounds;
	int pence;
};

class BankAccount
{
private:
	static int number;
public:
	BankAccount(const string& name, const Money& initialBalance) : name(name), balance(initialBalance)
	{
		accountNumber = number++;
	}
	void deposit(const Money& deposit);
	void display();
private:
	string name;
	int accountNumber;
	Money balance;
};

int BankAccount::number = 1000;

class CreditAccount : public BankAccount
{
public:
	CreditAccount(const string& name, const Money& initialBalance, const Money& overdraft_limit)
		: BankAccount(name, initialBalance), overdraft_limit(overdraft_limit) {}
	Money withdraw();
private:
	Money overdraft_limit;
};

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount(const string& name, const Money& initialBalance, double interest_rate)
		: BankAccount(name, initialBalance), interest_rate(interest_rate) {}
	void apply_interest();
	void setInterestRate(double rate);
	void close();
private:
    double interest_rate;
};

int main()
{
	CreditAccount john("John", Money(100, 50), Money(250, 0));
	CreditAccount susan("Susan", Money(50, 10), Money(100, 0));
//	SavingsAccount thomas("John", Money(5250, 25));
//	SavingsAccount christine("Christine", Money(1000, 0));
//	thomas.setInterestRate(1.5);
}
