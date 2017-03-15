///////////////////////////////////////////////////////////////////////////////
// File Name:      GradStudent.cpp
//
// Author:         Evan Kivolowitz
// CS email:       ekivolowitz@cs.wisc.edu
//
// Description:    The implementation file for the GradStudent class.
//
///////////////////////////////////////////////////////////////////////////////

#include "GradStudent.hpp"
#include <iostream>


int GradStudent::numGradStudents = 0;

GradStudent::GradStudent(std::string name,
			    const std::vector<double> &assignmentsScore,
			    double projectScore,
			    std::string researchArea,
			    std::string advisor) : Student(name, assignmentsScore, projectScore), 
				researchArea(researchArea), advisor(advisor)
{
	GradStudent::numGradStudents++;
}

std::string GradStudent::getResearchArea()
{
	return researchArea;
}

std::string GradStudent::getAdvisor()
{
	return advisor;
}

int GradStudent::getNumStudents()
{
	return GradStudent::numGradStudents;
}

void GradStudent::printDetails()
{
	Student::printDetails();
	std::cout << "Type = Graduate Student" << std::endl;
	std::cout << "Research Area = " << this->getResearchArea() << std::endl;
	std::cout << "Advisor = " << this->getAdvisor() << std::endl;
	std::cout << std::endl;
}

double GradStudent::getTotal()
{
	double assignmentScoreSum = 0;
	for(auto it = (this->getAssignmentsScore()).begin(); it != (this->getAssignmentsScore()).end(); ++it)
	{
		assignmentScoreSum += *it;
	}
	double avg_assignments_score = assignmentScoreSum / (this->getAssignmentsScore()).size();

	double total = avg_assignments_score * 0.5 + this->getProjectScore() * 0.5;
	return total;
}

std::string GradStudent::getGrade()
{
	if(this->getTotal() >= 80) return "CR";
	else return "N";
}