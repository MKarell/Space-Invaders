#ifndef INTERFEJS_H
#define INTERFEJS_H

#include <iostream>
#include <fstream>
#include <windows.h>

//typedef struct tagPOINT {
//  LONG x;
//  LONG y;
//} POINT, *PPOINT;

using namespace std;

/** @brief Wypisywanie planszy
 *
 * Funkcja wypisuje w konsoli podany znak na podanej wsp�rz�dnej
 * @param i pierwsza wsp�rz�dna
 * @param j druga wsp�rz�dna
 * @param znak symbol jaki zostanie wypisany
 */
void wypiszPlansze(int i, int j, char znak);

/** @brief Wypisywanie s�owa i zmiennej
 *
 * @param slowo s�owo jakie wypisze funkcja w konsoli
 * @param k zmienna typu int wypisywana w konsoli
 */
void wypisz(string slowo, int k);

/** @brief Wypisywanie s�owa
 *
 * @param slowo s�owo jakie funkcja wypisze w konsoli
 */
void wypiszS(string slowo);

/** @brief Wybieranie poziomu trudno�ci
 *
 * Funkcja wypisuje w konsoli poziomy trudno�ci i wymusza na u�ytkowniku wyb�r jednego
 * @return k wybrany poziom trudno�ci
 */
int poziom();

/** @brief Pauzowanie programu
 *
 * Funkcja wy�wietla menu pauzy i wymusza na u�ytkowniku dzia�anie
 */
bool pauza();

/** @brief Wy�wietlanie menu
 *
 * Funkcja wy�wietla menu i w niej u�ytkownik dokonuje wyboru operacji
 * @return bool
 */
bool menu();

#endif // INTERFEJS_H

