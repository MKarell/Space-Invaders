#ifndef STATKI_H
#define STATKI_H

#include <string>
#include <cstdlib>

/** @brief Elementy listy dynamicznej
 *
 * Definicja elementu jednokierunkowej dynamicznej listy statk�w
 */
class Statek
{
public:
    ///Wygl�d statku
    char tab;
    ///Pierwsza wsp�rz�dna
    int height;
    ///Druga wsp�rz�dna
    int width;
    ///Ilo�� �ycia
    int hp;
    ///Wska�nik na kolejny element listy
    Statek* nastepny;
};

/** @brief dodajWroga1
 *
 * Funkcja dodaje do listy nowy element
 * @param i pierwsza wsp�rz�dna
 * @param j druga wsp�rz�dna
 * @return Statek zwraca nowy element listy
 */
Statek* dodajWroga1(int i, int j);

/** @brief dodajWroga1
 *
 * Funkcja dodaje do listy nowy element
 * @param i pierwsza wsp�rz�dna
 * @param j druga wsp�rz�dna
 * @return Statek zwraca nowy element listy
 */
Statek* dodajWroga2(int i, int j);

/** @brief czyWyswietl
 *
 * Funkcja sprawdza czy na podanych wsp�rz�dnych wy�wietli� element listy
 * @param aktualny
 * @param h pierwsza wsp�rz�dna planszy
 * @param w druga wsp�rz�dna planszy
 * @return char przekazuje co ma wy�wietli�
 */
char czyWyswietl(Statek* aktualny, int h, int w);

/** @brief przesunWrogow
 *
 * Funkcja przesuwa fale wrog�w
 * @param aktualny g�owa listy fali wrog�w
 * @param kierunek zmienna przechowuj�ca kierunek w kt�rym b�dzie przemieszcza� si� fala wrog�w
 * @param w szeroko�� planszy
 */
void przesunWrogow(Statek* aktualny, bool& kierunek, int w);

/** @brief stworzBohatera
 *
 * @param h pierwsza wsp�rz�dna na kt�rej ma zosta� stworzony bohater
 * @param w druga wsp�rz�dna na kt�rej ma zosta� stworzony bohater
 * @return
 */
Statek stworzBohatera(int h, int w);

/** @brief nowaFala
 *
 * Funkcja dodaje nowych wrog�w do listy
 * @param aktualny g�owa listy fali wrog�w
 * @param w szeroko�� planszy
 * @param poz poziom trudno�ci
 */
void nowaFala(Statek* aktualny, int w, int poz);

#endif // STATKI_H

