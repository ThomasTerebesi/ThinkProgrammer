#include <iostream>

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

int compareFunc(const void* voidA, const void* voidB)
{
	int * intA = (int *)(voidA);
	int * intB = (int *)(voidB);
	return *intA - *intB;
}

int main()
{
	int sales[NUM_AGENTS][NUM_MONTHS] = {
		{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
		{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
		{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
	};

	for (int i = 0; i < NUM_AGENTS; i++)
		qsort(sales[i], NUM_MONTHS, sizeof(int), compareFunc);

	for (int i = 0; i < NUM_AGENTS; i++)
	{
		std::cout << "Agent " << (i + 1) << ": ";
		
		for (int j = 0; j < NUM_MONTHS; j++)
			std::cout << sales[i][j] << "\t";

		std::cout << std::endl;
	}

	int highestSales = 0;
	int highestAgent = -1;

	for (int i = 0; i < NUM_AGENTS; i++)
		if ((sales[i][5] + sales[i][6])/2 > highestSales)
		{
			highestSales = (sales[i][5] + sales[i][6]) / 2;
			highestAgent = i;
		}

	std::cout << "\nAgent " << (highestAgent + 1) << " has the highest median sales with " << highestSales << " units." << std::endl;

	std::cin.get();

	return 0;
}