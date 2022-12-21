//
//  main.c
//  Treasure Hunter Game
//
//  Created by Mehmet TIRPAN and Kerem KIYAK on 25.11.2022.
//

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

//#include <windows.h>
int x = 2, y = 4;

int matris[10][10];

int sayac = 5;

int can = 3;

void cerceve();

void elmasAtama();

void muhafizAtama();

void mYakaladimi();

void adres();

void elmasYeme();

void sifirla();

int elmaslar_x[5];

int elmaslar_y[5];

int muhafizlar_x[5];

int muhafizlar_y[5];

int yedimmi[10][10];


int main()
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++) // matris e deger atama

    {

        for (int j = 0; j < 10; j++)

        {

            matris[i][j] = 0;
        }
    }

    elmasAtama(matris);
    muhafizAtama(matris);
    sifirla();

    for (int i = 0; i < 5; i++)

    {

        yedimmi[elmaslar_x[i]][elmaslar_y[i]] = 1;
    }

    cerceve(matris, x, y);

    while (can > 0)

    {

        char tus;

        tus = getchar();

        switch (tus)

        {

        case 'w':

            if (x != 0)

            {

                x--;

                matris[x + 1][y] = 0;

                cerceve(matris, x, y);
            }

            else
            {

                printf("disari cikamazsiniz!!!");
            }

            break;

        case 'a':

            if (y != 0)

            {

                y--;

                matris[x][y + 1] = 0;

                cerceve(matris, x, y);
            }

            else
            {

                printf("disari cikamazsiniz!!!");
            }

            break;

        case 's':

            if (x != 9)

            {

                x++;

                matris[x - 1][y] = 0;

                cerceve(matris, x, y);
            }

            else
            {

                printf("disari cikamazsiniz!!!");
            }

            break;

        case 'd':

            if (y != 9)

            {

                y++;

                matris[x][y - 1] = 0;

                cerceve(matris, x, y);
            }

            else
            {

                printf("disari cikamazsiniz!!!");
            }

            break;
        }

        if (can == 0)

        {

            printf("\nmalesef kaybettiniz...");

            break;
        }

        if (sayac == 0)

        {

            printf("\noyunu kazandiniz...");
            break;
        }
    }

    return 0;
}

void cerceve(int matris[10][10], int x, int y)

{

    //system("cls");
    matris[x][y] = 1;

    printf("  ");

    for (int i = 0; i < 10; i++)

    {

        printf(" %d  ", i);
    }

    printf("\n");

    printf(" ");

    for (int i = 1; i <= 42; i++)

    {

        printf("*");
    }

    printf("\n");

    for (int i = 0; i < 10; i++)

    {

        printf("%d", i);

        printf("*");

        for (int j = 0; j < 10; j++)

        {

            printf("%d|", matris[i][j]);
        }

        printf("*");

        printf("\n");
    }

    printf(" ");

    for (int i = 1; i <= 42; i++)

    {

        printf("*");
    }

    elmasYeme(matris);

    printf("\n--caniniz:%d--\n", can);

    adres();

    mYakaladimi();
}

void elmasAtama(int matris[10][10])

{

    for (int i = 0; i < 5; i++)

    {
    
        matris[elmaslar_x[i]][elmaslar_y[i]] = 0;

        elmaslar_x[i] = rand() % 10;

        elmaslar_y[i] = rand() % 10;

        if (elmaslar_x[i] == 2 && elmaslar_y[i] == 4) // avcinin başlangic konumu ile elmasların cakimamasi icin .

        {
            i--;
            continue;
        }
    }

    for (int i = 0; i < 5; i++)

    {

        if (matris[elmaslar_x[i]][elmaslar_y[i]] != 0)

        {

            i--;
            continue;
        }

        matris[elmaslar_x[i]][elmaslar_y[i]] = 5;
    }
}

void muhafizAtama(int matris[10][10])

{

    for (int i = 0; i < 5; i++)

    {

        int muhafizDegerleri[3] = {-1, 0, 1};

        int k = rand() % 3;

        int l = rand() % 3;

        if (k == 1 && l == 1)
        {
            i--;
            continue;
        }
        if (elmaslar_x[i] == 0 && muhafizDegerleri[k]==-1 )
        {
            i--;
            continue;
        }
        if ( elmaslar_x[i] == 9 && muhafizDegerleri[k] == 1 )
        {
            i--;
            continue;
        }
        if (elmaslar_y[i] == 0 && muhafizDegerleri[l]==-1 )
        {
            i--;
            continue;
        }
        if ( elmaslar_y[i] == 9 && muhafizDegerleri[l] == 1)
        {
            i--;
            continue;
        }
        muhafizlar_x[i] = elmaslar_x[i] + muhafizDegerleri[k];
        muhafizlar_y[i] = elmaslar_y[i] + muhafizDegerleri[l];
        if (matris[muhafizlar_x[i]][muhafizlar_y[i]] != 0 || muhafizlar_x[i] == 2 && muhafizlar_y[i] == 4)
        {
            i--;
            continue;
        }
        matris[muhafizlar_x[i]][muhafizlar_y[i]] = 3;
    }
}

void elmasYeme(int matris[10][10])

{

    for (int i = 0; i < 5; i++)

    {

        if (elmaslar_x[i] == x && elmaslar_y[i] == y)

        {

            if (yedimmi[elmaslar_x[i]][elmaslar_y[i]] == 1)

            {

                yedimmi[elmaslar_x[i]][elmaslar_y[i]] = 0;

                sayac--;

                printf("\nelmas yediniz...");
            }
        }
    }
}

void adres()

{

    for (int i = 0; i < 5; i++)

    {

        if (yedimmi[elmaslar_x[i]][elmaslar_y[i]] == 1)

        {

            printf("\n%d.elmas:%d\n", i + 1, abs(x - elmaslar_x[i]) + abs(y - elmaslar_y[i]));
        }
    }
}

void mYakaladimi()

{

    for (int i = 0; i < 5; i++)

    {

        if (muhafizlar_x[i] == x && muhafizlar_y[i] == y)

        {

            can--;

            printf("\n\n\n \t\tmuhafiza yakalandiniz!!!\n\n\n\n\n");

            matris[muhafizlar_x[i]][muhafizlar_y[i]] = 0;

            x = 2;

            y = 4;

            cerceve(matris, x, y);
        }
    }
}
void sifirla()
{
    for (int i = 0; i < 5; i++)
    {
        matris[muhafizlar_x[i]][muhafizlar_y[i]]=0;
        matris[elmaslar_x[i]][elmaslar_y[i]]=0;
    }
}
