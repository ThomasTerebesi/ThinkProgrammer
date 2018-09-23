// "Problem: Tracking an Unknown Quantity of Student Records", page 126

#pragma once

#include "problem1.h"

class studentCollection
{
private:
	struct studentNode
	{
		studentRecord studentData;
		studentNode * next;
	};

public:
	studentCollection();
	~studentCollection();

	void AddRecord(studentRecord newStudent);
	studentRecord RecordWithNumber(int idNum);
	void RemoveRecord(int idNum);

	void PrintRecords();

private:
	typedef studentNode * studentList;
	studentList _listHead;

	void DeleteList(studentList &listPtr);
};