#include"boss.h"

void dodajElem1(Boss* glowa)
{
    glowa->hp = 30;
    glowa->wspol = new Wspol;
    Wspol* aktualny = glowa->wspol;
    for (int i = 0; i < 3; i++)
    {
        Wspol* nowy = new Wspol;
        nowy->t = 'M';
        nowy->w = 14 + i;
        nowy->h = 2;
        aktualny->nast = nowy;
        aktualny = nowy;
    }
    for (int i = 0; i < 5; i++)
    {
        Wspol* nowy = new Wspol;
        nowy->t = 'H';
        nowy->w = 13 + i;
        nowy->h = 3;
        aktualny->nast = nowy;
        aktualny = nowy;
    }
    for (int i = 0; i < 3; i++)
    {
        Wspol* nowy = new Wspol;
        nowy->t = 'T';
        nowy->w = 13 + 2 * i;
        nowy->h = 4;
        aktualny->nast = nowy;
        aktualny = nowy;
    }
    glowa->lewy = 0;
    glowa->prawy = 0;
}

void dodajElem2(Boss* aktualnyW, int h, int w)
{
    aktualnyW = new Boss;
    aktualnyW->hp = 15;
    aktualnyW->wspol = new Wspol;
    Wspol* kordy = aktualnyW->wspol;
    for (int i = 0; i < 3; i++)
    {
        Wspol* nowy = new Wspol;
        if (i == 1)
            nowy->t = '^';
        else if (i == 2)
            nowy->t = 'A';
        else if (i == 3)
            nowy->t = '^';
        nowy->w = w - 3 + i;
        nowy->h = h;
        kordy->nast = nowy;
        kordy = nowy;
    }
    for (int i = 0; i < 2; i++)
    {
        Wspol* nowy = new Wspol;
        nowy->t = 'T';
        nowy->w = w - 3 + 2 * i;
        nowy->h = h + 1;
        kordy->nast = nowy;
        kordy = nowy;
    }
    aktualnyW->lewy = 0;
    aktualnyW->prawy = 0;
}

Boss* stworzBossa()
{
    Boss* glowa = new Boss;
    dodajElem1(glowa);
    dodajElem2(glowa->lewy, glowa->wspol->nast->nast->h, glowa->wspol->nast->nast->w);
    dodajElem2(glowa->prawy, glowa->wspol->nast->nast->h, glowa->wspol->nast->nast->w);
    return glowa;
}

char wyswietlBossa(Boss* aktualnyG, int i, int j)
{
    if (aktualnyG == 0)
        return 0;
    if (aktualnyG->hp == 0)
    {
        wyswietlBossa(aktualnyG->lewy, i, j);
        wyswietlBossa(aktualnyG->prawy, i, j);
    }
    else
    {
        Wspol* akt = aktualnyG->wspol;
        while (akt->nast != 0)
        {
            akt = akt->nast;
            if (akt->h == i && akt->w == j)
                return akt->t;
        }
        return 0;
    }
}

void przesunBossa(Boss* aktualny)
{
    if (aktualny->wspol->nast == 0)
    {
        przesunBossa(aktualny->lewy);
        przesunBossa(aktualny->prawy);
    }
    else
    {

    }
}
