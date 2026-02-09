# Zadanie 3: Titulky

## Zadanie
Cieľom zadania je rozšíriť knižnicu `libdf` a implementovať novú knižnicu libsrt , ktorá umožní načítať, spracovať a zapísať súbory vo formáte srt. Zadanie odporúčame vypracovať v projekte `04-data` z cvičení.

## Rozšírečnie knižnice LIBDF

### Rozšírenie šablóny triedy DataFrame
Do šablóny triedy DataFrame pridajte šablónu členskej funkcie transform:
```cpp
template<typename F>
void transform(F f);
```
Funkcia transform aplikuje funkciu f typu `void(T&)` na všetky uchovávané záznamy. Funkcia transform je takmer totožná s funkciou apply. Rozdiel je v tom, že funkcia transform nie je const-kvalifikovaná– ňou aplikovaná funkcia f môže modifikovať záznamy.

### Pridanie zapisovania
Do priečinku libdf pridajte súbor `writer.hpp`. V ňom v mennom priestore df implementujte šablónu triedy Writer parametrizovanú jedným typovým parametrom T. Pri implementácii vychádzajte z UML diagramu tried na Obr. 1 a nasledovného popisu:
- `df::Writer<T>::write` – Otvorí súbor na zapisovanie. Ak sa súbor nepodarilo otvoriť, vyhodí výnimku (napríklad std::runtime_error). Deleguje načítanie na čistú virtuálnu funkciu writeImpl.
- `df::Writer<T>::writeImpl` – čistá virtuálna chránená členská funkcia.

<img width="652" height="114" alt="image" src="https://github.com/user-attachments/assets/c642c6c8-ad67-4fa6-8765-4161c750586e" /><br>

### Zapisovanie do formátu JSON

Do priečinku libdf pridajte súbor `json_writer.hpp`. V ňom v mennom priestore df implementujte šablónu triedy JSONWriter parametrizovanú jedným typovým parametrom T. Pri implementácii vychádzajte z UML diagramu tried na Obr. 2 a nasledovného popisu:
- `df::JSONWriter::writeImpl` – Vytvorí inštanciu triedy nlohmann::json– koreň vzni kajúceho JSON dokumentu typu pole ([]). Do koreňa ktorej vloží inštanciu rovnakej triedy získanú funkciou toJSON pre každý záznam z parametra df. Koreň dokumentu zapíše do výstupu ost.
- `df::JSONWriter::toJSON` – Čistá virtuálna členská funkcia. Jej implementácia konvertuje záznam typu T na uzol typu nlohmann::json.

<img width="572" height="232" alt="image" src="https://github.com/user-attachments/assets/cd78b269-c944-4ffe-bda1-2c9581ddc0d6" /><br>

## Pridanie knižnice LIBSRT

V koreni projektu (pozri časť Odovzdanie) vytvorte priečinok libsrt . V ňom vytvorte súbor, ktorý definuje cieľ - statickú knižnicu - srt . Knižnica bude závislá na cieli df a voliteľne na cieli uiutils . Priečinok libsrt pridajte do korenového suboru CMakeLists. txt . Dbajte na
presné pomenovanie suborov `CMakeLists.txt` vrátane malých a veľkých písmen.

### Načítanie titulkov
V priečinku libsrt vytvorte súbor subtitles.hpp . V ňom definujte štruktúru v mennom priestore srt reprezentujúcu jedno zobrazenie titulkov nasledovne:
```cpp
struct Subtitles {
  int id;
  std::chrono::milliseconds from;
  std::chrono::milliseconds to;
  std::string text;
};
```

V priečinku libsrt vytvorte subory srt_loader.hpp a srt_loader.cpp, a v nich implementujte triedu SrtLoader podla UML diagramu tried na Obr. 3 a nasledovného popisu:
- `srt::SrtLoader::load` - Načíta súbor vo formáte srt.

<img width="587" height="201" alt="image" src="https://github.com/user-attachments/assets/8db17bc0-558a-4054-befe-2ff3edd15c94" /><br>

### Uloženie titulkov
V priecinku libsrt vytvorte subory `srt_writer.hpp` a `srt_writer.cpp`, a v nich v mennom priestore srt implementujte triedy NativeSrtWriter a JSONSrtWriter podla UML diagramu tried na Obr. 4 a nasledovného popisu:
- `srt::NativeSrtWriter::writeImpl` – Zapíše titulky uložené v df do súboru daného cestou ost vo formáte srt.
- `srt::JSONSrtWriter::toJSON` – Vytvorí inštanciu triedy nlohmann::json. Inštancia bude mať atribúty identické so záznamom Subtitles. Príklad JSON vrcholu môže vy zerať nasledovne (pričom poradie atribútov sa môže líšiť):
```json
{
  "id": 3,
  "from": "00:00:48,630",
  "to": "00:00:53,610",
  "text": "Come from. The way.\n"
}
```

<img width="656" height="233" alt="image" src="https://github.com/user-attachments/assets/5305079c-090d-42e3-9e2f-902302874ef9" /><br>

### Spracovanie titulkov
V priečinku libsrt vytvorte súbor `srt_processor.hpp`, a v ňom v mennom priestore srt implementujte triedu SrtProcessor podl'a nasledovneho popisu a UML diagramu tried na Obr. 5:

- `srt::SrtProcessor::SrtProcessor` – Konštruktor– inicializuje členskú premennú `m_subtitles` prázdnym zoznamom.
- `srt::SrtProcessor::load` – šablóna členskej funkcie parametrizovaná typovým para metrom `Loader`. Za typový parameter Loader môže byť dosadená trieda SrtLoader alebo iná trieda s totožným rozhraním. Použije loader na načítanie titulkov zo súboru daného cestou path do členskej premennej `m_subtitles`.
- `srt::SrtProcessor::write` – šablóna členskej funkcie parametrizovaná typovým pa rametrom `Writer`. Za typový parameter Writer môže byť dosadená trieda napríklad NativeSrtWriter, JSONSrtWriter alebo iná trieda s totožným rozhraním. Použije writer na zápis titulkov do súboru daného cestou path.
- `srt::SrtProcessor::offset` – šablóna členskej funkcie parametrizovaná typovým pa rametrom `Duration`. Za typový parameter môže byť dosadený jeden z typov knižnice `std::chrono` reprezentujúci jednotku času. Posunie hodnoty atribútov `from` a `to` o zadaný čas.

<img width="581" height="140" alt="image" src="https://github.com/user-attachments/assets/9b805e14-44e6-4b42-8544-1da3660191b8" /><br>

### Pomocné funkcie
V priecinku libsrt vytvorte subory `utils.hpp` a `utils.cpp`, a v nich v mennom priestore `srt::utils` implementujte funkcie:
```cpp
std::chrono::milliseconds strToMs(std::string_view str);
std::string msToStr(std::chrono::milliseconds ms);
```
Podľa nasledovného popisu:
- `strToMs` – prekonvertuje reťazec na typ `std::chrono::milliseconds`. Formát vstupu je garantovane rovnaký ako formát výstupu funkcie msToStr.
- `msToStr` – prekonvertuje typ `std::chrono::milliseconds` na reťazec. Formát reťazca musí byť `hh:mm:ss,ms`, pričom hodiny, minúty a sekundy sú vždy zobrazené dvojciferne s pridaním nuly na začiatok, ak je to potrebné, a milisekundy sú zobrazené troj ciferne s pridaním núl na začiatok, ak je to potrebné. Príklad výstupu `"01:16:40,270"`.

## Ukážka výstupu
Na otestovanie vášho riešenia môžete použiť súbor `notld.srt`. Súbor môžete spracovať nasledovným programom:
```cpp
#include <libsrt/srt_loader.hpp>
#include <libsrt/srt_processor.hpp>
#include <libsrt/srt_writer.hpp>

#include <chrono>

int main(int argc, char** argv){
  srt::SrtLoaderloader;
  srt::NativeSrtWriternativeWriter;
  srt::JSONSrtWriterjsonWriter;
  srt::SrtProcessorprocessor;
  processor.load(loader, argv[1]);
  processor.write(nativeWriter, "native.srt");
  processor.offset(std::chrono::seconds{2});
  processor.write(jsonWriter, "json.json");
}
```

Výstup programu môžete porovnať so súbormi, ktoré sú prílohou tohto zadania. Na porovnanie dvoch súborov môžete použiť nástroj diff , ktorý je v prostredí UCRT64 dostupný po nainštalovaní balíčka
`pacman -S mingw-w64-ucrt-x86-diffutils`
Jeho použitie:
`diff native.srt notld.srt`
musí pri správnosti implementácie vrátit prázdny výstup.
