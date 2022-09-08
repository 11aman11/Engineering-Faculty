#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "C:\Users\Aman\Desktop\Concordia\SummerA2k22\Coen 243\C++\Assigments\Ass4\Student.cpp"
// above ^ due to linker problem I have to do this .cpp not .h and used my pc path!!!! so in case you want to test it put "Student.cpp"
using namespace std;

//Project
//Aman Singh ID# 40190387
//Marilou Sibley ID# 40003262

class Faculty
{
    public:
        string name;
        void setNameFaculty(string);
        string getNameFaculty();
        string getName();

        Faculty();

        int studentsECE, studentsME, studentsCE; //number of students in each deparment

	    Student* ECE; //a pointer for ECE students

	    Student* ME; //pointer for ME students

	    Student* CE; //a pointer for CE students

        int N_of_UnderGrad();
        int N_of_Grad();
        double Avg_UnderGrad();
        double Avg_Grad();

        void check();
};
