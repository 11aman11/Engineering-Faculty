//Project
//Aman Singh ID# 40190387
//Marilou Sibley ID# 40003262
#include <iostream>
#include <iomanip>
#include <string>
#include "Faculty.h"


using namespace std;
Faculty::Faculty()
{
    string FirstName,LastName,ID,DateOfBirth;
    double Gpa;
    int StartYear;
    int Credits;
    char Program;

    studentsCE=0;
    studentsECE=0;
    studentsME=0;

    ifstream infile;
    infile.open("student_elec_comp.txt");

    if(!infile)
    cout<<"File can't be opened!"<<endl;

    infile>>studentsECE; //reads the number of students
    ECE= new Student[studentsECE]; //dynamic array

    for(int i=0;i<studentsECE;i++)
    {
        infile>>ID>>FirstName>>LastName>>DateOfBirth>>Gpa>>StartYear>>Credits>>Program;

        ECE[i].setID(ID);
        ECE[i].setFirst(FirstName);
        ECE[i].setLast(LastName);
        ECE[i].setDate(DateOfBirth);
        ECE[i].setGpa(Gpa);
        ECE[i].setStart(StartYear);
        ECE[i].setCredits(Credits);
        ECE[i].setProgram(Program);
    }
    infile.close();
//////////////////////////////////////////////////
    infile.open("student_mech.txt");
    if(!infile)
    cout<<"File can't be opened!"<<endl;

    infile>>studentsME; //reads the number of students
    ME= new Student[studentsME]; //dynamic array

    for(int i=0;i<studentsME;i++)
    {
        infile>>ID>>FirstName>>LastName>>DateOfBirth>>Gpa>>StartYear>>Credits>>Program;

        ME[i].setID(ID);
        ME[i].setFirst(FirstName);
        ME[i].setLast(LastName);
        ME[i].setDate(DateOfBirth);
        ME[i].setGpa(Gpa);
        ME[i].setStart(StartYear);
        ME[i].setCredits(Credits);
        ME[i].setProgram(Program);
    }
    infile.close();
///////////////////////////////////////////////////

    infile.open("student_civil.txt");
    if(!infile)
    cout<<"File can't be opened!"<<endl;

    infile>>studentsCE; //reads the number of students
    CE= new Student[studentsCE]; //dynamic array

    for(int i=0;i<studentsCE;i++)
    {
        infile>>ID>>FirstName>>LastName>>DateOfBirth>>Gpa>>StartYear>>Credits>>Program;

        CE[i].setID(ID);
        CE[i].setFirst(FirstName);
        CE[i].setLast(LastName);
        CE[i].setDate(DateOfBirth);
        CE[i].setGpa(Gpa);
        CE[i].setStart(StartYear);
        CE[i].setCredits(Credits);
        CE[i].setProgram(Program);
    }
    infile.close();

}
int Faculty::N_of_UnderGrad()
{
    int counterECE=0;
    for(int i=0;i<studentsECE;i++)
    {
        if(ECE[i].getProgram()=='B')
        counterECE++;
    }
    //cout<<counterECE<<endl; was debugging
    int counterME=0;
    for(int i=0;i<studentsME;i++)
    {
        if(ME[i].getProgram()=='B')
        counterME++;
    }
    //cout<<counterME<<endl;
    int counterCE=0;
    for(int i=0;i<studentsCE;i++)
    {
        if(CE[i].getProgram()=='B')
        counterCE++;
    }
    //cout<<counterCE<<endl;
    // return counterECE+ counterME + counterCE; for debugging purpose
    return counterCE+counterECE+counterME;
}
int Faculty::N_of_Grad()
{
    int counterECE=0;
    for(int i=0;i<studentsECE;i++)
    {
        if(ECE[i].getProgram()=='M'||ECE[i].getProgram()=='P')
        counterECE++;
    }

    int counterME=0;
    for(int i=0;i<studentsME;i++)
    {
        if(ME[i].getProgram()=='M'||ME[i].getProgram()=='P')
        counterME++;
    }

    int counterCE=0;
    for(int i=0;i<studentsCE;i++)
    {
        if(CE[i].getProgram()=='M'||CE[i].getProgram()=='P')
        counterCE++;
    }

    return counterECE+ counterME + counterCE;
}
double Faculty::Avg_UnderGrad()
{
    double sum1=0;
    int counterECE=0;
    for(int i=0;i<studentsECE;i++)
    {
        if(ECE[i].getProgram()=='B')
        {
        sum1+=ECE[i].getGpa();
        counterECE++; //number of bachelors in ECE
        }
    }

    double sum2=0;
    int counterME=0;
    for(int i=0;i<studentsME;i++)
    {
        if(ME[i].getProgram()=='B')
        {
            sum2+=ME[i].getGpa();
            counterME++;
        }
    }

    double sum3=0;
    int counterCE=0;
    for(int i=0;i<studentsCE;i++)
    {
        if(CE[i].getProgram()=='B')
        {
            sum3+=CE[i].getGpa();
            counterCE++;
        }
    }

    double totalOfBachelorsGpa=sum1+sum2+sum3;
    int totalBachelors=counterCE+counterECE+counterME;

    return totalOfBachelorsGpa/totalBachelors;

}
double Faculty::Avg_Grad()
{
     double sum1=0;
     int counterECE=0; //number of students Grad + Masters
    for(int i=0;i<studentsECE;i++)
    {
        if(ECE[i].getProgram()=='M'||ECE[i].getProgram()=='P')
        {
            sum1+=ECE[i].getGpa();
            counterECE++;
        }
    }


    double sum2=0;
    int counterME=0;
    for(int i=0;i<studentsME;i++)
    {
        if(ME[i].getProgram()=='M'||ME[i].getProgram()=='P')
        {
            sum2+=ME[i].getGpa();
            counterME++;
        }
    }

    double sum3=0;
    int counterCE=0;
    for(int i=0;i<studentsCE;i++)
    {
        if(CE[i].getProgram()=='M'||CE[i].getProgram()=='P')
        {
            sum3+=CE[i].getGpa();
            counterCE++;
        }
    }
    double TotalOfGradMastersGpa=sum1+sum2+sum3;
    int TotalGradMasters= counterCE+counterME+counterECE;

    return TotalOfGradMastersGpa/TotalGradMasters;
}
//below  was used for debugging purpose
void Faculty::check()
{
//    char c= CE[0].getProgram();
//    cout<<c;
    //CE[0].Print_Std_info();
    // double s=CE[0].getGpa();
    // cout<<s<<endl;
}
void Faculty::setNameFaculty(string s)
{
    name=s;
}
string Faculty::getNameFaculty()
{
    return name;
}