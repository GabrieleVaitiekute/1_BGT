
#include <iostream>
#include <sstream>
#include <fstream>
#include <random> 
std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution<int> charKiekis(1001, 2000);
std::uniform_int_distribution<char> dis(33, 126); // ASCII 


int main()
{
    std::ofstream GenFailas("VienuSkiriasi1.txt");
    if (!GenFailas.is_open())
        {
            std::cerr << "Failed to open file." << std::endl;
            return 1;
        }

    int charKiekisGen = charKiekis(generuoti);

    for(int i = 0; i < charKiekisGen; i++)
        {
            GenFailas << dis(generuoti);
        }

    GenFailas.close();

    return 0;
}