#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Course
{
    private:
        string name;
        double credit;
        string grade;
    public:
        Course() : name(0), credit(0.0), grade(0) {};
        Course(string name, double credit, string grade)
        : name(name), credit(credit), grade(grade) {};
        ~Course() {};
        string getName() const { return name; }
        double getCredit() const { return credit; }
        string getGrade() const { return grade; }
};

int main()
{
    map<string, double> gpaMap;
    gpaMap.insert(pair<string, double>("A+", 4.5));
    gpaMap.insert(pair<string, double>("A0", 4.0));
    gpaMap.insert(pair<string, double>("B+", 3.5));
    gpaMap.insert(pair<string, double>("B0", 3.0));
    gpaMap.insert(pair<string, double>("C+", 2.5));
    gpaMap.insert(pair<string, double>("C0", 2.0));
    gpaMap.insert(pair<string, double>("D+", 1.5));
    gpaMap.insert(pair<string, double>("D0", 1.0));
    gpaMap.insert(pair<string, double>("F", 0.0));

    vector<Course> validCourses;

    for (int _ = 0; _ < 20; _++)
    {
        string name;
        double credit;
        string grade;
        cin >> name;
        cin >> credit;
        cin >> grade;
        
        if (grade != "P") validCourses.push_back(Course(name, credit, grade));
    }

    double cgpa = 0.0;
    double totalCredit = 0.0;
    for (vector<Course>::iterator iter = validCourses.begin(); iter != validCourses.end(); iter++)
    {
        totalCredit += iter->getCredit();
        cgpa += iter->getCredit() * gpaMap[iter->getGrade()];
    }
    cgpa /= totalCredit;
    
    cout << setprecision(7) << cgpa;

    return 0;
}