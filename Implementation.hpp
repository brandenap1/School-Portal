//
//  Implementation.hpp
//  School_Database
//
//  Created by Branden Applewhite on 10/6/22.
//

#ifndef Implementation_hpp
#define Implementation_hpp

#include "Person_Objects.h"

string getStudent_Password(int StudentID,map<int,Student>* Student_bookPt);
string getEmployee_Password(int EmployeeID,map<int,Employee>* Employee_bookPt);
// Profiles
bool Employee_Profile(Employee* ePt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt);
bool Student_Profile(Student* sPt,map<int,Student>* Student_bookPt);
bool Developer_Profile(Developer* dPt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt,map<int,Developer>* Developer_bookPt);
// Sign in
bool Employee_SignIn(Employee* ePt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt);
bool Developer_SignIn(Developer* dPt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt,map<int,Developer>* Developer_bookPt);
bool Student_SignIn(Student* sPt,map<int,Student>* Student_bookPt);
bool SignIn(Employee* ePt,Student* sPt,Developer* dPt,map<int,Student>* Student_bookPt,map<int,Employee>* Employee_bookPt,map<int,Developer>* Developer_bookPt);
// New User
bool NewUser(Employee* ePt,Student* sPt,Developer* dPt,map<int,Employee>* Employee_bookPt,map<int,Student>* Student_bookPt,map<int,Developer>* Developer_bookPt);
bool NewUser_Employee(Employee* ePt,map<int,Employee>* Employee_bookPt);
bool NewUser_Student(Student* sPt, map<int,Student>* Student_bookPt);
bool NewUser_Developer(Developer* dPt, map<int,Developer>* Developer_bookPt);
// Full Program
bool Program(map<int,Employee>& Employee_book,map<int,Student>& Student_book,map<int,Developer>& Developer_book);


#endif /* Implementation_hpp */
