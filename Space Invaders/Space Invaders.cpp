#include <ctime>
#include "statki.h"
#include "pociski.h"
#include "funkcje.h"
#include "interfejs.h"
#include "highscore.h"
#include "boss.h"

using namespace std;

struct Plansza
{
    char sign;
};

void Gra(Plansza** pole, int height, int width, bool czyWczytac)
{
    int poz, slow = 0, b = 0;
    int points = 0;
    Statek bohater = stworzBohatera(height, width);
    Pocisk* pociskiBohatera = new Pocisk;
    Pocisk* pociskiWroga = new Pocisk;
    Statek* listaWrogow = new Statek;
    listaWrogow->nastepny = NULL;
    pociskiBohatera->nastepny = NULL;
    pociskiWroga->nastepny = NULL;
    Statek* aktualny = listaWrogow;
    Boss* boss = 0;

    bool kierunek = 1;

    if (czyWczytac)
        wczytaj(bohater, pociskiBohatera, listaWrogow, pociskiWroga, points, poz);
    else
        poz = poziom();

    while (true)
    {
        bool koniec = 0;
        czyscEkran();
        if (listaWrogow->nastepny == NULL)
        {
            //boss=stworzBossa();
            nowaFala(listaWrogow, width, poz);
            //b++;
        }

        aktualny = listaWrogow->nastepny;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (bohater.hp == 0 && i == height / 2 && j >= width / 2 - 4 && j <= width / 2 + 4)
                {
                    string napis = "GAME OVER";
                    pole[i][j].sign = napis[j - (width / 2 - 4)];
                    koniec = 1;
                }

                else if (j == 0 || j == width - 1)
                    pole[i][j].sign = '|';

                else if (i == 0 || i == height - 1)
                    pole[i][j].sign = '-';

                else if (j == bohater.width && i == bohater.height)
                    pole[i][j].sign = bohater.tab;

                else if (czyWyswietl(listaWrogow, i, j) != 0 && boss == 0)
                    pole[i][j].sign = czyWyswietl(listaWrogow, i, j);

                else if (boss != 0)
                    pole[i][j].sign = wyswietlBossa(boss, i, j);

                else if (wyswietlPociski(pociskiBohatera, i, j))
                    pole[i][j].sign = '^';

                else if (wyswietlPociski(pociskiWroga, i, j))
                    pole[i][j].sign = '*';

                else
                    pole[i][j].sign = ' ';
                wypiszPlansze(i, j, pole[i][j].sign);
            }
        }
        Sleep(30);
        przesunPociskWroga(pociskiWroga, poz);
        //dodajPociskBossa(boss,pociskiWroga);
        while (aktualny != NULL)
        {
            if (rand() % (300 / poz) == 0)
                dodajPociskWroga(pociskiWroga, aktualny->height, aktualny->width);
            aktualny = aktualny->nastepny;
        }
        czyTrafBohater(bohater, pociskiWroga);

        przesunPociskBohatera(pociskiBohatera);


        if (slow > 1)
            slow = 0;
        slow++;

        if (GetAsyncKeyState(VK_SPACE) && slow == 2)
        {
            dodajPociskBohatera(pociskiBohatera, bohater.height, bohater.width);
            slow = 0;
        }
        if (GetAsyncKeyState(0x41) && bohater.width > 1)
            bohater.width--;
        else if (GetAsyncKeyState(0x44) && bohater.width < width - 2)
            bohater.width++;
        else if (GetAsyncKeyState(0x52) && bohater.height > 1)
            bohater.height--;
        else if (GetAsyncKeyState(0x57) && bohater.height < height - 2)
            bohater.height++;
        else if (GetAsyncKeyState(0x50))
        {
            system("cls");
            wypiszS("Pauza.");
            if (pauza())
            {
                zapisz(bohater, pociskiBohatera, listaWrogow, pociskiWroga, points, poz);
                return;
            }
        }
        if (listaWrogow != 0)
            usunWroga(listaWrogow, pociskiBohatera, points);
        //esle

        wypisz("Health", bohater.hp);

        wypisz("Points", points);

        przesunWrogow(listaWrogow, kierunek, width);

        if (pociskiBohatera->nastepny != NULL && pociskiBohatera->nastepny->h < 1)
            usunPocisk(pociskiBohatera);
        Pocisk* chwilowy = pociskiWroga->nastepny;
        Pocisk* poprzedni = pociskiWroga;

        while (chwilowy != NULL)
        {
            if (chwilowy->h == height)
                usunPocisk(poprzedni);
            else
                poprzedni = chwilowy;
            chwilowy = poprzedni->nastepny;
        }
        if (koniec)
        {
            system("PAUSE");
            system("cls");
            Lista* poczatek = 0;
            poczatek = pobierzScory(poczatek, poz);
            dodajWynik(points, poczatek);
            usunOstatni(poczatek);
            system("cls");
            wypiszScory(poczatek);
            wpiszScory(poczatek, poz);
            break;
        }
    }
}

int main()
{
    srand(time(NULL));
    int m = 15, n = 29;
    Plansza** plansz = new Plansza * [m];
    for (int i = 0; i < m; i++)
        plansz[i] = new Plansza[n];

    bool czyWczytac = menu();

    Gra(plansz, m, n, czyWczytac);
}
