#include <iostream>
#include <string>

struct student
{
	int grade;
	int studentID;
	std::string name;
};

void AddStudent(student*& sa, int& length, int l_grade, int l_id, std::string name);

int main()
{
	int arraySize = 10;

	student* studentArray = new student[arraySize]
	{
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

	for (int i = 0; i < arraySize; i++)
		std::cout << studentArray[i].studentID << "\t" << studentArray[i].grade << "\t" << studentArray[i].name << std::endl;


	std::cout << "\nAfter adding two new students:" << std::endl;
	AddStudent(studentArray, arraySize, 22, 10011, "Martin");
	AddStudent(studentArray, arraySize, 78, 10012, "Paul");

	for (int i = 0; i < arraySize; i++)
		std::cout << studentArray[i].studentID << "\t" << studentArray[i].grade << "\t" << studentArray[i].name << std::endl;

	std::cin.get();

	delete[] studentArray;

	return 0;
}

void AddStudent(student*& sArray, int& length, int l_grade, int l_id, std::string l_name)
{
	student* newStudentArray = new student[length + 1];

	for (int i = 0; i < length; i++)
		newStudentArray[i] = sArray[i];

	newStudentArray[length].grade = l_grade;
	newStudentArray[length].studentID = l_id;
	newStudentArray[length].name = l_name;

	delete[] sArray;

	sArray = newStudentArray;
	length++;
}
