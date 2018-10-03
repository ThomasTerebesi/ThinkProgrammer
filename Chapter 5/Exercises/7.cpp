// This was already partially solved for the two problems on pages 118 and 126

#include <iostream>
#include "studentCollection.h"

int main()
{
	StudentCollection stuCollection1;

	StudentRecord stu3(84, 1152, "Sue");
	StudentRecord stu2(75, 4875, "Ed");
	StudentRecord stu1(98, 2938, "Todd");

	stuCollection1.AddRecord(stu3);
	stuCollection1.AddRecord(stu2);
	stuCollection1.AddRecord(stu1);

	std::cout << "stuCollection1:" << std::endl;
	stuCollection1.PrintRecords();


	StudentCollection stuCollection2;

	StudentRecord stu6(76, 2381, "Bob");
	StudentRecord stu5(69, 3047, "Mara");
	StudentRecord stu4(93, 2938, "Phil");

	stuCollection2.AddRecord(stu6);
	stuCollection2.AddRecord(stu5);
	stuCollection2.AddRecord(stu4);

	std::cout << "\nstuCollection2:" << std::endl;
	stuCollection2.PrintRecords();


	std::cout << "\nCreating copy of stuCollection2 in stuCollection3." << std::endl;
	StudentCollection stuCollection3 = stuCollection2;


	stuCollection2.RemoveRecord(3047);

	std::cout << "\nstuCollection2 after RemoveRecord(3047):" << std::endl;

	stuCollection2.PrintRecords();


	std::cout << "\nstuCollection3:" << std::endl;
	stuCollection3.PrintRecords();


	std::cin.get();

	return 0;	
}