///////////////////////////////////////////////////////////////////////////////
// File Name:      Student.cpp
//
// Author:         Evan Kivolowitz
// CS email:       ekivolowitz@cs.wisc.edu
//
// Description:    The implementation file for the Student class.
//
// Sources: http://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c 
//
///////////////////////////////////////////////////////////////////////////////

#include "Student.hpp"
#include <iostream>
#include <sstream>
int Student::numStudents = 0;


Student::Student(std::string name, const std::vector<double> &assignmentsScore, double projectScore)
{
	this->name = name;
	this->assignmentsScore = assignmentsScore;
	this->projectScore = projectScore;
	this->id = Student::numStudents;
	Student::numStudents++;
}

std::string Student::formatAssignmentsScore(std::vector<double> &a)
{
	std::string retValue = "[";
	for(auto it = a.begin(); it != a.end(); ++it)
	{
		if(it + 1 == a.end())
		{
			std::ostringstream convertStream;
			convertStream << *it;
			std::string convertString = convertStream.str();
			retValue += convertString;
			// retValue += dtos(*it);
			retValue += "]";	
		} 
		else
		{
			std::ostringstream convertStream;
			convertStream << *it;
			std::string convertString = convertStream.str();
			retValue += convertString;
			retValue += ", ";
		}
	}
	return retValue;
}


int Student::getId()
{
	return id;
}

std::string Student::getName()
{
	return name;
}


const std::vector<double>& Student::getAssignmentsScore()
{
	return assignmentsScore;
}

double Student::getProjectScore()
{
	return projectScore;
}

int Student::getNumStudents()
{
	return Student::numStudents;
}

void Student::printDetails()
{
	std::cout << "STUDENT DETAILS:" << std::endl;
	std::cout << "Id = " << this->getId() << std::endl;
	std::cout << "Name = " << this->getName() << std::endl;
	std::cout << "Assignments = " << this->formatAssignmentsScore(this->assignmentsScore) << std::endl;
	std::cout << "Project = " << this->getProjectScore() << std::endl;
	std::cout << "Total = " << this->getTotal() << std::endl;
	std::cout << "Grade = " << this->getGrade() << std::endl;
}
