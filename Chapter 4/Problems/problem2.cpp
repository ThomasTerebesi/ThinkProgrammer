// "Problem: Tracking an Unknown Quantity of Student Records", page 101

#include <iostream>
#include <memory>

struct listNode
{
	int studentNum;
	int grade;
	listNode * next;

	~listNode()
	{
		delete next;
	}
};

typedef listNode * studentCollection;

void AddRecord(studentCollection& sc, int stuNum, int stuGr)
{
	listNode * newNode = new listNode;
	newNode->studentNum = stuNum;
	newNode->grade = stuGr;
	newNode->next = sc;
	sc = newNode;
}

double AverageRecord(studentCollection sc)
{
	if (sc == nullptr)
		return 0.0;

	int count = 0;
	double sum = 0;
	listNode * loopPtr = sc;

	while (loopPtr != nullptr)
	{
		sum += loopPtr->grade;
		count++;
		loopPtr = loopPtr->next;
	}
	
	return sum / count;
}

int main()
{
	studentCollection sc;
	
	listNode * node1 = new listNode;
	node1->studentNum = 1001;
	node1->grade = 78;

	listNode* node2 = new listNode;
	node2->studentNum = 1012;
	node2->grade = 93;

	listNode* node3 = new listNode;
	node3->studentNum = 1076;
	node3->grade = 85;

	sc = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = nullptr;

	AddRecord(sc, 1274, 91);

	double average = AverageRecord(sc);

	std::cout << average << std::endl;
	
	std::cin.get();

	return 0;
}