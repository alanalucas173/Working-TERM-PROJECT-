#include"Account.h"
#include"CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount()
{
	Account();
	overDraftLimit = 200;
}
CheckingAccount::CheckingAccount(Account* accountCustomer, string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _overDraftLimit) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
{
	overDraftLimit = 200;
}
void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
	overDraftLimit = 200;
}

//over load
void CheckingAccount::withdrawal(double _withdrawalAmount)
{
	int continueOverDraft;
	int balance;
	if (_withdrawalAmount > getBalance())
	{
		cout << "You do not have enough to withdraw... Do you want to overdraft withdraw?" << endl;
		cout << "$20 service fee if you continue \nEnter 0 to coninue or any other number to exit ";
		cin >> continueOverDraft;
		if (continueOverDraft == 0)
		{
			if ((getBalance() - _withdrawalAmount) <= overDraftLimit && _withdrawalAmount <= overDraftLimit)
			{
				balance = getBalance() - _withdrawalAmount -20;
				setBalance(balance);
				cout << "Withdrawal Complete... New balance: $" << getBalance();
				withdrawals++;
			}
			else
			{
				cout << "You went over the overdraft limit, unable to withdraw" << endl;
			}
		}
		else
		{
			cout << "Overdraft canceled" << endl;
		}
	}
	else
	{
		balance = getBalance() - _withdrawalAmount;
		setBalance(balance);
		cout << "Withdraw complete, New Balance: $" << getBalance();
	}
}


void CheckingAccount::depositChecking()
{
	double depositAmmount = 0;
	cout << "Your current balance is: $" << Account::getBalance() << endl;
	cout << "Please eneter how much you would like to deposit into your account: $";
	cin >> depositAmmount;
	if (depositAmmount >= 0)
	{
		Account::setBalance(Account::getBalance() + depositAmmount);
		cout << "Your deposit has been added..." << endl;
		cout << "Your new balance is: $" << getBalance() << endl;
	}
	else
	{
		cout << "You have inputted an invalid deposit ammount. This will not be added to your Checking Account." << endl;
		cout << "Please try again!" << endl;
	}
}
