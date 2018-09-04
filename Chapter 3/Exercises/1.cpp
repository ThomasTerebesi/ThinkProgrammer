#include <iostream>
#include <string>

const int ARRAY_SIZE = 10;

struct student
{
	int grade;
	int studentID;
	std::string name;
};

int SortByGrade(const void* voidA, const void* voidB)
{
	student * studentA = (student*)(voidA);
	student * studentB = (student*)(voidB);

	return studentB->grade - studentA->grade;
}

int SortByID(const void* voidA, const void* voidB)
{
	student * studentA = (student*)(voidA);
	student * studentB = (student*)(voidB);

	return studentA->studentID - studentB->studentID;
}

int main()
{
	student studentArray[ARRAY_SIZE] = {
		{78, 10004, "Sasha"},
		{81, 10009, "Aretha"},
		{87, 10001, "Fred"},
		{68, 10010, "Veronica"},
		{84, 10005, "Erin"},
		{28, 10002, "Tom"},
		{70, 10008, "Candy"},
		{75, 10007, "Leslie"},
		{100, 10003, "Alistair"},
		{98, 10006, "Belinda"}
	};

	std::cout << "Contents of studentArray before qsort():" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << studentArray[i].studentID << "\t" << studentArray[i].name << ", " << studentArray[i].grade << " points" << std::endl;

	// Sort by grade
	qsort(studentArray, ARRAY_SIZE, sizeof(student), SortByGrade);

	std::cout << "\nContents of studentArray after qsort() - sorted by grade:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << studentArray[i].studentID << "\t" << studentArray[i].name << ", " << studentArray[i].grade << " points" << std::endl;

	// Sort by studentID
	qsort(studentArray, ARRAY_SIZE, sizeof(student), SortByID);

	std::cout << "\nContents of studentArray after qsort() - sorted by studentID:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << studentArray[i].studentID << "\t" << studentArray[i].name << ", " << studentArray[i].grade << " points" << std::endl;

	std::cin.get();

	return 0;
}