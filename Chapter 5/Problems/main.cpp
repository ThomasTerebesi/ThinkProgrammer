// "Problem: Class Roster", page 118
// "Problem: Tracking an Unknown Quantity of Student Records", page 126


#include "studentCollection.h"

int main()
{
	StudentCollection stuCollection;

	StudentRecord stu3(84, 1152, "Sue");
	StudentRecord stu2(75, 4875, "Ed");
	StudentRecord stu1(98, 2938, "Todd");

	stuCollection.AddRecord(stu3);
	stuCollection.AddRecord(stu2);
	stuCollection.AddRecord(stu1);

	std::cout << "stuCollection:" << std::endl;
	stuCollection.PrintRecords();

	stuCollection.RemoveRecord(4875);

	std::cout << "\nAfter using 'RemoveRecord(4875)':" << std::endl;
	
	stuCollection.PrintRecords();

	std::cin.get();

	return 0;
}