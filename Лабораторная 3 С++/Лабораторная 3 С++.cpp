#include <iostream>


using namespace std;

bool isSame(const string& s)
{
    return count(s.begin(), s.end(), '[') == count(s.begin(), s.end(), ']');//Проверка
}

int main(int argc, char* argv[])
{
    //string s1("hell[o]wrld"), s2("[hell[[[]]]][o]wrld]");
    
    char s1 [100];//Инициализация массива
    char s2 [100];
    cout << "1. Input some '[' and ']':" << endl;
    cin >> s1;//Ввод массива
   
    cout << "2. Input some '[' and ']':"<< endl;
    cin >> s2;//Ввод ещё одного массива
    cout << boolalpha;//Перевод из 0,1 в True False
    cout << s1 << " => " << isSame(s1) << endl;
    cout << s2 << " => " << isSame(s2) << endl;
 
}
