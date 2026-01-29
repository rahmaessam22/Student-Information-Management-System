#include <iostream>
#include <fstream>
#include "Scou.h"
using namespace std ;

           //setters
void Score::set_student_no(string stu) { student_no = stu; }
void Score::set_course_no(string c) { course_no = c; }
void Score::set_score(float s) { score = s; }

           //getters
string Score::get_student_no() const { return student_no; }
string Score::get_course_no() const { return course_no; }
float Score::get_score() const { return score; }

           //input & display
void Score::input_score()
{
    cout << "Enter student no: ";
    getline (cin , student_no);

    cout << "Enter course no: ";
    getline (cin , course_no);

    cout << "Enter the score (0 to 150): ";
    cin >> score;
    for ( ; score < 0 || score > 150 ;)
      {
        cout << "Invalid input! Please enter a score between 0 and 150 only." << endl;
        cin >> score;
      }
    cin.ignore();
}
void Score::display_score() const
{
    cout << "=================================" << endl;
    cout << "Student no is: " << student_no << endl;
    cout << "Course no is: " << course_no << endl;
    cout << "Score in this course: " << score << endl;
    cout << "=================================" << endl;
}

void Score::save_to_file(const vector <Score> &scores, const string &filename)
{
    ofstream out(filename);
    if (!out) { cout << "Error opening file " << filename << "!\n"; return; }

    for (const auto &sc : scores)
    {
        out << sc.get_student_no() << "\n";
        out << sc.get_course_no() << "\n";
        out << sc.get_score() << "\n";
        out << "----\n";
    }
    out.close();
}
void Score::load_from_file(vector <Score> &scores, const string &filename)
{
    ifstream in(filename);
    if (!in) { cout << "No file " << filename << " found. Starting empty.\n"; return; }

    scores.clear();
    while (true)
    {
        string stu_no, course_no;
        float score;

        if (!getline(in, stu_no)) break;
        getline(in, course_no);
        in >> score;
        in.ignore();

        string separator; 
        getline(in, separator);

        Score sc;
        sc.set_student_no(stu_no);
        sc.set_course_no(course_no);
        sc.set_score(score);

        scores.push_back(sc);
    }
    in.close();
}