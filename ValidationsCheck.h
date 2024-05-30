#include<iostream>
#include<string>
#include<cmath>
#include <sstream>
#include <cctype>

using namespace std;

bool isAlphabetic(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

string getFirstName() {
    string fname;
    while (true) {
        cout << "Enter Your First Name: ";
        cin >> fname;
        if (isAlphabetic(fname)) {
            return fname;
        } else {
            cout << "Error: Invalid input. Please enter alphabetic characters only." << endl;
        }
    }
}

string getLastName() {
    string lname;
    while (true) {
        cout << "Enter Your Last Name: ";
        getline(cin, lname);
        if (isAlphabetic(lname)) {
            return lname;
        } else {
            cout << "Error: Invalid input. Please enter alphabetic characters only." << endl;
        }
    }
}

bool datecheck(int datedep) {
    int date = datedep / 1000000;
    int month = (datedep / 10000) % 100;
    int year = datedep % 10000;

    if (year > 2023 && month >= 1 && month <= 12 && date >= 1 && date <= 31)
        return true;
    
    return false;
}

int getValidDate() {
    int datedep;

    do {
        cout << "Enter date of departure (DDMMYYYY): ";
        cin >> datedep;

        if (!datecheck(datedep)) {
            cout << "Invalid date! Please enter a valid date." << endl;
        }

    } while (!datecheck(datedep));

    return datedep;
}

bool isNumeric(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

string getPhoneNumber() {
    string input;
    while (true) {
        cout << "Enter Your Phone Number (Without -): ";
        getline(cin, input);
        if (isNumeric(input)) {
            return input;
        }
        cout << "Error: Invalid input. Please enter a valid integer." << endl;
    }
}

long int getPassportNumber() {
    string input;
    while (true) {
        cout << "Enter Your Passport Number (Without -): ";
        cin.ignore();
        getline(cin, input);
        if (isNumeric(input)) {
            stringstream ss(input);
            long int passportNo;
            if(ss >> passportNo && ss.eof()) {
                return passportNo;
            }
        }
        cout << "Error: Invalid input. Please enter a valid integer." << endl;
    }
}