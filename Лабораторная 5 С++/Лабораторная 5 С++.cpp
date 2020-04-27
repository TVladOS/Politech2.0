#include <iostream>
#include <fstream>
#include <string>
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
struct scientist
{
    char name[55];
    char date[10];
	char sex[5];
	string nationality;
	char academic_degree[20];
	char position[20];
	char phone_number[20];
};
int main()
{
	int choice;
	cout << "Vvedite 1 chtoby vvesti svoi danniye" << endl;
	cout << "Vvedite 2 chtoby prosmotret' svoi danniye\n> ";
	cin >> choice;
	if (choice==1)
	{
		int const MAX = 1; //кол-во экземпляров структуры//
		scientist b[MAX];
		for (int i = 0; i < MAX; ++i)
		{

			cout << "\nEnter name :" << endl;
			cin >> b[i].name;
			cout << "Enter sex :" << endl;
			cin >> b[i].sex;
			cout << "Enter nationality :" << endl;
			cin >> b[i].nationality;

			cout << "Enter date :" << endl;
			cin >> b[i].date;

			cout << "Enter academic degree :" << endl;
			cin >> b[i].academic_degree;
			cout << "Enter position :" << endl;
			cin >> b[i].position;
			cout << "Enter phone number :" << endl;
			cin >> b[i].phone_number;
		}

		ofstream outfile;
		outfile.open("Out.txt");
		for (int i = 0; i < MAX; ++i)

			outfile << "Name: " << b[i].name << "\n" << "sex: " << b[i].sex << "\n"
			<< "nationality: " << b[i].nationality << "\n" << "date: " << b[i].date << "\n" << "academic degree: " <<
			b[i].academic_degree << "\n" << "position: " << b[i].position << "\n" << "phone number: " << b[i].phone_number << endl;
	}
	else
	{

	}
    

    system("pause");
    return 0;
}