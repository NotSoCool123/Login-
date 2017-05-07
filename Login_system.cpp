#include <iostream>
#include <string>
using namespace std;

class account
{
	int password = 0;
	bool admin = false;
	int failed_attempts = 0;
public:
	string User_name;
	account(string _name, string _password, bool _admin)
	{
		User_name = _name;
		for (int i = 0; i < _password.length();i++) // swts user password and stors the data 
		{
			password += _password.at(i) - 'a' + 1;

		}
		admin = _admin;
	}
	account() {}

	bool Attempt_login(string attempt_password)
	{
		if (failed_attempts == 3)
		{
			cout << "failed too many login attempts" << endl;
			return false;

		}
		int temp = 0;
		for (int i = 0; i < attempt_password.length();i++)
		{
			temp += attempt_password.at(i) - 'a' + 1;

		}
		if (temp == password)
		{
			return true;
		}
		else
		{
			failed_attempts++;
			return false;
		}
	}
};
void login(account*users)
{
	string temp;
	cout << "enter in your password" << endl;
	cin >> temp;
	if (users->Attempt_login(temp)) // temp [passed to users attempt login functon// 
	{
		cout << "Welcome User " << users->User_name << endl;

	}
	else
	{
		cout << "login failed" << endl;
	}


}
int main()
{
	account users[10];
	int total_accounts = 0;
	for (;;)
	{
		cout << "welcome to the abertay system account maker" << endl;
		cout << "do you have an account?" << endl;
		cout << "Y/N" << endl;
		char temp2;
		cin >> temp2;
		if (temp2 == 'Y')
		{
			int temp;
			cout << "what is your user ID?" << endl;
			cin >> temp;
			login(&users[temp]); //passes pointer to the users account to login//
		}
		else
		{
			string  temp1;
			string Pword;
			char admin;

			cout << "what is your user name?" << endl;
			cin >> temp1;
			cout << "are you an admin?; Y/N" << endl;
			cin >> admin;
			cout << "Etner in a password" << endl;
			cin >> Pword;
			users[total_accounts] = account(temp1, Pword, admin == 'Y'); //passes temp1,pword, and admin check to the constructor// 
																		 // made users for the accounts// 
			cout << "your user ID is  " << total_accounts << endl;
			total_accounts++; // goes  though the accounts till ten which is the full amount; 

		}
	}

}


