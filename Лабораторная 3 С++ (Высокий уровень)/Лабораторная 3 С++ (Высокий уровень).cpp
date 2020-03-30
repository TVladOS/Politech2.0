#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << str << endl;
    system("pause");
    return 0;
    setlocale(0, " ");
}