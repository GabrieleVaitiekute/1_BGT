#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

std::string stringToHex(const std::string& output)
{
    std::ostringstream hexStream;

    for (unsigned char c : output) 
        hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    
	return hexStream.str();

}


int calculateASCIIsum(const std::string& str)
{
    int ascii_sum = 0;
    for (char ch : str) 
        ascii_sum += static_cast<int>(ch);
    
    return ascii_sum;
}


std::string recombinePieces(std::vector<std::string>& pieces)
{

    std::vector<std::pair<int, std::string>> piece_scores;
    
    for (const auto& piece : pieces)
	{
        int score = calculateASCIIsum(piece);
        piece_scores.push_back({score, piece});
    }
    

    std::sort(piece_scores.begin(), piece_scores.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return a.first < b.first;  // Sort based on the score
    });
    

    std::string recombinedString;
    for (const auto& piece : piece_scores) 
        recombinedString += piece.second;
    
    return recombinedString;
}

std::vector<int> calculateSplitPoints(const std::string& FinalOutput, int max_splits)  
{
    std::vector<int> split_points;
    int totalLength = FinalOutput.length();
    
    int ascii_sum = calculateASCIIsum(FinalOutput);

    for (int i = 1; i <= max_splits; i++) 
	{
        int split_point = (ascii_sum * i + static_cast<int>(FinalOutput[i % totalLength])) % totalLength;
        if (split_point > 0 && split_point < totalLength && std::find(split_points.begin(), split_points.end(), split_point) == split_points.end())
		{
            split_points.push_back(split_point);
        }
    }
    
    std::sort(split_points.begin(), split_points.end());//Taškai surikiuojami didėjimo tvarka nuosekliam skaidymui.
    
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

    int s = 0;
	
    while(input.length() < 63)
    {
        input.push_back(input[s % input.length()]);
        s++;
    }
    
    
    for (int i = input.length(); i > 0; i--)
    {
        
        char x = (input[(i - 4) % input.length()] + 3);
        char y = (((i % 2 == 0) ? input[(i + 1) % input.length()] : input[0]) * 7);
        char z = (((i % 2 != 0) ? static_cast<int>(input[(i + 1) % input.length()]) : static_cast<int>(input[0])) % 256);
        
        output.push_back(x);
        output.push_back(y);
        output.push_back(z);
    }

    std::string FinalOutput = stringToHex(output);//Pavercia i hex

    int max_splits = 8; 
    std::vector<std::string> pieces = splitString(FinalOutput, max_splits);//Padalina i kelis stringus

    FinalOutput = recombinePieces(pieces);//Sudeda atgal skirtingu eiliskumu

    if (FinalOutput.size() > 64)
    FinalOutput = FinalOutput.substr(0, 64);

    std::cout << "Rezultatas: " << FinalOutput;

}
