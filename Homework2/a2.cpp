///////////////////////////////////////////////////////////////////////
// File Name:      a2.cpp
//
// Author:         Evan Kivolowitz
// CS email:       ekivolowitz@wisc.edu
// 
// Description:   This is P2? I think?
//
// Sources:       -
//
// URL(s) of sources:           
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>


using namespace std;

/**
*	This function's sole purpose is to get user input and return it. 
*	It's used exclusively as a helper in the readInFile method.
*	@param string promptMessage - message to display out to user on which file (first or second)
*		to prompt.
*	@return the value the user enters from stdin. 
*/

string getFileName(string promptMessage)
{
	string fileName;
	cout << promptMessage;
    getline(cin, fileName);
    return fileName;
}

/**
*	This function gets the file name for file 1 and 2, then reads the file in.
*	@param ifstream& file - file to read information in.
*	@param vector<string>& vec - vector to store the lines read in into.
*	@param string& fName - a name to store the valid filename in.
*	@param stringfileNumber - file number. Either 'first' or 'second'. 
*	return - void
*/
void readInFile(ifstream& file, vector<string>& vec, string& fName, const string fileNumber)
{
	//temporary variable declared out here so that I can assign it to fName once a valid 
	//filename is entered.
	string fileName;

	//runs at least once.
	do
    {
    	string getFileNameMessage = "Enter the name of the " + fileNumber + " file: ";
    	fileName = getFileName(getFileNameMessage);
    	file.open(fileName);
    	if(!file.is_open()) cout << "Input file " << fileName << " is NOT found. Please try again." << endl;

    }while(!file.is_open());

    fName = fileName;

    string line;
	while(getline(file, line)) vec.push_back(line);

	file.close();
}


/**
*	This function calculates the intersection between the two recipe vectors passed to it.
*	@param vector<string>& v1 - vector one compare to vector 2.
*	@param vector<string>& v2 - vector to be compared to against vector 1. 
*	@
*
*/
void fileIntersection(vector<string>& v1, vector<string>& v2, 
	vector<string>& intersection)
{
	for(unsigned int i = 0; i < v1.size(); ++i)
	{
		string v1Value = v1[i];
		for(unsigned int j = 0; j < v2.size(); j++)
		{
			if(v1Value.compare(v2[j]) == 0)
			{
				intersection.push_back(v1Value);
				break;
			}
		}
	}
}

void fileDisjoint(vector<string>& v1, vector<string>& v2,
 vector<string>& disjoint)
{
	bool inV2 = false;
	for(unsigned int i = 0; i < v1.size(); ++i)
	{
		string v1Value = v1[i];
		for(unsigned int j = 0; j < v2.size(); ++j)
		{
			if(v1Value.compare(v2[j]) == 0)
			{
				inV2 = true;
			}
		}
		if(!inV2)
		{
			disjoint.push_back(v1Value);
		}
		else
		{
			inV2 = false;
		}
	}
}


int main(int argc, char * argv[])
{
    string fileName1;
    string fileName2;

    ifstream file1;
    ifstream file2;
    ofstream intersectionOutput;
    ofstream difference;

    vector<string> file1Values;
    vector<string> file2Values;
    vector<string> intersection;
    vector<string> disjoint;

    readInFile(file1, file1Values, fileName1, "first");
    readInFile(file2, file2Values, fileName2, "second");
    cout << endl;

    fileIntersection(file1Values, file2Values, intersection);
    fileDisjoint(file1Values, file2Values, disjoint);

    cout << "Number of recipes in " << fileName1 << " = " << file1Values.size() << endl;
    cout << "Number of recipes in " << fileName2 << " = " << file2Values.size() << endl;
    cout << "Number of recipes that are present in BOTH " << fileName1 << " AND " << fileName2 <<"= " << intersection.size() << endl;
    cout << "Number of recipes that are in " << fileName1 << " BUT NOT IN " << fileName2 << " = " << disjoint.size() << endl;
    cout << endl;

    sort(intersection.begin(), intersection.end());
    sort(disjoint.begin(), disjoint.end());
    
    if(intersection.size() > 0)
    {
    	cout << "List of recipes that are present in BOTH " << fileName1 << " AND " << fileName2 << ": " << endl;
    	for(unsigned int i = 0; i < intersection.size(); ++i)
    	{
    		cout << intersection[i] << endl;
    	}

    	cout << endl;
    }

    intersectionOutput.open("intersection.txt");
    difference.open("difference.txt");

    for(unsigned int i = 0; i < intersection.size(); ++i)
    {
    	intersectionOutput << intersection[i] << endl;
    }

    intersectionOutput.close();

    for(unsigned int i = 0; i < disjoint.size(); ++i)
    {
    	difference << disjoint[i] << endl;
    }

    difference.close();
    cout << "The set intersection of the two files was written to a file named intersection.txt" << endl;
    cout << "The set difference of the two files was written to a file named difference.txt" << endl;

    return 0;
}
