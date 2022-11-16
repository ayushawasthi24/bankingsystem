#include <iostream>
#include <vector>
using namespace std;

void welcome();

class User {
public:
    string name;
    string ID;
    string PWD;
    double balance;
};

vector<User> uservector;
User *users = new User[10];
int noofusers=0;
void home(User s) {
    cout << "Choice List" << endl;
    cout << "1. Deposit Money" << endl << "2. Withdraw Money" << endl << "3. Balance Enquiry" << endl << "4. Transfer Money" << endl << "5. Logout" << endl;;
    int n;
    cin >> n;
    string d;
    int found=0;;
    double amt;
    switch(n) {
        case 1:
            cout << "Enter the amount to be deposited" << endl;
            cin >> amt;
            s.balance += amt;
            cout << amt << " successfully deposited in your account" << endl << "Your account balance is = " << endl << s.balance << endl;
            home(s);
            break;
        case 2:
            cout << "Enter the amount to be withdrawn" << endl;
            cin >> amt;
            if(s.balance >= amt){
                s.balance -= amt;
                cout << "Amount successfully withdrawn" << endl << "Your account balance is = " << endl << s.balance << endl;
            }
            else {
                cout << "Your account does not have sufficient balance" << endl;
            }
            home(s);
            break;
        case 3:
            cout << "Your account balance is = " << endl << s.balance << endl;
            home(s);
            break;
        case 4:
            cout << "Enter the amount to be transferred" << endl;
            cin >> amt;
            cout << "Enter the user id of the account you want to transfer the money to" << endl;
            cin >> d;
            for(auto i : uservector) {
                if(i.ID == d){
                    found = 1;
                    i.balance += amt;
                    s.balance -= amt;
                    cout << "Amount transferred successfully" << endl;
                    break;
                }
                else 
                    continue;
            }
            if(found == 0){
                cout << "User not found" << endl;
            }
            home(s);
            break;
        case 5:
            cout << "You have been successfully logged out" << endl;
            welcome();
            break;
        default :
            cout << "Invalid Choice" << endl;
            break;
    }
}

void login() {
    cout << "Enter your user ID" << endl;
    string id;
    cin >> id;
    int found = 0;
    for(auto i : uservector){
        if(i.ID == id){
            found =1;
            cout << "Enter password" << endl;
            string pwd;
            cin >> pwd;
            if(i.PWD == pwd){
                cout << "Hello " << i.name << endl;
                home(i);
            } else {
                cout << "The password is incorrect" << endl;
                return;
            }   
        }
        else {
            continue;
        }
    }
    if(found == 0) {
        cout << "User not found" << endl;
    }
}
void newuser() {
    noofusers++;
    cout << "Enter a new user ID and password respectively" << endl;
    string id;
    string pwd;
    cin >> id >> pwd;
    string n;
    cout << "Enter your name" << endl;
    cin >> n;
    users[noofusers].ID = id;
    users[noofusers].PWD = pwd;
    users[noofusers].name = n;
    uservector.push_back(users[noofusers]);
    cout << "You have been registered successfully" << endl;
    welcome();
}


void welcome(){
    cout << "1. Login" << endl << "2. New User" << endl << "3. Exit" << endl;
    int n;
    cin >> n;
    switch(n){
        case 1:
            login();
            break;
        case 2:
            newuser();
            break;
        case 3:
            return;
        default:
            cout << "Invalid Input" << endl;
            break;
    }
}

int main() {
    welcome();
    return 0;
}
