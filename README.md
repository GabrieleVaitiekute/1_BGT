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

  ### 1 ir 2 etapai
  Šiam etapui buvo sukurti:
  - 3 failai (avienas.txt, bvienas.txt, cvienas.txt), turinys po vieną simbolį a, b, c atitinkamai. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas, nepaisant to, kad jame buvo tik 1 simbolis. Taip įvyko su visais 3 failais.
  - 3 failai (Daug1.txt, Daug2.txt, Daug3.txt), turinys skirtingą kiekį simbolių, bet visi virš 1000. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas. Taip įvyko su visais 3 failais.
  - 3 failai (SkiriasiVienu1.txt, SkiriasiVienu2.txt, SkiriasiVienu3.txt), kurie skirasi vienu viduriniu simboliu. Paleidus programą kelis kartus su vienu ir tuo pačiu failu išvestas toks pat 64 simbolių ilgio rezultatas. Taip įvyko su visais 3 failais. Taip pat svarbu paminėti, kad visų trijų failų         rezultatai skiriasi: 4c7d797d7a6b6c53537d2d6b2c6b32585e7d7d6b69556b2a731f7d296b557c56, c6fa47d516b27621e7d4a6b235e17d5b6b7230ee7d806b364c5e7d7367d446b4, d796b2a753537d2d6b2f2f49732585e7d7d6b69554c731f7d296b557c567d326.
  - Vienas tuščias failas, kurį paleidus, nebuvo išvestas joks rezultatas.
  
  ### 3 etapas

  
  ### 4 ir 5 etapai

  ### 6 etapas

  ### 7 etapas
