#include <fstream>
#include <iterator>
using namespace std;

int main() 
//19 вариант. Записать в файл g все чётные числа файла f, а в файл h все нечётные
{
    ifstream ifs("f.txt");
    ofstream ofs1("g.txt");
    ofstream ofs2("h.txt");

    for (istream_iterator<int> it = istream_iterator<int>(ifs); it != istream_iterator<int>(); ++it)
        if (*it % 2) ofs2 << *it << ' ';
        else ofs1 << *it << ' ';

    return 0;
}