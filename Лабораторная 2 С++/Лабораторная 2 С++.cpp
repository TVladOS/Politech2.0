#include <iostream>
#include <Windows.h>

#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;

struct Date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	if ((day < 1) || (month < 1) || (year < 1))
		result = false;
	else {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}

		default:
			result = false;
		}
	}
	return result;
}

struct Person
{
	char FirstName[15],
		SecondName[15],
		LastName[15],
		Sex[7],
		Nationality[56],
		Address[255],
		School[255],
		Class[10],
		Number[56];

	int Age,
		Height,
		Weight;
		


	Date Birthday;
};

Person* InitArray(int Dimension);//возвращяет указатель на масив структур размерности Dimension
Person InitPerson();
void DisplayArray(Person* Massive, int Dimaension);
void DisplayChoise(Person*, int, char*, int, int);
void DisplayPerson(Person);
void SortFirstName(Person*, int);
int& CheckCorectDigitValue(int&);

void main(int argc, char* argv)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");

	int Dimension;
	char SexTag[7];
	int LowAge, UpperAge;
	bool begin = true;
tryagain:
	Person* MassiveStruct = nullptr;
	do
	{
		cout << "Enter school number:  ";
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "[!]Previous input failed, please re-enter !!!" << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\n[!]Dynamic array don't exist!\n";

			do {
				cout << "[!]Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы... ";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);

	cout << "\n------------FULL INFORMATION------------\n";
	DisplayArray(MassiveStruct, Dimension);

	cout << "\n[!]Enter the sex-tag: ";
	do {
		cin >> SexTag;
	} while (isdigit((char)SexTag[1]));
	cout << "\nEnter of boundary of age: ";
	do
	{
		cin >> LowAge >> UpperAge;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
			break;
	} while (true);

	cout << "\n[!]The list of choice-persons: ";
	DisplayChoise(MassiveStruct, Dimension, SexTag, LowAge, UpperAge);

	cout << "\n[!]The sorting list of persons: ";
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);

	delete MassiveStruct;
}
Person InitPerson()
{
	Person Pupil;

	cout << "\nEnter first name: ";
	garbage_collector();
	cin.getline(Pupil.FirstName, 255);

	cout << "Enter second name: ";
	garbage_collector();
	cin.getline(Pupil.SecondName, 255);

	cout << "Enter last name: ";
	garbage_collector();
	cin.getline(Pupil.LastName, 255);

	cout << "Enter the age: ";
	garbage_collector();
	cin >> Pupil.Age;

	cout << "Enter sex: ";
	garbage_collector();
	cin.getline(Pupil.Sex, 255);

	cout << "Enter nationality: ";
	garbage_collector();
	cin.getline(Pupil.Nationality, 255);

	cout << "Enter height: ";
	garbage_collector();
	cin >> Pupil.Height;

	cout << "Enter weight: ";
	garbage_collector();
	cin >> Pupil.Weight;

	do {
		cout << "Enter birthday: ";
		garbage_collector();
		cin >> Pupil.Birthday.day >> Pupil.Birthday.month >> Pupil.Birthday.year;
	} while (!Pupil.Birthday.isCorrect());

	cout << "Enter telephone number: ";
	garbage_collector();
	cin.getline(Pupil.Number, 56);

	cout << "Enter address: ";
	garbage_collector();
	cin.getline(Pupil.Address, 255);

	cout << "Enter number of school: ";
	garbage_collector();
	cin.getline(Pupil.School, 255);

	cout << "Enter class: ";
	garbage_collector();
	cin.getline(Pupil.Class, 10);
	

	return Pupil;
}

Person* InitArray(int Dimension)
{
	Person* Massive = new Person[Dimension];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\n[!]Enter the information about %d person ", i + 1);
		Massive[i] = InitPerson();
	}
	return Massive;
}

void DisplayArray(Person* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { DisplayPerson(Massive[i]); }
}

void DisplayChoise(Person* Massive, int Dimension, char* SexTag, int LowAge, int UpperAge)
{
	for (size_t i = 0; i < Dimension; i++)
	{
		if (
			strcmp(Massive[i].Sex, SexTag) == 0 &&
			Massive[i].Age <= UpperAge &&
			Massive[i].Age >= LowAge
			)
		{
			DisplayPerson(Massive[i]);
		}
	}
}

void DisplayPerson(Person Pupil)
{
	cout << "Full name: " << Pupil.FirstName << " " << Pupil.SecondName << " " << Pupil.LastName << endl;
	cout << "Age: " << Pupil.Age << endl;
	cout << "Gender: " << Pupil.Sex << endl;
	cout << "Height: " << Pupil.Height << endl;
	cout << "Weight: " << Pupil.Weight << endl;
	cout << "Birthday: " << Pupil.Birthday.day << "." << Pupil.Birthday.month << "." << Pupil.Birthday.year << endl;
	cout << "Telephone number: " << Pupil.Number << endl;
	cout << "Address: " << Pupil.Address << endl;
	cout << "School: " << Pupil.School << endl;
	cout << "Class: " << Pupil.Class <<"\n\n";

}
void SortFirstName(Person* Massive, int Dimension)
{
	Person Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (strcmp(Massive[q].FirstName, Massive[q - 1].FirstName) < 0)

				Temp = Massive[q];
			Massive[q] = Massive[q - 1];
			Massive[q - 1] = Temp;

		}
	}
}
int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "[!]Please re-enter!!!";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}