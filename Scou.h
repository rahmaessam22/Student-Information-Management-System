#include <iostream>
using namespace std;
#pragma once

class Score
{
  private:
    string student_no;
    string course_no;
    float score;
  public:
           //setters
    void set_student_no (string stu);
    void set_course_no (string c);
    void set_score (float s);

           //getters
    string get_student_no() const;
    string get_course_no() const;
    float get_score() const;

           //input & display
    void input_score ();
    void display_score () const;

    void save_to_file(const vector <Score> &scores, const string &filename);
    void load_from_file(vector <Score> &scores, const string &filename);

};