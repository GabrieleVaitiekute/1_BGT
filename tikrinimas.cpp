#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <bitset>
#include <numeric>
#include <algorithm>

using namespace std;
int hexIdecimal(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    return -1;
}

int skaiciuotiBituSkirtuma(const string &hash1, const string &hash2)
{
    int skirtumas = 0;
    for (size_t i = 0; i < hash1.length(); i++)
    {
        char bit1 = hash1[i];
        char bit2 = hash2[i];
        skirtumas += bitset<4>(hexIdecimal(bit1) ^ hexIdecimal(bit2)).count();
    }
    return skirtumas;
}

int skaiciuotiHexSkirtuma(const string &hash1, const string &hash2)
{
    int skirtumas = 0;
    for (size_t i = 0; i < hash1.length(); i++)
    {
        if (hash1[i] != hash2[i])
        {
            skirtumas++;
        }
    }
    return skirtumas;
}

int main()
{
    std::ifstream failas("Rezultatai.txt");
    // 4 - 4 ir 5 testavimo etapai, 6 - 6 etapas
    int testavimas = 6;

    if (!failas.is_open())
    {
        std::cerr << "Failo negalima atidaryti." << std::endl;
        return 1;
    }

    if (testavimas == 4)
    {

        int kart = 0;

        for (int i = 0; i < 100000; i++)
        {
            std::string hash1, hash2;
            if (!(failas >> hash1 >> hash2))
            {
                break;
            }
            if (hash1 == hash2)
                kart++;
        }

        std::cout << kart << std::endl;
    }

    if (testavimas == 6)
    {

        std::string eilute, hash1, hash2;

        vector<int> bituSkirtumai;
        vector<int> hexSkirtumai;

        while (getline(failas, eilute))
        {
            istringstream iss(eilute);
            if (!(iss >> hash1 >> hash2))
            {
                break;
            } // klaida

            int bituSkirtumas = skaiciuotiBituSkirtuma(hash1, hash2);
            int hexSkirtumas = skaiciuotiHexSkirtuma(hash1, hash2);
            bituSkirtumai.push_back(bituSkirtumas);
            hexSkirtumai.push_back(hexSkirtumas);
        }

        if (bituSkirtumai.empty() || hexSkirtumai.empty())
        {
            cout << "Duomenų apdorojimui nėra." << endl;
            return 1;
        }

        double minBitSkirtProcentai = static_cast<double>(*min_element(bituSkirtumai.begin(), bituSkirtumai.end())) / 256 * 100;
        double maxBitSkirtProcentai = static_cast<double>(*max_element(bituSkirtumai.begin(), bituSkirtumai.end())) / 256 * 100;
        double avgBitSkirtProcentai = static_cast<double>(accumulate(bituSkirtumai.begin(), bituSkirtumai.end(), 0.0) / bituSkirtumai.size()) / 256 * 100;

        double minHexSkirtProcentai = static_cast<double>(*min_element(hexSkirtumai.begin(), hexSkirtumai.end())) / 64 * 100;
        double maxHexSkirtProcentai = static_cast<double>(*max_element(hexSkirtumai.begin(), hexSkirtumai.end())) / 64 * 100;
        double avgHexSkirtProcentai = static_cast<double>(accumulate(hexSkirtumai.begin(), hexSkirtumai.end(), 0.0) / hexSkirtumai.size()) / 64 * 100;

        cout << fixed << setprecision(2);
        cout << "Bitu lygmenyje - Maziausias: " << minBitSkirtProcentai << "%, Didziausias: " << maxBitSkirtProcentai << "%, Vidurkis: " << avgBitSkirtProcentai << "%" << endl;
        cout << "Hex'u lygmenyje - Maziausias: " << minHexSkirtProcentai << "%, Didziausias: " << maxHexSkirtProcentai << "%, Vidurkis: " << avgHexSkirtProcentai << "%" << endl;
    }
    failas.close();
    return 0;
}
