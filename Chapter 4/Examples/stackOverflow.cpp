// "Stack Overflow", page 89

int count = 0;
void StackOverflow()
{
	count++;
	StackOverflow();
}

int main()
{
	StackOverflow();

	return 0;
}