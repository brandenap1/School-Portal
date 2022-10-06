//
//  Implementation.cpp
//  School_Database
//
//  Created by Branden Applewhite on 10/6/22.
//

#include "Implementation.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Accessing Passwords ////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Other person accessing passwords
string getStudent_Password(int StudentID,map<int,Student>* Student_bookPt)
{
    for(auto i : *Student_bookPt)
    {
        if(StudentID == i.first)
        {
            return (i.second).getPassword();
        }
    }
    return "Invalid StudentID";
}

string getEmployee_Password(int EmployeeID,map<int,Employee>* Employee_bookPt)
{
    for(auto i : *Employee_bookPt)
    {
        if(EmployeeID == i.first)
        {
            return (i.second).getPassword();
        }
    }
    return "Invalid EmployeeID";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Profile ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Employee
bool Employee_Profile(Employee* ePt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt)
{
    bool enable = true;
    while(enable)
    {
        try
        {
            cout << "|||||||||Home||||||||||" << endl;
            cout << "Name (1) | Employee ID (2) | Password (3) | Student Directory (4) | Schedule (5)" << endl;
            int op1;
            cin >> op1;
            if(op1 == 1 || op1 == 2 || op1 == 3 || op1 == 4 || op1 == 5)
            {
                int op2;
                if(op1 == 1)
                {
                    cout << "Get Name (1) | Change Name (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {cout << ePt->getName() << endl;}
                    else if(op2 == 2)
                    {
                        string op3;
                        cout << "New Name: " << endl;
                        cin >> op3;
                        ePt->setName(op3);
                    }
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 2)
                {
                    cout << "Get Employee ID (1)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {cout << ePt->getID() << endl;}
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 3)
                {
                    cout << "Get Password (1) | Change Password (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                        cout << "Enter Dev code to get password" << endl;
                    else if(op2 == 2)
                    {
                        string op3;
                        cout << "New Password: " << endl;
                        cin >> op3;
                        ePt->setPassword(op3);
                        cout << "New Password set: " << op3 << endl;
                    }
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 4)
                {
                    cout << "Name   |   Student ID  |   Password" << endl;
                    for(auto i : *Student_bookPt)
                    {
                        cout << (i.second).getName() << "    " << (i.second).getID() << "   " << (i.second).getPassword() << endl;
                    }
                }
                else if(op1 == 5)
                {
                    cout << "Get Class Schedule (1) | Add Class (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {
                        for(auto i : ePt->getClassSchedule())
                        {
                            cout << "Period: " << i.first << "  |   " << "Class: " << i.second << endl;
                        }
                    }
                    else if(op2 == 2)
                    {
                        cout << "Enter Class Subject: " << endl;
                        string subject;
                        cin >> subject;
                        cout << "What period do you wnat to take the class?" << endl;
                        int period;
                        cin >> period;
                        if(cin.fail())
                        {
                            throw(op2);
                        }
                        ePt->addClass(subject,period);
                    }
                    else
                    {
                        throw(op2);
                    }
                }
            }
            else {throw(op1);}
        }
        catch(int op1)
        {
            cout << "Invalid key. Press x to exit Employee Profile | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

// Student
bool Student_Profile(Student* sPt,map<int,Student>* Student_bookPt)
{
    bool enable = true;
    while(enable)
    {
        try
        {
            cout << "|||||||||Home||||||||||" << endl;
            cout << "Name (1) | Student ID (2) | Password (3) | Schedule (4)" << endl;
            int op1;
            cin >> op1;
            if(op1 == 1 || op1 == 2 || op1 == 3 || op1 == 4)
            {
                int op2;
                if(op1 == 1)
                {
                    cout << "Get Name (1) | Change Name (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {cout << sPt->getName() << endl;}
                    else if(op2 == 2)
                    {
                        string op3;
                        cout << "New Name: " << endl;
                        cin >> op3;
                        sPt->setName(op3);
                    }
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 2)
                {
                    cout << "Get Student ID (1)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {cout << sPt->getID() << endl;}
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 3)
                {
                    cout << "Get Password (1) | Change Password (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {
                        cout << "Need Developer ID." << endl;
                    }
                    else if(op2 == 2)
                    {
                        string op3;
                        cout << "New Password: " << endl;
                        cin >> op3;
                        sPt->setPassword(op3);
                        cout << "New Password set: " << op3 << endl;
                    }
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 4)
                {
                    cout << "Get Class Schedule (1)  | Add Class (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {
                        for(auto i : sPt->getClassSchedule())
                        {
                            cout << "Period: " << i.first << "  |   " << "Class: " << i.second << endl;
                        }
                    }
                    else if(op2 == 2)
                    {
                        cout << "Enter Class Subject: " << endl;
                        string subject;
                        cin >> subject;
                        cout << "What period do you wnat to take the class?" << endl;
                        int period;
                        cin >> period;
                        if(cin.fail())
                        {
                            throw(op2);
                        }
                        sPt->addClass(subject,period);
                    }
                    else
                    {
                        throw(op2);
                    }
                }
            }
            else {throw(op1);}
        }
        catch(int op1)
        {
            cout << "Invalid key. Press x to exit Student Profile | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

// Developer
bool Developer_Profile(Developer* dPt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt,map<int,Developer>* Developer_bookPt)
{
    bool enable = true;
    while(enable)
    {
        try
        {
            cout << "|||||||||Home||||||||||" << endl;
            cout << "Name (1) | Developer ID (2) | Password (3) | Student Directory (4) | Employee Directory (5)" << endl;
            int op1;
            cin >> op1;
            if(op1 == 1 || op1 == 2 || op1 == 3 || op1 == 4 || op1 == 5)
            {
                int op2;
                if(op1 == 1)
                {
                    cout << "Get Name (1) | Change Name (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {cout << dPt->getName() << endl;}
                    else if(op2 == 2)
                    {
                        string op3;
                        cout << "New Name: " << endl;
                        cin >> op3;
                        dPt->setName(op3);
                    }
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 2)
                {
                    cout << "Get Developer ID (1)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                    {cout << dPt->getID() << endl;}
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 3)
                {
                    cout << "Get Password (1) | Change Password (2)" << endl;
                    cin >> op2;
                    if(op2 == 1)
                        dPt->getPassword();
                    else if(op2 == 2)
                    {
                        string op3;
                        cout << "New Password: " << endl;
                        cin >> op3;
                        dPt->setPassword(op3);
                        cout << "New Password set: " << op3 << endl;
                    }
                    else
                    {
                        throw(op2);
                    }
                }
                else if(op1 == 4)
                {
                    cout << "Name   |   Student ID  |   Password" << endl;
                    for(auto i : *Student_bookPt)
                    {
                        cout << (i.second).getName() << "    " << (i.second).getID() << "   " << (i.second).getPassword() << endl;
                    }
                }
                else if(op1 == 5)
                {
                    cout << "Name   |   Employee ID  |   Password" << endl;
                    for(auto i : *Employee_bookPt)
                    {
                        cout << (i.second).getName() << "    " << (i.second).getID() << "   " << (i.second).getPassword() << endl;
                    }
                }
            }
            else {throw(op1);}
        }
        catch(int op1)
        {
            cout << "Invalid key. Press x to exit Developer Profile | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sign In ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Employee
bool Employee_SignIn(Employee* ePt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt)
{
    bool enable = 1;
    while(enable)
    {
        try
        {
            cout << "Enter your Employee ID: " << endl;
            int employeeID;
            cin >> employeeID;
            string password;
            if(cin.fail()) {throw(employeeID);}
            cout << "Enter your Password: " << endl;
            cin >> password;
            
            for(auto i : *Employee_bookPt)
            {
                if(employeeID == i.first)
                {
                    if(password == (i.second).getPassword())
                    {
                        ePt = &i.second;
                        cout << "You are signed in." << endl;
                        Employee_Profile(ePt,Employee_bookPt,Student_bookPt);
                        return true;
                    }
                    else
                    {
                        throw(password);
                    }
                }
            }
            throw(employeeID);
        }
        catch(int employeeID)
        {
            cout << "Employee ID doesn't exist | press x to exit Sign In | any key to continue" << endl;
            string op1;
            cin >> op1;
            if(op1 == "x") {enable = 0;}
        }
        catch(string password)
        {
            cout << "Entered the Wrong Password. | press x to exit Sign In | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

// Developer
bool Developer_SignIn(Developer* dPt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt,map<int,Developer>* Developer_bookPt)
{
    bool enable = 1;
    while(enable)
    {
        try
        {
            cout << "Enter your Developer ID: " << endl;
            int developerID;
            cin >> developerID;
            string password;
            if(cin.fail()) {throw(developerID);}
            cout << "Enter your Password: " << endl;
            cin >> password;
            
            for(auto i : *Developer_bookPt)
            {
                if(developerID == i.first)
                {
                    if(password == (i.second).getPassword())
                    {
                        dPt = &i.second;
                        cout << "You are signed in." << endl;
                        Developer_Profile(dPt,Employee_bookPt,Student_bookPt,Developer_bookPt);
                        return true;
                    }
                    else
                    {
                        throw(password);
                    }
                }
            }
            
            throw(developerID);
        }
        catch(int developerID)
        {
            cout << "Developer ID doesn't exist | press x to exit Sign In | any key to continue" << endl;
            string op1;
            cin >> op1;
            if(op1 == "x") {enable = 0;}
        }
        catch(string password)
        {
            cout << "Entered the Wrong Password. | press x to exit Sign In | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

// Student
bool Student_SignIn(Student* sPt,map<int,Student>* Student_bookPt)
{
    bool enable = 1;
    while(enable)
    {
        try
        {
            cout << "Enter your Student ID: " << endl;
            int studentID;
            cin >> studentID;
            string password;
            if(cin.fail()) {throw(studentID);}
            cout << "Enter your Password: " << endl;
            cin >> password;
            
            for(auto i : *Student_bookPt)
            {
                if(studentID == i.first)
                {
                    if(password == (i.second).getPassword())
                    {
                        sPt = &i.second;
                        cout << "You are signed in." << endl;
                        Student_Profile(sPt,Student_bookPt);
                        return true;
                    }
                    else
                    {
                        throw(password);
                    }
                }
            }
            
            throw(studentID);
        }
        catch(int studentID)
        {
            cout << "Student ID doesn't exist | press x to exit Sign In | any key to continue" << endl;
            string op1;
            cin >> op1;
            if(op1 == "x") {enable = 0;}
        }
        catch(string password)
        {
            cout << "Entered the Wrong Password. | press x to exit Sign In | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

// Full Sign in Program
bool SignIn(Employee* ePt,Student* sPt,Developer* dPt,map<int,Student>* Student_bookPt,map<int,Employee>* Employee_bookPt,map<int,Developer>* Developer_bookPt)
{
    bool enable = 1;
    while(enable)
    {
        try
        {
            cout << "Employee, Student, or Developer Sign In? (Press e for Employee | s for student | d for Developer)" << endl;
            string op1;
            cin >> op1;
            if(op1 == "e" || op1 == "s" || op1 == "d")
            {
                if(op1 == "e")
                {
                    return Employee_SignIn(ePt,Employee_bookPt,Student_bookPt);
                }
                else if(op1 == "s")
                {
                    return Student_SignIn(sPt,Student_bookPt);
                }
                else if(op1 == "d")
                {
                    return Developer_SignIn(dPt,Employee_bookPt,Student_bookPt,Developer_bookPt);
                }
            }
            else
            {
                throw(op1);
            }
        }
        catch(string op1)
        {
            cout << "Invalid key. press x to exit Sign In | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Adding Users ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Employee
bool NewUser_Employee(Employee* ePt,map<int,Employee>* Employee_bookPt)
{
    // Adding Employee
    cout << "Name: " << endl;
    string name;
    cin >> name;
    Employee e1(name);
    ePt = &e1;
    cout << "Choose a Password: " << endl;
    string password;
    cin >> password;
    ePt->setPassword(password);
    cout << "Password has been set." << endl;
    Employee_bookPt->insert({ePt->getID(),*ePt});
    cout << "Employee Has Been Added." << endl;
    cout << "Employee ID: " << ePt->getID() << endl;
    return true;
}

// Student
bool NewUser_Student(Student* sPt, map<int,Student>* Student_bookPt)
{
    // Adding Employee
    cout << "Name: " << endl;
    string name;
    cin >> name;
    Student s1(name);
    sPt = &s1;
    cout << "Choose a Password: " << endl;
    string password;
    cin >> password;
    sPt->setPassword(password);
    cout << "Password has been set." << endl;
    Student_bookPt->insert({sPt->getID(),*sPt});
    cout << "Student Has Been Added." << endl;
    cout << "Student ID: " << sPt->getID() << endl;
    return true;
}

// Developer
bool NewUser_Developer(Developer* dPt, map<int,Developer>* Developer_bookPt)
{
    // Adding Developer
    cout << "Name: " << endl;
    string name;
    cin >> name;
    Developer d1(name);
    dPt = &d1;
    cout << "Choose a Password: " << endl;
    string password;
    cin >> password;
    dPt->setPassword(password);
    cout << "Password has been set." << endl;
    Developer_bookPt->insert({dPt->getID(),*dPt});
    cout << "Developer Has Been Added." << endl;
    cout << "Developer ID: " << dPt->getID() << endl;
    return true;
}

// Full New User Program
bool NewUser(Employee* ePt,Student* sPt,Developer* dPt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt,map<int,Developer>* Developer_bookPt)
{
    bool enable = 1;
    while(enable)
    {
        try
        {
            cout << "|||||||||New User||||||||||" << endl;
            cout << "Employee (e) or Student (s) or Developer (d)" << endl;
            string op1;
            cin >> op1;
            if(op1 == "e" || op1 == "s" || op1 == "d")
            {
                if(op1 == "e")
                {
                    return NewUser_Employee(ePt,Employee_bookPt);
                }
                else if(op1 == "s")
                {
                    return NewUser_Student(sPt,Student_bookPt);
                }
                else if(op1 == "d")
                {
                    return NewUser_Developer(dPt,Developer_bookPt);
                }
            }
            else {throw(op1);}
        }
        catch(string op1)
        {
            cout << "Invalid key. Press x to exit NewUser | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x") {enable = 0;}
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Home Portal ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Program(map<int,Employee>& Employee_book,map<int,Student>& Student_book,map<int,Developer>& Developer_book)
{
    bool enable = true;
    map<int,Employee>* Employee_bookPt = new map<int,Employee>;
    map<int,Student>* Student_bookPt = new map<int,Student>;
    map<int,Developer>* Developer_bookPt = new map<int,Developer>;
    Employee_bookPt = &Employee_book;
    Student_bookPt = &Student_book;
    Developer_bookPt = &Developer_book;
    Employee* ePt = new Employee;
    Student* sPt = new Student;
    Developer* dPt = new Developer;
    
    while(enable)
    {
        try
        {
            cout << "Welcome to the School Portal: " << endl;
            cout << "Press s to Sign In | Press n to add New User" << endl;
            string op1;
            cin >> op1;
            if(op1 == "s" || op1 == "n")
            {
                if(op1 == "s")
                {
                    SignIn(ePt,sPt,dPt,Student_bookPt,Employee_bookPt,Developer_bookPt);
                }
                else if(op1 == "n")
                {
                    NewUser(ePt,sPt,dPt,Employee_bookPt,Student_bookPt,Developer_bookPt);
                }
            }
            else {throw(op1);}
        }
        catch(string op1)
        {
            cout << "Invalid key. Press x to close program | any key to continue" << endl;
            string op2;
            cin >> op2;
            if(op2 == "x")
            {
                Employee_book = *Employee_bookPt;
                Student_book = *Student_bookPt;
                Developer_book = *Developer_bookPt;
                delete Employee_bookPt;
                delete Student_bookPt;
                delete Developer_bookPt;
                delete ePt;
                delete sPt;
                delete dPt;
                
                enable = 0;
            }
        }
    }
    return false;
}
