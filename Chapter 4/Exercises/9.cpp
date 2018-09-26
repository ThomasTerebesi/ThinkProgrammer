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

int main()
{
	intNode * myList = new intNode;

	IntToList(8613, myList);

	std::cout << "myList: " << ListToInt(myList) << std::endl;

	std::cin.get();

	return 0;
}