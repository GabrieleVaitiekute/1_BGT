#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

std::string stringToHex(const std::string& output) {
    std::ostringstream hexStream;

    for (unsigned char c : output) 
	{
        // Kiekvieną simbolį paverčia į šešioliktainę reikšmę
        hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

	return hexStream.str();

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
		input.push_back(input[s * 2]);
		s++;
	}
	
	
	for (int i = input.length(); i > 0; i--)
	{
		
		char x = (input[(i - 4) % input.length()] + 3);
	
        char y = (((i % 2 == 0) ? input[i + 1] : input[0]) * 7);
		
        char z = (((i % 2 != 0) ? static_cast<int>(input[i + 1]) : static_cast<int>(input[0])) % 256);
		
		output.push_back(x);
        output.push_back(y);
        output.push_back(z);
    }

	for(int e = 0; e < 32; e += 2)
	{
		swap(output[e], output[63-e]);
	}
	std::string FinalOutput = stringToHex(output);

	if (FinalOutput.size() > 64)
	FinalOutput = FinalOutput.substr(0, 64);

	
	cout << "Rezultatas: ";
	cout << FinalOutput;

}
/*Laba      
x2inaek2gpnef2ug6ee2kdnea2m2oe22dahea2aepe82zj5ej27xpeo2bebed2gs
s22neee22peex22geej22deee222eea2d2hoamaapn8kze56ju7fpnogbkbadigx
s2idaee2gonex2uj6ej2k8nee2maoea2d2he22aaped2ze5eg27fpep2bkben2gx
4374c052d03c4034c3b60efc4694c90fe64641176475f4440117447027451112
4344c052d03c4034c3b60efc4694c90fe6664ff76675f4640ff746f02765bff2
461414724c4c801414464c4c2014146f4c4c931414704c4c3a14143a4c4cd314
laba      
xainaakagpnafaug6aeakdnaaam2oa2adahaaaaepa8azj5aja7xpaoabebadags
saanaaeaapaaxaagaajaadaaeaa2aaaad2hoamaapn8kze56ju7fpnogbkbadigx
saidaaeagonaxauj6ajak8naeamaoaaad2ha2aaapadaze5aga7fpapabkbanagx
4344c052d03c4034c3b60efc4694c90fe6664ff76675f4640ff746f02765bff2
46f4f4726c6c7ef4f4466c6c71f4f46f6c6c93f4f4706c6c8bf4f48b6c6cd3f4

*/