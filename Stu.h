#include <iostream>
using namespace std;
#pragma once

class Student
{
  private:
    int age;
    string name;
    string sex;
    string institution;
    string major;
    string student_no;
  public:
           //setters
    void set_student_no (string i);
    void set_name (string n);
    void set_sex (string s);
    void set_age (int a);
    void set_institution (string in);
    void set_major (string m);

           //getters
    string get_student_no() const;
    string get_name() const;
    string get_sex() const;
    int get_age() const;
    string get_institution() const;
    string get_major() const;

           //input & display
    void input_student ();
    void display_student() const;

    void save_to_file(const vector <Student> &students, const string &filename);
    void load_from_file(vector <Student> &students, const string &filename);

};