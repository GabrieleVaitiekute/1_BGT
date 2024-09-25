
#include <iostream>
#include <sstream>
#include <fstream>
#include <random> 
std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution<int> charKiekis(1001, 2000);
std::uniform_int_distribution<char> dis(33, 126); // ASCII 


int main()
{
    std::ofstream GenFailas("SkirtingosPoros.txt");

    if (!GenFailas.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

        /*1 ŽINGSNIS
        int charKiekisGen = charKiekis(generuoti);

        for(int i = 0; i < charKiekisGen; i++)
        {
            GenFailas << dis(generuoti);
        }
        */

        
       /*4 ŽINGSNIS 
    
        for(int e = 0; e < 4; e++)//pridetas, kai prireike generuoti poras
        {
            int ilgis = 10;
            if(e == 1)ilgis = 100;
            if(e == 2)ilgis = 500;
            if(e == 3)ilgis = 1000;
            for(int a=0; a<25000; a++)
            {  
                std::string RanStringA, RanStringB;
                for(int i = 0; i < ilgis; i++)// 10, 100, 500, 1000
                {
                    char RanCharA = dis(generuoti);
                    RanStringA += RanCharA;

                    char RanCharB = dis(generuoti);
                    RanStringB += RanCharB;

                }

                GenFailas << RanStringA << " " << RanStringB <<std::endl;
            }
        }*/


        /*6 ŽINGSNIS*/


            for(int a=0; a<100000; a++)
            {
                std::string RanStringA, RanStringB;
                for(int i = 0; i < 500; i++)
                {
                    char RanChar = dis(generuoti);
                    RanStringA += RanChar;
                }
                GenFailas << RanStringA;//isspausdina pirma(A) stringa

                RanStringB = RanStringA;//pirma prilygina antram

                char Bpirmas = RanStringA[0] + 2;// Pirmas A stringo simbolis pajudinamas per du, veliau bus priskirtas B strino pirmam simboliui

                if (Bpirmas > 126) Bpirmas = 33 + (Bpirmas - 127);//isitikinama kad judinant per du neiseinama uz acii ribu
                
                RanStringB[0] = Bpirmas;// Pajudintas pirmas A stringo simbolis priskirtas B pradziai
                
                GenFailas<< " " <<RanStringB;//Isspausdintas B

                GenFailas<< std::endl;
            } 

    GenFailas.close();

    return 0;
}