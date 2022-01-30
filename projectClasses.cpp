//Final computer science project
//By: Ahmed Fawzy -  ICS4U1-02
//This "projectClasses.cpp" file holds the defintion for each method declared in the header file...
//These methods are later used in the main...

#include "projectHeader.h"//includes the header file, in order to define the methods

string userInterface::intro()//user interface method...
    {
        //prints a box that explains the program and shows the options
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"|Welcome to the Password Protection Software                            |"<<endl;
        cout<<"|This program will encrypt and store data for up to 7 accounts !        |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|Press 1: To add,change or delete data to an account :                  |"<<endl;
        cout<<"|Press 2: To view data from any account :                               |"<<endl;
        cout<<"|Press any other key: To quit the program :                             |"<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl<<endl;

        string a;
        cin>>a;
        return a;//option is returned...

    }//end of intro() function


//The bottom 6 functions are part of the "parent" class which all sub classes inherite from.

void parent::classFunction(){}//this function is declared as "virtual" in the header. it acts as a polymorphic function that the subclasses define

void parent::write()//this function will write to the file
    {
        ofstream writer("EveryData.txt");//will write to the file "EveryData.txt", if file is not found, the upload function will throw an exception before this function is called...

    for(int y=0;y<7;y++)//runs 7 times for each of the 7 accounts
    {
        for(int x=0;x<2;x++)//runs 2 times, once for the username, second for the password
        {
            writer<<data[y][x]<<" ";//writes the data array to the file (data is gathered in the upload function...)

        }//end of inner for loop
        writer<<endl;//after each account, new line is inputed

    }//end of outer for loop
    }//end of write() function

int parent::accountOption()//function used to display all accounts and asks user which account he/she wants to alter...
    {
         while(true)//runs until broken
        {
        try{//used to throw and catch execptions...

         cout<<"Press the assoicated number to access the account data: "<<endl;
        for(int i=0; i<7;i++)//the 7 accounts are printed
        {
            cout<<i+1<<". "<<accounts[i]<<endl;
        }
        string StringOption;
        cin>>StringOption;//user inputs the account he/she wants to alter
        int option=stoi(StringOption);//option is converted to an integer... (if letter is inputed, exception will be catched)
        if(option>7||option<1)//if options is out of the range
            throw int(1);//exception (1) is thrown

        return option;//if no excpetions are thrown, the option data is returned to be used by other functions later
        break;//if no exceptions are throw, the loop breaks. else it will ask the user to input the option again...

        }catch(...){cout<<endl<<"The value is out of range ! "<<endl<<endl;}//catchs the exceptions and tells the user that the input is wrong
        }//end of while loop

    }//end of function

void parent::uploadData()//function used to upload data from file to a 2d array
    {
        try{//used to throw exceptions
ifstream opener;
opener.open("EveryData.txt");//opens file
if(opener.fail())
    throw int(2);//if file cannot open, exception is thrown

        while(!opener.eof())//read the file until the end
        {
        for(int y=0;y<7;y++)//runs 7 times of the 7 accounts
        {
            for(int x=0; x<2;x++)//runs 2 times for the account and password
        {
        opener>>data[y][x];//inputs them into data array... (file contains the string "empty" if no data is there)
        }//end of inner for loop
        }//end of outer for loop
        }//end of while
    opener.close();//file is closed

    }catch (int a)//if exception is caught
    {
    cout<<endl<<endl<<"--------------------------------------------------------";
    cout<<endl<<"Error "<<a<<": File data not found !"<<endl;//tells user that file is not found...
    cout<<"Please make sure the data file 'EveryData.txt' is avaliable - program will terminate !"<<endl;
    exit(a);//whole program ends...because no file means no data can be edited
    }//end of catch

}//end of upload() function

string parent::encrypt(string a)//function used to encrpt a string
{
    int size1=a.size();//size of passed string is stored
    for(int i=0;i<size1;i++)//runs for each character in string
    {
     a[i]=a[i]+1;//each character is moved 1 letter to the right...
    }//end of for loop
    return a;//returns the new encrpyted string
}//end of function

string parent::decrypt(string a)//funtion used to decrypt a string
    {
        int size1=a.size();//gets size of passed string
        for(int i=0;i<size1;i++)//runs until for all characters
        {
        a[i]=a[i]-1;//moves the characters 1 to the left (back to original)
        }//end of for loop

        return a;//returns the new decrypted string
    }//end of function

//the bottom function is part of the "changeData" class, which is inherited from the "parent" class
void changeData::classFunction()//this virtual function is defined here for this subclass. It changes the data (option 1)
{
    int option;
    option=accountOption();//asks user which account they want to change (calls the inherited function...)
    cout<<endl<<"You choose to add,change or delete your "<<accounts[option-1]<<" data:"<<endl;

    while(true){//runs until broken...
    try{//used to throw exceptions
    cout<<"Press 1 to delete the data: "<<endl;
    cout<<"Press 2 to add new data to the account: "<<endl;
    int option2;
    cin>>option2;//user inputs his/her option

    if(option2 !=1 && option2 !=2)
        throw int(1);//if our of range, exception is thrown

    string NewAccount;
    string NewPassword;


    if(option2==1)//if user wants to delete data (option 1)
    {
        NewAccount="empty";//both account and password are set to "empty"
        NewPassword="empty";
    }//end of if statment

    if(option2==2)//if user wants to alter or add data (option 2)
    {
        cout<<"Enter the account username: "; //user inputs the username and passowrd, for the specfic account they picked earlier
        cin>>NewAccount;
        cout<<"Enter the account password: ";
        cin>>NewPassword;
    }//end of if statment


    uploadData();//data is upload from the file

    if(option2==1)//if user wants to delete data
    {
        if(data[option-1][0]=="empty")//if data is already empty
            cout<<"Data is already empty !"<<endl;

        else cout<<"Data is deleted !"<<endl;//lets user know data has been deleted...
    }//end of if statment

    data[option-1][0]=encrypt(NewAccount);//username and password data becomes an encrypted version of whatever the user entered. using the encrypt function
    data[option-1][1]=encrypt(NewPassword);

    if(option2==2)//if user picked to change/add data
    {
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"Username and Password are now encrypted and stored !"<<endl<<endl;//lets the user know the data is stored...
        cout<<"All data is encrypted 1 letter to the right !"<<endl;
        cout<<"The encrypted username is: "<<data[option-1][0]<<endl;//tells the user the encrypted data...
        cout<<"The encrypted password is: "<<data[option-1][1]<<endl;
       cout<<"------------------------------------------------------------------"<<endl;
    }//end of if statment


    write();//the updates data is now written back to the file using the function write()...

     break;//if no excpetions are thrown, the loop breaks
    }catch(...){cout<<endl<<"Value is out of range !"<<endl<<endl;}//if the user inputs a out of range option, it tells the user. and while loop allows the user to go back and enter value
    }//end of while

}//end of function

//the bottom function is a virtual function inherited from the parent class, and is defined here in the "view" class used for option 2...
void view::classFunction()//this function displays the data for the user
{
    uploadData();//data is uploaded to the 2d array
    int option;
    option=accountOption();//asks user what account they want to see...

    if(data[option-1][0]=="empty")//if data is set to "empty" (even if user inputs "empty" as the actual data, once its encrypted, the data will not be "empty")
            cout<<"Account does not have any data !"<<endl;//tells the user that no data is avaliable
    else{
    cout<<"The account name for your "<<accounts[option-1]<<" is :"<<decrypt(data[option-1][0])<<endl;//else, it decrypts the data, and prints it
    cout<<"The password for your "<<accounts[option-1]<<" is :"<<decrypt(data[option-1][1])<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl<<endl;
}//end of function
