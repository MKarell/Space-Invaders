#include "interfejs.h"

void wypiszPlansze(int i, int j, char znak)
{
    if (i != 0 && j == 0)
        cout << endl;
    cout << znak;
}

void wypisz(string slowo, int k)
{
    cout << endl;
    cout << slowo << ":" << k;
}

void wypiszS(string slowo)
{
    cout << slowo << endl;
}

int poziom()
{
    cout << "1.Latwy\n2.Sredni\n3.Trudny" << endl;
    while (true)
    {
        system("pause");
        if (GetAsyncKeyState(0x31))
        {
            system("cls");
            return 1;
        }
        else if (GetAsyncKeyState(0x32))
        {
            system("cls");
            return 2;
        }
        else if (GetAsyncKeyState(0x33))
        {
            system("cls");
            return 3;
        }

        //        if( HIBYTE( GetKeyState( VK_LBUTTON ) ) )
        //        {
        //            POINT * pos = GetCursorPos();
        //            POINT points = *pos;
        //            if(points.x==0 && points.y<=5)
        //                return 1;
        //            else if(points.x==1 && points.y<=6)
        //                return 2;
        //            else if(points.x==2 && points.y<=6)
        //                return 3;
        //        }
    }
}

bool pauza()
{
    while (true)
    {
        cout << "1.Wznow\n2.Zapisz\n3.Wyjdz" << endl;
        system("pause");
        if (GetAsyncKeyState(0x31))
        {
            system("cls");
            return 0;
        }
        else if (GetAsyncKeyState(0x32))
            return 1;
        else if (GetAsyncKeyState(0x33))
            exit(0);
    }
}

bool menu()
{
    while (true)
    {
        cout << "1.Nowa Gra\n2.Wczytaj Gre\n3.Wyjdz" << endl;
        system("pause");
        if (GetAsyncKeyState(0x31))
        {
            system("cls");
            return 0;
        }

        else if (GetAsyncKeyState(0x32))
        {
            if (!ifstream("save.txt", ios::ate).tellg())
            {
                system("cls");
                cout << "Nie ma sejwu";
                Sleep(1000);
            }
            else
                return 1;
        }

        else if (GetAsyncKeyState(0x33))
            exit(0);

        system("cls");
    }
}
