#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

char* Revers(char* str, int m)
{
    for (int i = 0; i < m / 2; i++)
        swap(str[i], str[m - 1 - i]);
    return str;
}

int main()
{
    /*В заданном массиве символов слова зашифрованы — каждое из них записано наоборот. Расшифровать сообщение .*/
    int m;
    cout << "Input your string:\n";
    const int N = 256;
    const char* SEPARATORS = "!?.,;/*-+\n\t ";
    char S[N];
    char temp_S[N];
    
    cin.getline(S, 256);
    strncpy(temp_S, S, strlen(S) + 1);
    
    //cout << S << endl;
   
    char* ptr = 0;
    ptr = strtok(S, SEPARATORS);
    while (ptr)
    {

        for (m = 0; ptr[m] != '\0'; m++);
        Revers(ptr, m);
        cout << "\n========================================================================================================================\n" << endl;
        cout << ptr << " ";
        ptr = strtok(0, SEPARATORS);
    }
    strncpy(S, temp_S, strlen(temp_S) + 1);

    
    //cout << S << '\n';
    cin.get();

    system("pause");
    return 0;
}