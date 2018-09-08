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

	return studentA->grade - studentB->grade;
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

	qsort(studentArray, ARRAY_SIZE, sizeof(student), SortByGrade);

	std::cout << "ID\tGrade\tName" << std::endl;
	std::cout << "========================" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << studentArray[i].studentID << "\t" << studentArray[i].grade << "\t" << studentArray[i].name << std::endl;

	float first, second, third;

	// First quartile
	if (ARRAY_SIZE * 0.25 == static_cast<int>(ARRAY_SIZE * 0.25))
		first = (studentArray[static_cast<int>((ARRAY_SIZE * 0.25) - 1)].grade + studentArray[static_cast<int>(ARRAY_SIZE * 0.75)].grade) / 2;
	else
		first = studentArray[static_cast<int>(ceil((ARRAY_SIZE * 0.25) - 1))].grade;

	// Second quartile
	if (ARRAY_SIZE % 2 == 0)
		second = (studentArray[(ARRAY_SIZE / 2) - 1].grade + studentArray[(ARRAY_SIZE / 2)].grade) / 2.0f;
	else
		second = studentArray[ARRAY_SIZE / 2].grade;

	// Third quartile
	if (ARRAY_SIZE * 0.75 == static_cast<int>(ARRAY_SIZE * 0.75))
		third = (studentArray[static_cast<int>((ARRAY_SIZE * 0.75) - 1)].grade + studentArray[static_cast<int>(ARRAY_SIZE * 0.75)].grade) / 2;
	else
		third = studentArray[static_cast<int>(ceil((ARRAY_SIZE * 0.75) - 1))].grade;

	std::cout << "\nTo score as well or better than 25% of the students, you would need a grade of " << first << "." << std::endl;
	std::cout << "To score as well or better than 50% of the students, you would need a grade of " << second << "." << std::endl;
	std::cout << "To score as well or better than 75% of the students, you would need a grade of " << third << "." << std::endl;
	

	std::cin.get();

	return 0;
}