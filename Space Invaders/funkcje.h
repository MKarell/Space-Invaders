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
 * Funkcja sprawdzaj�ca czy nale�y usun�� wroga z listy wrog�w por�wnuj�c z list� pocisk�w i dodaj�ca punkty.
 * @param aktWrog Lista wrog�w rekordu typu Statek przechowuj�ca informacje o wrogach
 * @param aktPocisk Lista pocisk�w rekordu typu Pocisk przechowuj�ca informacje o pociskach
 * @param points Punkty
 */
void usunWroga(Statek* aktWrog, Pocisk* aktPocisk, int& points);

/** @brief Sprawdzanie czy bohater zosta� trafiony
 *
 * Funkcja sprawdzaj�ca czy bohater zosta� trafiony pociskiem wroga
 * @param bohater zmienna rekordu typu Statek przechowuj�ca informacje o bohaterze
 * @param aktualny Lista pocisk�w rekordu typu Pocisk przechowuj�ca informacje o pociskach
 */
void czyTrafBohater(Statek& bohater, Pocisk* aktualny);

/** @brief Wczytywanie gry
 *
 * Funkcja wczytuje dane z pliku tekstowego aby wczyta� zapisany stan programu
 * @param bohater zmienna rekordu typu Statek przechowuj�ca informacje o bohaterze
 * @param pociskiBohatera Lista pocisk�w rekordu typu Pocisk przechowuj�ca informacje o pociskach
 * @param listaWrogow Lista wrog�w rekordu typu Statek przechowuj�ca informacje o wrogach
 * @param pociskiWroga Lista pocisk�w rekordu typu Pocisk przechowuj�ca informacje o pociskach
 * @param points Punkty
 */
void wczytaj(Statek& bohater, Pocisk* pociskiBohatera, Statek* listaWrogow, Pocisk* pociskiWroga, int& punkty, int& poz);

/** @brief Zapisywanie stanu gry
 *
 * Funkcja zapisuj�ca aktualny stan programu do pliku tekstowego
 * @param bohater zmienna rekordu typu Statek przechowuj�ca informacje o bohaterze
 * @param pociskiBohatera Lista pocisk�w rekordu typu Pocisk przechowuj�ca informacje o pociskach
 * @param listaWrogow Lista wrog�w rekordu typu Statek przechowuj�ca informacje o wrogach
 * @param pociskiWroga Lista pocisk�w rekordu typu Pocisk przechowuj�ca informacje o pociskach
 * @param points Punkty
 */
void zapisz(Statek& bohater, Pocisk* pociskiBohatera, Statek* listaWrogow, Pocisk* pociskiWroga, int& punkty, int poz);

void dodajPociskBossa(Boss* aktualnyW, Pocisk* glpocisk);

#endif // FUNKCJE_H
