#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <fstream>
#include <string>
#include "interfejs.h"

using namespace std;

/** @brief Elementy listy dynamicznej
 *
 * Definicja elementu jednokierunkowej dynamicznej listy tabeli wyników
 */
class Lista
{
public:
    /// Imie gracza
    string imie;
    /// Wynik gracza
    int wynik;
    /// WskaŸnik na nastêpny element listy
    Lista* nastepny;
};

/** @brief Pobieranie wyników
 *
 * Funkcja pobiera z piku tekstowego wyniki i zapisuje je w liœcie rekordu typu Lista
 * @param poczatek g³owa listy wyników
 * @param poz poziom trudnoœci
 * @return poczatek g³owa listy wyników
 */
Lista* pobierzScory(Lista* poczatek, int poz);
/** @brief Dodanie wyniku
 *
 * Funkcja dodaje uzyskany wynik do listy
 * @param w liczba punktów
 * @param poczatek g³owa listy wyników rekordu typu Lista
 */
void dodajWynik(int w, Lista*& poczatek);

/** @brief Usuwanie ostatniego wyniku
 *
 * Funkcja usuwa ostatni element listy
 * @param aktualny g³owa listy wyników rekordu typu Lista
 */
void usunOstatni(Lista* aktualny);

/** @brief Wpisywanie wyników
 *
 * Funkcja wpisuje liste wyników do pliku tekstowego
 * @param aktualny g³owa listy wyników rekordu typu Lista
 */
void wypiszScory(Lista* aktualny);

/** @brief Wypisywanie wyników
 *
 * Funkcja wypisuje liste wyników
 * @param aktualny glowa listy wyników
 * @param poziom trudnoœci
 */
void wpiszScory(Lista* aktualny, int poz);

#endif // HIGHSCORE_H

