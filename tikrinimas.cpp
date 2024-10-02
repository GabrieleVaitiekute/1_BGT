#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <numeric>

using namespace std;

int hexCharToDecimal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + c - 'a';
    return -1;
}

int countBitDifference(const std::string& hash1, const std::string& hash2) {
    int difference = 0;
    for (size_t i = 0; i < hash1.length(); i++) {
        char byte1 = hash1[i];
        char byte2 = hash2[i];
        difference += std::bitset<4>(hexCharToDecimal(byte1) ^ hexCharToDecimal(byte2)).count();
    }
    return difference;
}

int countHexDifference(const std::string& hash1, const std::string& hash2) {
    int difference = 0;
    for (size_t i = 0; i < hash1.length(); i++) {
        if (hash1[i] != hash2[i]) {
            difference++;
        }
    }
    return difference;
}

int main()
{
    int testavimas = 6; 
    if(testavimas == 4)
    {    std::ifstream failas("Rezultatai.txt");  

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
    }

    if(testavimas == 6)
    {
        std::ifstream failas("Rezultatai.txt");
        std::string line, hash1, hash2;

    std::vector<int> bitDifferences;
    std::vector<int> hexDifferences;

    while (std::getline(failas, line))
    {
        std::istringstream iss(line);
        if (!(iss >> hash1 >> hash2)) { break; } // error

        int bitDifference = countBitDifference(hash1, hash2);
        int hexDifference = countHexDifference(hash1, hash2);
        bitDifferences.push_back(bitDifference);
        hexDifferences.push_back(hexDifference);
    }

    if (bitDifferences.empty() || hexDifferences.empty()) {
        std::cout << "No data to process." << std::endl;
        return 1;
    }

    int minBitDiff = *min_element(bitDifferences.begin(), bitDifferences.end());
    int maxBitDiff = *max_element(bitDifferences.begin(), bitDifferences.end());
    double avgBitDiff = std::accumulate(bitDifferences.begin(), bitDifferences.end(), 0.0) / bitDifferences.size();

    int minHexDiff = *min_element(hexDifferences.begin(), hexDifferences.end());
    int maxHexDiff = *max_element(hexDifferences.begin(), hexDifferences.end());
    double avgHexDiff = std::accumulate(hexDifferences.begin(), hexDifferences.end(), 0.0) / hexDifferences.size();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Bit Level Differences - Min: " << minBitDiff << ", Max: " << maxBitDiff << ", Avg: " << avgBitDiff << std::endl;
    std::cout << "Hex Level Differences - Min: " << minHexDiff << ", Max: " << maxHexDiff << ", Avg: " << avgHexDiff << std::endl;

    
    }
    return 0;
}

