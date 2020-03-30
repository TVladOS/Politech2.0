#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> strtok(const string, const string);

int main()
{
    string s(",hello my name is,!V! I! P!  ");
    string d(" ,.!");
    vector<string> v;
    
    v = strtok(s,d);
    
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));

    return 0;
}

vector<string> strtok(const string s, const string DELIM)
{
    vector<string> v;
    string tmp;
    size_t l, r;

    for (l = s.find_first_not_of(DELIM), r = s.find_first_of(DELIM, l);
        l != string::npos; l = s.find_first_not_of(DELIM, r), r = s.find_first_of(DELIM, l))
        v.push_back(s.substr(l, r - l));
   
    return v;
}