# BGT pirmoji užduotis

## Pseudo kodas

1. **Duomenų įvedimas\nuskaitymas** Svarbu komandinėje eilutėje įvesti nuskaitymo pasirinkimo skaičių, bei jei reikia ir failo, nuo kurio norite nuskaityti pavadinimą
  -  Komandinėje eilutėje turi būti pateiktas skaičius nurodantis, kokį nuskaitymo būdą norima naudoti (1 - jei nuskaityti viską arba įvesti ranka; 3 - tam tikrą kiekį eilučių(eViso), kiekį galima pakeisti main.cpp faile; 4 - jei norima nuskaityti poras nuo failo ) Skaičiai atitinka testavimo etapus, bet 4 taip pat tinka ir 6 etapui.
  -  Jei perduodamas failo pavadinimas kaip argumentas, nuskaitoma viso failo turinys.
  -  Jei nurodytas tik skaičius(1), programa paprašo vartotojo įvesti tekstą per komandinę eilutę.

2. **hashInput** Įvesties apdorojimas, priklausant nuo nuskaitymo būdo pasirinkimo 
  - Jei buvo įvestas skaičius 1 arba 3, nusiunčiamas jis vienas apdoroti ir šios funkcijos trukmė yra matuojama
  - Jei buvo įvestas 4, cikliškai siunčiomi pirmas ir antras poros nariai, trukmė neskaičiuojama
    
3.  **padToLength** Įvesties prailginimas
  - Jei įvestis(pavadinta input) per trumpa, ji prailginama pridedant reikšmes, pagrįstas pradiniu teksto ilgiu ir iteracijos skaičiaus su 3 daugyba.

4. **calculateSplitPoints(const std::string &output)** Teksto dalinimo taškų radimas
  - **int ascii_sum = calculateASCIIsum(output)** Apskaičiuojama visų eilutės simbolių ASCII vertė
  - **for (int i = 1; i <= max_splits; i++)** Skaičiuojamas potencialus skaidymo taškas, naudojant ASCII sumą, simbolių pozicijas ir modulį.
  - **if(...)**  Užtikrina, kad vienas ir tas pats skaidymo taškas nebūtų pridėtas kelis kartus.
  - **std::sort(...)**  Taškai išdėstomi didėjimo tvarka, kas būtina tolesniam teksto skaidymui.
    
5. **splitString(const std::string &output)** Teksto dalinimas
  - iš 5 punkto funkcijos gaunami dalijimo taškai
  - **for (int split_point : splitPoints)** tekstas dalijamas į skirtingo ilgio dalis
    
6. **recombinePieces(std::vector<std::string> &pieces, const std::string &output)** Teskto sudėjimas atgal
  - Išskaidytos dalys sujungiamos atgal į vieną tekstą. Dalys rikiuojamos pagal jų ASCII sumą mažėjimo tvarka (dar kartą panaudojam)
  - **for (const auto& piece : pieces)** Apskaičiuojama gautų dalių simbolių ASCII vertė su calculateASCIIsum(FinalOutput) funkcija
  - **std::sort** Dalys išrikiuojamos pagal ASCII vertes mažėjimo tvarka
  - **for (const auto& piece : piece_scores)** dalys sudedamos atgal į viena string
    
7. **avalancheXOR(const std::string &input)**
  - **dynamic_shift = (calculateASCIIsum(input) % 7) + 1** Apskaičiuojamas dinamiškas bitų poslinkis, remiantis visos įvesties ASCII sumos liekana dalijant iš 7, prie kurios pridedamas 1
  - **for (int r = 0; r < rounds; r++)** Ciklas vyksta 3 kartus
  - **for (size_t i = 0; i < result.length(); i++)** Kiekvieno simbolio result eilutėje vykdomos operacijos
  - **char xor_result = (result[i] ^ rotateRight(result[(i + 1) % result.length()], (dynamic_shift + r))) + (i % 7)** Skaičiuojama nauja simbolio vertė naudojant XOR tarp dabartinio simbolio ir kito, kuris paslinktas per nustatytą bitų skaičių, pridedant liekaną iš i dalijant iš 7
  - **xor_result = (xor_result + (i * prime)) % 256**  Prie XOR rezultato pridedamas i ir prime sandauga, o gautas rezultatas dalijamas iš 256 modulo,  kad rezultatas išliktų ribose
  - **xor_result ^= rotateRight(result[(i + 2) % result.length()], (5 + r + dynamic_shift))** Dar kartą vykdomas XOR tarp xor_result ir dar vieno paslinkto simbolio
  - **result[i] = xor_result** Atnaujinamas result eilutės i simbolis su naujai gauta xor_result reikšme
    
8. **rotateRight(unsigned char value, int shift)**
  - grąžina naują simbolio bitų išdėstymą, kur bitai, esantys už shift pozicijų, yra perstumiami į dešinę (value >> shift), o likę bitai (8 minus shift) yra perkeliami į kairę (value << (8 - shift)), taip sukant bitus į dešinę.
    
9. **stringToHex(output)** Konvertavimas
  - Konvertuoja sutrumpintą iki reikiamo ilgio eilutę į jos atitinkamą šešioliktainę reikšmę
    
10. **Išvesties spausdinimas**
  - Jei buvo nurodytas nuskaitymo būdas 1 arba 3, tai rezultatas bus išvestas į terminalą
  - Jei buvo nurodytas 4, tai rezultatus rasite faile Rezultatai.txt
    

## Testavimas

  ### 1 ir 2 etapai
  Šiam etapui buvo sukurti:
  - 3 failai (avienas.txt, bvienas.txt, cvienas.txt), turinys po vieną simbolį a, b, c atitinkamai. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas, nepaisant to, kad jame buvo tik 1 simbolis. Taip įvyko su visais 3 failais.
  - 3 failai (Daug1.txt, Daug2.txt, Daug3.txt), turinys skirtingą kiekį simbolių, bet visi virš 1000. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas. Taip įvyko su visais 3 failais.
  - 3 failai (SkiriasiVienu1.txt, SkiriasiVienu2.txt, SkiriasiVienu3.txt), kurie skirasi vienu viduriniu simboliu. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas. Taip įvyko su visais 3 failais. Taip pat svarbu paminėti, kad visų trijų failų         rezultatai skiriasi: ca0620fce5f0e00dd730772da53502a64b69cd385bcd1d0ed42f34d5f6ba3b22, 8b57d351ce7605823d3f69cc23df289f7da6f574675fa8faa7bb9b5e80ccfcf5, eb2bb6ec1d3b4a0540edf45236787c64cafbcda5b9a13c835a04efd6b91bbcfd.
  - Vienas tuščias failas, kurį paleidus, buvo išmestas pranešimas, kad failas yra tuščias.
  
  ### 3 etapas

  Lentelė su visais laikais ir vidurkiais
 ![Screenshot 2024-10-02 163358](https://github.com/user-attachments/assets/b6177657-7a67-49ce-83e4-a83efdfcce45)

  Vidurkių diagrama 
![image](https://github.com/user-attachments/assets/4230fab7-e64d-4a01-b85e-c6be0754c17a)

Lygindami v0.1 ir v0.2 laikus pasebėsite, kad v0.2 laikai yra geresni.

  ### 4 ir 5 etapai
  Buvo sugenera 25 000 porų, kurių ilgis 10 simbolių, kitas 25 000 porų, kurių ilgis - 100, dar kitas 25000 poras - 500, ir galiausiai likusias 25 000 poras, kurių ilgis - 1000 simbolių. Failas su poromis nuskaitytas su main.cpp programa, kuri išvedė gautus rezultatus į kitą failą (Rezultatai.txt), tuomet failas tikrinimas.cpp nuskaitė duomenys nuo rezultatų failo ir kievienos poroas hash'ai buvo palyginti. Nebuvo rasta nei vienos vienodos poros, vadinasi funkcija atitinka 6 reikalavimą, t.y., atsparumą kolizijai. 
  
  ### 6 etapas
Įvedus poras (pvz.: Lietuva ir lietuva) gaunami šiektiek sutampantys rezultatai, tai reiškia, kad lavinos efektas nėra pilnai tenkinamas. (771466968144c6c14614f3a4c641475792c6c14614f3a4c6c14754f2c4c64146 ir 77df6f3a6c6cf4756f2c6c64f46577f46968f46c6cf4616f3a6c679f47478c36). 
  
  ### 7 etapas
Viską apibendrinant, iš atliktų tyrimu galima teigti, kad kodo greitis ir atsparumas kolizijai yra stiprybės. Na o silpnybė - netenkinamas lavinos efektas, todėl kitą versiją reikės tobulinti.
