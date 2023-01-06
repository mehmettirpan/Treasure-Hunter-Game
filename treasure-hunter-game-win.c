#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <windows.h>//system cls icin

//sifirlama yapilmadan once kodun calismasini takip etmek icin elmaslara 5 , muhafizlara 3 atanmistir.
//daha sonrasidan sifirlama yapildigi icin tahtada 5 ve 3 ler gozukmemekdedir.


int x = 2, y = 4;//avcinin baslangic konumu

int matris[10][10];//tahtadaki 100 hucreyi olusturmak icin

int sayac = 5;//avcinin 5 kere elmas yemesi halinde kazandigini soylemek icin

int can = 3;//avcinin 3 kere muhafiza denk gelmesi halinde oyunu kaybettigini soylemek icin

void cerceve(int matris[10][10], int x , int y);//cerceveyi yazdiran fonksiyon

void elmasAtama(int matris[10][10]);//elmaslari atayan fonksiyon

void muhafizAtama(int matris[10][10]);//muhafizlari atayan fonksiyon

void mYakaladimi();//muhfizin uzerine gelip gelmediginizi kontrol eden fonksiyon

void adres();//adresleri hesaplayan fonksiyon

void elmasYeme(int matris[10][10]);//elmas yememizi kontrol eden fonksiyon

void sifirla();//elmaslari ve muhafizlari gizlemek icin uzerlerine sifir atayan fonksiyon

int elmaslar_x[5];//elmasların x konumlari matrisi

int elmaslar_y[5];//elmasların y konumlari matrisi

int muhafizlar_x[5];//muhafizlarin x konumlari matrisi

int muhafizlar_y[5];//muhafizlarin y konumlari matrisi

int yedimmi[10][10];//elmaslarin yenip yenmedigini kontrol etmek icin olusturdugumuz matris

void load();


int main()
{
    load();
    srand(time(NULL));//random atama icin

    for (int i = 0; i < 10; i++) // matris e deger atama

    {

        for (int j = 0; j < 10; j++)

        {

            matris[i][j] = 0;//matrisin tum elemanlarina 0 atadik
        }
    }

    elmasAtama(matris);
    muhafizAtama(matris);
    sifirla();

    for (int i = 0; i < 5; i++)

    {

        yedimmi[elmaslar_x[i]][elmaslar_y[i]] = 1;//yedimmi matrisindeki bes elmas konumunun degerine 1 atiyoruz.
    }

    cerceve(matris, x, y);

    while (can > 0)//can 0 lanana kadar calisacak

    {

        char tus;

        tus = getche();

        switch (tus)

        {

        case 'w':

            if (x != 0)//tahtanin disina tasma olmamasi icin

            {

                x--;

                matris[x + 1][y] = 0;//eski yerine sifir atiyoruz.

                cerceve(matris, x, y);
            }

            else
            {

                printf("\ndisari cikamazsiniz!!!");
            }

            break;

        case 'a':

            if (y != 0)//tahtanin disina tasma olmamasi icin

            {

                y--;

                matris[x][y + 1] = 0;//eski yerine sifir atiyoruz.

                cerceve(matris, x, y);
            }

            else
            {

                printf("\ndisari cikamazsiniz!!!");
            }

            break;

        case 's':

            if (x != 9)//tahtanin disina tasma olmamasi icin

            {

                x++;

                matris[x - 1][y] = 0;//eski yerine sifir atiyoruz.

                cerceve(matris, x, y);
            }

            else
            {

                printf("\ndisari cikamazsiniz!!!");
            }

            break;

        case 'd':

            if (y != 9)//tahtanin disina tasma olmamasi icin

            {

                y++;

                matris[x][y - 1] = 0;//eski yerine sifir atiyoruz.

                cerceve(matris, x, y);
            }

            else
            {

                printf("\ndisari cikamazsiniz!!!");
            }

            break;
        }

        if (can == 0)

        {
            system("cls");

            printf("\n\n\n\n\n\n\n\t\t\t\t\tMalesef Kaybettiniz...\n\n\n\n\n\n\n");

            break;
        }

        if (sayac == 0)

        {
            system("cls");

            printf("\n\n\n\n\n\n\n\t\t\t\t\tOyunu Kazandiniz...\n\n\n\n\n\n\n");
            break;
        }
    }

    return 0;
}

void load()
{
    int row,col,r,c,q;
    printf("\n\t\t\t\t\tAvci Oyununa Hos Geldiniz\n");
    printf("\n\n\n\n\n\n\n\t\t\t\t\tLoading...\n\t\t\t\t\t");
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); // Loading ekranının hızını ayarlar
        printf("%c",177);
    }
    printf("\n\t\t\t\t\t(Bir tusa bas)");

    getche();
}

void cerceve(int matris[10][10], int x, int y)

{

    system("cls");
    matris[x][y] = 1;

    printf("  ");

    for (int i = 0; i < 10; i++)

    {

        printf("%d ", i);
    }

    printf("\n");

    printf(" ");

    for (int i = 1; i <= 22; i++)

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

    for (int i = 1; i <= 22; i++)

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

        matris[elmaslar_x[i]][elmaslar_y[i]] = 0;//elmaslara  önce 0 atiyoruz

        elmaslar_x[i] = rand() % 10;//elmaslarin x ve y konumlarini rastgele aliyoruz

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

        matris[elmaslar_x[i]][elmaslar_y[i]] = 5;//sifirlamadan once kodun calismasini takip etmek icin elmaslara 5
        //atadik
    }
}

void muhafizAtama(int matris[10][10])

{

    for (int i = 0; i < 5; i++)

    {

        int muhafizDegerleri[3] = {-1, 0, 1};//muhafizlarimizin elmaslarin yaninda olmasi icin

        int k = rand() % 3;//randim 0 1 2 uretir

        int l = rand() % 3;

        if (k == 1 && l == 1)
        {
            i--;// eger bu if kosulu gerceklesir ise for dongusunde atama islemini tekararlamak icin
            continue;
        }
        if (elmaslar_x[i] == 0 && muhafizDegerleri[k]==-1 )//tahta disina muhafiz atmamamak icin
        {
            i--;
            continue;
        }
        if ( elmaslar_x[i] == 9 && muhafizDegerleri[k] == 1 )//tahta disina muhafiz atmamamak icin
        {
            i--;
            continue;
        }
        if (elmaslar_y[i] == 0 && muhafizDegerleri[l]==-1 )//tahta disina muhafiz atmamamak icin
        {
            i--;
            continue;
        }
        if ( elmaslar_y[i] == 9 && muhafizDegerleri[l] == 1)//tahta disina muhafiz atmamamak icin
        {
            i--;
            continue;
        }
        muhafizlar_x[i] = elmaslar_x[i] + muhafizDegerleri[k];//muhafizlarimizin elmaslarin yaninda olmasi icin
        muhafizlar_y[i] = elmaslar_y[i] + muhafizDegerleri[l];//muhafizlarimizin elmaslarin yaninda olmasi icin
        if (matris[muhafizlar_x[i]][muhafizlar_y[i]] != 0 || muhafizlar_x[i] == 2 && muhafizlar_y[i] == 4)
        {
            //muhafizi avcinin baslangic konumuna atamamak icin
            // ayrica daha onceden o konumda  baska bir sey var ise onun uzerine muhafiz atamamak icin

            i--;
            continue;
        }
        matris[muhafizlar_x[i]][muhafizlar_y[i]] = 3;//sifirlamayi yapmadan once tahtada kodun calismasini takip etmek
        //icin muhafizlara 3 atadik
    }
}

void elmasYeme(int matris[10][10])

{

    for (int i = 0; i < 5; i++)

    {

        if (elmaslar_x[i] == x && elmaslar_y[i] == y)

        {

            if (yedimmi[elmaslar_x[i]][elmaslar_y[i]] == 1)//eger avci elmasın ustune gelmis ve elmasda daha onceden //alinmamis sa o zaman elmasin yendigini soyleyen ve yenen elmasın yerine yedimmi matrisinde 0 atar

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

        if (yedimmi[elmaslar_x[i]][elmaslar_y[i]] == 1)//bes elmas konumu icin

        {

            printf("\n%d.elmas:%d\n", i + 1, abs(x - elmaslar_x[i]) + abs(y - elmaslar_y[i]));//uzaklıkları bulup //mutlağını yazdırıyoruz.
        }
    }
}

void mYakaladimi()

{

    for (int i = 0; i < 5; i++)//bes muhafiz oldugu icin

    {

        if (muhafizlar_x[i] == x && muhafizlar_y[i] == y)

        {

            can--;

            printf("\nmuhafiza yakalandiniz!!!\n");

            matris[muhafizlar_x[i]][muhafizlar_y[i]] = 0;

            x = 2;//tekrardan baslangic konumuna donmesi icin

            y = 4;

            cerceve(matris, x, y);
        }
    }
}
void sifirla()//muhafizlarin ve elmaslarin gorunmemesi icin uzerine 0 atiyoruz
{
    for (int i = 0; i < 5; i++)//bes muhafiz bes elmas var ondan
    {
        matris[muhafizlar_x[i]][muhafizlar_y[i]]=0;
        matris[elmaslar_x[i]][elmaslar_y[i]]=0;
    }
}