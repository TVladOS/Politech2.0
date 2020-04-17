#include <iostream>

using namespace std;


int main()
{
    char S[1000];
    cout << "Input your char: ";
    cin.getline(S, 1000);
    bool found = false;
    int i = 0;
    while (!found && i < strlen(S))
        if (S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z')
            
            found = true;
        else
            i++;
    if (found)
        cout << "Your string has latin letters";
    else
        cout << "There are no latin letters in your string";
}

