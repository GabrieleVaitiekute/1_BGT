#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

char wrapCharacter(int value)
{
    int numLetters = 26; // nuo a iki z
    int numDigits = 10;  //  nuo 0 to 9
    int totalCharacters = numLetters + numDigits; // is viso 
    value = value % totalCharacters; 

    if (value < numLetters)
        return 'a' + value; 
    
	else 
        return '0' + (value - numLetters); 
    
}
using namespace std;
int main()
{
	string input, output;
	std::cout << "Iveskite norima teksta: ";
	getline(cin, input);
	int s = 0;
	while(input.length() < 63)
	{
		input.push_back(input[s * s]);
		s++;
	}
	

	int length = input.length();
	
	for (int i = length; i > 0; i--)
	{
		
		char x = wrapCharacter(input[(i - 4) % length] + 3);
	
        char y = wrapCharacter(((i % 2 == 0) ? input[i + 1] : input[0]) * 7);
		
        char z = wrapCharacter(((i % 2 != 0) ? static_cast<int>(input[i + 1]) : static_cast<int>(input[0])) % 256);
		
		output.push_back(x);
        output.push_back(y);
        output.push_back(z);
    }
	
	if (output.size() > 64)
	output = output.substr(0, 64);

	cout << "Rezultatas: ";
	cout << output;
}
