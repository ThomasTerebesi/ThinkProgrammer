#include <iostream>
#include <string>

class Automobile
{
public:
	Automobile();
	Automobile(int year, std::string maName, std::string moName);

	void SetModelYear(int year);
	int GetModelYear();

	void SetManufacturerName(std::string maName);
	std::string GetManufacturerName();

	void SetModelName(std::string moName);
	std::string GetModelName();

private:
	int _modelYear;
	std::string _manufacturerName;
	std::string _modelName;
};

int main()
{
	Automobile myCar(1956, "Chevrolet", "Impala");

	std::cout << myCar.GetModelYear() << " " << myCar.GetManufacturerName() << " " << myCar.GetModelName() << std::endl;

	std::cout << "\nWhoops, that's the wrong model year!" << std::endl;

	myCar.SetModelYear(1957);

	std::cout << "\n" << myCar.GetModelYear() << " " << myCar.GetManufacturerName() << " " << myCar.GetModelName() << std::endl;

	std::cin.get();

	return 0;
}

Automobile::Automobile()
	: _modelYear(0), _manufacturerName(""), _modelName("")
{
}

Automobile::Automobile(int year, std::string maName, std::string moName)
	: _modelYear(year), _manufacturerName(maName), _modelName(moName)
{
}

void Automobile::SetModelYear(int year)
{
	_modelYear = year;
}

int Automobile::GetModelYear()
{
	return _modelYear;
}

void Automobile::SetManufacturerName(std::string maName)
{
	_manufacturerName = maName;
}

std::string Automobile::GetManufacturerName()
{
	return _manufacturerName;
}

void Automobile::SetModelName(std::string moName)
{
	_modelName = moName;
}

std::string Automobile::GetModelName()
{
	return _modelName;
}
