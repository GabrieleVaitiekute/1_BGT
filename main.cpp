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
	for (char a : input)
	{
		char newh;
		if(!(a >= 'a' && a <= 'z' || a >= '0' && a <= '9'))
		{	
			a = 'b';
		}
		
		newh = a + 2;
		output += newh;
	}
	cout << "Rezultatas: ";
	cout << output;
}
