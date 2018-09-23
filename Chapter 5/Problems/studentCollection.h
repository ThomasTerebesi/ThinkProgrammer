// "Problem: Tracking an Unknown Quantity of Student Records", page 126

#pragma once

#include "studentRecord.h"

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
	studentCollection(const studentCollection & original);
	~studentCollection();

	void AddRecord(studentRecord newStudent);
	studentRecord RecordWithNumber(int idNum);
	void RemoveRecord(int idNum);

	void PrintRecords();

	studentCollection & operator=(const studentCollection & rhs);

private:
	typedef studentNode * studentList;
	studentList _listHead;

	void DeleteList(studentList &listPtr);
	studentList CopiedList(const studentList original);
};