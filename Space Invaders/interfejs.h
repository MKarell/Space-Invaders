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
 * Funkcja wypisuje w konsoli podany znak na podanej wspó³rzêdnej
 * @param i pierwsza wspó³rzêdna
 * @param j druga wspó³rzêdna
 * @param znak symbol jaki zostanie wypisany
 */
void wypiszPlansze(int i, int j, char znak);

/** @brief Wypisywanie s³owa i zmiennej
 *
 * @param slowo s³owo jakie wypisze funkcja w konsoli
 * @param k zmienna typu int wypisywana w konsoli
 */
void wypisz(string slowo, int k);

/** @brief Wypisywanie s³owa
 *
 * @param slowo s³owo jakie funkcja wypisze w konsoli
 */
void wypiszS(string slowo);

/** @brief Wybieranie poziomu trudnoœci
 *
 * Funkcja wypisuje w konsoli poziomy trudnoœci i wymusza na u¿ytkowniku wybór jednego
 * @return k wybrany poziom trudnoœci
 */
int poziom();

/** @brief Pauzowanie programu
 *
 * Funkcja wyœwietla menu pauzy i wymusza na u¿ytkowniku dzia³anie
 */
bool pauza();

/** @brief Wyœwietlanie menu
 *
 * Funkcja wyœwietla menu i w niej u¿ytkownik dokonuje wyboru operacji
 * @return bool
 */
bool menu();

#endif // INTERFEJS_H

