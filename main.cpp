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


int calculate_ascii_sum(const std::string& str)
{
    int ascii_sum = 0;
    for (char ch : str) 
        ascii_sum += static_cast<int>(ch);
    
    return ascii_sum;
}


std::string recombine_pieces(std::vector<std::string>& pieces)
{

    std::vector<std::pair<int, std::string>> piece_scores;
    
    for (const auto& piece : pieces)
	{
        int score = calculate_ascii_sum(piece);
        piece_scores.push_back({score, piece});
    }
    

    std::sort(piece_scores.begin(), piece_scores.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return a.first < b.first;  // Sort based on the score
    });
    

    std::string recombined_string;
    for (const auto& piece : piece_scores) 
        recombined_string += piece.second;
    
    return recombined_string;
}

std::vector<int> calculate_split_points(const std::string& FinalOutput, int max_splits)
{
    std::vector<int> split_points;
    int total_length = FinalOutput.length();
    
    int ascii_sum = calculate_ascii_sum(FinalOutput);

    for (int i = 1; i <= max_splits; i++) 
	{
        int split_point = (ascii_sum * i + static_cast<int>(FinalOutput[i % total_length])) % total_length;
        if (split_point > 0 && split_point < total_length && std::find(split_points.begin(), split_points.end(), split_point) == split_points.end())
		{
            split_points.push_back(split_point);
        }
    }
    
    // Sort the split points to ensure proper splitting order
    std::sort(split_points.begin(), split_points.end());
    
    return split_points;
}

std::vector<std::string> split_string(const std::string& FinalOutput, int max_splits) 
{
    std::vector<int> split_points = calculate_split_points(FinalOutput, max_splits);
    std::vector<std::string> pieces;
    
    int start = 0;
    for (int split_point : split_points) {
        pieces.push_back(FinalOutput.substr(start, split_point - start));
        start = split_point;
    }
    pieces.push_back(FinalOutput.substr(start));  // Add the last piece
    
    return pieces;
}

using namespace std;
int main(int argc, char* argv[])
{  
 
    string input, output;
    if (argc > 1) 
    {
        // Failo pavadinimas buvo nurodytas per komandinę eilutę
        std::ifstream inputFailas(argv[1]);
        if (inputFailas) 
        {
            std::string line;
            while (std::getline(inputFailas, line)) {
                input += line;  // Nuskaito failo turinį
            }
            inputFailas.close();
        } 
        else 
        {
            std::cerr << "Nepavyko atidaryti failo: " << argv[1] << std::endl;
            return 1;  // Klaidos kodas
        }
    } 
    else 
    {
        std::cout << "Iveskite norima teksta: ";
        getline(cin, input);
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

    std::string FinalOutput = stringToHex(output);

    int max_splits = 8; 
    std::vector<std::string> pieces = split_string(FinalOutput, max_splits);

    FinalOutput = recombine_pieces(pieces);

    if (FinalOutput.size() > 64)
    FinalOutput = FinalOutput.substr(0, 64);

    cout << "Rezultatas: " << FinalOutput;
    
}
