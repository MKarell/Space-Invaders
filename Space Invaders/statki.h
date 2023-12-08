#ifndef STATKI_H
#define STATKI_H

#include <string>
#include <cstdlib>

/** @brief Elementy listy dynamicznej
 *
 * Definicja elementu jednokierunkowej dynamicznej listy statków
 */
class Statek
{
public:
    ///Wygl¹d statku
    char tab;
    ///Pierwsza wspó³rzêdna
    int height;
    ///Druga wspó³rzêdna
    int width;
    ///Iloœæ ¿ycia
    int hp;
    ///WskaŸnik na kolejny element listy
    Statek* nastepny;
};

/** @brief dodajWroga1
 *
 * Funkcja dodaje do listy nowy element
 * @param i pierwsza wspó³rzêdna
 * @param j druga wspó³rzêdna
 * @return Statek zwraca nowy element listy
 */
Statek* dodajWroga1(int i, int j);

/** @brief dodajWroga1
 *
 * Funkcja dodaje do listy nowy element
 * @param i pierwsza wspó³rzêdna
 * @param j druga wspó³rzêdna
 * @return Statek zwraca nowy element listy
 */
Statek* dodajWroga2(int i, int j);

/** @brief czyWyswietl
 *
 * Funkcja sprawdza czy na podanych wspó³rzêdnych wyœwietliæ element listy
 * @param aktualny
 * @param h pierwsza wspó³rzêdna planszy
 * @param w druga wspó³rzêdna planszy
 * @return char przekazuje co ma wyœwietliæ
 */
char czyWyswietl(Statek* aktualny, int h, int w);

/** @brief przesunWrogow
 *
 * Funkcja przesuwa fale wrogów
 * @param aktualny g³owa listy fali wrogów
 * @param kierunek zmienna przechowuj¹ca kierunek w którym bêdzie przemieszczaæ siê fala wrogów
 * @param w szerokoœæ planszy
 */
void przesunWrogow(Statek* aktualny, bool& kierunek, int w);

/** @brief stworzBohatera
 *
 * @param h pierwsza wspó³rzêdna na której ma zostaæ stworzony bohater
 * @param w druga wspó³rzêdna na której ma zostaæ stworzony bohater
 * @return
 */
Statek stworzBohatera(int h, int w);

/** @brief nowaFala
 *
 * Funkcja dodaje nowych wrogów do listy
 * @param aktualny g³owa listy fali wrogów
 * @param w szerokoœæ planszy
 * @param poz poziom trudnoœci
 */
void nowaFala(Statek* aktualny, int w, int poz);

#endif // STATKI_H

