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
	for (char a : input)
	{
		
		if(!(a >= 'a' && a <= 'z' || a >= '0' && a <= '9'))
		{	
			a = 'b';
		}
		
        char new1 = a + 2 % 256;
        char new2 = a * 3 % 256;
        char new3 = a - 1 % 256;
        char new4 = a + 4 % 256;
        
        
        std::string hash = {new1, new2, new3, new4};
        
        output += hash;
    }
	
	
	if (output.size() > 20)
	output = output.substr(0, 20);

	cout << "Rezultatas: ";
	cout << output;
}
