#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "statki.h"
#include "pociski.h"
#include "boss.h"
#include <windows.h>
#include <fstream>

/** @brief Czyszczenie ekranu*/
void czyscEkran();

/** @brief Usuwanie Wroga
 *
 * Funkcja sprawdzaj¹ca czy nale¿y usun¹æ wroga z listy wrogów porównuj¹c z list¹ pocisków i dodaj¹ca punkty.
 * @param aktWrog Lista wrogów rekordu typu Statek przechowuj¹ca informacje o wrogach
 * @param aktPocisk Lista pocisków rekordu typu Pocisk przechowuj¹ca informacje o pociskach
 * @param points Punkty
 */
void usunWroga(Statek* aktWrog, Pocisk* aktPocisk, int& points);

/** @brief Sprawdzanie czy bohater zosta³ trafiony
 *
 * Funkcja sprawdzaj¹ca czy bohater zosta³ trafiony pociskiem wroga
 * @param bohater zmienna rekordu typu Statek przechowuj¹ca informacje o bohaterze
 * @param aktualny Lista pocisków rekordu typu Pocisk przechowuj¹ca informacje o pociskach
 */
void czyTrafBohater(Statek& bohater, Pocisk* aktualny);

/** @brief Wczytywanie gry
 *
 * Funkcja wczytuje dane z pliku tekstowego aby wczytaæ zapisany stan programu
 * @param bohater zmienna rekordu typu Statek przechowuj¹ca informacje o bohaterze
 * @param pociskiBohatera Lista pocisków rekordu typu Pocisk przechowuj¹ca informacje o pociskach
 * @param listaWrogow Lista wrogów rekordu typu Statek przechowuj¹ca informacje o wrogach
 * @param pociskiWroga Lista pocisków rekordu typu Pocisk przechowuj¹ca informacje o pociskach
 * @param points Punkty
 */
void wczytaj(Statek& bohater, Pocisk* pociskiBohatera, Statek* listaWrogow, Pocisk* pociskiWroga, int& punkty, int& poz);

/** @brief Zapisywanie stanu gry
 *
 * Funkcja zapisuj¹ca aktualny stan programu do pliku tekstowego
 * @param bohater zmienna rekordu typu Statek przechowuj¹ca informacje o bohaterze
 * @param pociskiBohatera Lista pocisków rekordu typu Pocisk przechowuj¹ca informacje o pociskach
 * @param listaWrogow Lista wrogów rekordu typu Statek przechowuj¹ca informacje o wrogach
 * @param pociskiWroga Lista pocisków rekordu typu Pocisk przechowuj¹ca informacje o pociskach
 * @param points Punkty
 */
void zapisz(Statek& bohater, Pocisk* pociskiBohatera, Statek* listaWrogow, Pocisk* pociskiWroga, int& punkty, int poz);

void dodajPociskBossa(Boss* aktualnyW, Pocisk* glpocisk);

#endif // FUNKCJE_H
