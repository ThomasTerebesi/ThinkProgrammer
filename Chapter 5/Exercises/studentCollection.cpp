#include "studentCollection.h"

StudentCollection::StudentCollection()
{
	_listHead = nullptr;
}

StudentCollection::StudentCollection(const StudentCollection & original)
{
	_listHead = CopiedList(original._listHead);
}

StudentCollection::~StudentCollection()
{
	DeleteList(_listHead);
}

void StudentCollection::AddRecord(StudentRecord newStudent)
{
	StudentNode * newNode = new StudentNode;
	newNode->studentData = newStudent;
	newNode->next = _listHead;
	_listHead = newNode;
}

StudentRecord StudentCollection::RecordWithNumber(int idNum)
{
	StudentNode * loopPtr = _listHead;

	while (loopPtr != nullptr && loopPtr->studentData.GetStudentID() != idNum)
		loopPtr = loopPtr->next;

	if (loopPtr == nullptr)
		return StudentRecord(-1, -1, "");
	else
		return loopPtr->studentData;
}

void StudentCollection::RemoveRecord(int idNum)
{
	StudentNode * loopPtr = _listHead;
	StudentNode * trailing = nullptr;

	while (loopPtr != nullptr && loopPtr->studentData.GetStudentID() != idNum)
	{
		trailing = loopPtr;
		loopPtr = loopPtr->next;
	}

	if (loopPtr == nullptr)
		return;

	if (trailing == nullptr)
		_listHead = _listHead->next;
	else
		trailing->next = loopPtr->next;
	
	delete loopPtr;
}

void StudentCollection::PrintRecords()
{
	StudentNode * loopPtr = _listHead;

	while (loopPtr != nullptr)
	{
		std::cout << "ID: " << loopPtr->studentData.GetStudentID() << "\tName: " << loopPtr->studentData.GetName() << "\tGrade: " << loopPtr->studentData.GetGrade() << std::endl;

		loopPtr = loopPtr->next;
	}
}

StudentCollection StudentCollection::RecordsWithinRange(int min, int max)
{
	StudentCollection newStudentCollection;
	StudentNode * loopPtr = _listHead;

	while (loopPtr != nullptr)
	{
		if (loopPtr->studentData.GetGrade() >= min && loopPtr->studentData.GetGrade() <= max)
		{
			StudentRecord newStudentRecord;

			newStudentRecord.SetGrade(loopPtr->studentData.GetGrade());
			newStudentRecord.SetName(loopPtr->studentData.GetName());
			newStudentRecord.SetStudentID(loopPtr->studentData.GetStudentID());

			newStudentCollection.AddRecord(newStudentRecord);
		}

		loopPtr = loopPtr->next;
	}

	return newStudentCollection;
}

StudentCollection & StudentCollection::operator=(const StudentCollection & rhs)
{
	if (this != &rhs)
	{
		DeleteList(_listHead);
		_listHead = CopiedList(rhs._listHead);
	}

	return *this;
}

void StudentCollection::DeleteList(studentList & listPtr)
{
	while (listPtr != nullptr)
	{
		StudentNode * temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

StudentCollection::studentList StudentCollection::CopiedList(const studentList original)
{
	if (original == nullptr)
		return nullptr;

	studentList newList = new StudentNode;

	newList->studentData = original->studentData;
	
	StudentNode * oldLoopPtr = original->next;
	StudentNode * newLoopPtr = newList;

	while (oldLoopPtr != nullptr)
	{
		newLoopPtr->next = new StudentNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->studentData = oldLoopPtr->studentData;
		oldLoopPtr = oldLoopPtr->next;
	}

	newLoopPtr->next = nullptr;

	return newList;
}
