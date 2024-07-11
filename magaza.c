#include <stdio.h>
#include <string.h>

int main() {
    char ad[20];
    char ayakkabiTuru[20];
    int cinsiyet, ayakkabiNumara;

    printf("Mağazamıza hoş geldiniz\n");
    printf("Lütfen adınızı paylaşabilir misiniz: ");
    scanf("%s", ad);
    printf("Lütfen cinsiyetinizi belirtiniz. Kadın için 1'e, erkek için 2'ye sayısını giriniz: ");
    scanf("%d", &cinsiyet);

    // Cinsiyet kontrolü
    if (cinsiyet != 1 && cinsiyet != 2) {
        printf("Geçersiz cinsiyet seçimi. Lütfen 1 veya 2 giriniz.\n");
        return 1; // Programı hemen sonlandır
    }

    printf("Çizmeler için C, Botlar için B, Klasik ayakkabılar için D karakterini giriniz: ");
    scanf("%s", ayakkabiTuru);

    // Ayakkabi turunu kontrol et ve B, C veya D harfi girildiyse ilgili isime cevir
    if (strcmp(ayakkabiTuru, "B") == 0) {
        strcpy(ayakkabiTuru, "Bot");
    } else if (strcmp(ayakkabiTuru, "C") == 0) {
        strcpy(ayakkabiTuru, "Çizme");
    } else if (strcmp(ayakkabiTuru, "D") == 0) {
        strcpy(ayakkabiTuru, "Klasik Ayakkabı");
    } else {
        printf("Geçersiz ayakkabi turu. Lutfen B, C veya D giriniz.\n");
        return 1; // Programı hemen sonlandır
    }

    printf("Lütfen ayakkabı numaranızı belirtiniz (%s için uygun aralık): ", (cinsiyet == 1) ? "35-41" : "39-46");
    scanf("%d", &ayakkabiNumara);

    // Kullanıcıya farklı bir ayakkabı türü seçme şansı vermek
    printf("Yeni bir ayakkabı türü seçmek ister misiniz? (Evet için 1, Hayır için 0): ");
    int yeniSecim;
    scanf("%d", &yeniSecim);

    if (yeniSecim == 1) {
        printf("Yeni ayakkabı türünü giriniz: ");
        scanf("%s", ayakkabiTuru);
    }

    // Kullanıcı 1 girdiğinde "kadın" yazdırma
    printf("Sayın %s, %s bölümünden, %s reyonundan, %d numaralı ayakkabı seçiminiz kaydedilmiştir. Doğru ise 7, yanlış ise 8 tuşuna basınız.", ad, (cinsiyet == 1) ? "kadın" : "erkek", ayakkabiTuru, ayakkabiNumara);

    return 0;
}
