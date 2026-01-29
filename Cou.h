#include <iostream>
using namespace std;
#pragma once

class Course
{
  private:
    int course_credit;
    string  course_no;
    string course_name;
    string course_property;
  public:
          //setters
    void set_course_no (string no);
    void set_course_name (string name);
    void set_course_credit (int c);
    void set_course_property (string p);

          //getters
    string get_course_no() const;
    string get_course_name() const;
    int get_course_credit() const;
    string get_course_property() const;

          //input & display
    void input_course ();
    void display_course() const;

    void save_to_file(const vector <Course> &courses, const string &filename);
    void load_from_file(vector <Course> &courses, const string &filename);

};