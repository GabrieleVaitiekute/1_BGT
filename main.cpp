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
	cout << "Iveskite norima teksta: ";
	getline(cin, input);
	string hash;
	for (char a : input)
	{
		char new1, new2, new3, new4;
		if(!(a >= 'a' && a <= 'z'))
		{	
			a = 'b';
		}
		if(!(a >= '0' && a <= '9'))
		{	
			a = '2';
		}
		new1 = a + 2;
		new2 = a*3;
		new3 = a - 1;
		new4 = a + 4;
		hash = new1 + new2 + new3 + new4;
		output += hash;
	}
	
	if (output.size() > 20)
	output = output.substr(0, 20);

	cout << "Rezultatas: ";
	cout << output;
}
