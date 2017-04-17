///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         <your name>
// CS email:       <your CS email>
//
// Description:    Methods to perform some processing on student objects.
//
// Sources:        <Sources, if any>
//
// URL(s) of sources:
//                 <URLs of your sources, if any>
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"

// TODO: add other #include statements here, and using namespace std if desired
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

void fillStudents(std::istream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {

    // TODO: Implement this method.
    std::string tempLine;
	while(std::getline(inFile, tempLine))
	{
		std::stringstream ss;
		std::vector<std::string> values;
		ss.str(tempLine);
		std::string item;
		while(std::getline(ss, item, ','))
		{
			values.push_back(item);
		}

		if(values[0] == "U")
		{
			std::vector<double> assignmentsScores;
			std::string name = values[1];
			for(auto it = values.begin() + 2; it != values.begin() + 8; ++it)
			{
				assignmentsScores.push_back(stod(*it));
			}

			double projectScore = stod(values[8]);
			std::string residence_hall = values[9];
			std::string yearInSchool = values[10];
			UndergradStudent u(name, assignmentsScores, projectScore, residence_hall, yearInSchool);
			ugstudents.push_back(u);			
		}
		else if(values[0] == "G")
		{
			std::vector<double> assignmentsScores;
			std::string name = values[1];
			for(auto it = values.begin() + 2; it != values.begin() + 8; ++it)
			{
				assignmentsScores.push_back(stod(*it));
			}

			double projectScore = stod(values[8]);
			std::string area_of_research = values[9];
			std::string advisor = values[10];
			GradStudent g(name, assignmentsScores, projectScore, area_of_research, advisor);
			gstudents.push_back(g);
		}
	}

}

void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.
    for(auto it = students.begin(); it != students.end(); ++it)
    {
    	((*it).get()).printDetails();
    }
}



void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.

	double sumStudentsTotal = 0;
	double meanStudentsTotal = 0;


    // compute the # of students based on the type of students.
	int numStudents = students.size();
	

    // compute the mean of the total score.

	for(auto it = students.begin(); it != students.end(); ++it)
    {
    	sumStudentsTotal += ((*it).get()).getTotal();
    }

    meanStudentsTotal = sumStudentsTotal / numStudents;

    std::cout << "Number of students = " << numStudents << std::endl;
    std::cout << "The mean of the total score = " << meanStudentsTotal << std::endl;
    std::cout << "The sorted list of students (id, name, total, grade) in descending order of total:" << std::endl;
    std::sort(students.begin(), students.end(), [](Student& A, Student& B) {return A.getTotal() > B.getTotal() ;} );


    for(auto it = students.begin(); it != students.end(); ++it)
    {
    	std::cout << (*it).get().getId() << ", " << (*it).get().getName() << ", " << (*it).get().getTotal() << ", " << (*it).get().getGrade() << std::endl;
    }
    std::cout << std::endl;
    //sort and print the students based on their total.
    //printStudents(students);
}
