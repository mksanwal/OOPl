// Develop a program in C++ to create a database of student’s information system containing the
// following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
// address, Telephone number, Driving license no. and other. Construct the database with
// suitable member functions. Make use of constructor, default constructor, copy constructor,
// destructor, static member functions, friend class, this pointer, inline code and dynamic
// memory allocation operators-new and delete as well as exception handling.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to store student information
class Student {
private:
    // Private member variables
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    // Default constructor
    Student() : rollNumber(0), division('A') {}

    // Parameterized constructor
    Student(string name, int rollNumber, string studentClass, char division, string dob, string bloodGroup, string contactAddress, string telephoneNumber, string drivingLicenseNo)
        : name(name), rollNumber(rollNumber), studentClass(studentClass), division(division), dob(dob), bloodGroup(bloodGroup), contactAddress(contactAddress), telephoneNumber(telephoneNumber), drivingLicenseNo(drivingLicenseNo) {}

    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }



    // Static member function to show total number of students
    static void showTotalStudents() {
        static int totalStudents = 0;
        totalStudents++;
        cout << "Total students: " << totalStudents << endl;
    }

    // Friend class declaration
    friend class Display;

    // Inline function to display student details
    inline void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }

    // Overloading new operator for dynamic memory allocation
    void* operator new(size_t size) {
        cout << "Overloading new operator with size: " << size << endl;
        void *p = ::operator new(size);
        return p;
    }

    // Overloading delete operator for dynamic memory deallocation
    void operator delete(void *p) {
        cout << "Overloading delete operator" << endl;
        ::operator delete(p);
    }

    // Function to take input from user
    void input() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // To ignore the newline character left by cin
        cout << "Enter Class: ";
        getline(cin, studentClass);
        cout << "Enter Division: ";
        cin >> division;
        cin.ignore();
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Contact Address: ";
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);
        cout << "Enter Driving License No: ";
        getline(cin, drivingLicenseNo);
    }
};

// Friend class to display student information
class Display {
public:
    void showStudent(const Student &s) {
        s.display();
    }
};

int main() {
    try {
        vector<Student*> students; // Vector to store multiple student objects
        char choice;

        do {
            Student *s = new Student();
            s->input();
            students.push_back(s);
            Student::showTotalStudents();

            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;
            cin.ignore(); // To ignore the newline character left by cin
        } while (choice == 'y' || choice == 'Y');

        Display d;
        for (const auto &student : students) {
            d.showStudent(*student);
        }

        // Deleting all student objects
        for (auto &student : students) {
            delete student;
        }
    } catch (bad_alloc &e) {
        // Handling memory allocation failure
        cout << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}
