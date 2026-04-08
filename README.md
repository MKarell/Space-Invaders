# Console Space Invaders 🚀

Jest to gra zręcznościowa wzorowana na klasycznym Space Invaders, napisana całkowicie od zera w języku C++. Gra działa w oknie konsoli Windows, posiadając własny, niestandardowy system renderowania grafiki opartej na znakach ASCII. Projekt jest przykładem zastosowania wskaźników i dynamicznych struktur danych bez użycia gotowych kontenerów z biblioteki standardowej (STL).

## 🎮 Główne funkcje
* **Dynamiczne Fale Przeciwników:** Mechanika płynnego poruszania się wrogów oraz ich ataków.
* **Ręczne Zarządzanie Pamięcią:** Wszelkie obiekty w grze (pociski, statki, wyniki) oparte są na autorskich listach jednokierunkowych i dynamicznej alokacji pamięci.
* **System Zapisów (Save/Load):** Możliwość zapauzowania gry i zrzutu pełnego stanu pamięci (pozycji, HP, aktywnych pocisków) do pliku `save.txt`, a następnie wczytania go przy ponownym uruchomieniu.
* **Tablica Wyników (Highscores):** Obsługa tabeli najlepszych graczy z podziałem na 3 poziomy trudności (Łatwy, Średni, Trudny), zapisywana w lokalnych plikach tekstowych.
* **Walka z Bossem:** Dodatkowa struktura przeciwnika (Boss) oparta na drzewie binarnym do przechowywania jego geometrii i punktów trafień.

## 💻 Użyte technologie
* **Język:** C++ (standard konsolowy)
* **Biblioteki:** standardowe biblioteki C++ (`<iostream>`, `<fstream>`, `<string>`) oraz Windows API (`<windows.h>`) do asynchronicznej obsługi klawiatury (`GetAsyncKeyState`) i modyfikacji kursora konsoli.
* **Architektura:** Podział logiki na moduły (statki, pociski, interfejs, boss) z użyciem plików `.h` oraz `.cpp`.

## 🚀 Jak skompilować i uruchomić?

1. Sklonuj repozytorium na swój dysk:
   ```bash
   git clone [https://github.com/MKarell/Space-Invaders.git](https://github.com/MKarell/Space-Invaders.git)
2. Projekt jest gotowy do otwarcia w Microsoft Visual Studio. Uruchom plik Space Invaders.sln.

3. Skompiluj projekt (najlepiej w trybie Release dla płynniejszego działania pętli gry).

4. Do sterowania używaj klawiszy W, A, S, D lub strzałek (zmiana rozmiaru/ruchu statku) oraz Spacji do strzelania. Klawisz P służy do pauzy.
