// "Problem: Tracking an Unknown Quantity of Student Records", page 126

#pragma once

#include "studentRecord.h"

class StudentCollection
{
private:
	struct StudentNode
	{
		StudentRecord studentData;
		StudentNode * next;
	};

public:
	StudentCollection();
	StudentCollection(const StudentCollection & original);
	~StudentCollection();

	void AddRecord(StudentRecord newStudent);
	StudentRecord RecordWithNumber(int idNum);
	void RemoveRecord(int idNum);

	void PrintRecords();

	StudentCollection & operator=(const StudentCollection & rhs);

private:
	typedef StudentNode * studentList;
	studentList _listHead;

	void DeleteList(studentList &listPtr);
	studentList CopiedList(const studentList original);
};