//By: Ahmed Fawzy

//This is the main.cpp
//This main.cpp file simply calls the necessary methods
//all classes and methods are declared in "projectHeader.h"
//all classes and methods are defined in "projectClasses.cpp"


#include<iostream>
#include<fstream>
#include "projectHeader.h"//includes the project header, so classes can be used...
using namespace std;

int main()
{

changeData changer;//creates an object of class changeData, used for the first option
view viewer;//creates an object of class view, used for the second option

parent *options[2]={&changer,&viewer};//creates an array of pointers of type parent class, and assigns the object of each option to the pointers

userInterface *one;//pointer of UI class
string option;//used to store user input...

while(true)//runs until broken...
{

    option=one->intro();//calls the intro function which asks user what option they want to excute... stores option into variable
    if(option=="1")//if the option is "1"
    {
        options[0]->classFunction();//the virtual function set in the derived class for option 1 is called through the parent class...

    }//end of if statment

    else if(option=="2")//if user wants option "2"
    {

        options[1]->classFunction();//the virtual function set in the derived class for option 2 is called through the parent class...
    }//end of else if statment

    else{cout<<"Thank You for using the Password Protection Software - Made by Ahmed Fawzy !"<<endl;
        break;}//if user inputs any other value, the program gives a ending statment, and loop breaks...

}//end of while loop

}//end of main

