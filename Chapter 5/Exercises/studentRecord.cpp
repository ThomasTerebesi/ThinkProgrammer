// "Problem: Class Roster", page 118

#include "studentRecord.h"

StudentRecord::StudentRecord()
{
	SetGrade(0);
	SetStudentID(-1);
	SetName("");
}

StudentRecord::StudentRecord(int newGrade, int newID, std::string newName)
{
	SetGrade(newGrade);
	SetStudentID(newID);
	SetName(newName);
}

int StudentRecord::GetGrade()
{
	return _grade;
}

void StudentRecord::SetGrade(int newGrade)
{
	if (IsValidGrade(newGrade))
		_grade = newGrade;
	else
		std::cout << "studentRecord::SetGrade(): Invalid grade." << std::endl;
}

int StudentRecord::GetStudentID()
{
	return _studentID;
}

void StudentRecord::SetStudentID(int newID)
{
	if (newID <= 10000)
		_studentID = newID;
}

std::string StudentRecord::GetName()
{
	return _name;
}

void StudentRecord::SetName(std::string newName)
{
	// TODO: check if valid
	_name = newName;
}

std::string StudentRecord::LetterGrade()
{
	if (!IsValidGrade(_grade))
		return "studentRecord::LetterGrade(): Invalid grade.";

	const int NUMBER_CATEGORIES = 11;
	const std::string GRADE_LETTER[] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A" };
	const int LOWEST_GRADE_SCORE[] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
	int category = 0;

	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;

	return GRADE_LETTER[category - 1];
}

bool StudentRecord::IsValidGrade(int grade)
{
	if ((grade >= 0) && (grade <= 100))
		return true;
	else
		return false;
}
