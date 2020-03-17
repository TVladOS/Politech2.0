#include <iostream>

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

struct Product
{
	char name[56];
	int quantity;
	float price;
	char manufactory[128];
	Date release;

};

void Task18_1()
{
	cout << "Task 18.1" << endl;
	//Определить среднюю стоимость товара и товар с минимальной стоимостью.

	const int N = 2;
	Product group[N];

	for (int i = 0; i < N; i++)
	{
		cout << endl;

		cout << "Input name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "Input quantity: ";
		while (!(cin >> group[i].quantity))
		{
			cout << "Input quantity: ";
			cin >> group[i].quantity;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Input price: ";
		while (!(cin >> group[i].price))
		{
			cout << "Input price: ";
			cin >> group[i].price;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Input Manufactory: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].manufactory, 128);

		do
		{
			cout << "Input release: ";
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].release.day >> group[i].release.month >> group[i].release.year;
		} while (!group[i].release.isCorrect());
	}

	float middlePrice = 0, min = 0;
	bool minones = true;

	for (int i = 0; i < N; i++)
	{
		middlePrice += (group[i].price);
		if (minones)
		{
			min = group[i].price + 1;
			minones = false;
		}
		float newmin = group[i].price;
		if (newmin < min)
			min = newmin;

	}

	middlePrice = middlePrice / N;

	cout << "\nAverage cost of goods: " << middlePrice << endl;

	cout << "\nMinimum cost product: " << endl;

	for (int i = 0; i < N; i++)
	{
		if (min == group[i].price)
		{
			cout << "-----------------------" << endl;
			cout << "Name: " << group[i].name;
			cout << "\nQuantity: " << group[i].quantity;
			cout << "\nPrice: " << group[i].price;
			cout << "\nManufactory: " << group[i].manufactory;
			cout << "\nRelease: " << group[i].release.day << "." << group[i].release.month << "." << group[i].release.year << endl;
		}
	}
	cout << endl;
}

struct ProductMiddle
{
	char name[56];
	float price;
	Date release;
	Date shelfLife;
	int quantity;
	char manufactory[128];
};

void Task18_2()
{
	cout << "Task 18.2" << endl;
	//Вывести сведения о товарах, срок годности которых меньше 20-ти дней. Определить количество просроченых товаров.

	const int N = 2;
	int sum = 0;
	ProductMiddle group[N];
	Date nowday;

	do
	{
		cout << "\nInput today's date: ";
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> nowday.day >> nowday.month >> nowday.year;

	} while (!nowday.isCorrect());

	cout << "\n";

	for (int i = 0; i < N; i++)
	{

		cout << endl;

		cout << "Input name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "Input price: ";
		while (!(cin >> group[i].price))
		{
			cout << "Input price: ";
			cin >> group[i].price;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		do
		{
			cout << "Input release: ";
			cin.clear();
			cin >> group[i].release.day >> group[i].release.month >> group[i].release.year;
			cin.ignore(std::cin.rdbuf()->in_avail());

		} while (!group[i].release.isCorrect());

		do
		{
			while (group[i].shelfLife.year < group[i].release.year)
			{
				cout << "Input shelf life: ";
				cin >> group[i].shelfLife.day >> group[i].shelfLife.month >> group[i].shelfLife.year;
				cin.clear();
				cin.ignore(std::cin.rdbuf()->in_avail());
			}

			if ((group[i].shelfLife.year == group[i].release.year) && (group[i].shelfLife.month < group[i].release.month))
			{
				while (group[i].shelfLife.month < group[i].release.month)
				{
					cout << "Input shelf life: ";
					cin >> group[i].shelfLife.day >> group[i].shelfLife.month >> group[i].shelfLife.year;
					cin.clear();
					cin.ignore(std::cin.rdbuf()->in_avail());
				}
			}

			if ((group[i].shelfLife.day <= group[i].release.day) && (group[i].shelfLife.month == group[i].release.month) && (group[i].shelfLife.year == group[i].release.year))
			{
				while (group[i].shelfLife.day <= group[i].release.day)
				{
					cout << "Input shelf life: ";
					cin >> group[i].shelfLife.day >> group[i].shelfLife.month >> group[i].shelfLife.year;
					cin.clear();
					cin.ignore(std::cin.rdbuf()->in_avail());
				}
			}

		} while (!group[i].shelfLife.isCorrect());

		cout << "Input quantity: ";
		while (!(cin >> group[i].quantity))
		{
			cout << "Input quantity: ";
			cin >> group[i].quantity;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Input Manufactory: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].manufactory, 128);
	}

	for (int i = 0; i < N; i++)
	{
		int maxdate = 0, out = group[i].release.day + 20, outdate = group[i].release.day, outmonth = group[i].release.month, outyear = group[i].release.year;
		switch (group[i].release.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			maxdate = 31;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			maxdate = 30;
			break;
		}

		case 2:
		{
			if (group[i].release.year % 4 != 0)
			{
				maxdate = 28;
			}
			else
				if (group[i].release.year % 400 == 0)
					maxdate = 29;
				else
					if ((group[i].release.year % 100 == 0) && (group[i].release.year % 400 != 0))
						maxdate = 28;
					else
						if ((group[i].release.year % 4 == 0) && (group[i].release.year % 100 != 0))
							maxdate = 29;
			break;
		}
		}
		if ((out % maxdate) < (out))
		{
			outdate = out % maxdate;
			outmonth++;
			if (outmonth > 12)
			{
				outmonth = 1;
				outyear++;
			}
		}
		else
			outdate = out;

		if (outyear >= group[i].shelfLife.year)
		{
			if (outmonth >= group[i].shelfLife.month)
			{
				if (outdate > group[i].shelfLife.day)
				{
					cout << "-----------------------" << endl;
					cout << "Name: " << group[i].name;
					cout << "\nPrice: " << group[i].price;
					cout << "\nRelease: " << group[i].release.day << "." << group[i].release.month << "." << group[i].release.year;
					cout << "\nShelf Life: " << group[i].shelfLife.day << "." << group[i].shelfLife.month << "." << group[i].shelfLife.year;
					cout << "\nQuantity: " << group[i].quantity;
					cout << "\nManufactory: " << group[i].manufactory << endl;
					cout << "-----------------------" << endl;
				}
			}
		}

		if (nowday.year >= group[i].shelfLife.year)
		{
			if (nowday.month >= group[i].shelfLife.month)
			{
				if (nowday.day > group[i].shelfLife.day)
				{
					sum++;
				}
			}

		}

	}
	cout << "\nThe number of expired goods: " << sum << endl;
}

int main()
{
	Task18_1();
	Task18_2();
	return 0;
}