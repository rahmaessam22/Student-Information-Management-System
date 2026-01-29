#include <iostream>
#include <vector>
#include "Stu.h"
#include "Cou.h"
#include "Scou.h"
#include "fun.h"
using namespace std;

int main()
{
    vector <Student> students;
    vector <Course> courses;
    vector <Score> scores;

    load_all_data(students, courses, scores);

    run_menu(students, courses, scores);

    save_all_data(students, courses, scores);
}