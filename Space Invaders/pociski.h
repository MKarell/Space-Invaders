#ifndef POCISKI_H
#define POCISKI_H

/** @brief Elementy listy dynamicznej
 *
 * Definicja elementu jednokierunkowej dynamicznej listy pocisków
 */
class Pocisk
{
public:
    /// Pierwsza wspó³rzêdna
    int h;
    /// Druga wspó³rzêdna
    int w;
    /// Zmienna mówi¹ca za którym powtórzeniem pêtli pocisk siê przesunie
    int speed;
    //int damage;
    /// WskaŸnik na nastêpny element listy
    Pocisk* nastepny;
};

/** @brief dodajPociskBohatera
 *
 * Funkcja dodaje pocisk Bohatera jako kolejny element listy
 * @param aktualny g³owa listy pocisków Bohatera rekordu typu Pocisk
 * @param h pierwsza wspó³rzêdna
 * @param w druga wspó³rzêdna
 */
void dodajPociskBohatera(Pocisk* aktualny, int h, int w);

/** @brief dodajPociskWroga
 *
 * Funkcja dodaje pocisk wroga jako kolejny element listy
 * @param aktualny g³owa listy pocisków wroga rekordu typu Pocisk
 * @param h pierwsza wspó³rzêdna planszy
 * @param w druga wspó³rzêdna planszy
 */
void dodajPociskWroga(Pocisk* aktualny, int h, int w);

/** @brief przesunPociskBohatera
 *
 * Funkcja zmieniaj¹ca pierwsz¹ wspó³rzêdn¹ na o jeden wiêksz¹
 * @param aktualny g³owa listy pocisków Bohatera rekordu typu Pocisk
 */
void przesunPociskBohatera(Pocisk* aktualny);

/** @brief przesunPociskWroga
 *
 * Funkcja zmieniaj¹ca pierwsz¹ wspó³rzêdn¹ na o jeden mniejsz¹
 * @param aktualny g³owa listy pocisków wroga rekordu typu Pocisk
 * @param poz poziom trudnoœci
 */
void przesunPociskWroga(Pocisk* aktualny, int poz);

/** @brief wyswietlPociski
 *
 * Funkcja sprawdzaj¹ca na jakich wspó³rzêdnych planszy nale¿y wyœwietliæ pociski
 * @param aktualny
 * @param h pierwsza wspó³rzêdna planszy
 * @param w druga wspó³rzêdna planszy
 * @return bool zwraca czy nale¿y wyœwietliæ
 */
bool wyswietlPociski(Pocisk* aktualny, int h, int w);

/** @brief usunPocisk
 *
 * Funkcja usuwa wybrany element listy
 * @param aktualny element listy pocisków rekordu typu Pocisk
 */
void usunPocisk(Pocisk* aktualny);

#endif // POCISKI_H

