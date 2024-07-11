#include <stdio.h>
#include<string.h>
int main() {
    char y[2];
    char e[] = "e";
    char h[] = "h";
    
    printf("yangın riski var mı? (e/h): ");
    scanf("%s",y);
    
    if (strcmp(y,h) == 0) {
        printf("bitir/n");
    } else {
        printf("yangın tüpünü al\n");
        printf("pim açık mı? (e/h): ");
        scanf("%s",y);
        if (strcmp(y,h) == 0) {
            printf("pimi çek\n");
        }
        if (strcmp(y,e) == 0 || strcmp(y,h) == 0) {
            printf("kayıt eden biri var mı? (e,h):");
            scanf("%s",y);
            printf("can riski var mı? (e/h): ");
            scanf("%s",y);
            if (strcmp(y,h)==1) {
                printf("bitir\n");
            } else {
                printf("kendini riske değer mi? (e/h): ");
                scanf("%s",y);
                if(strcmp(y,h)==0) {
                    printf("bitir\n");
                    } else {
                        printf("yangın başladı mı? (e/h): ");
                        scanf("%s",y);
                    if (strcmp(y,h)==0) {
                        printf("bitir\n");
                    } else {
                        int sayac;
                        printf("yangının derecesi kaç?: ");
                        scanf("%d",&sayac);
                        
                        for (int i= sayac; i>0;i--) {
                            printf("yangın tüpü sık\n");
                            printf("yangın derecesi bir azaltıldı\n");
                        }
                        printf("Bitir\n");
                    }
                }
            }
        }
    }
    return 0;
}