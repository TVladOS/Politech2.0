#include <iostream>
#include <string>
#include <fstream> 
#include <windows.h>

using namespace std;



struct Lakes
{
    string name;
    string country;
    int deep;
    int sold;
};


int main()
{
    setlocale(0, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Task 19 easy "<< endl;
    /*Создать бинарный файл с информацией об озерах: 
     наименование озера; 
     страна расположения озера; 
     глубина озера; 
     соленость озера в процентах.*/ 
    
    int x;
    cout << "\nВведите количество озёр: ";
    while (!(cin >> x))
    {
        cout << "\nВведите количество озёр корректно: "<<endl;
        cin >> x;
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
    }

    Lakes* lakes = new Lakes[x];
   
    for (int i = 0; i < x; i++)
    {

        cout << "\nВведите название озера: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, lakes[i].name);

        cout << "Введите страну расположения озера: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, lakes[i].country);

        cout << "Введите глубину озера в метрах: ";
        while (!(cin >> lakes[i].deep))
        {
            cout << "Введите глубину озера в метрах корректно: ";
            cin >> lakes[i].deep;
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
        }

        do
        {
            cout << "Введите уровень солености озера в процентах: ";
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> lakes[i].sold;
        } while (lakes[i].sold > 100);

    }

    //Открываем файл для записи в бинарном режиме
    ofstream out("Easy19.dat", ios::binary | ios::out);
    out.write((char*)&lakes, sizeof lakes); //Записываем объект lakes в открытый нами файл
    out.close();//Закрываем открытый файл

    Lakes* lakes2 = new Lakes[x];

    // Открываем файл только для чтения, открываем в бинарном режиме
    fstream in("Easy19.dat", ios::binary | ios::in);
    in.read((char*)&lakes2, sizeof lakes2); //Считываем информацию в объект lakes2
    in.close(); //Закрываем открытый файл
    
    int writeOff = 0;
    for (int i = 0; i < x; i++)
    {
        if (lakes2[i].deep < 50 && lakes2[i].sold > 20)
        {
            cout << "\n---------------------------\n";
            cout << "Название озера: " << lakes[i].name << endl;
            cout << "Страна расположения озера: " << lakes[i].country << endl;
            cout << "Глубина озера: " << lakes[i].deep << "м" << endl;
            cout << "Солёность озера: " << lakes[i].sold << "%" << endl;
        }
    }


}
