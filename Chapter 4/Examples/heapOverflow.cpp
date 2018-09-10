// "Heap Overflow", page 89

// USE AT YOUR OWN RISK

/*
	int main()
	{
		const int intsPerKilobyte = 1024 / sizeof(int);

		while (true)
			int * oneKiloByteArray = new int[intsPerKilobyte];

		return 0;
	}
*/
