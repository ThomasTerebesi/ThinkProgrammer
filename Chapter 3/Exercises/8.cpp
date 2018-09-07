#include <iostream>

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

	int upperQuartile, middleQuartile, lowerQuartile;

	// Finding the middle quartile
	if (ARRAY_SIZE % 2 == 0)
		middleQuartile = (studentArray[ARRAY_SIZE / 2].grade + studentArray[(ARRAY_SIZE / 2) + 1].grade) / 2;
	else
		middleQuartile = studentArray[ARRAY_SIZE / 2 + 1].grade;

	// Calculating the upper quartile
	upperQuartile = (ARRAY_SIZE + middleQuartile) / 2;

	int count = 0;

	while (studentArray[count].grade > middleQuartile)
	{
		// TODO: Do this right
		count++;
	}



	if ((count + 1) % 2 == 0)
		upperQuartile;
	else
		upperQuartile;

	// Calculating the lower quartile
	lowerQuartile = (ARRAY_SIZE - middleQuartile) / 2;

	std::cout << "U: " << upperQuartile << std::endl;
	std::cout << "M: " << middleQuartile << std::endl;
	std::cout << "L: " << lowerQuartile << std::endl;

	std::cin.get();

	return 0;
}