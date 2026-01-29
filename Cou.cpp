#include <iostream>
#include <fstream>
#include "Cou.h"
using namespace std;

          //setters
void Course::set_course_no(string no) { course_no = no; }
void Course::set_course_name(string name) { course_name = name; }
void Course::set_course_credit(int c) { course_credit = c; }
void Course::set_course_property(string p) { course_property = p; }
   
          //getters
string Course::get_course_no() const { return course_no; }
string Course::get_course_name() const { return course_name; }
int Course::get_course_credit() const { return course_credit; }
string Course::get_course_property() const { return course_property; }

          //input & display
void Course::input_course()
{
    cout << "Enter course no: ";
    getline(cin, course_no);   

    cout << "Enter course name: ";
    getline(cin, course_name);

    cout << "Enter course credit: ";
    cin >> course_credit;
    cin.ignore();              
    
    cout << "Enter course property (compulsory or optional): ";
    getline (cin , course_property);
    for ( ; course_property != "compulsory" && course_property != "optional" ; )
      {
        cout << "Invalid input! Please enter compulsory or optional only." << endl;
        getline (cin , course_property);
      }
}
void Course::display_course() const
{
    cout << "=================================" << endl;
    cout << "Course no       : " << course_no << endl;
    cout << "Course name     : " << course_name << endl;
    cout << "Course credit   : " << course_credit << endl;
    cout << "Course property : " << course_property << endl;
    cout << "=================================" << endl;
}

void Course::save_to_file(const vector<Course> &courses, const string &filename)
{
    ofstream out(filename);
    if (!out) {cout << "Error opening file " << filename << "!\n"; return; }

    for (const auto &c : courses)
    {
        out << c.get_course_no() << "\n";
        out << c.get_course_name() << "\n";
        out << c.get_course_credit() << "\n";
        out << c.get_course_property() << "\n";
        out << "----\n";
    }
    out.close();
}
void Course::load_from_file(vector<Course> &courses, const string &filename)
{
    ifstream in(filename);
    if (!in) { cout << "No file " << filename << " found. Starting empty.\n"; return; }

    courses.clear();
    while (true)
    {
        string course_no, course_name, course_property;
        int course_credit;

        if (!getline(in, course_no)) break;
        getline(in, course_name);
        in >> course_credit;
        in.ignore();
        getline(in, course_property);

        string separator; 
        getline(in, separator);

        Course c;
        c.set_course_no(course_no);
        c.set_course_name(course_name);
        c.set_course_credit(course_credit);
        c.set_course_property(course_property);

        courses.push_back(c);
    }
    in.close();
}