#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <fstream>
#include <string>
#include "interfejs.h"

using namespace std;

/** @brief Elementy listy dynamicznej
 *
 * Definicja elementu jednokierunkowej dynamicznej listy tabeli wynik�w
 */
class Lista
{
public:
    /// Imie gracza
    string imie;
    /// Wynik gracza
    int wynik;
    /// Wska�nik na nast�pny element listy
    Lista* nastepny;
};

/** @brief Pobieranie wynik�w
 *
 * Funkcja pobiera z piku tekstowego wyniki i zapisuje je w li�cie rekordu typu Lista
 * @param poczatek g�owa listy wynik�w
 * @param poz poziom trudno�ci
 * @return poczatek g�owa listy wynik�w
 */
Lista* pobierzScory(Lista* poczatek, int poz);
/** @brief Dodanie wyniku
 *
 * Funkcja dodaje uzyskany wynik do listy
 * @param w liczba punkt�w
 * @param poczatek g�owa listy wynik�w rekordu typu Lista
 */
void dodajWynik(int w, Lista*& poczatek);

/** @brief Usuwanie ostatniego wyniku
 *
 * Funkcja usuwa ostatni element listy
 * @param aktualny g�owa listy wynik�w rekordu typu Lista
 */
void usunOstatni(Lista* aktualny);

/** @brief Wpisywanie wynik�w
 *
 * Funkcja wpisuje liste wynik�w do pliku tekstowego
 * @param aktualny g�owa listy wynik�w rekordu typu Lista
 */
void wypiszScory(Lista* aktualny);

/** @brief Wypisywanie wynik�w
 *
 * Funkcja wypisuje liste wynik�w
 * @param aktualny glowa listy wynik�w
 * @param poziom trudno�ci
 */
void wpiszScory(Lista* aktualny, int poz);

#endif // HIGHSCORE_H

