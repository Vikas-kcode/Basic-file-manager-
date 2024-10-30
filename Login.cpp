#include <iostream>

#include <fstream>

#include <string>

#include <algorithm>



using namespace std;



struct User {

    string username;

    string password;

};



void registerUser() {

    User user;

    cout << "Enter username: ";

    cin >> user.username;

    cout << "Enter password: ";

    cin >> user.password;



    ifstream file(user.username + ".txt");

    if (file.is_open()) {

        cout << "Username already exists. Please choose another username." << endl;

        return;

    }

    file.close();



    ofstream outputFile(user.username + ".txt");

    outputFile << user.username << endl;

    outputFile << user.password << endl;

    outputFile.close();



    cout << "Registration successful!" << endl;

}



void loginUser() {

    string username, password;

    cout << "Enter username: ";

    cin >> username;

    cout << "Enter password: ";

    cin >> password;



    ifstream file(username + ".txt");

    if (!file.is_open()) {

        cout << "Username does not exist." << endl;

        return;

    }



    string storedUsername, storedPassword;

    file >> storedUsername;

    file >> storedPassword;

    file.close();



    if (password == storedPassword) {

        cout << "Login successful!" << endl;

    } else {

        cout << "Incorrect password." << endl;

    }

}



int main() {

    int choice;

    while (true) {

        cout << "1. Register" << endl;

        cout << "2. Login" << endl;

        cout << "3. Exit" << endl;

        cin >> choice;



        switch (choice) {

            case 1:

                registerUser();

                break;

            case 2:

                loginUser();

                break;

            case 3:

                return 0;

            default:

                cout << "Invalid choice. Please choose again." << endl;

        }

    }



    return 0;

}
