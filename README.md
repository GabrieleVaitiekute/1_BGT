# BGT

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
