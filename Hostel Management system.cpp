//Al-WALEED BOYS HOSTEL MANAGEMENT SYSTEM.

//Header Files:
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <process.h>
#include <string.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//Classes & Functions:
class person
{
public:
    char date[20];
    char name[80];
    char father[50];
    char age[50];
    char cnic[50];
    char fcnic[50];
    char qualif[50];
    char religion[50];
    char city[50];
    char contact[50];
    char email[50];

public:
    void getData(void)
    {
        system("cls");
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << setw(115) << "=========================================================\n";
        cout << setw(115) << "||  NEW ADMISSION FORM - PLEASE FILL THE PROPER DATA   ||\n";
        cout << setw(115) << "=========================================================\n";
        cout << setw(150) << "--------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << setw(84) << "Enter date: ";
        cin.get(date, 20);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter name: ";
        cin.get(name, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter age: ";
        cin.get(age, 10);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter Father's name: ";
        cin.get(father, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter CNIC: ";
        cin.get(cnic, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter Father's CNIC: ";
        cin.get(fcnic, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter Qualification: ";
        cin.get(qualif, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter Religion: ";
        cin.get(religion, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter City: ";
        cin.get(city, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter Contact: ";
        cin.get(contact, 80);
        cin.ignore();

        cout << "\n";
        cout << setw(84) << "Enter Email: ";
        cin.get(email, 80);
        cin.ignore();
    }
    void showData(void)
    {
        Sleep(80);
        cout << setw(84) << "Date of Admission: " << date << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Name: " << name << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Age: " << age << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Father's name: " << father << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "CNIC: " << cnic << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Father's CNIC: " << fcnic << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Qualification: " << qualif << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Religion: " << religion << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "City: " << city << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Contact: " << contact << "\n";
        cout << "\n";
        Sleep(80);
        cout << setw(84) << "Email: " << email << "\n";
        cout << "\n";
    }

    void showList(void)
    {
        person pers;
        ifstream form;

        form.open("Persfile.DAT", ios::in | ios::binary);
        form.seekg(0, ios::end);
        int endposition = form.tellg();
        int n = endposition / sizeof(person);
        int count = n;
        for (int l = 1; l <= count; l++)
        {
            n = l;
            int position = (n - 1) * sizeof(person);
            form.seekg(position);
            form.read(reinterpret_cast<char *>(&pers), sizeof(pers));
            cout << setw(75) << l << "=> " << pers.name << endl;
        }
    }

    void diskIn(int);
    void diskOut();
    static int diskCount();
};

void person::diskIn(int pn)
{
    ifstream infile;
    infile.open("Persfile.DAT", ios::binary);
    infile.seekg(pn * sizeof(person));
    infile.read((char *)this, sizeof(*this));
}

void person::diskOut()
{
    ofstream outfile;
    outfile.open("Persfile.DAT", ios::app | ios::binary);
    outfile.write((char *)this, sizeof(*this));
}

int person::diskCount()
{
    ifstream infile;
    infile.open("Persfile.DAT", ios::binary);
    infile.seekg(0, ios::end);
    return (int)infile.tellg() / sizeof(person);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int login()
{
    int i = 0;
    while (i < 5)
    {
        cout << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n";
        cout << setw(115) << "=========================================================\n";
        cout << setw(115) << "||  WELCOME TO AL-WALEED BOYS HOSTEL MANAGEMENT SYSTEM ||\n";
        cout << setw(115) << "=========================================================\n";
        cout << "\n";

        string code;
        cout << setw(73) << "Enter Password: ";
        cin >> code;
        cout << "\n";

        if (code == "112200")
        {
            system("color F0");
            cout << "\n";
            cout << setw(95) << "|------------------|\n";
            cout << setw(95) << "| LOGIN SUCCESSFUL |\n";
            cout << setw(95) << "|------------------|\n";
            system("pause");
            break;
        }
        else
        {
            cout << "\n\a";
            i++;
            system("color F4");
            system("cls");
        }
    }
    if (i == 5)
    {
        cout << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n";
        cout << setw(118) << "===========================================================\n\a";
        cout << setw(118) << "||  TOO MANY LOGIN ATTEMPTS - PROGRAM WILL NOW TERMINATE ||\n\a";
        cout << setw(118) << "===========================================================\n\a";
        system("pause");
        exit(0);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void entry()
{
    char ch;
    do
    {
        person p;
        p.getData();
        p.diskOut();
        cout << "\n"
             << "\n";
        cout << setw(105) << "------------------------------------------------";
        cout << " \n";
        cout << setw(100) << "Do another entry (y/n)? ";
        cin >> ch;
        system("cls");

    } while (ch == 'y');
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void data()
{
    int c = person::diskCount();
    system("cls");
    cout << "\n"
         << "\n"
         << "\n";
    cout << setw(95) << "=========================\n";
    cout << setw(95) << "|| -- Students Data -- ||\n";
    cout << setw(95) << "=========================\n";
    cout << "\n"
         << "\n"
         << "\n";
    cout << setw(65) << "There are " << c << " Students in Hostel | " << 50 - c << " Vacancies are empty.\n";
    cout << "\n"
         << "\n"
         << "\n";
    cout << setw(105) << "-------------------------------------------\n";
    cout << "\n"
         << "\n";

    person list;
    list.showList();
    cout << "\n";
    int d;
    cout << setw(100) << "Enter Student number to show his data: ";
    cin >> d;
    system("cls");
    cout << " \n"
         << " \n"
         << " \n"
         << " \n"
         << " \n";
    cout << setw(105) << "------------------------------------------------";
    cout << " \n"
         << "\n";

    ifstream form;
    form.open("Persfile.DAT", ios::in | ios::binary);
    form.seekg(0, ios::end);
    int endposition = form.tellg();
    int position = (d - 1) * sizeof(person);
    form.seekg(position);
    form.read(reinterpret_cast<char *>(&list), sizeof(list));

    list.showData();
    cout << " \n";
    cout << setw(105) << "------------------------------------------------";
    cout << " \n";
    cout << " \n";
    system("pause");
    system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void print(){
    system("cls");
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    char pname[50], pfname[50], pfees[50], pdate[50];
    ofstream file;
    file.open("print.txt");

    cout<<setw(86)<<"Enter Your name: ";
    cin.get(pname, 50);
    cin.ignore();

    cout<<"\n"<<"\n";
    cout<<setw(86)<<"Enter Your Fathers name: ";
    cin.get(pfname, 50);
    cin.ignore();

    cout<<"\n"<<"\n";
    cout<<setw(86)<<"Enter fees amount Rs: ";
    cin.get(pfees, 50);
    cin.ignore();

    cout<<"\n"<<"\n";
    cout<<setw(86)<<"Enter date: ";
    cin.get(pdate, 50);
    cin.ignore();

    file<<"\n";
    file<<"=========================================================\n";
    file<<"||     Monthly Fees Recipt | Al-Waleed Boys Hostel     ||\n";
    file<<"=========================================================\n";
    file<<"---------------------------------------------------------\n";

    file<<"Name: "<<pname<<"\n";
    file<<"Fathers Name: "<<pfname<<"\n";
    file<<"Fees Amount: "<<pfees<<"\n";
    file<<"Date: "<<pdate<<"\n";

    file<<"---------------------------------------------------------\n";
    file<<"\n";
    file<<"\n";
    file<<"\n";
    file<<"\n";
    file<<"___________________\n";
    file<<" Stamp / Signature";
    file.close();
    

    system("cls");
    cout<<"\n"<<"\n";
    cout<<"\n"<<"\n";
    cout<<"\n"<<"\n";
    cout<<"\n"<<"\n";

    cout<<setw(110)<<"=========================================================\n";
    cout<<setw(110)<<"||     Monthly Fees Recipt | Al-Waleed Boys Hostel     ||\n";
    cout<<setw(110)<<"=========================================================\n";
    cout<<setw(110)<<"---------------------------------------------------------\n";

    cout<<setw(80)<<"Name: "<<pname<<"\n"<<"\n";
    cout<<setw(80)<<"Fathers Name: "<<pfname<<"\n"<<"\n";
    cout<<setw(80)<<"Fees Amount: "<<pfees<<"\n"<<"\n";
    cout<<setw(80)<<"Date: "<<pdate<<"\n"<<"\n";

    cout<<setw(110)<<"---------------------------------------------------------\n";
    cout<<setw(110)<<"\n";
    cout<<setw(110)<<"\n";
    cout<<setw(110)<<"\n";
    cout<<setw(80)<<"\n";
    cout<<setw(80)<<"___________________\n";
    cout<<setw(80)<<" Stamp / Signature";

    cout<<"\n";
    cout<<"\n";
    cout<<"\n"<<"\n";
    cout<<"\n"<<"\n";
    cout<<setw(90)<<"----------------------\n";
    cout<<setw(90)<<" Press Enter to Print \n";
    cout<<setw(90)<<"----------------------\n";
    getch();
    cout<<setw(80)<<"Printing";
    for(int i=0; i<20; i++){
        cout<<"-";
        Sleep(200);
        i++;
    }
    system("notepad /p print.txt");
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu()
{
    system("cls");
    cout << setw(100) << " \n";
    cout << setw(100) << " \n";
    cout << setw(100) << " \n";
    cout << setw(100) << " \n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n";
    cout << setw(115) << "=========================================================\n";
    cout << setw(115) << "||  WELCOME TO AL-WALEED BOYS HOSTEL MANAGEMENT SYSTEM ||\n";
    cout << setw(115) << "=========================================================\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << setw(95) << "=====================\n";
    cout << setw(95) << "|| -- Main Menu -- ||\n";
    cout << setw(95) << "=====================\n";
    cout << setw(100) << " \n";
    cout << setw(100) << " \n";
    cout << setw(100) << " \n";
    cout << setw(100) << " \n";
    cout << setw(100) << " \n";
    cout << setw(100) << "For New admission click (n): \n";
    cout << "\n";
    cout << setw(100) << "For Students Data click (d): \n";
    cout << "\n";
    cout << setw(100) << "To Print Fees Recipt click (p): \n";
    cout << "\n";
    cout << setw(100) << "To exit click (0): \n";
    cout << setw(84) << " ";
    int c = person::diskCount();
    char h;
    cin >> h;
    cin.ignore();
    if (c <= 50)
    {
        switch (h)
        {
        case 'n':
            entry();
            return menu();
            break;

        case 'd':
            data();
            return menu();
            break;

        case 'p':
            print();
            return menu();
            break;
        case '0':
            exit(0);
            break;

        default:
            system("cls");
            cout << "\n"
                 << "\n"
                 << "\n"
                 << "\n"
                 << "\n"
                 << "\n"
                 << "\n"
                 << "\n"
                 << "\n"
                 << "\n";
            cout << setw(93) << "Invalid Input\n";
            system("pause");
            system("cls");
            return menu();
            break;
        }
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////

//Starting of Main() function;
int main()
{
    system("color F0");  //For Background Color
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //For Full Screen Console
    SetConsoleTitleA("Al-Waleed Boys Hostel"); //Title of Console

    login();  //Login Function

    menu();  //Menu Function

}
