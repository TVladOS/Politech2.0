#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

void taskMedium18()
{
    cout << "\nTask 18 (medium)\n" << endl;
    /*Ввести в Memo или в StringGrid некоторое количесто как положительных так и отрицательных
    целых чисел и записать в бинарный файл. Переписать бинарный фацй так чтобы каждое отвецательное
    значение было увеличено на 3, а положительное - уменьшено на 3. Распечатать числа до и после изменения.*/

    const int N = 2, M = 3;
    int arr[N][M], arr2[N][M];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cout << "Введите [" << i + 1 << "][" << j + 1 << "]: ";
            while (!(cin >> arr[i][j]))
            {
                cout << "Введите [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> arr[i][j];
                cin.clear();
                cin.ignore(std::cin.rdbuf()->in_avail());
            }
        }

    //Открываем файл для записи в бинарном режиме
    ofstream out("taskMedium18.dat", ios::binary | ios::out);
        out.write((char*)&arr, sizeof arr); //Записываем объект goods в открытый нами файл
    out.close();//Закрываем открытый файл

    // Открываем файл только для чтения, открываем в бинарном режиме
    fstream in("taskMedium18.dat", ios::binary | ios::in);
        in.read((char*)&arr2, sizeof arr2); //Считываем информацию в объект goods2
    in.close(); //Закрываем открытый файл

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] > 0)
                arr2[i][j] -= 3;
            if (arr[i][j] < 0)
                arr2[i][j] += 3;
        }
        
    ofstream out2("taskMedium18.dat", ios::binary | ios::out);
        out2.write((char*)&arr2, sizeof arr);
    out2.close();

    cout << "До изменений:" << endl;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "\nПосле измеенений:" << endl;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << arr2[i][j] << " ";
        cout << endl;
    }     
}

int main()
{
    setlocale(0, "ru");
    taskMedium18();    
}
