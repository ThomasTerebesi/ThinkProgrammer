#include <iostream>

struct intNode
{
	int i;

	intNode * next;

	~intNode()
	{
		delete next;
	}
};

typedef intNode * intList;

void IntToList(int number, intList & iList)
{
	if (number < 0)
	{
		iList = nullptr;
		return;
	}

	int myNumber = number;
	intNode * loopPtr = iList;

	while (loopPtr->next != nullptr)
	{
		if (myNumber >= 10)
		{
			loopPtr->i = myNumber % 10;
			myNumber /= 10;
			loopPtr->next = new intNode;
			loopPtr = loopPtr->next;
		}
		else
		{
			loopPtr->i = myNumber;
			loopPtr->next = nullptr;
		}
	}
}

int ListToInt(const intList & iList)
{
	intNode * loopPtr = iList;

	int exponent = 0;
	int sum = 0;

	while (loopPtr != nullptr)
	{
		sum += loopPtr->i * static_cast<int>(pow(10, exponent++));
		loopPtr = loopPtr->next;
	}

	return sum;
}

intList AddIntLists(const intList & iList1, const intList & iList2)
{
	int sum = ListToInt(iList1) + ListToInt(iList2);

	intList result = new intNode;

	IntToList(sum, result);

	return result;
}

int main()
{
	intList myList1 = new intNode;
	intList myList2 = new intNode;

	IntToList(126, myList1);
	IntToList(294, myList2);

	std::cout << "myList1: " << ListToInt(myList1) << std::endl;
	std::cout << "myList2: " << ListToInt(myList2) << std::endl;

	std::cout << "\nCreating myList3 as the sum of myList1 and myList2..." << std::endl;
	intList myList3 = AddIntLists(myList1, myList2);

	std::cout << "\nmyList3: " << ListToInt(myList3) << std::endl;

	std::cin.get();

	return 0;
}