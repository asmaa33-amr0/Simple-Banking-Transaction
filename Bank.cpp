

#include <iostream>
#include <string>
using namespace std;


struct clients_acc {
    string username;
    string password;
    int balance;
};

// array of struct to hold data for 5 clients  called "client"
clients_acc client[5];


struct account
{
    char user_name;
    char ac_num;
    int balance;
};

//un is an Abbreviation for username
string un, new_un;

int x = 2;
int withDraw_Deposit_Amount, Balance = 500000, whichOne = 0;

//fun check if the password belongs to this client's account
void check_pw();

//the fun that  starts the modification by asking the admin to enter the client's username
void modification();

// fun to show the options can be edited
void adminmenu();

// fun to edit the username works with the username entered by the user,the new username in case the user changed it and the array"client" i made
void edit_un(clients_acc client[], string& un, string new_un);

//fun to edit the password works with the username entered by the user and the array"client" i made
void edit_pw(clients_acc client[], string& un);

void delay(int a);
void inputValid();
void notZeroInput();
void Deposit(string& username);
void withDraw(string& username);
void goodAmount();
void depositCout();
void withdrawCout();
void Choosing();
void user_name(clients_acc client[], int& x);
void pass_word(clients_acc client[], int& x);
void close_acc();

//function to display all account details
void list_accounts(int& x);
;
void return_to_admins_list();
void return_to_clints_list(string& username);
int main() {

    while (true) {

        // examples for clients accounts to test the code
        client[0].username = "ahmed"; client[0].password = "123"; client[0].balance = 500000;
        client[1].username = "mohamed"; client[1].password = "1234"; client[1].balance = 4545454;

        int key;
        int exit;
        string username1 = "manager", password1 = "iamaadmin", password, username;


        //login
        cout << "Enter username please" << endl;
        cin >> username;
        cout << "Enter password please" << endl;
        cin >> password;
        cout << "You have logged in successfully  Thank you" << endl;


        //if the user is an admin
        if (username1 == username && password1 == password) {

            cout << "Press 1 to Add a New Account" << endl;
            cout << "Press 2 to Modify An Account" << endl;
            cout << "Press 3 to Close An Account" << endl;
            cout << "Press 4 to List All Accounts" << endl;
            cin >> key;
            if (key == 1) {
                
                user_name(client, x);
            }
            else if (key == 2) {


                modification();
            }
            else if (key == 3) {
                close_acc();
            }
            else {
                list_accounts(x);
            }
        }


        //if the user is a client  
        else {
            cout << " Welcome to banking with us " << endl;
            cout << "Press 1 to Balance Enquiry" << endl;
            cout << "Press 2 to Withdraw Amount or  Deposit Amount" << endl;
            cin >> key;
            if (key == 1) {
                for (int i = 0; i < 5; i++) {
                    if (username == client[i].username ) {

                        cout << "Your current balance : " << client[i].balance << endl;
                        break;
                    }
                    
                }
            }

            else if (key == 2) {
                cout << "If you want to WithDraw Enter 3  " << endl;
                cout << "If you want to deposit Enter 4  " << endl;
                cin >> whichOne;
                cout << endl;

                if (whichOne == 3) {
                    withDraw(username);
                    cout << endl;
                }
                else if (whichOne == 4)
                    Deposit(username);
                cout << endl;
            }
        }

        cout << "If you want to Logout press 0" << endl;
        cout << "If you want to do another operation press 1" << endl;
        cin >> exit;

        if (exit == 0) {
            break;
        }
        //checking to display admins list agin 
        else if (exit == 1 && username1 == username && password1 == password)
            return_to_admins_list();
        //checking to display clints list agin 
        else
            return_to_clints_list(username);
        return 0;
    }
}














































void check_pw() {
    string prev_pw, ans4; bool flag = true;
    for (int i = 0; i < 5; i++) {
        if (un == client[i].username) {
            cout << "enter the client's password  \n";
            cin >> prev_pw;
            if (prev_pw != client[i].password) {// to check if the password belongs to this account or not
                cout << "wrong password\n";
                cout << "press '0' to go back  or any other key to try again\n";
                cin >> ans4;
                flag = false;
                if (ans4 == "0") {
                    modification();
                    break;
                }
                else {
                    check_pw();
                    break;
                }
            }
        }
    }
    if (flag)
        adminmenu();

}


void modification() {
    bool sign = true;
    cout << "enter the client's username \n";
    cin >> un;
    for (int i = 0; i < 5; i++) {
        if (un == client[i].username) {//to know which accout we are editing to change it later
            sign = false;
            check_pw();
            break;
        }
    }
    while (sign) {
        cout << "wrong username please try again\n";
        modification();
        break;
    }
}


void adminmenu() {
    int ans2;
    cout << "press : \n";
    cout << "1.to change the username\n";
    cout << "2.to change the password\n";
    cout << "3.to modify another accout\n";
    cin >> ans2;
    if (ans2 == 1)
        edit_un(client, un, new_un);
    else if (ans2 == 2)
        edit_pw(client, un);
    else if (ans2 == 3)
        modification();
    else {
        cout << "invalid order \n";

    }
}


void edit_pw(clients_acc client[], string& un) {
    int ans; char ans2; string ans3;
    string new_pw2, new_pw;
    for (int i = 0; i < 5; i++) {
        if (un == client[i].username) {//to know which accout we are editing to change it later
            cout << "please enter the new password \n";
            cin >> new_pw;
            cout << "please confirm the password\n";
            cin >> new_pw2;
            while (new_pw2 != new_pw) {
                cout << "passwords do no match please try again\n";
                cin >> new_pw2;
            }
            client[i].password = new_pw;//changes the password
            cout << "the password has been changed successfully\n ";
            break;
        }
    }
    cout << "if you want to edit anything else \n";
    adminmenu();
}


void edit_un(clients_acc client[], string& un, string new_un) {
    string ans3;
    for (int i = 0; i < 5; i++) {
        if (un == client[i].username) {//to know which accout we are editing to change it later
            cout << "please enter the new username\n";
            cin >> new_un;
            for (int j = 0; j < 5; j++) {
                if (new_un == client[j].username) {//to check if the new username is alreade taken by any other account
                    while (new_un == client[j].username) {// will run untill he enter 0 or enter a valid username
                        cout << "the username is already taken\n";
                        cout << "press '0' to go back to the menu or any other key to try again\n";
                        cin >> ans3;
                        if (ans3 == "0")
                            adminmenu();
                        else {
                            cout << "please enter the new username\n";
                            cin >> new_un;

                        }

                    }
                }
            }
            client[i].username = new_un;  //changes the username
            cout << "the username has been changed successfully to \t" << client[i].username << endl;
            break;
        }
    }un = new_un;

    cout << "if you want to edit anything else\n";  adminmenu();
}


// To know which operation to do 
void Choosing() {
    if (whichOne == 3)
        withdrawCout();
    else if (whichOne == 4)
        depositCout();

}


void depositCout() {

    cout << endl << "Please , Enter the amount you want to Deposit : ";
}


void withdrawCout() {

    cout << endl << "Please , Enter the amount you want to withdraw : ";
}


void delay(int a)
{
    int add = 0;
    long time;
    int i;

    time = a * 100000000;

    for (int i = 0; i < time; i++) // To take enough time;
    {
        add *= i;
        add++;
    }
}


void goodAmount()
{
    while (withDraw_Deposit_Amount % 10 != 0)
    {
        cout << endl << "Sorry , Enter amount like this (100 , 1000 , ... )" << endl;
        cout << endl << "Please , try again" << endl;
        Choosing();
        inputValid();
        notZeroInput();
    }
}


void inputValid()     // Function to force the user to input integers
{
    while (!(cin >> withDraw_Deposit_Amount))
    {
        cout << endl << "Sorry , Please enter an integers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        Choosing();
    }
}


void notZeroInput()
{


    while (withDraw_Deposit_Amount < 0 || withDraw_Deposit_Amount == 0)
    {
        cout << endl << "Sorry , you must enter an amount bigger than Zero " << endl;
        cout << endl << "Please , try again" << endl;
        Choosing();
        inputValid();
    }
}


void Deposit(string& username)
{

    cout << "Please , Enter the amount you want to Deposit : ";


    inputValid();            // Check if input is integer or not
    notZeroInput();          // Check if input bigger than zero 
    goodAmount();     // Check if input like this (100, 1000 , ...)
    for (int i = 0; i < 5; i++) {
        if (username == client[i].username) {
            client[i].balance += withDraw_Deposit_Amount;
            cout << endl << "Please wait ... \n" << endl;
            delay(10); // To delay the operation 

            cout << "Successful Deposit operation , Your new Balance is :" << client[i].balance << endl;
            cout << endl << " -----------------------------------------------------------" << endl;
            cout << "             -----------------------------------               " << endl;
            cout << "                         --------------               ";
        }
    }
}


void withDraw(string& username)
{

    cout << "Please , Enter the amount you want to withdraw : ";

    inputValid();            // Check if input is integer or not
    notZeroInput();          // Check if input bigger than zero 
    goodAmount();     // Check if input like this (100, 1000 , ...)


    while (withDraw_Deposit_Amount > Balance)     // If the withdraw amount is bigger than balance enter again
    {
        cout << endl << "Sorry , your balance is not enough \n";
        cout << endl << "Please , try again \n";
        cout << endl << "Please , Enter the amount you want to withdraw  : ";
        inputValid();
        notZeroInput();
        goodAmount();
    }
    for (int i = 0; i < 5; i++) {
        if (username == client[i].username) {
            client[i].balance -= withDraw_Deposit_Amount;
            cout << endl << "Please wait ... \n" << endl;
            delay(10); // To delay the operation 

            cout << "Successful Withdrawal , Your new Balance is :" << client[i].balance << endl;
            cout << endl << " -----------------------------------------------------------" << endl;
            cout << "             -----------------------------------               " << endl;
            cout << "                         --------------               ";
            break;
        }
    }
}


void user_name(clients_acc client[], int& x)
{
  
    bool sin = true;
    string new_user;
    cout << "enter the user name\n";
    cin >> new_user;
    for (int j = 0; j < 5; j++) {
        if (new_user == client[j].username) {//to check if the new username is alreade taken by any other account
            sin = false;
            while (new_user == client[j].username) {// will run untill he enter 0 or enter a valid username
                cout << "the username is invalid\n";
                cout << "press '0' to go back or any other key to try again\n";
                string ans;
                cin >> ans;
                if (ans == "0")
                    break;
                else {
                    cout << "please enter the new username\n";
                    cin >> new_user;
                }
            }
        }
    }
    if (sin)
    {
        client[x].username = new_user;
        pass_word(client, x);
    }
}


void pass_word(clients_acc client[], int& x)
{
    cout << "enter the password\n";
    string pass;
    cin >> pass;
    client[x].password = pass;
    ++x;
    cout << "Do you want to add another account? y / n \n";
    char c;
    cin >> c;
    if (c == 'y')
    {
        user_name(client, x);
    }
}


void close_acc()
{
    string old_user, old_pass;
    cout << "enter the user name you want to close\n";
    cin >> old_user;
    cout << "enter the password\n";
    cin >> old_pass;
    for (int j = 0; j < 5; j++)
    {
        if (old_user == client[j].username)
        {
            client[j].username = '0';
            client[j].password = '0';
        }
    }
    cout << "successfully closed " << endl;
}


//function to display all accounts details
void list_accounts(int& x)
{
    int ch;
    string user_name[100], admin;
    int ac_num, balance[100];
    cout << "ADMIN'S ACCOUNT :---" << admin << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "User name :" << client[i].username << endl;
        cout << "Password :" << client[i].password << endl;
        cout << "balance : " << client[i].balance << endl;
    }
}
//function to return to admins list
void return_to_admins_list() {
    int key;
    cout << "Press 1 to Add a New Account" << endl;
    cout << "Press 2 to Modify An Account" << endl;
    cout << "Press 3 to Close An Account" << endl;
    cout << "Press 4 to List All Accounts" << endl;
    cin >> key;
    if (key == 1) {
        user_name(client, x);
    }
    else if (key == 2) {


        modification();
    }
    else if (key == 3) {
        close_acc();
    }
    else {
        list_accounts(x);
    }
    for (int i = 0; i < 2; i++) {
        int exit;
        cout << "If you want to Logout press 0" << endl;
        cout << "If you want to do another operation press 1" << endl;
        cin >> exit;
        if (exit == 0)
            break;

        //checking to display admins list agin 

        return_to_admins_list();

    }

}
//function to return to clints list
void return_to_clints_list(string& username) {
    int key;
    string password;
    cout << "Press 1 to Balance Enquiry" << endl;
    cout << "Press 2 to Withdraw Amount or  Deposit Amount" << endl;
    cin >> key;
    if (key == 1) {
        for (int i = 0; i < 5; i++) {
            if (username == client[i].username) {

                cout << "Your current balance : " << client[i].balance << endl;
                break;
            }
        }
    }

    else if (key == 2) {
        cout << "If you want to WithDraw Enter 3  " << endl;
        cout << "If you want to deposit Enter 4  " << endl;
        cin >> whichOne;
        cout << endl;

        if (whichOne == 3) {
            withDraw(username);
            cout << endl;
        }
        else if (whichOne == 4) {
            Deposit(username);
            cout << endl;
        }
    } for (int i = 0; i < 1; i++) {
        int exit;
        cout << "If you want to Logout press 0" << endl;
        cout << "If you want to do another operation press 1" << endl;
        cin >> exit;
        if (exit == 0)
            break;

        //checking to display clints list agin 

        return_to_clints_list(username);

    }

}