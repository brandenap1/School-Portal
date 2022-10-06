//
//  Person_Objects.h
//  School_Database
//
//  Created by Branden Applewhite on 10/6/22.
//

#ifndef Person_Objects_h
#define Person_Objects_h

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person
{
public:
    
    Person(const string& Name = "John");
    // Copy Constructor
    Person(const Person& source);
    // Assignment Operator (copy)
    Person& operator=(const Person& source);
    // Move Constructor
    Person(Person&& source) noexcept;
    // Assignment Operator (move)
    Person& operator=(Person&& source);
    // Destructor
    ~Person();
    virtual int getID() { cout << "You Dont Have an ID" << endl; return 9999;}
    virtual string getName() {return name;}
    virtual void setName(const string& Name) {name = Name;}
    virtual string getPassword() {cout << "You don't have permission to see Password" << endl; return "N/A";}
    virtual void setPassword(const string& Password) {password = Password;}
    virtual map<int,string> getClassSchedule() {cout << "You don't have a Class Schedule" << endl; return {{0,"N/A"}};}
    virtual void addClass(const string& subject,const int& period) {cout << "You don't have permission to add Class" << endl;}
    
protected:
    string name;
    string password;
    static int Period;
    static int employeenextID;
    static int studentnextID;
    static int developernextID;
};


class Employee: public Person
{
public:
    
    Employee(const string& Name = "John");
    // Copy Constructor
    Employee(const Employee& source);
    // Assignment Operator (copy)
    Employee& operator=(const Employee& source);
    // Move Constructor
    Employee(Employee&& source) noexcept;
    // Assignment Operator (move)
    Employee& operator=(Employee&& source);
    // Destructor
    ~Employee();
    // Member Functions
    int getID() {return employeeID;}
    map<int,string> getClassSchedule() {return *classSchedule;}
    void addClass(const string& subject,const int& period);
    
private:
    int employeeID;
    int used;
    int capacity = 8;
    map<int,string>* classSchedule;
};

class Student: public Person
{
public:
    
    Student(const string& Name = "John");
    // Copy Constructor
    Student(const Student& source);
    // Assignment Operator (copy)
    Student& operator=(const Student& source);
    // Move Constructor
    Student(Student&& source) noexcept;
    // Assignment Operator (move)
    Student& operator=(Student&& source);
    // Destructor
    ~Student();
    // Member Functions
    int getID() {return studentID;}
    map<int,string> getClassSchedule() {return *classSchedule;}
    void addClass(const string& subject,const int& period);
    
private:
    int studentID;
    int used;
    int capacity = 8;
    map<int,string>* classSchedule;
};

class Developer: public Person
{
public:
    
    Developer(const string& Name = "John");
    // Copy Constructor
    Developer(const Developer& source);
    // Assignment Operator (copy)
    Developer& operator=(const Developer& source);
    // Move Constructor
    Developer(Developer&& source) noexcept;
    // Assignment Operator (move)
    Developer& operator=(Developer&& source);
    // Destructor
    ~Developer();
    // Member Functions
    int getID() {return developerID;}
    string getPassword() {return password;}
    
private:
    int developerID;
};

#endif /* Person_Objects_h */
