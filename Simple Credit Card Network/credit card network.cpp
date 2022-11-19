#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <istream>
#include <limits>


using namespace std;

string first_name;
string last_name;
string country;
int salary;
string credit_card_number;
string cvv;
string name;
string card_user_info;
int choose;
int credit = 10000;
int spend = 0;
int pay;
string password;
int card_passwd;

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}


void newcard() {
	cout << "Signup for a New Card" << endl;
	cout << "Enter First Name: "; cin >> first_name;
	cout << "Enter Last Name: "; cin >> last_name;
	cout << "Enter Country: "; cin >> country;
	cout << "Enter Salary (USD): "; cin >> salary;
	cout << "-------" << endl;
	if (salary >= 2000) {
		cout << "The Credit Card Registered Successful!" << endl;
		unsigned long long cardnumber;
		unsigned i;

		cardnumber = rand() % 9 + 1;

		for (i = 0; i < 15; i++)
		{
			cardnumber *= 10;
			cardnumber += rand() % 10;
		}

		unsigned long long cvv;
		unsigned j;

		cvv = rand() % 9 + 1;

		for (j = 0; j < 2; j++)
		{
			cvv *= 10;
			cvv += rand() % 10;
		}

		ofstream cardinfo;
		cardinfo.open(first_name + "_" + last_name + ".txt");
		cardinfo << cardnumber << endl;
		cardinfo << cvv << endl;
		cardinfo << first_name << endl;
		cardinfo << last_name << endl;
		cardinfo << country << endl;
		cardinfo.close();

		cout << "Card Password (6 digital): "; cin >> password;

		ofstream userpasswd;
		cardinfo.open(first_name + "_" + last_name + "_" + "passwd" + ".txt");
		cardinfo << password << endl;
		cardinfo.close();

	}
	else if (salary < 2000) {
		cout << "You don't have qualificate to Register Credit Card!" << endl;
	}
}


void check() {
	cout << "Enter First Name: "; cin >> first_name;
	cout << "Enter Last Name: "; cin >> last_name;
	cout << "Enter Card Password: "; cin >> password;

	ifstream userpasswd(first_name + "_" + last_name + "_" + "passwd" + ".txt");
	string card_passwd;
	while (getline(userpasswd, card_passwd)) {
		if (card_passwd == password) {
			cout << "Successful!" << endl;
			fstream cardinfo;
			cardinfo.open(first_name + "_" + last_name + ".txt");
			while (getline(cardinfo, card_user_info)) {
				cout << card_user_info << endl;
			}
		}
		else {
			cout << "Wrong Password or Name" << endl;
		}
	}
}


void payment() {
	cout << "Enter Credit Card Number: "; cin >> credit_card_number;
	cout << "Enter Credit Card CVV: "; cin >> cvv;
	cout << "Enter First Name: "; cin >> first_name;
	cout << "Enter Last Name: "; cin >> last_name;
	cout << "Amount Wanto to Pay: "; cin >> pay;

	fstream card_info(first_name + "_" + last_name + ".txt");

	GotoLine(card_info, 2);

	string info_cvv;
	card_info >> info_cvv;

	if (info_cvv == cvv) {
		cout << "Prossing...Payment" << endl;
		spend += pay;
		ofstream cardinfo_spend;
		cardinfo_spend.open(first_name + "_" + last_name + "_" + "spend" + ".txt");
		cardinfo_spend << spend << endl;
		cardinfo_spend.close();
		cout << "Successful!" << endl;
	}
	else {
		cout << "Prossing...Payment" << endl;
		cout << "Unsuccessful!" << endl;
	}
}



void spent() {
	cout << "Enter First Name: "; cin >> first_name;
	cout << "Enter Last Name: "; cin >> last_name;
	cout << "Enter Card Password: "; cin >> password;
	int credit = 10000;
	fstream card_spend;
	string card_spent;
	card_spend.open(first_name + "_" + last_name + "_" + "spend" + ".txt");
	while (getline(card_spend, card_spent)) {
		
		credit = credit - stoi(card_spent);
	}
	
	ifstream userpasswd(first_name + "_" + last_name + "_" + "passwd" + ".txt");
	string card_passwd;
	while (getline(userpasswd, card_passwd)) {
		if (card_passwd == password) {
			cout << "Successful!" << endl;
			
			cout << "Credit: " << credit << endl;
		}
		else {
			cout << "Wrong Password or Name" << endl;
		}
	}
}

int main()
{
	do{
	cout << "1. Register a New Credit Card; 2. Check Credit Card; 3. Make a Payment; 4. Card Spent; 5. Exit" << endl;
	cin >> choose;
	system("cls");

	switch (choose) {
	case 1:
		newcard();
		break;
	case 2:
		check();
		break;
	case 3:
		payment();
		break;
	case 4:
		spent();
		break;
	}
	} while (choose < 5);

	return 0;
}