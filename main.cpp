#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

using namespace std;
int main()
{
	string input, output;
	std::cout << "Iveskite norima teksta: ";
	getline(cin, input);
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		char a = input[i];
		if(!(a >= 'a' && a <= 'z' || a >= '0' && a <= '9'))
		{	
			a = 'b';
		}
        char x = (a + 3); 
        char y = (i + 1 < length) ? input[i + 1] : input[0];  
		char z = (i + 1 < length) ? static_cast<int>(input[i + 1]) % 256 : static_cast<int>(input[0]) % 256;

		std::string hash;
		hash.push_back(x);
		hash += std::to_string(static_cast<unsigned char>(y));
		hash.push_back(static_cast<char>(z));  
 		output += hash;
    }
	
	if (output.size() > 20)
	output = output.substr(0, 20);

	cout << "Rezultatas: ";
	cout << output;
}
