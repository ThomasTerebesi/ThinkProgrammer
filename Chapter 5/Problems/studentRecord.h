// "Problem: Class Roster", page 118

#pragma once

#include <iostream>
#include <string>

class studentRecord
{
public:
	studentRecord();
	studentRecord(int newGrade, int newID, std::string newName);

	int GetGrade();
	void SetGrade(int newGrade);

	int GetStudentID();
	void SetStudentID(int newID);

	std::string GetName();
	void SetName(std::string newName);

	std::string LetterGrade();

private:
	int _grade;
	int _studentID;
	std::string _name;

	bool IsValidGrade(int grade);
};
