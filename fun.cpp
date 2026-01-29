#include "fun.h"

void wait_for_enter() 
{
    cout << "Press Enter to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void run_menu(vector<Student> &students, vector<Course> &courses, vector<Score> &scores)
{
    int choice;
    do
    {
        cout << "=======================================\n";
        cout << "  Student Information and Grades Management System\n";
        cout << "=======================================\n";
        cout << "1.  Enter student information.\n";
        cout << "2.  Modify student information.\n";
        cout << "3.  Delete student information.\n";
        cout << "4.  Display student information based on criteria.\n";
        cout << "5.  Enter course information.\n";
        cout << "6.  Modify course information.\n";
        cout << "7.  Delete course information.\n";
        cout << "8.  Student selects courses.\n";
        cout << "9.  Enter student grades for courses.\n";
        cout << "10. Display students who failed in a course.\n";
        cout << "11. Display selected courses and obtained credits of a student.\n";
        cout << "0.  Exit.\n";
        cout << "=======================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1: input_student(students); break;
            case 2: modify_student(students); break;
            case 3: delete_student(students); break;
            case 4: search_students(students, courses, scores); break;
            case 5: input_course(courses); break;
            case 6: modify_course(courses); break;
            case 7: delete_course(courses); break;
            case 8: student_select_courses(students, courses, scores); break;
            case 9: enter_student_scores(scores, students, courses); break;
            case 10: display_failed_students(scores, courses, students); break;
            case 11: display_student_credits(scores, courses); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Please enter a number between 0 and 11.\n";
        }

        if (choice != 0)  wait_for_enter();
        cout << endl;

    } while (choice != 0);
}

void input_student(vector<Student> &students)
{
    Student s;
    s.input_student();
    for (const auto &stu : students)
    {
        if (stu.get_student_no() == s.get_student_no())
        {
            cout << "Student with this ID already exists! Cannot add duplicate.\n";
            return;
        }
    }

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void modify_student(vector<Student> &students)
{
    string stu_id;
    cout << "Enter student ID to modify: ";
    getline(cin, stu_id);

    for (auto &s : students)
    {
        if (s.get_student_no() == stu_id)
        {
            int choice;
            do {
                cout << "\nCurrent student info:\n";
                s.display_student();
                cout << "Which field do you want to modify?\n";
                cout << "1. Student no\n";
                cout << "2. Name\n";
                cout << "3. Sex\n";
                cout << "4. Age\n";
                cout << "5. Institution\n";
                cout << "6. Major\n";
                cout << "0. Finish editing\n";
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch(choice) {
                    case 1: {
                        string new_no;
                        cout << "Enter new student no: ";
                        getline(cin, new_no);
                        s.set_student_no(new_no);
                        break;
                    }
                    case 2: {
                        string new_name;
                        cout << "Enter new name: ";
                        getline(cin, new_name);
                        s.set_name(new_name);
                        break;
                    }
                    case 3: {
                        string new_sex;
                        cout << "Enter new sex (male/female): ";
                        getline(cin, new_sex);
                        while(new_sex != "male" && new_sex != "female") {
                            cout << "Invalid input! Please enter 'male' or 'female': ";
                            getline(cin, new_sex);
                        }
                        s.set_sex(new_sex);
                        break;
                    }
                    case 4: {
                        int new_age;
                        cout << "Enter new age: ";
                        cin >> new_age;
                        while(new_age <= 0) {
                            cout << "Invalid input! Please enter positive number: ";
                            cin >> new_age;
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        s.set_age(new_age);
                        break;
                    }
                    case 5: {
                        string new_inst;
                        cout << "Enter new institution: ";
                        getline(cin, new_inst);
                        s.set_institution(new_inst);
                        break;
                    }
                    case 6: {
                        string new_major;
                        cout << "Enter new major: ";
                        getline(cin, new_major);
                        s.set_major(new_major);
                        break;
                    }
                    case 0:
                        cout << "Finished editing student.\n";
                        break;
                    default:
                        cout << "Invalid choice! Try again.\n";
                }

            } while(choice != 0);

            cout << "Student information updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!" << endl;
}

void delete_student(vector <Student> &students)
{
    string stu_id;
    cout << "Enter student ID to delete: ";
    getline(cin , stu_id);

    for (int i = 0 ; i < students.size() ; i++)
    {
        if (students[i].get_student_no() == stu_id)
        {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void search_students(const vector <Student> &students , const vector <Course> &courses , const vector <Score> &scores) 
{
    int choice;
    cout << "\nSearch by:\n";
    cout << "1. Student ID\n";
    cout << "2. Student Name\n";
    cout << "3. Institution\n";
    cout << "4. Courses selected by a student\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string id;
        cout << "Enter student ID: ";
        getline(cin, id);

        for (const auto &s : students) {
            if (s.get_student_no() == id) {
                s.display_student();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    else if (choice == 2) {
        string name;
        cout << "Enter student name: ";
        getline(cin, name);

        bool found = false;
        for (const auto& s : students) {
            if (s.get_name() == name) {
                s.display_student();
                found = true;
            }
        }
        if (!found) cout << "No matching students!\n";
    }

    else if (choice == 3) {
        string inst;
        cout << "Enter institution: ";
        getline(cin, inst);

        bool found = false;
        for (const auto& s : students) {
            if (s.get_institution() == inst) {
                s.display_student();
                found = true;
            }
        }
        if (!found) cout << "No matching students!\n";
    }

    else if (choice == 4) {
        string id;
        cout << "Enter student ID: ";
        getline(cin, id);

        cout << "Courses selected:\n";
        for (const auto& sc : scores) {
            if (sc.get_student_no() == id) {
                for (const auto &c : courses) {
                    if (c.get_course_no() == sc.get_course_no()) {
                        cout << c.get_course_name() << " (" << c.get_course_credit() << " credits)\n";
                    }
                }
            }
        }
    }
}

void input_course(vector<Course> &courses)
{
    Course c;
    c.input_course();
    for (const auto &course : courses)
    {
        if (course.get_course_no() == c.get_course_no())
        {
            cout << "Course with this ID already exists! Cannot add duplicate.\n";
            return;
        }
    }

    courses.push_back(c);
    cout << "Course added successfully!\n";
}

void modify_course(vector<Course> &courses)
{
    string course_no;
    cout << "Enter course ID to modify: ";
    getline(cin, course_no);

    for (auto &c : courses)
    {
        if (c.get_course_no() == course_no)
        {
            int choice;
            do {
                cout << "\nCurrent course info:\n";
                c.display_course();
                cout << "Which field do you want to modify?\n";
                cout << "1. Course no\n";
                cout << "2. Course name\n";
                cout << "3. Course credit\n";
                cout << "4. Course property\n";
                cout << "0. Finish editing\n";
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch(choice) {
                    case 1: {
                        string new_no;
                        cout << "Enter new course no: ";
                        getline(cin, new_no);
                        c.set_course_no(new_no);
                        break;
                    }
                    case 2: {
                        string new_name;
                        cout << "Enter new course name: ";
                        getline(cin, new_name);
                        c.set_course_name(new_name);
                        break;
                    }
                    case 3: {
                        int new_credit;
                        cout << "Enter new course credit: ";
                        cin >> new_credit;
                        while(new_credit <= 0) {
                            cout << "Invalid input! Please enter positive number: ";
                            cin >> new_credit;
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        c.set_course_credit(new_credit);
                        break;
                    }
                    case 4: {
                        string new_property;
                        cout << "Enter new course property (compulsory/optional): ";
                        getline(cin, new_property);
                        while(new_property != "compulsory" && new_property != "optional") {
                            cout << "Invalid input! Please enter 'compulsory' or 'optional': ";
                            getline(cin, new_property);
                        }
                        c.set_course_property(new_property);
                        break;
                    }
                    case 0:
                        cout << "Finished editing course.\n";
                        break;
                    default:
                        cout << "Invalid choice! Try again.\n";
                }

            } while(choice != 0);

            cout << "Course information updated successfully!\n";
            return;
        }
    }

    cout << "Course not found!" << endl;
}

void delete_course(vector <Course> &courses)
{
    string course_no;
    cout << "Enter course ID to delete: ";
    getline(cin , course_no);
    for (int i = 0 ; i < courses.size(); i++)
    {
        if (courses[i].get_course_no() == course_no)
        {
            courses.erase(courses.begin() + i);
            cout << "Course deleted successfully!\n";
            return;
        }
    }
    cout << "Course not found!" << endl;
}

void enter_student_scores(vector <Score> &scores, const vector <Student> &students, const vector <Course> &courses)
{
    string stu_id, course_id;
    cout << "Enter student ID: ";
    getline(cin, stu_id);
    cout << "Enter course ID: ";
    getline(cin, course_id);

    for (auto &sc : scores)
    {
        if (sc.get_student_no() == stu_id && sc.get_course_no() == course_id)
        {
            float temp_score;
            cout << "Enter score: ";
            cin >> temp_score;
            cin.ignore();
            sc.set_score(temp_score);
            cout << "Score updated successfully!\n";
            return;
        }
    }
    cout << "Score record not found!" << endl;
}

void student_select_courses(vector <Student> &students, vector <Course> &courses, vector <Score> &scores)
{
    string stu_id;
    cout << "Enter student ID: ";
    getline(cin, stu_id);

    bool found = false;
    for (auto &s : students)
    {
        if (s.get_student_no() == stu_id)
        {
            found = true;
            break;
        }
    }
    if (!found) { cout << "Student not found!" << endl; return; }

    int total_credits = 0;
    int course_choice;

    do {
        vector <int> available_indices;
        cout << "\nAvailable courses to register:\n";

        for (int i = 0; i < courses.size(); i++)
        {
            bool already_registered = false;
            for (auto &sc : scores)
            {
                if (sc.get_student_no() == stu_id && sc.get_course_no() == courses[i].get_course_no())
                {
                    already_registered = true;
                    break;
                }
            }
            if (!already_registered)
            {
                available_indices.push_back(i);
                cout << available_indices.size() << ". " << courses[i].get_course_name()
                     << " (" << courses[i].get_course_credit() << " credits)" << endl;
            }
        }

        if (available_indices.empty())
        {
            cout << "No more courses available to register.\n";
            break;
        }

        cout << "Enter course number to register (0 to finish): ";
        cin >> course_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (course_choice == 0) break;

        if (course_choice >= 1 && course_choice <= available_indices.size())
        {
            int idx = available_indices[course_choice - 1];
            Score sc;
            sc.set_student_no(stu_id);
            sc.set_course_no(courses[idx].get_course_no());
            sc.set_score(0);
            scores.push_back(sc);
            total_credits += courses[idx].get_course_credit();
            cout << "Course '" << courses[idx].get_course_name() << "' added successfully.\n";
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }

    } while (true);

    cout << "Registration finished. Total selected credits: " << total_credits << endl;
}

void display_failed_students(const vector<Score> &scores, const vector<Course> &courses, const vector<Student> &students) 
{
    string course_id;
    cout << "Enter course ID: ";
    getline(cin, course_id);

    bool found_failed = false;

    for (const auto &sc : scores) 
    {
        if (sc.get_course_no() == course_id && sc.get_score() < 90) 
        {
            string student_name = "Unknown";
            for (const auto &s : students)
            {
                if (s.get_student_no() == sc.get_student_no()) {
                    student_name = s.get_name();
                    break;
                }
            }
            cout << "Student ID: " << sc.get_student_no() 
                 << ", Name: " << student_name
                 << ", Score: " << sc.get_score() << endl;
            found_failed = true;
        }
    }

    if (!found_failed) {
        cout << "No students failed in this course.\n";
    }
}

void display_student_credits(const vector <Score> &scores, const vector <Course> &courses) 
{
    string stu_id;
    cout << "Enter student ID: ";
    getline(cin, stu_id);

    int selected_credits = 0;
    int obtained_credits = 0;
    bool has_courses = false;

    cout << "\nCourses selected by the student:\n";

    for (const auto &sc : scores) 
    {
        if (sc.get_student_no() == stu_id) 
        {
            for (const auto &c : courses) 
            {
                if (c.get_course_no() == sc.get_course_no()) 
                {
                    has_courses = true;
                    selected_credits += c.get_course_credit();
                    if (sc.get_score() >= 90) obtained_credits += c.get_course_credit();

                    cout << "- " << c.get_course_name() 
                         << " (" << c.get_course_credit() << " credits)";
                    if (sc.get_score() >= 90)
                        cout << " - Passed";
                    else
                        cout << " - Not passed";
                    cout << endl;
                }
            }
        }
    }

    if (!has_courses)
    {
        cout << "No courses selected by this student.\n";
    }

    cout << "\nTotal selected credits: " << selected_credits << endl;
    cout << "Total obtained credits: " << obtained_credits << endl;
}

void save_all_data(const vector <Student> &students,const vector <Course> &courses,const vector <Score> &scores)
{
    Student s;
    s.save_to_file(students, "students.txt");

    Course c;
    c.save_to_file(courses, "courses.txt");

    Score sc;
    sc.save_to_file(scores, "scores.txt");

    cout << "All data saved successfully!\n";
}

void load_all_data(vector<Student> &students,vector<Course> &courses,vector<Score> &scores)
{
    Student s;
    s.load_from_file(students, "students.txt");

    Course c;
    c.load_from_file(courses, "courses.txt");

    Score sc;
    sc.load_from_file(scores, "scores.txt");

    cout << "All data loaded successfully!\n";
}