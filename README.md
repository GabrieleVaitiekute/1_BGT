# BGT pirmoji užduotis

## Pseudo kodas

1. **Duomenų įvedimas\nuskaitymas**
  - **if (inputFailas)** Jei perduodamas failo pavadinimas kaip argumentas, nuskaitoma viso failo turinys.
  - **else**Jei argumentų nėra, programa paprašo vartotojo įvesti tekstą per komandinę eilutę.
    
2.  **while(input.length() < 63)** Įvesties prailginimas
  - Jei įvestis(pavadinta input) per trumpa, ji prailginama kartojant input simbolius.
    
3. **for (int i = input.length(); i > 0; i--)** Simbolių transformacija
  - Kiekvienam simboliui skaičiuojami trys nauji simboliai(x, y, z), remiantis originalaus simbolio pozicija ir vertėmis.
  - **x = (input[(i - 4) % input.length()] + 3)**
    Gįžtame atgal 4 pozicijas nuo dabartinio i indekso ir prieitą simbolio vertę padidiname 3, naudojant modulio operaciją, kad išvengtume perėjimo už eilutės ribų.
  - **y = (((i % 2 == 0) ? input[(i + 1) % input.length()] : input[0]) * 7)**
    Pirmiausia tikrinama, ar i yra lyginis (i % 2 == 0). Jei taip, pasirenkamas simbolis, esantis viena pozicija toliau nuo i, jei ne - paimamas pirmasis įvesties simbolis (input[0]).
    Gautas simbolis dauginamas iš 7.
  - **z = (((i % 2 != 0) ? static_cast<int>(input[(i + 1) % input.length()]) : static_cast<int>(input[0])) % 256)**
    Tikrinama, ar i yra nelyginis. Jei taip, pasirenkamas simbolis, esantis viena pozicija toliau nuo i, jei ne - paimamas pirmasis įvesties simbolis.
    Gautas simbolio ASCII vertė moduliavojama su 256, kad užtikrintume, jog rezultatas tilptų į vieno baito dydį.
    
4. **stringToHex(output)** Konvertavimas
  - Konvertuoja eilutę į jos atitinkamą šešioliktainę reikšmę
    
5. **calculateSplitPoints(FinalOutput, max_splits)** Teksto dalinimo taškų radimas
  - **int ascii_sum = calculateASCIIsum(FinalOutput)** Apskaičiuojama visų eilutės simbolių ASCII vertė
  - **for (int i = 1; i <= max_splits; i++)** Skaičiuojamas potencialus skaidymo taškas, naudojant ASCII sumą, simbolių pozicijas ir modulį.
  - **if(...)**  Užtikrina, kad vienas ir tas pats skaidymo taškas nebūtų pridėtas kelis kartus.
  - **std::sort(...)**  Taškai išdėstomi didėjimo tvarka, kas būtina tolesniam teksto skaidymui.
    
6. **splitString(FinalOutput, max_splits)** Teksto dalinimas
  - iš 5 punkto funkcijos gaunami dalijimo taškai
  - **for (int split_point : splitPoints)** tekstas dalijamas į skirtingo ilgio dalis
    
7. **recombinePieces(pieces)** Teskto sudėjimas atgal
  - Išskaidytos dalys sujungiamos atgal į vieną tekstą. Dalys rikiuojamos pagal jų ASCII sumą mažėjimo tvarka (dar kartą panaudojam)
  - **for (const auto& piece : pieces)** Apskaičiuojama gautų dalių simbolių ASCII vertė su calculateASCIIsum(FinalOutput) funkcija
  - **std::sort** Dalys išrikiuojamos pagal ASCII vertes mažėjimo tvarka
  - **for (const auto& piece : piece_scores)** dalys sudedamos atgal į viena string
    
8. **if (FinalOutput.size() > 64)** Išvesties trumpinimas
    
9. **Išvesties spausdinimas**

## Testavimas

  ### 1 ir 2 etapai
  Šiam etapui buvo sukurti:
  - 3 failai (avienas.txt, bvienas.txt, cvienas.txt), turinys po vieną simbolį a, b, c atitinkamai. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas, nepaisant to, kad jame buvo tik 1 simbolis. Taip įvyko su visais 3 failais.
  - 3 failai (Daug1.txt, Daug2.txt, Daug3.txt), turinys skirtingą kiekį simbolių, bet visi virš 1000. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas. Taip įvyko su visais 3 failais.
  - 3 failai (SkiriasiVienu1.txt, SkiriasiVienu2.txt, SkiriasiVienu3.txt), kurie skirasi vienu viduriniu simboliu. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas. Taip įvyko su visais 3 failais. Taip pat svarbu paminėti, kad visų trijų failų         rezultatai skiriasi: ca0620fce5f0e00dd730772da53502a64b69cd385bcd1d0ed42f34d5f6ba3b22, 8b57d351ce7605823d3f69cc23df289f7da6f574675fa8faa7bb9b5e80ccfcf5, eb2bb6ec1d3b4a0540edf45236787c64cafbcda5b9a13c835a04efd6b91bbcfd.
  - Vienas tuščias failas, kurį paleidus, buvo išmestas pranešimas, kad failas yra tuščias.
  
  ### 3 etapas

  Lentelė su visais laikais ir vidurkiais
  ![Screenshot 2024-09-26 143516](https://github.com/user-attachments/assets/7229d8d2-40cc-4877-bc72-274dd26987ad) 

  Vidurkių diagrama 
  ![Screenshot 2024-09-26 143521](https://github.com/user-attachments/assets/29f8dff1-4091-43f6-8c1a-d73328d84c80) 

  
  ### 4 ir 5 etapai
  Buvo sugenera 25 000 porų, kurių ilgis 10 simbolių, kitas 25 000 porų, kurių ilgis - 100, dar kitas 25000 poras - 500, ir galiausiai likusias 25 000 poras, kurių ilgis - 1000 simbolių. Failas su poromis nuskaičiuotas su programa, kuri išvedė gautus rezultatus į kitą failą, tuomet buvo nuskaityti duomenys ir kievienos poroas hash'ai palyginti. Nebuvo rasta nei vienos vienodos poros, vadinasi funkcija atitinka 6 reikalavimą, t.y., atsparumą kolizijai.
  
  ### 6 etapas
Įvedus poras (pvz.: Lietuva ir lietuva) gaunami šiektiek sutampantys rezultatai, tai reiškia, kad lavinos efektas nėra pilnai tenkinamas. (771466968144c6c14614f3a4c641475792c6c14614f3a4c6c14754f2c4c64146 ir 77df6f3a6c6cf4756f2c6c64f46577f46968f46c6cf4616f3a6c679f47478c36). 
  
  ### 7 etapas
Viską apibendrinant, iš atliktų tyrimu galima teigti, kad kodo greitis ir atsparumas kolizijai yra stiprybės. Na o silpnybė - netenkinamas lavinos efektas, todėl kitą versiją reikės tobulinti.
