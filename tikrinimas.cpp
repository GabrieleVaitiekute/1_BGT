#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
int main()
{
 std::ifstream failas("Rezultatai.txt");  
    if (!failas.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    int kart = 0;

    for (int i = 0; i < 100000; i++) {
        std::string hash1, hash2;
        if (!(failas >> hash1 >> hash2)) 
        { 
            break; 
        }
        if (hash1 == hash2) kart++;
    }
    
    std::cout << kart << std::endl;  

    failas.close();  
    return 0;
}

