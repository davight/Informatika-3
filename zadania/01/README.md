# Zadanie 1: Vizualizácia množín

Cieľom zadania je implementovať triedu SetVisualizer, ktorá bude zobrazovať výsledky množinových operácií. Triedu implementujte v mennom priestore setvis podľa UML diagramu tried na Obr. 1 v súboroch `set_visualizer.cpp` a `set_visualizer.hpp`.

<img width="526" height="219" alt="image" src="https://github.com/user-attachments/assets/0eeaf592-f2bc-41e6-9f9b-a9474d0a677a" /> <br>


V príklade uvažujeme s podmnožinami základnej množiny s kardinalitou 64. Podmnožiny sú re prezentované číslami typu `std::uint64_t`. Jednotlivé bity reprezentujú prítomnosť (bit s hod notou 1) alebo neprítomnosť (bit s hodnotou 0) prvkov základnej množiny v podmnožine. 
- Metódy calc*(a,b) vypočítajú danú množinovú operáciu nad argumentami a a b a vrátia jej výsledok (množina reprezentované číslom typu `std::uint64_t`).
- Metódy show*(a,b) vypočítajú danú množinovú operáciu nad argumentami a a b a zo brazia jej výsledok spolu s pôvodnými množinami.
Bity zobrazovanej množiny sú postupne umiestňované na riadky ASCII displeja s rozmerom 8x8 od najmenej po najviac významný bit. Bit s hodnotou 1 je reprezentovaný znakom '*' a bit s hodnotou 0 je reprezentovaný znakom '.'

## Testy:

**Vizualizácia množinových operácií pre hodnoty:**
```cpp
const std::uint64_t a = 0x0F0F0F0F0F0F0F0F;
const std::uint64_t b = 0xFFFFFFFF00000000;
```

**Vyzerá nasledovne:**

intersection(a, b)
```
****....
****....
****....
****....
********
********
********
********
```

union(a, b)
```
****....
****....
****....
****....
********
********
********
********
```

difference(a, b)
```
****....
****....
****....
****....
********
********
********
********
```

complement(a)
```
********
********
********
********
********
********
********
********
```

<footer>idk jak ukazat cervenu sorry not sorry</footer>
