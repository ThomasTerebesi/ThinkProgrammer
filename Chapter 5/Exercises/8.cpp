#include <iostream>
#include "studentCollection.h"

int main()
{
	StudentCollection stuCollection;

	StudentRecord stu6(76, 2381, "Bob");
	StudentRecord stu5(69, 3047, "Mara");
	StudentRecord stu4(93, 2938, "Phil");
	StudentRecord stu3(84, 1152, "Sue");
	StudentRecord stu2(75, 4875, "Ed");
	StudentRecord stu1(98, 2938, "Todd");

	stuCollection.AddRecord(stu6);
	stuCollection.AddRecord(stu5);
	stuCollection.AddRecord(stu4);
	stuCollection.AddRecord(stu3);
	stuCollection.AddRecord(stu2);
	stuCollection.AddRecord(stu1);

	std::cout << "stuCollection:" << std::endl;
	stuCollection.PrintRecords();

	StudentCollection rangedCollection = stuCollection.RecordsWithinRange(65, 80);

	std::cout << "\nrangedCollection for grades within a range from 65 to 80:" << std::endl;
	rangedCollection.PrintRecords();

	std::cin.get();

	return 0;
}