//
//  GUI.cpp
//  School_Database
//
//  Created by Branden Applewhite on 10/6/22.
//

#include <stdio.h>
#include "GUI.h"

namespace Application
{
    void StartApp()
    {
        map<int,Employee> Employeebook;
        map<int,Student> Studentbook;
        map<int,Developer> Developerbook;
        Program(Employeebook,Studentbook,Developerbook);
    }
}
