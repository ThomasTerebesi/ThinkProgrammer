// "Problem: Class Roster", page 118

#include "problem1.h"

studentRecord::studentRecord()
{
	SetGrade(0);
	SetStudentID(-1);
	SetName("");
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName)
{
	SetGrade(newGrade);
	SetStudentID(newID);
	SetName(newName);
}

int studentRecord::GetGrade()
{
	return _grade;
}

void studentRecord::SetGrade(int newGrade)
{
	if (IsValidGrade(newGrade))
		_grade = newGrade;
	else
		std::cout << "SetGrade(): Invalid grade." << std::endl;
}

int studentRecord::GetStudentID()
{
	return _studentID;
}

void studentRecord::SetStudentID(int newID)
{
	if (newID <= 10000)
		_studentID = newID;
}

std::string studentRecord::GetName()
{
	return _name;
}

void studentRecord::SetName(std::string newName)
{
	// TODO: check if valid
	_name = newName;
}

std::string studentRecord::LetterGrade()
{
	if (!IsValidGrade(_grade))
		return "LetterGrade(): Invalid grade.";

	const int NUMBER_CATEGORIES = 11;
	const std::string GRADE_LETTER[] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A" };
	const int LOWEST_GRADE_SCORE[] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
	int category = 0;

	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;

	return GRADE_LETTER[category - 1];
}

bool studentRecord::IsValidGrade(int grade)
{
	if ((grade >= 0) && (grade <= 100))
		return true;
	else
		return false;
}
