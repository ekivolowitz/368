////////////////////////////////////////////////////////////////////////////////
// File Name:      a1.cpp
//
// Author:         Evan Kivolowitz
// CS email:       ekivolowitz@wisc.edu
//
// Description:    A program that reads in a string and
//                 repeats it in a grid-like format
//
// Sources:        n/a
//
// URL(s) of sources: n/a
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

/**
* This function takes the string to repeat and formats it in accordance
* to the specified parameters of columns and rows. 
* @param String str - the string to repeat.
* @param int rows - number of rows to repeat the string
* @param int columns - number of times to repeat the string per row.
* @return A string formatted in the correct way. 
*/
string formatOutput(string str, int rows, int columns)
{
    //Initialize the string to return.
    string ret = "";

    //Number of rows.
    for(int i = 0; i < rows; i++)
    {
        //Number of columns per row. 
        for(int j = 0; j < columns; j++)
        {
            ret = ret + str;
        }
        //If it is the last row, do not add a newline character.
        if(i == rows -1)
        {
            continue;
        }
        else
        {
            ret = ret + "\n";
        }
    }
    //return when finished. 
    return ret;
}



int main()
{
    string inputString;
    cout << "Enter a fancy string: ";
    getline(cin, inputString);

    int rows;
    int columns;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of cols: ";
    cin >> columns;
    
	string outputString;
	if(rows != 0)
	{
		outputString = formatOutput(inputString, rows, columns);
		cout << outputString << endl;
	}
}
