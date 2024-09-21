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
	
	
	for (int i = input.length(); i > 0; i--)
	{
		
		char x = wrapCharacter(input[(i - 4) % input.length()] + 3);
	
        char y = wrapCharacter(((i % 2 == 0) ? input[i + 1] : input[0]) * 7);
		
        char z = wrapCharacter(((i % 2 != 0) ? static_cast<int>(input[i + 1]) : static_cast<int>(input[0])) % 256);
		
		output.push_back(x);
        output.push_back(y);
        output.push_back(z);
    }
	
	

	if (output.size() > 64)
	output = output.substr(0, 64);

	for(int e = 0; e < 32; e += 2)
	{
		swap(output[e], output[63-e]);
	}
	cout << "Rezultatas: ";
	cout << output;

}
/*Laba      
x2inaek2gpnef2ug6ee2kdnea2m2oe22dahea2aepe82zj5ej27xpeo2bebed2gs
s22neee22peex22geej22deee222eea2d2hoamaapn8kze56ju7fpnogbkbadigx
s2idaee2gonex2uj6ej2k8nee2maoea2d2he22aaped2ze5eg27fpep2bkben2gx
sg2debeb2oepx72je5jz28epea2aehad22eo2m2aendk2ee6gu2fenpg2keani2x
laba      
xainaakagpnafaug6aeakdnaaam2oa2adahaaaaepa8azj5aja7xpaoabebadags
saanaaeaapaaxaagaajaadaaeaa2aaaad2hoamaapn8kze56ju7fpnogbkbadigx
saidaaeagonaxauj6ajak8naeamaoaaad2ha2aaapadaze5aga7fpapabkbanagx
sgadabebaoapx7aja5jza8apeaaaahada2ao2maaandkaea6guafanpgakaaniax
*/