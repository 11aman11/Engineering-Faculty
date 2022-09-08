//Project
//Aman Singh ID# 40190387
//Marilou Sibley ID# 40003262

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Faculty.cpp" //due to linker problem I have to do this .cpp not .h

using namespace std;

int main()
{
    Faculty f1;

    f1.setNameFaculty("Engineering");

    cout<<"Number of Undergraduate Students in the "<<f1.getNameFaculty()<<" faculty: ";
    cout<<f1.N_of_UnderGrad()<<endl<<endl;

    cout<<"Number of graduate Students in the "<<f1.getNameFaculty()<<" faculty: ";
    cout<<f1.N_of_Grad()<<endl<<endl;

    cout<<"Average GPA of Undergraduate Students in the "<<f1.getNameFaculty()<<" faculty: ";
    cout<<setprecision(3)<<f1.Avg_UnderGrad()<<endl<<endl;

    cout<<"Average GPA of graduate Students in the "<<f1.getNameFaculty()<<" faculty: ";
    cout<<setprecision(3)<<f1.Avg_Grad()<<endl<<endl;

     //cout<<f1.Avg_Grad()<<endl; for debugging purpose
    // // f1.check(); for debugging purpose
}

