#include "studentCollection.h"

studentCollection::studentCollection()
{
	_listHead = nullptr;
}

studentCollection::studentCollection(const studentCollection & original)
{
	_listHead = CopiedList(original._listHead);
}

studentCollection::~studentCollection()
{
	DeleteList(_listHead);
}

void studentCollection::AddRecord(studentRecord newStudent)
{
	studentNode * newNode = new studentNode;
	newNode->studentData = newStudent;
	newNode->next = _listHead;
	_listHead = newNode;
}

studentRecord studentCollection::RecordWithNumber(int idNum)
{
	studentNode * loopPtr = _listHead;

	while (loopPtr != nullptr && loopPtr->studentData.GetStudentID() != idNum)
		loopPtr = loopPtr->next;

	if (loopPtr == nullptr)
		return studentRecord(-1, -1, "");
	else
		return loopPtr->studentData;
}

void studentCollection::RemoveRecord(int idNum)
{
	studentNode * loopPtr = _listHead;
	studentNode * trailing = nullptr;

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

void studentCollection::PrintRecords()
{
	studentNode * loopPtr = _listHead;

	while (loopPtr != nullptr)
	{
		std::cout << "ID: " << loopPtr->studentData.GetStudentID() << "\tName: " << loopPtr->studentData.GetName() << "\tGrade: " << loopPtr->studentData.GetGrade() << std::endl;

		loopPtr = loopPtr->next;
	}
}

studentCollection & studentCollection::operator=(const studentCollection & rhs)
{
	if (this != &rhs)
	{
		DeleteList(_listHead);
		_listHead = CopiedList(rhs._listHead);
	}

	return *this;
}

void studentCollection::DeleteList(studentList & listPtr)
{
	while (listPtr != nullptr)
	{
		studentNode * temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

studentCollection::studentList studentCollection::CopiedList(const studentList original)
{
	if (original == nullptr)
		return nullptr;

	studentList newList = new studentNode;

	newList->studentData = original->studentData;
	
	studentNode * oldLoopPtr = original->next;
	studentNode * newLoopPtr = newList;

	while (oldLoopPtr != nullptr)
	{
		newLoopPtr->next = new studentNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->studentData = oldLoopPtr->studentData;
		oldLoopPtr = oldLoopPtr->next;
	}

	newLoopPtr->next = nullptr;

	return newList;
}
