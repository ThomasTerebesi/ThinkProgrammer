#include "problem2.h"

int main()
{
	studentCollection s;

	studentRecord stu3(84, 1152, "Sue");
	studentRecord stu2(75, 4875, "Ed");
	studentRecord stu1(98, 2938, "Todd");

	s.AddRecord(stu3);
	s.AddRecord(stu2);
	s.AddRecord(stu1);

	s.PrintRecords();

	s.RemoveRecord(4875);

	std::cout << "\nAfter using 'RemoveRecord(4875)':" << std::endl;
	
	s.PrintRecords();

	std::cin.get();

	return 0;
}