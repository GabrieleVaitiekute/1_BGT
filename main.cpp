#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

// Padding funkcija, kad eilutė būtų pakankamo ilgio
std::string padToLength(const std::string& input, size_t length) {
    std::string padded = input;
    int s=0;
    while (padded.length() < length) {
        padded += std::to_string(input.length() + s*3); 
        s++; // Pridedame eilutės ilgį kaip užpildymą
    }
    return padded.substr(0, length);  // Iškerpame, jei per ilga
}


std::string stringToHex(const std::string& output)
{
    std::ostringstream hexStream;

    for (unsigned char c : output) 
        hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    
	return hexStream.str();

}
// Helper function to rotate bits to the right
unsigned char rotateRight(unsigned char value, int shift) 
{
    return (value >> shift) | (value << (8 - shift)); 
}
// Funkcija, kuri naudoja XOR ir rotavimą, kad geriau išsklaidytų bitus
std::string avalancheXOR(const std::string& input) 
{
    std::string result;

    for (size_t i = 0; i < input.length(); ++i) 
    {
    char xor_result = (input[i] ^ rotateRight(input[(i + 1) % input.length()], 3)) + (i % 7);
    xor_result ^= static_cast<char>(255 * (std::sin(i) + 1) / 2);  // Non-linear transformation using sine
    result.push_back(xor_result);
    }

    return result;
}
int calculateASCIIsum(const std::string& str)
{
    int ascii_sum = 0;
    for (char ch : str) 
        ascii_sum += static_cast<int>(ch);
    
    return ascii_sum;
}




std::vector<int> calculateSplitPoints(const std::string& FinalOutput, int max_splits)  
{
std::vector<int> split_points;
    int totalLength = FinalOutput.length();
    int ascii_sum = calculateASCIIsum(FinalOutput);
    int rolling_hash = 0;

    for (int i = 1; i <= max_splits; i++) {
        rolling_hash = (rolling_hash + static_cast<int>(FinalOutput[i % totalLength]) * i) % totalLength;
        int split_point = (ascii_sum * i + rolling_hash) % totalLength;
        if (split_point > 0 && split_point < totalLength && std::find(split_points.begin(), split_points.end(), split_point) == split_points.end()) {
            split_points.push_back(split_point);
        }
    }

    std::sort(split_points.begin(), split_points.end());
    return split_points;
}

std::vector<std::string> splitString(const std::string& FinalOutput, int max_splits) 
{
    std::vector<int> splitPoints = calculateSplitPoints(FinalOutput, max_splits);
    std::vector<std::string> pieces;
    
    int start = 0;
    for (int split_point : splitPoints) 
    {
        pieces.push_back(FinalOutput.substr(start, split_point - start));
        start = split_point;
    }
    pieces.push_back(FinalOutput.substr(start));  // Prideda paskutinę dalį
    
    return pieces;
}
std::string recombinePieces(std::vector<std::string>& pieces, const std::string& input)
{

    std::vector<std::pair<int, std::string>> piece_scores;
    int input_checksum = calculateASCIIsum(input); 

    for (const auto& piece : pieces) {
        int score = calculateASCIIsum(piece) ^ input_checksum;  
        piece_scores.push_back({score, piece});
    }

    std::sort(piece_scores.begin(), piece_scores.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return a.first < b.first;
    });

    std::string recombinedString;
    for (const auto& piece : piece_scores) 
        recombinedString += piece.second;

    return recombinedString;
}
int main(int argc, char* argv[])
{  
    std::string input, output;
    if (argc > 1) 
    {
        // Jei failo pavadinimas buvo nurodytas per komandinę eilutę
        std::ifstream inputFailas(argv[1]);
        if (inputFailas) 
        {
            std::string eilute;
            while (std::getline(inputFailas, eilute))
                 input += eilute;  // Nuskaito failo turinį
            
            inputFailas.close();
        } 
        else // Jei failas nenurodytas, prašoma įvesti ranka
        {
            std::cerr << "Nepavyko atidaryti failo: " << argv[1] << std::endl;
            return 1;  // Klaidos kodas
        }
    } 
    else 
    {
        std::cout << "Iveskite norima teksta: ";
        std::getline(std::cin, input);
    }

    // Užpildymas, kad tekstas būtų bent 64 simbolių
    output = padToLength(input, 64);

    output = avalancheXOR(output);

    std::string FinalOutput = stringToHex(output);//Pavercia i hex

    int max_splits = 10; 
    std::vector<std::string> pieces = splitString(FinalOutput, max_splits);//Padalina i kelis stringus

    FinalOutput = recombinePieces(pieces, FinalOutput);//Sudeda atgal skirtingu eiliskumu

if (FinalOutput.size() > 64) 
{
    FinalOutput = FinalOutput.substr(0, 64);  // Apkarpo iki 64
}

    std::cout << "Rezultatas: " << FinalOutput;

}
