//Final computer science project
//By: Ahmed Fawzy -  ICS4U1-02

//This "projectHeader.h" file is used to declare the classes and there methods...
//All methods are defined in the "projectClasses.cpp" file
//methods are called and used in the main.cpp file...

#ifndef PROJECTHEADER_H_INCLUDED
#define PROJECTHEADER_H_INCLUDED
#include<iostream>
#include<fstream>
using namespace std;

class userInterface//class used for the main UI
{
public:
    string intro();// UI function...
};//end of class

class parent//the user has two options (change data) or (view data), this class contains multiple functions that the 2 classes use in order to excute any of the options...
{
public:

string accounts[7]={"Facebook","Gmail","Instagram","Twitter","LinkedIn","Hotmail","Skype"};//the pre-set accounts
string data[7][2]={};//data array used to store the data...

virtual void classFunction();//virtual function that is defined in each subclass...

void write();//functions used to write the data array to file...
int accountOption();//function used to display the accounts and asks user which account they want to access...
void uploadData();//funcion used to upload data from file into data array
string encrypt(string a);//function used to encrypt the data (1 letter to the right)
string decrypt(string a);//function used to decrpyt the data  (1 letter to the right)

};//end of class

class changeData: public parent//class used for option 1, and it inherits all the functions in the parent class...
{
public:
    void classFunction();//virtual function which alters/adds data to the file (option 1)
};//end of class

class view: public parent//class used for option 2, and it inherits all the functions in the parent class..
{
public:
void classFunction();//virtual function which displays the desired account data...
};//end of class



#endif // PROJECTHEADER_H_INCLUDED
