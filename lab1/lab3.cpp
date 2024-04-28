#include <iostream>
#include <string>
#include <vector>

class Course {
private:
    std::string course_code;
    std::string course_name;

public:
    Course(std::string code, std::string name) : course_code(code), course_name(name) {}

    std::string getCourseCode() const { return course_code; }
    std::string getCourseName() const { return course_name; }
};

class Grade {
private:
    int mark;
    char grade;

public:
    Grade(int m) : mark(m) {
        if (mark > 69)
            grade = 'A';
        else if (mark > 59)
            grade = 'B';
        else if (mark > 49)
            grade = 'C';
        else if (mark > 39)
            grade = 'D';
        else
            grade = 'E';
    }

    int getMark() const { return mark; }
    char getGrade() const { return grade; }
};

class Student {
private:
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    std::vector<Grade> grades;

public:
    Student(std::string regno, std::string n, int a, const Course& c)
        : registration_number(regno), name(n), age(a), course(c) {}

    std::string getRegistrationNumber() const { return registration_number; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    const Course& getCourse() const { return course; }

    void addGrade(const Grade& g) { grades.push_back(g); }

    // Function to calculate and return the average grade
    double getAverageGrade() const {
        int sum = 0;
        for (const Grade& g : grades)
            sum += g.getMark();
        return static_cast<double>(sum) / grades.size();
    }
};

int main() {
    // Create courses
    Course c1("msa001", "mathematics for science");
    Course c2("css002", "Calculus I");

    // Create students
    Student s1("sct212-001/24", "mark Njoroge", 19, c1);
    Student s2("sct212-002/24", "victor maweu", 20, c2);

    // Add marks and calculate grades
    s1.addGrade(Grade(85));
    s1.addGrade(Grade(95));
    s1.addGrade(Grade(75));

    s2.addGrade(Grade(65));
    s2.addGrade(Grade(55));
    s2.addGrade(Grade(45));

    // Print student details and average grades
    std::cout << "Student 1: " << s1.getRegistrationNumber() << ", " << s1.getName()
              << ", " << s1.getAge() << ", " << s1.getCourse().getCourseCode()
              << ", " << s1.getCourse().getCourseName() << ", Average Grade: "
              << s1.getAverageGrade() << std::endl;

    std::cout << "Student 2: " << s2.getRegistrationNumber() << ", " << s2.getName()
              << ", " << s2.getAge() << ", " << s2.getCourse().getCourseCode()
              << ", " << s2.getCourse().getCourseName() << ", Average Grade: "
              << s2.getAverageGrade() << std::endl;

    return 0;
}
