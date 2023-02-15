#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool run = true;

struct UserData {
    string username;
    string password;
};

int getAction()
{
    int action;

    cout << "Action Selector:" << endl;
    cout << "[1] Login" << endl;
    cout << "[2] Register" << endl;
    cout << "[3] Exit" << endl;

    cout << "Choose action: ";
    cin >> action;

    return action;
}

UserData getUserData()
{
    UserData userdata;

    cout << "Enter username: ";
    cin >> userdata.username;

    cout << "Enter password: ";
    cin >> userdata.password;

    return userdata;
}

bool validateAction(int action)
{
    if (action < 1 || action > 3) {
        return false;
    }

    else {
        return true;
    }
}

bool login() {
    UserData userdata = getUserData();
    string compPassword;

    ifstream read(userdata.username + ".txt");

    getline(read, compPassword);

    if (compPassword == userdata.password) {
        return true;
    }

    else {
        return false;
    }
}

bool registr() {
    UserData userdata = getUserData();

    ofstream file;

    file.open(userdata.username + ".txt");
    file << userdata.password << endl;
    file.close();

    return true;
}

int main(int argc, char** argv)
{
    int action, isActionValid;

    while (run) {
        action = getAction();
        isActionValid = validateAction(action);

        if (isActionValid) {
            if (action == 1) {
                bool loginResult = login();

                if (loginResult) {
                    cout << "Logged in successfully." << endl;
                    run = false;
                    continue;
                }

                else {
                    cout << "Login failed. Invalid credentials. Try again." << endl;
                    continue;
                }
            }

            else if (action == 2) {
                bool registrationResult = registr();
            }

            else if (action == 3) {
                run = false;
                continue;
            }
        }

        else {
            cout <<  "Invalid action. Try again." << endl;
            continue;
        }
    }

    return 0;
}
