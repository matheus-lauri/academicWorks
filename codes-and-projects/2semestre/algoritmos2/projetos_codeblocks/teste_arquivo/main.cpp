#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream arquivo;
    arquivo.open("exemplo.txt");
    arquivo << "Escrevendo nesse arquivo\n";
    arquivo.close();
    return 0;
}
