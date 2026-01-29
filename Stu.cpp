#include <iostream>
#include <fstream>
#include "Stu.h"
using namespace std ;

           //setters
void Student::set_student_no(string i) { student_no = i; }
void Student::set_name(string n) { name = n; }
void Student::set_sex(string s) { sex = s; }
void Student::set_age(int a) { age = a ; }
void Student::set_institution(string in) { institution = in; }
void Student::set_major(string m) { major = m; }

           //getters
string Student::get_student_no() const { return student_no; }
string Student::get_name() const { return name; }
string Student::get_sex() const { return sex; }
int Student::get_age() const { return age; }
string Student::get_institution() const { return institution; }
string Student::get_major() const { return major; }

           //input & display
void Student::input_student()
{
    cout << "Enter student no: ";
    getline (cin , student_no);

    cout << "Enter name: ";
    getline (cin , name);

    cout << "Enter sex (male or female): ";
    getline (cin , sex);
    for ( ; sex != "male" && sex != "female" ; )
     {
        cout << "Invalid input! Please enter 'male' or 'female' only." << endl;
        getline (cin , sex);
     }

    cout << "Enter age: ";
    cin >> age;
    for ( ; age <= 0 ; )
    {
        cout << "Invalid input! Please enter positive number only." << endl;
        cin >> age;
    }
    cin.ignore ();

    cout << "Enter institution: ";
    getline (cin , institution);

    cout << "Enter major: ";
    getline (cin , major);
}
void Student::display_student() const
{
    cout << "=================================" << endl;
    cout << "Student no is          : " << student_no << endl;
    cout << "Student name is        : " << name << endl;
    cout << "Student sex is.        : " << sex << endl;
    cout << "Student age is         : " << age << endl;
    cout << "Student institution is : " << institution << endl;
    cout << "Student major is       : " << major << endl;
    cout << "=================================" << endl;
}

void Student::save_to_file(const vector <Student> &students, const string &filename)
{
    ofstream out(filename);
    if (!out) { cout << "Error opening file " << filename << "!\n"; return; }

    for (const auto& s : students)
    {
        out << s.get_student_no() << "\n";
        out << s.get_name() << "\n";
        out << s.get_sex() << "\n";
        out << s.get_age() << "\n";
        out << s.get_institution() << "\n";
        out << s.get_major() << "\n";
        out << "----\n";
    }
    out.close();
}

void Student::load_from_file(vector <Student> &students, const string &filename)
{
    ifstream in(filename);
    if (!in) { cout << "No file " << filename << " found. Starting empty.\n"; return; }

    students.clear();
    while (true)
    {
        string stu_no, name, sex, institution, major;
        int age;

        if (!getline(in, stu_no)) break;
        getline(in, name);
        getline(in, sex);
        in >> age;
        in.ignore();
        getline(in, institution);
        getline(in, major);

        string separator; 
        getline(in, separator);

        Student s;
        s.set_student_no(stu_no);
        s.set_name(name);
        s.set_sex(sex);
        s.set_age(age);
        s.set_institution(institution);
        s.set_major(major);

        students.push_back(s);
    }
    in.close();
}