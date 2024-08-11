#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RESET "\x1B[0m"
#define BLUE "\x1B[34m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

void print(char arr[9]);
void toldirish(char arr[9]);
int cheking(char a[9], int i);
void tozalash();
int dastur(char arr[9], int yurish);
void harf(char a);

int main(){
    m3:
    tozalash();
    char arr[9];

    int i = 1, index;
    toldirish(arr);
    
    printf("Qanday o'ynamoqchisiz\n\n");
    printf("Do'st bilan o'ynash - 1\nDastur bilan o'ynash - 2\n");
    b:
    printf("\nBuyruqni kiriting = ");
    scanf("%d", &index);

    if(index == 1){
        // Do'st bilan o'ynash

        while(1){
            tozalash();
            print(arr);
            if(i % 2 == 1){
                printf("X ni navbati\n");
            }else{
                printf("O ni navbati\n");
            }
            m:
            printf("katakni kiritng = ");
            scanf("%d", &index);
            if(arr[index - 1] == 'X' ||arr[index - 1] == 'O'|| index > 9 || index < 1){
                printf("Ushbu katak band, qayta kiriting\n");
                goto m;
            }else{
                if(i % 2 == 1){
                    arr[index-1] = 'X';
                }else{
                    arr[index-1] = 'O';
                }
            }
            if(cheking(arr, i) == 0){
                tozalash();
                print(arr);
                printf("O'YIN TUGADI\nG'olib: X");
                break;
            }else if(cheking(arr, i) == 1){
                tozalash();
                print(arr);
                printf("O'YIN TUGADI\nG'olib: O");
                break;
            }else if(cheking(arr, i) == 2){
                tozalash();
                print(arr);
                printf("O'YIN TUGADI\nDURANG!");
                break;
            }
            ++i;
        }

    }else if(index == 2){
        // Dastur bilan o'ynash
        tozalash();
        while(1){
            
            
            if(i % 2 == 1){
                print(arr);
                printf("Sizni navbatingiz (X)\n");
                m2:
                printf("katakni kiritng = ");
                scanf("%d", &index);
                if(arr[index - 1] == 'X' ||arr[index - 1] == 'O'|| index > 9 || index < 1){
                printf("Ushbu katak band, qayta kiriting\n");
                goto m2;
                }
                arr[index-1] = 'X';
                tozalash();
            }else{
                printf("Dasturni navbati (O)\n");
                index = dastur(arr, i);
                printf("Dastur joyladi: katak - %d\n", index);
                arr[index - 1] = 'O';
                
            }
            
            
            if(cheking(arr, i) == 0){
                tozalash();
                print(arr);
                printf("O'YIN TUGADI\nG'olib: X");
                break;
            }else if(cheking(arr, i) == 1){
                tozalash();
                print(arr);
                printf("O'YIN TUGADI\nG'olib: O");
                break;
            }else if(cheking(arr, i) == 2){
                tozalash();
                print(arr);
                printf("O'YIN TUGADI\nDURANG!");
                break;
            }
            ++i;
        }

    }else{
        printf("Buyruq xato kiritildi qayta urinib ko'ring");
        goto b;
    }
        printf("\n\nYana o'ynaysizmi %c", (char)2);
        printf("\nHa - 1\nYo'q - 2\n");
        m4:
        printf("\nBuyruq = ");
        scanf("%d", &index);
        if(index == 1){
            goto m3;
        }else if(index == 2){
            return 0;
        }else{
            printf("Xato buyruq qayta urinib ko'ring\n");
            goto m4;
        }
}

void print(char arr[9]){
    printf(" _________________\n");
    printf("|     |     |     |\n");
    printf("|  ");
    harf(arr[0]);
    printf("  |  ");
    harf(arr[1]);
    printf("  |  ");
    harf(arr[2]);
    printf("  |\n");
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  ");
    harf(arr[3]);
    printf("  |  ");
    harf(arr[4]);
    printf("  |  ");
    harf(arr[5]);
    printf("  |\n");
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  ");
    harf(arr[6]);
    printf("  |  ");
    harf(arr[7]);
    printf("  |  ");
    harf(arr[8]);
    printf("  |\n");
    printf("|_____|_____|_____|\n");
}   
void toldirish(char arr[9]){
    for(int i = 1; i <= 9; i++){
        arr[i - 1] = (char)(i + 48);
    }
}
int cheking(char a[9], int i){
    if(a[0] == 'X' && a[1] == 'X' && a[2] == 'X'||
       a[3] == 'X' && a[4] == 'X' && a[5] == 'X'||
       a[6] == 'X' && a[7] == 'X' && a[8] == 'X'||
       a[0] == 'X' && a[3] == 'X' && a[6] == 'X'||
       a[1] == 'X' && a[4] == 'X' && a[7] == 'X'||
       a[2] == 'X' && a[5] == 'X' && a[8] == 'X'||
       a[0] == 'X' && a[4] == 'X' && a[8] == 'X'||
       a[2] == 'X' && a[4] == 'X' && a[6] == 'X'){
        return 0;
    }else if(a[0] == 'O' && a[1] == 'O' && a[2] == 'O'||
       a[3] == 'O' && a[4] == 'O' && a[5] == 'O'||
       a[6] == 'O' && a[7] == 'O' && a[8] == 'O'||
       a[0] == 'O' && a[3] == 'O' && a[6] == 'O'||
       a[1] == 'O' && a[4] == 'O' && a[7] == 'O'||
       a[2] == 'O' && a[5] == 'O' && a[8] == 'O'||
       a[0] == 'O' && a[4] == 'O' && a[8] == 'O'||
       a[2] == 'O' && a[4] == 'O' && a[6] == 'O'){
        return 1;
    }else if(i == 9){
        return 2;
    }else{
        return 3;
       }
}
void tozalash(){
    system("cls || clear");
}
void harf(char a){
    if(a == 'X'){
        printf(RED "X" RESET);
    }else if(a == 'O'){
        printf(BLUE "O" RESET);
    }else{
        printf(GREEN "%c" RESET, a);
    }
}
int dastur(char arr2[9], int yurish){
    char arr[9];
    for(int i = 0; i < 9; i++){
        arr[i] = arr2[i];
    }
    // 1-darajali yutish tekshiruvi
    for(int i = 0; i < 9; i++){
       if(arr[i] != 'X' && arr[i] != 'O'){
            arr[i] = 'O';
            if(cheking(arr, yurish) == 1||cheking(arr, yurish) == 2){
                return i + 1;
            }else{
                arr[i] = '0';
            }
       }
    }

    // 1-darajali bloklash tekshiruvi
    for(int i = 0; i < 9; i++){
       if(arr[i] != 'X' && arr[i] != 'O'){
            arr[i] = 'X';
            if(cheking(arr, yurish) == 0||cheking(arr, yurish) == 2){
                return i + 1;
            }else{
                arr[i] = '0';
            }
       }
    }

    // 2 - darajali yutish tekshiruvi
    {
        int max = 0, extimol = 0, qaytish = 0;
        
        for (int i = 0; i < 9; i++)
        {
            if(arr[i] != 'X' && arr[i] != 'O'){
                arr[i] = 'O';
                for (int j = 0; j < 9; j++)
                {
                    if(arr[j] != 'X' && arr[j] != 'O'){
                        arr[j] = 'O';
                        if(cheking(arr, 0) == 1){
                            ++extimol;
                        }
                        arr[j] = '0';
                    }
                }
                arr[i] = '0';

                if(extimol > max){
                    max = extimol;
                    qaytish = i + 1;
                }
                extimol = 0;
            }
            
        }
        if(qaytish > 0){
            return qaytish;
        }
    }
    
    // 3 - darajali yutish tekshiruvi
    {
    int max = 0, extimol = 0, qaytish = 0;
    
        for (int  i = 0; i < 9; i++)
        {
            if(arr[i] != 'X' && arr[i] != 'O'){
                arr[i] = 'O';
                for (int j = 0; j < 9; j++)
                {
                    if(arr[j] != 'X' && arr[j] != 'O'){
                        arr[j] = 'O';
                        for (int k = 0; k < 9; k++)
                        {
                            if(arr[k] != 'X' && arr[k] != 'O'){
                                arr[k] = 'O';
                                if(cheking(arr, 0) == 1){
                                    ++extimol;
                                }
                                arr[k] = '0';
                            }
                        }
                        arr[j] = '0';
                    }
                }
                arr[i] = '0';

                if(extimol > max){
                    max = extimol;
                    qaytish = i + 1;
                }
                extimol = 0;
            }
        }
        return qaytish;
        
    }
}