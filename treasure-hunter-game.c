// author Mehmet TIRPAN
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>

int main(){
srand(time(NULL));
int x=2, y=4;


    int i,j=0;
    char matris[10][10];
        for(i=0; i<10; i++){
            for(j=0; j<10; j++){
                matris[i][j]=' ';
            }
        }











 //     5 adet elmasın ayrı ayrı atandığı bölüm --------------------------------------------------------------------------------------------------


        int a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
        a1 = rand() % 10;
        b1 = rand() % 10;
        if(((a1==a2)||(a1==a3)||(a1==a4)||(a1==a5))&&((b1==b2)||(b1==b3)||(b1==b4)||(b1==b5))){
        a1 = rand() % 10;
        b1 = rand() % 10;
        }
        else if ((a1==2) && (b1==4)){
        a1 = rand() % 10;
        b1 = rand() % 10;
        }
        matris[a1][b1] = 'e';


        a2 = rand() % 10;
        b2 = rand() % 10;
        if(((a1==a2)||(a2==a3)||(a2==a4)||(a2==a5))&&((b1==b2)||(b2==b3)||(b2==b4)||(b2==b5))){
        a2 = rand() % 10;
        b2 = rand() % 10;
        }
        else if ((a2==2) && (b2==4)){
        a2 = rand() % 10;
        b2 = rand() % 10;
        }
        matris[a2][b2] = 'e';


        a3 = rand() % 10;
        b3 = rand() % 10;
        if(((a3==a1)||(a3==a2)||(a3==a4)||(a3==a5))&&((b3==b1)||(b3==b2)||(b3==b4)||(b3==b5))){
        a3 = rand() % 10;
        b3 = rand() % 10;
        }
        else if ((a3==2) && (b3==4)){
        a3 = rand() % 10;
        b3 = rand() % 10;
        }
        matris[a3][b3] = 'e';


        a4 = rand() % 10;
        b4 = rand() % 10;
        if(((a4==a1)||(a4==a2)||(a4=a3)||(a4==a5))&&((b4==b1)||(b4==b2)||(b4==b3)||(b4==b5))){
        a4 = rand() % 10;
        b4 = rand() % 10;
        }
        else if ((a4==2) && (b4==4)){
        a4 = rand() % 10;
        b4 = rand() % 10;
        }
        matris[a4][b4] = 'e';


        a5 = rand() % 10;
        b5 = rand() % 10;
        if(((a5==a2)||(a5==a3)||(a5==a4)||(a1==a5))&&((b5==b2)||(b5==b3)||(b5==b4)||(b1==b5))){
        a5 = rand() % 10;
        b5 = rand() % 10;
        }
        else if ((a5==2) && (b5==4)){
        a5 = rand() % 10;
        b5 = rand() % 10;
        }
        matris[a5][b5] = 'e';
    

//-------------------------------------------------------------------------------------------------------------------------------------------------

//  Muhafız atamaları


//-------------------------------------------------------------------------------------------------------------------------------------------------


    while(1){
//-------------------------------------------------------------------------------------------------------------------------------------------------
        //  Uzaklık gösteren ekran

        int uzaklık1,uzaklık2,uzaklık3,uzaklık4,uzaklık5;
        printf("\n Uzaklıklar;");
            if ((x==a1)&&(y==b1)){
                printf("\n1.elmas Alındı");
            }
            else{
            uzaklık1 = abs(x-a1) + abs(y-b1);
            printf("\n elmas 1: %d", uzaklık1);
             }
            uzaklık2 = abs(x-a2) + abs(y-b2);
            printf("\n elmas 2: %d", uzaklık2);

             uzaklık3 = abs(x-a3) + abs(y-b3);
            printf("\n elmas 3: %d", uzaklık3);

             uzaklık4 = abs(x-a4) + abs(y-b4);
            printf("\n elmas 4: %d", uzaklık4);

             uzaklık5 = abs(x-a5) + abs(y-b5);
            printf("\n elmas 5: %d \n", uzaklık5);

//-------------------------------------------------------------------------------------------------------------------------------------------------
    matris[x][y] ='A';  // Avcı


    for(i=0;i<10;i++){
        for(int j=0; j<10; j++){
            printf("%c", matris[i][j]);
        }
        printf("\n");
    }
        

        printf("yön tuşlarına basınız\n(w-a-s-d);\n");
        printf("oyundan cikmak icin e tusuna basınız \n");
        char yon = getchar();

        matris[x][y] = ' ';   // matris hareket ettikten sonra arkasındaki satıra tekrardan boşluk atayan kod


//       matris alanı içerisine sınırlandırılmış switch komutları ---------------------------------------------------------------------------

        switch (yon) {
           case 'w' :
            if(x>0){
                x--;
            }
            else
            {
                printf("\nAlandan çıkılmaz");
            }
             break;
            
                
           case 'a' :
                if(y>0){
                    y--;
                }
                else
                {
                    printf("\nAlandan çıkılmaz");
                }
             break;
                
           case 's' :
            if(x<9){
                x++;
            }
            else
            {
                printf("\nAlandan çıkılmaz");
            }
             break;
                
            case 'd' :
            if(y<9){
                y++;
            }
            else
            {
                printf("\nAlandan çıkılmaz");
            }
             break;

            case 'e':
            return 1;
        }

    }
    return 0;
}

