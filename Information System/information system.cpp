#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

string username;
string passwd;
string content;
int number;
int choose;
string name;
int age;
string gender;
string phone;
ifstream infofile;
string infocontent;
string email;
string id;
int a;


void signup() {
	cout << "Enter New Username: ";
	cin >> username;
	cout << "Enter New Password: ";
	cin >> passwd;
	ofstream outfile(username + ".txt"); // create a file
	outfile << passwd; // input content into file
	outfile.close(); // close file

}

void system() {

	do {
		cout << "1. Personal Information Input; 2. Information Check; 3. Exit" << endl;
		cin >> choose;
		system("cls");

		if (choose == 1) {

			cout << "Enter Name: ";
			cin >> name;
			cout << "ID: ";
			cin >> id;
			cout << "Enter Age: ";
			cin >> age;
			cout << "Enter Gender (M / F): ";
			cin >> gender;
			cout << "Enter Email: ";
			cin >> email;
			cout << "Enter Phone Number: ";
			cin >> phone;

			ofstream infofile(username + "_info.txt");
			infofile << "Name: " << name << endl;
			infofile << "ID: " << id << endl;
			infofile << "Age: " << age << endl;
			infofile << "Gender: " << gender << endl;
			infofile << "Email: " << email << endl;
			infofile << "Phone Number: " << phone << endl;
			infofile.close();

			ofstream listfile("check_list.txt", ios::app);
			listfile << username << " " << name << " " << id << endl;
			listfile.close();


		}
		else if (choose == 2) {

			cout << "Enter the username: ";
			cin >> username;
			infofile.open(username + "_info.txt");
			while (getline(infofile, infocontent)) {
				cout << infocontent << endl;
			}
		}
	} while (choose != 3);
}

void login() {

	ifstream datafile(username + ".txt"); // putin the file name
	getline(datafile, content); // get the content from file and storage into content

	datafile.close();

	for (int i = 0; i <= 3; i++) {
		cout << "Enter Username: ";
		cin >> username;

		cout << "Enter Password: ";
		cin >> passwd;

		if (content == passwd) {
			cout << "Successful Login to System --- " + username << endl;
			a = 1;
			break;
		}
		else {
			cout << "Wrong password or username" << endl;
			a = 2;
		}
	}

}



int main()
{
	do {
		cout << "1. Signup; 2. Login; 3. Exit" << endl;
		cin >> number;
		system("cls");

		switch (number) {
		case 1:
			signup();
			break;
		case 2:
			login();
			if (a == 1) {
				system();
				cout << "Already Logout Account!" << endl;
				break;
			}
			else if (a == 2) {
				break;
			}

		}
	} while (number > 2 || number == 1);

	return 0;

}
