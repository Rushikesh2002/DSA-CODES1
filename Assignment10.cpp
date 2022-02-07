#include <iostream>
#include <fstream>
using namespace std;
class student
{
public:
    int rn;
    char div[20];
    char name[20], adr[20];
};
class File
{
    char fname[20];

public:
    void create();
    void display();
    void add();
    void Delet(int rn);
    void search(int rn);
    void modify(int rn);
};

void File ::create()
{
    ofstream fp; // write into file
    student s;
    char option;
    cout << "Enter File name to be opened\n";
    cin >> fname;
    fp.open(fname);
    do
    {
        cout << "Enter student Roll No, Div, Name, Address\n";
        cin >> s.rn >> s.div >> s.name >> s.adr;
        fp.write((char *)(&s), sizeof(s));
        cout << "Do you want to add more records (y/n) \n";
        cin >> option;
    } while (option == 'y');
    fp.close();
}
void File ::display()
{
    ifstream fp; // read from file
    student s;
    fp.open(fname);
    cout << "Roll No\tDiv\tName\tAddress\n";
    cout << "-------------------------------" << endl;
    fp.read((char *)(&s), sizeof(s));
    while (!fp.eof())
    {
        cout << s.rn << "\t" << s.div << "\t" << s.name << "\t" << s.adr << "\n";
        fp.read((char *)(&s), sizeof(s));
    }
    fp.close();
}
void File ::add()
{
    fstream fp;
    student s;
    fp.open(fname, ios::app);
    cout << "Enter records to be added \n Enter Roll No\tDiv\tName\tAddress\n";
    cin >> s.rn >> s.div >> s.name >> s.adr;
    fp.write((char *)(&s), sizeof(s));
    fp.close();
}
void File ::search(int rn)
{
    fstream fp;
    student s;
    int flag = 0;
    fp.open(fname);
    fp.read((char *)(&s), sizeof(s));
    while (!fp.eof())
    {
        if (rn == s.rn)
        {
            flag = 1;
            break;
        }
        fp.read((char *)(&s), sizeof(s));
    }
    if (flag == 1)
    {
        cout << "Record is Found" << endl;
        cout << "Roll.no\t Div \tName \tAddress " << endl;
        cout << s.rn << " \t " << s.div << "\t " << s.name << "\t " << s.adr << "\n ";
        cout << "----------------------------" << endl;
    }
    else
        cout << "Record not found\n";
    fp.close();
}
void File ::Delet(int rn)
{
    ifstream fp1;
    ofstream fp2;
    student s;
    int flag = 0;
    fp1.open(fname);
    fp2.open("temp.txt");
    fp1.read((char *)(&s), sizeof(s));
    while (!fp1.eof())
    {
        if (rn == s.rn)
        {
            cout << "Record deleted " << endl;
            cout << "Roll.no\t Div\t Name\t Address " << endl;
            cout << s.rn << "\t" << s.div << "\t" << s.name << "\t" << s.adr << "\n";
            cout << "-------------------------------" << endl;
            flag = 1;
        }
        else
            fp2.write((char *)(&s), sizeof(s));
        fp1.read((char *)(&s), sizeof(s));
    }
    if (flag == 0)
        cout << "Record not found\n";

    fp1.close();
    fp2.close();
    remove(fname);
    rename("temp.txt", fname);
}
void File::modify(int rn)
{
    ifstream fp;
    ofstream tempfile;
    student s;
    int flag = 0;
    fp.open(fname);
    tempfile.open("Temp.txt");
    fp.read((char *)(&s), sizeof(s));
    while (!fp.eof())
    {
        if (rn == s.rn)
        {

            cout << "Record is Found" << endl;
            cout << "Roll.no\t Div \tName \tAddress " << endl;
            cout << s.rn << " \t " << s.div << "\t " << s.name << "\t " << s.adr << "\n ";
            cout << "----------------------------" << endl;

            cout << "Enter Modify data :" << endl;
            cout << "Enter student Roll No, Div, Name, Address\n";
            cin >> s.rn >> s.div >> s.name >> s.adr;

            flag = 1;
        }
        tempfile.write((char *)&s, sizeof(s));
        fp.read((char *)(&s), sizeof(s));
    }
    if (flag == 0)
        cout << "Record for Roll No. " << rn << " not found " << endl;
    else
        cout << "Record Modified Successfully" << endl;

    fp.close();
    tempfile.close();
    remove(fname);
    rename("Temp.txt", fname);
}
int main()
{
    int choice, rn;
    File obj;
    do
    {
        cout << "Select operation from : \n 1) Create records \n 2) Display records \n 3) Add records \n 4) Remove records \n 5) Search records \n 6) Modify records \n 7) exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.add();
            break;
        case 4:
            cout << "Enter student Roll No whose record to be deleted\n ";
            cin >> rn;
            obj.Delet(rn);
            break;

        case 5:
            cout << "Enter student Roll No whose record to be  searched\n ";
            cin >> rn;
            obj.search(rn);
            break;
        case 6:
            cout << "Enter student Roll No whose record to be Modify\n ";
            cin >> rn;
            obj.modify(rn);
            break;
        case 7:
            cout << "Exit\n";
            break;
        default:
            cout << "Wrong Choice\n";
            break;
        }
    } while (choice != 7);
    return 0;
}