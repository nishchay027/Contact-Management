#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

string fname,lname,phone_num;


bool check_digits(string x){

    if(x.length() == 10){
        return true;
    }
    else{
        return false;
    }
}


void addContact(){

    ofstream phone("number.txt", ios::app);

    system("cls");

    cout << "Enter First Name : ";
    cin >> fname;

    cout << "Enter Last Name : ";
    cin >> lname;

    cout << "Enter 10-Digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) == true){

            if(phone.is_open()){

                phone << fname << " " << lname << " " << phone_num << endl;
                cout << "Contact Saved Successfully!";
            }
            else{
                cout << "Error Opening File !";
            }
        }
    else{
        cout << "A Phone Number Must Contain 10 Digits";
    }

    phone.close();
}


void searchContact(){

    bool found = false;

    ifstream myfile("number.txt");

    string keyword;
    cout << "\n\tEnter Name To Search: ";
    cin >> keyword;

    while(myfile >> fname >> lname >> phone_num){

        if(keyword == fname || keyword == lname){

            system("cls");

            cout << "Contact details..";
            cout << "First Name : " << fname;
            cout << "Last Name : " << lname;
            cout << "Phone Number : " << phone_num;

            found = true;
            break;
        }
    }

    if(found == false){
        cout << "No Such Contact Found";
    }
}


void help(){
    cout << "This displays help";
}


void self_exit(){

    system("cls");

    cout << "Thank You For Using !";
    exit(1);
}


int main(){

    int choice;

    system("cls");
    system("color 0A");

    cout << "Contact Management" << endl << endl;
    cout << "1. Add Contact\n2. Search Contact\n3. Help\n4. Exit\n> ";
    cin >> choice;

    switch(choice){

        case 1: addContact();
                break;

        case 2: searchContact();
                break;

        case 3: help();
                break;

        case 4: self_exit();
                break;

        default: cout << "Invalid Input!" << endl;
                 cout << "Press Any Key To Continue...";
                 getch();
                 main();
    }
}