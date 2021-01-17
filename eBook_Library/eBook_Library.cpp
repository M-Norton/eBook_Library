// eBook_Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//fn prototypes
void saveInfo();
void displayInfo();

int main()
{
    //Title graphic
    cout << R"(                                                 
       ___           _     _    _ _
   ___| _ ) ___  ___| |__ | |  (_) |__ _ _ __ _ _ _ _  _
  / -_) _ \/ _ \/ _ \ / / | |__| | '_ \ '_/ _` | '_| || |
  \___|___/\___/\___/_\_\ |____|_|_.__/_| \__,_|_|  \_, |
                                                    |__/                  
                 An eBook Library builder.

 ==========================================================                                           
 )" << '\n';

    saveInfo();
    displayInfo();

    return 0;
}//end main

//fn def
void saveInfo()
{
    //writes records to a sequential access file
    string title = "";
    string author = "";

    //creates file object and opens the file
    ofstream outFile;
    outFile.open("eBooks.txt", ios::app);

    //determin wheather the file was opened
    if (outFile.is_open())
    {
        cout << "Adding eBooks to your Library:" << endl << endl;
        cout << "Enter an eBook Title (-1 to stop): ";
        getline(cin, title);
        while (title != "-1")
        {
            cout << "Enter the eBook's Author: ";
            getline(cin, author);
            //write the record
            outFile << title << '#' << author << endl;

            cout << "Enter an eBook Title (-1 to stop): ";
            getline(cin, title);
        }//end while
        outFile.close();
    }
    else
        cout << "eBooks.txt file could not be opened." << endl;
}//end saveInfo fn

void displayInfo()
{
    //displays the records stored in the file
    string title = "";
    string author = "";

    //create file object and open the file
    ifstream inFile;
    inFile.open("eBooks.txt", ios::in);

    //determine whether the file was opened
    if (inFile.is_open())
    {
        cout << endl << endl << "Your eBook Library" << endl;
        cout << "----------------" << endl;

        //read a record
        getline(inFile, title, '#');
        getline(inFile, author);

        while (!inFile.eof())
        {
            //display the record
            cout << title << " by " << author << endl;

            //read another record
            getline(inFile, title, '#');
            getline(inFile, author);
        }//end while
        inFile.close();
    }
    else
        cout << "eBooks.txt file could not be opened." << endl;
}//end displayInfo fn
