#pragma once
#include <iostream>
#include <vector>
#include "Stu.h"
#include "Cou.h"
#include "Scou.h"
using namespace std;


void wait_for_enter();
void run_menu(vector<Student> &students, vector<Course> &courses, vector<Score> &scores);

void input_student(vector <Student> &students);
void modify_student(vector <Student> &students);
void delete_student(vector <Student> &students);
void search_students(const vector <Student> &students , const vector <Course> &courses , const vector <Score> &scores);

void input_course(vector <Course> &courses);
void modify_course(vector <Course> &courses);
void delete_course(vector <Course> &courses);

void student_select_courses(vector <Student> &students, vector <Course> &courses, vector <Score> &scores);
void enter_student_scores(vector <Score> &scores, const vector <Student>&students, const vector <Course> &courses);

void display_failed_students(const vector <Score> &scores, const vector <Course> &courses, const vector<Student> &students);
void display_student_credits(const vector <Score> &scores, const vector <Course> &courses);

void save_all_data(const vector<Student> &students,const vector<Course> &courses,const vector<Score> &scores);
void load_all_data(vector<Student> &students,vector<Course> &courses,vector<Score> &scores);