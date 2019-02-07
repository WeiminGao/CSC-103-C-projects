#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Grading {
public:
string name;
	int percentage;
    Grading (const string& n, const int p) : name(n), percentage(p) {}
    virtual void get_raw_score();
	virtual void get_adj_score();
};

class Assignment : public Grading { 
public:
    int score;

};

class Exam : public Grading {
public:
    int score;

};

class Project : public Assignment {
public:
   string letter_grade;
};

class Quiz : public Exam {
public:
	string letter_grade;

};


class CourseWork {
    vector <Grading*> g;
public:
    void push_back() {
    void sort_name() {};
    void sort_score() {};
};
    
  int main() {
     CourseWork c;
        
     c.push_back(new Quiz("Quiz", 5, "B-"));
     c.push_back(new Quiz("Quiz", 5, "C+"));
     c.push_back(new Quiz("Quiz", 5, "A"));
     c.push_back(new Exam("Midterm", 10, 50));
     c.push_back(new Exam("Final", 30, 85.5));
     c.push_back(new Project("Project", 5, "A-"));
     c.push_back(new Project("Project", 15, "B-"));
     c.push_back(new Project("Project", 15, "B-"));
     c.push_back(new Project("Demo", 10, "C"));
        
     cout << "** Showing populated data..." << endl;
     cout << c << endl << endl;; 
     
     c.sort_name();  
     cout << "** Showing sorted by name..." << endl;
     cout << c << endl << endl;

     c.sort_score();
     cout << "** Showing sorted by score..." << endl;
     cout << c << endl; 
     
     return 0;
   } 