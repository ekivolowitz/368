///////////////////////////////////////////////////////////////////////////////
// File Name:      UndergradStudent.cpp
//
// Author:         Evan Kivolowitz
// CS email:       ekivolowitz@cs.wisc.edu
//
// Description:    The implementation file for the UndergradStudent class.
//
///////////////////////////////////////////////////////////////////////////////

#include "UndergradStudent.hpp"
#include <iostream>

int UndergradStudent::numUndergradStudents = 0;

UndergradStudent::UndergradStudent(std::string name,
                 const std::vector<double> &assignmentsScore,
                 double projectScore,
                 std::string residenceHall,
                 std::string yearInCollege) : 
					Student(name, assignmentsScore, projectScore),
					residenceHall(residenceHall), yearInCollege(yearInCollege)
{
	UndergradStudent::numUndergradStudents++;
}

std::string UndergradStudent::getResidenceHall()
{
	return residenceHall;
}

std::string UndergradStudent::getYearInCollege()
{
	return yearInCollege;
}

int UndergradStudent::getNumStudents()
{
	return UndergradStudent::numUndergradStudents;
}

void UndergradStudent::printDetails()
{
	Student::printDetails();
	std::cout << "Type = Undergraduate Student" << std::endl;
	std::cout << "Residence Hall = " << this->getResidenceHall() << std::endl;
	std::cout << "Year in College = " << this->getYearInCollege() << std::endl;
	std::cout << std::endl;
}

double UndergradStudent::getTotal()
{
	double assignmentScoreSum = 0;
	for(auto it = (this->getAssignmentsScore()).begin(); it != (this->getAssignmentsScore()).end(); ++it)
	{
		assignmentScoreSum += *it;
	}
	double avg_assignments_score = assignmentScoreSum / (this->getAssignmentsScore()).size();

	double total = avg_assignments_score * 0.7 + this->getProjectScore() * 0.3;
	return total;
}

std::string UndergradStudent::getGrade()
{
	if(this->getTotal() >= 70) return "CR";
	else return "N";
}