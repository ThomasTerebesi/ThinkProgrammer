#include <iostream>

const int NUM_AGENTS = 4;
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
		{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, 9117, 4959, 1122, 7766, 2534},
		{-1, -1, 67, 67, 265, 376, 232, 223, 4546, 564, 4544, -1},
		{-1, -1, -1, -1, 7829, 4902, 8921, 2301, 4307, -1, -1, -1}
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
	int currentAgentSales[NUM_MONTHS];
	int counter;

	for (int i = 0; i < NUM_AGENTS; i++)
	{
		counter = 0;
		for (int k = 0; k < NUM_MONTHS; k++)
			currentAgentSales[k] = 0;

		for (int j = 0; j < NUM_MONTHS; j++)
			if (sales[i][j] != -1)
				currentAgentSales[counter++] = sales[i][j];

		//if (counter == 0 && currentAgentSales[0] > highestSales)
		//{
		//	highestSales = currentAgentSales[0];
		//	highestAgent = i;
		//}
		//else 
		if (counter % 2 == 0)
		{
			if ((currentAgentSales[(counter / 2) - 1] + currentAgentSales[counter / 2]) / 2 > highestSales)
			{
				highestSales = (currentAgentSales[(counter / 2) - 1] + currentAgentSales[counter / 2]) / 2;
				highestAgent = i;
			}
		}
		else
			if (currentAgentSales[counter / 2] > highestSales)
			{
				highestSales = currentAgentSales[counter / 2];
				highestAgent = i;
			}
	}

	std::cout << "\nAgent " << (highestAgent + 1) << " has the highest median sales with " << highestSales << " units." << std::endl;

	std::cin.get();

	return 0;
}