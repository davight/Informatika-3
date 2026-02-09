# Zadanie 2: Turtlepreter

## Zadanie
Cieľom zadania je rozšíriť projekt Turtlepreter. Východiskom pre vypracovanie zadania je stav projektu po 8. cvičení, v ktorom sú implementované aspoň triedy Controllable, Node, ICommand, Cursor, CursorUp, SequentialCursor, Interpreter, Turtle, TurtleCommand, CommandJump, CommandRotate.

## Úprava korytnačky
Triedu Turtle je potrebné rozšíriť tak, aby umožňovala vykreslenie úsekov cesty rôznymi farbami. Za týmto účelom je potrebné do triedy Turtle pridať nasledovné metódy:
- `size_t getPathSegmentCount() const` – vráti počet segmentov, z ktorých sa skladá cesta vykresľovaná korytnačkou.
- `ImVec4 getPathSegmentPoints(size_t i) const` – vráti počiatočný a koncový bod segmentu, ktorý je vykreslený ako i-ty v poradí (pričom prvý vykreslený segment pova žujeme za nultý).
- `ImColor getPathSegmentColor(size_t i) const` – vráti farbu (pozri sekciu Reprezentácia farieb) segmentu, ktorý je vykreslený ako i-ty v poradí.
- `void setColor(ImColor color)` – nastaví farbu ďalších segmentov, ktoré budú vykreslené korytnačkou.
Počiatočná hodnota farby segmentov vykresľovaných korytnačkou je RGB(0,255,0) (zelená)

<img width="525" height="232" alt="image" src="https://github.com/user-attachments/assets/b2643fe8-e385-4577-8f3b-715193611c12" /><br>

## Reprezentácia farieb
Na reprezentáciu farieb použite triedu ImColor. Jej konštruktor preberá tri hodnoty z rozsahu [0, 255], ktoré reprezentujú zložky R, G a B vo farebnom modeli RGB. Metóda `DrawList::AddLine` používaná pri vykresľovaní preberá inštanciu tejto triedy ako 3. parameter

## Príkaz zmeny farby
Pre možnosť zmeny farby z interpretovaného programu je potrebné pridať príkaz. Vytvorte novú triedu CommandSetColor ako potomka triedy TurtleCommand. Trieda CommandSetColor musí implementovať nasledovné metódy:
- `CommandSetColor(ImColor color)` – konštruktor, uloží si hodnotu farby, ktorú bude korytnačke nastavovať
- `std::string toString()` – vráti reťazec reprezentujúci príkaz, presný formát nie je dôležitý
- `void executeOnTurtle(Turtle &turtle)` – nastaví korytnačke danú farbu čiary jej setColor metódou
Deklaráciu a definície triedy CommandSetColor umiestnite do súboru turtle.(hpp|cpp).

## Logovanie príkazov
V poslednom kroku je potrebné pridať čistú virtuálnu metódu do abstraktnej triedy ICommand:
- `virtual void log(std::ostream &ost) const = 0` - ktorá do výstupného prúdu (ost) vypíše informácie o danom príkaze v presne určenom formáte. Implementácia metódy pre jednotlivé príkazy musí zapísať nasledovné reťazce:

| Trieda | Formát | Príklad |
| ------ | ------ | ------- |
| CommandRotate | "rotate(`{angleRad}`)\n" | rotate(3.14) |
| CommandJump |"jump(`{x}`,`{y}`)\n" | jump(100,100) |
| CommandSetColor | "setColor(`{x}`,`{y}`,`{z}`)\n" | setColor(1,0,0) |

kde zátvorky `{ }` označujú zástupný objekt, ktorý musí byť vo výstupe nahradený skutočnými hodnotami. Trieda ImColor má verejnú členskú premennú Value typu ImVec4, ktorej zložky x,y,z je potrebné použiť vo výstupe pre triedy CommandSetColor. Pre zabezpečenie konzistentného výstupu použite na výpis čísel výstupný prúd ost. Nepoužívajte funkciu `std::format`.
