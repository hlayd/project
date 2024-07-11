#include <stdio.h>
#include <string.h> //strcmp strcpy
#include <stdlib.h> //atoi atof

int main() {
    char isim[20];
    char akonum[] = "park";
    char motor[] = "kapalı";
    char sonuc;
    char sifre[20];
    char karar[2];
    int kilit = 0;
    int dogruSifre = 123;
    int sifreGirisHakki = 3;
    int konum = 0;
    int motorCalisiyor = 0;
    float sarj = 68.300;
    float sicaklik = -3.40;
    float mesafe = (sarj * 5.68);


    printf("Lütfen kullanıcı adı giriniz: ");
    scanf("%s", isim);

    if (strcmp(isim, "halil") != 0) {
        printf("Yanlış kullanıcı adı girdiniz. İyi günler dileriz.\n");
        return 0;
    }

    while (sifreGirisHakki > 0) {
        printf("Sayın %s, aracınızın uygulamasını açmak için şifrenizi giriniz (%d giriş hakkı): ", isim, sifreGirisHakki);
        scanf("%s", &sifre);

        if (atoi(sifre) == dogruSifre) {
            printf("Şifre doğru. Aracınızın durumu için devam edebilirsiniz.\n");
            while (1) {
                printf("Araç durumunuzu öğrenmek için 1, uygulamayı kapatmak için farklı bir sayı giriniz: ");
                scanf(" %c", &sonuc);

                if (sonuc == '1') {
                    printf("\n----------------------------------------------------------\nAracınızın Motoru %s\nAracınız %s konumunda, kapıları kilitli\nAracınızın şarj seviyesi %% %f\nMevcut şarj seviyesi ile gidilebilecek mesafe %.3f Km \nAraç içi sıcaklık %.2f°\n----------------------------------------------------------", motor, akonum, sarj, mesafe, sicaklik);
                    printf("\nAracınızı çalıştırmak/durdurmak için 1.\nAracınızı şarj etmek için 2.\nAraç içi sıcaklığı ayarlamak için 3.\nAraç konumunu Ev/Park olarak değiştirmek için 4.\nAracınızı açmak/kilitlemek için 5.\n----------------------------------------------------------\nYapmak istediğiniz işlemi seçiniz:");
                    scanf("%s", karar);

                    if (atoi(karar) >= 1 && atoi(karar) <= 5) {
                        switch (atoi(karar)) {
                            case 1:
                                if (!motorCalisiyor) {
                                    printf("Araç çalıştırılıyor...\n");
                                    motorCalisiyor = 1;
                                    strcpy(motor, "açık");
                                } else {
                                    printf("Araç kapatılıyor.\n");
                                    motorCalisiyor = 0;
                                    strcpy(motor, "kapalı");
                                }
                                break;
                            case 2:
                                printf("Aracınızın şarj seviyesi %% %f.\nlütfen yeni Şarj seviyesini giriniz: ", sarj);
                                char yeniSarj[32];
                                scanf("%s", &yeniSarj);
                                if (atof(yeniSarj) <= 100 && sarj < atof(yeniSarj)) {
                                    sarj = atof(yeniSarj);
                                    printf("Araç şarj ediliyor...\n");
                                } else {
                                    printf("Yanlış değer girdiniz. Değerler değişmedi.\n");
                                }
                                break;
                            case 3:
                                printf("Araç içi sıcaklığınız %.2f°, lütfen yeni sıcaklık değerini giriniz (4-24): ", sicaklik);
                                char yeniSicaklik[32];
                                scanf("%s", &yeniSicaklik);
                                if (atof(yeniSicaklik) <= 24 && atof(yeniSicaklik) >= 4) {
                                    sicaklik = atof(yeniSicaklik);
                                    sarj = sarj - 0.0026;

                                    printf("Araç içi sıcaklığınız:%.2f°\n", sicaklik);
                                } else {
                                    printf("Yanlış giriş yaptınız lütfen yeniden deneyin. Değerler değişmedi.\n");
                                }
                                break;
                            case 4:
                                if (!konum) {
                                    printf("Araç Çalıştırılıyor...\nAraç hareket halinde.\nAraç belirlenen 'ev' konumundadır.\nAraç kapatılıyor...\n");
                                    konum = 1;
                                    sarj = sarj - 0.0176;
                                    strcpy(akonum, "ev");
                                } else {
                                    printf("Araç Çalıştırılıyor...\nAraç hareket halinde.\nAraç belirlenen 'park' konumundadır.\nAraç kapatılıyor...\n");
                                    konum = 0;
                                    sarj = sarj - 0.0176;
                                    strcpy(akonum, "park");
                                }
                                break;
                            case 5:
                                if (!kilit) {
                                    printf("Araç kapıları açılıyor\n");
                                    kilit = 1;
                                } else {
                                    printf("Araç kapıları kilitleniyor.\n");
                                    kilit = 0;
                                }
                                break;
                        }
                    } else {
                        printf("Geçersiz bir seçenek girdiniz. Lütfen 1 ile 5 arasında bir değer girin.\n");
                    }
                } else {
                    break;
                }
                mesafe = sarj * 5.68;
            }
            break;
        } else {
            printf("Şifre yanlış. Kalan giriş hakkı: %d\n", --sifreGirisHakki);

            if (sifreGirisHakki == 0) {
                printf("Giriş hakkınız doldu. Uygulama kapatılıyor. İyi günler dileriz.\n");
                return 0;
            }
        }
    }
    printf("İyi günler dileriz.");
    return 0;
}
