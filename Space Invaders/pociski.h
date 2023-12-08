#ifndef POCISKI_H
#define POCISKI_H

/** @brief Elementy listy dynamicznej
 *
 * Definicja elementu jednokierunkowej dynamicznej listy pocisk�w
 */
class Pocisk
{
public:
    /// Pierwsza wsp�rz�dna
    int h;
    /// Druga wsp�rz�dna
    int w;
    /// Zmienna m�wi�ca za kt�rym powt�rzeniem p�tli pocisk si� przesunie
    int speed;
    //int damage;
    /// Wska�nik na nast�pny element listy
    Pocisk* nastepny;
};

/** @brief dodajPociskBohatera
 *
 * Funkcja dodaje pocisk Bohatera jako kolejny element listy
 * @param aktualny g�owa listy pocisk�w Bohatera rekordu typu Pocisk
 * @param h pierwsza wsp�rz�dna
 * @param w druga wsp�rz�dna
 */
void dodajPociskBohatera(Pocisk* aktualny, int h, int w);

/** @brief dodajPociskWroga
 *
 * Funkcja dodaje pocisk wroga jako kolejny element listy
 * @param aktualny g�owa listy pocisk�w wroga rekordu typu Pocisk
 * @param h pierwsza wsp�rz�dna planszy
 * @param w druga wsp�rz�dna planszy
 */
void dodajPociskWroga(Pocisk* aktualny, int h, int w);

/** @brief przesunPociskBohatera
 *
 * Funkcja zmieniaj�ca pierwsz� wsp�rz�dn� na o jeden wi�ksz�
 * @param aktualny g�owa listy pocisk�w Bohatera rekordu typu Pocisk
 */
void przesunPociskBohatera(Pocisk* aktualny);

/** @brief przesunPociskWroga
 *
 * Funkcja zmieniaj�ca pierwsz� wsp�rz�dn� na o jeden mniejsz�
 * @param aktualny g�owa listy pocisk�w wroga rekordu typu Pocisk
 * @param poz poziom trudno�ci
 */
void przesunPociskWroga(Pocisk* aktualny, int poz);

/** @brief wyswietlPociski
 *
 * Funkcja sprawdzaj�ca na jakich wsp�rz�dnych planszy nale�y wy�wietli� pociski
 * @param aktualny
 * @param h pierwsza wsp�rz�dna planszy
 * @param w druga wsp�rz�dna planszy
 * @return bool zwraca czy nale�y wy�wietli�
 */
bool wyswietlPociski(Pocisk* aktualny, int h, int w);

/** @brief usunPocisk
 *
 * Funkcja usuwa wybrany element listy
 * @param aktualny element listy pocisk�w rekordu typu Pocisk
 */
void usunPocisk(Pocisk* aktualny);

#endif // POCISKI_H

