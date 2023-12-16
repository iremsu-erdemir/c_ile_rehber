#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <clocale>


#define N 10

struct personel_tip {
    char isim[16];
    char soyisim[16];
    float maas;
    int baslama_yili;
    char il[20];
    char telefon[16]; // Telefon numarası eklendi
};

void Buff_sil(void) {
    while (getchar() != '\n');
}

void menu(void);
void ekle(void);
void ara(void);
void listele(void);
void guncelle(void);
void sil(void);

typedef struct personel_tip tip;
tip kisi[N];
int mevcut = 0;

int main() {
    setlocale(LC_ALL, "Turkish");

    do {
        menu();
    } while (1);

    // Bu kısım asla çalışmayacak, sonsuz döngü nedeniyle.
    // system("pause");
    return 0;
}

void menu(void) {
    char secim;
    system("cls");
    printf("     MENU             %d\n", mevcut);
    printf("1-Kayıt Ekle\n");
    printf("2-Kayıt Ara\n");
    printf("3-Kayıt Listele\n");
    printf("4-Kayıt Güncelle\n");
    printf("5-Kayıt Sil\n");
    printf("6-Çıkış\n");
    printf("Seçiminiz(1/2/3/4/5/6): ");

    do {
        secim = getchar();

        // Eğer kullanıcı geçersiz bir seçenek girdiyse
        if (!(secim >= '1' && secim <= '6')) {
            printf("Lütfen geçerli bir seçenek giriniz (1-6): ");
        }

    } while (!(secim >= '1' && secim <= '6'));

    printf("\n");

    switch (secim) {
    case '1': ekle(); break;
    case '2': ara(); break;
    case '3': listele(); break;
    case '4': guncelle(); break;
    case '5': sil(); break;
    case '6': {
        printf("\nÇıktınız.\n");
        system("pause");
        exit(0);
    }
    }
}

void ekle(void) {
    if (mevcut != N) {
        system("cls");
        printf("%d. indisli konuma saklanacak olan kişinin bilgilerini gir :\n", mevcut);
        printf("Ad : "); scanf("%s", kisi[mevcut].isim);
        printf("Soyad :"); scanf("%s", kisi[mevcut].soyisim);
        printf("İli :"); scanf("%s", kisi[mevcut].il);
        printf("İşe başlama yılı :"); scanf("%d", &kisi[mevcut].baslama_yili);
        Buff_sil();
        printf("Maaşı : "); scanf("%f", &kisi[mevcut].maas);
        Buff_sil();
        printf("Telefon : "); scanf("%s", kisi[mevcut].telefon); // Telefon numarasını ekledik
        Buff_sil();
        ++mevcut;
        printf("Kayıtlı kişi adedi : %d\n\n", mevcut);
        system("pause");
    }
    else {
        printf("Dizi dolu.\n");
        system("pause");
    }
}

void ara(void) {
    char aranan_isim[16];
    int bulunan = 0;

    system("cls");
    printf("Aranacak kişinin adını girin: ");
    scanf("%s", aranan_isim);

    for (int i = 0; i < mevcut; i++) {
        if (strcmp(aranan_isim, kisi[i].isim) == 0) {
            printf("Bulunan Kişi:\n");
            printf("Ad: %s\n", kisi[i].isim);
            printf("Soyad: %s\n", kisi[i].soyisim);
            printf("İl: %s\n", kisi[i].il);
            printf("İşe Başlama Yılı: %d\n", kisi[i].baslama_yili);
            printf("Maaş: %.2f\n", kisi[i].maas);
            printf("Telefon: %s\n", kisi[i].telefon); // Telefon numarasını ekledik
            printf("-------------------------\n");
            bulunan = 1;
        }
    }

    if (!bulunan) {
        printf("Kişi bulunamadı.\n");
    }

    printf("\n");
    system("pause");
}

void listele(void) {
    if (mevcut == 0) {
        printf("Listelenecek kayıt bulunmamaktadır.\n");
    }
    else {
        system("cls");
        printf("     KAYIT LISTESI\n");
        printf("-------------------------\n");
        for (int i = 0; i < mevcut; i++) {
            printf("Kişi %d:\n", i + 1);
            printf("Ad: %s\n", kisi[i].isim);
            printf("Soyad: %s\n", kisi[i].soyisim);
            printf("İl: %s\n", kisi[i].il);
            printf("İşe Başlama Yılı: %d\n", kisi[i].baslama_yili);
            printf("Maaş: %.2f\n", kisi[i].maas);
            printf("Telefon: %s\n", kisi[i].telefon); // Telefon numarasını ekledik
            printf("-------------------------\n");
        }
    }
    printf("\n");
    system("pause");
}

void guncelle(void) {
    if (mevcut == 0) {
        printf("Güncellenecek kayıt bulunmamaktadır.\n");
    }
    else {
        system("cls");
        printf("     KAYIT GÜNCELLEME\n");
        printf("-------------------------\n");

        char aranan_isim[16];
        printf("Güncellenecek kişinin adını girin: ");
        scanf("%s", aranan_isim);

        int bulunan = 0;
        for (int i = 0; i < mevcut; i++) {
            if (strcmp(aranan_isim, kisi[i].isim) == 0) {
                printf("Kişi Bulundu, Yeni Bilgileri Girin:\n");
                printf("Ad: "); scanf("%s", kisi[i].isim);
                printf("Soyad: "); scanf("%s", kisi[i].soyisim);
                printf("İl: "); scanf("%s", kisi[i].il);
                printf("İşe Başlama Yılı: "); scanf("%d", &kisi[i].baslama_yili);
                Buff_sil();
                printf("Maaş: "); scanf("%f", &kisi[i].maas);
                Buff_sil();
                printf("Telefon: "); scanf("%s", kisi[i].telefon); // Telefon numarasını ekledik
                Buff_sil();
                bulunan = 1;
                break; // Güncelleme yapıldı, döngüden çık
            }
        }

        if (!bulunan) {
            printf("Kişi bulunamadı.\n");
        }
        else {
            printf("Kişi başarıyla güncellendi.\n");
        }
    }
    printf("\n");
    system("pause");
}

void sil(void) {
    if (mevcut == 0) {
        printf("Silinecek kayıt bulunmamaktadır.\n");
    }
    else {
        system("cls");
        printf("     KAYIT SILME\n");
        printf("-------------------------\n");

        char silinecek_isim[16];
        printf("Silinecek kişinin adını girin: ");
        scanf("%15s", silinecek_isim);  // Use scanf to get the name input

        int bulunan = 0;
        for (int i = 0; i < mevcut; i++) {
            if (strcmp(silinecek_isim, kisi[i].isim) == 0) {
                printf("Kişi Bulundu ve Silinecek:\n");
                printf("Ad: %s\n", kisi[i].isim);
                printf("Soyad: %s\n", kisi[i].soyisim);
                printf("İl: %s\n", kisi[i].il);
                printf("İşe Başlama Yılı: %d\n", kisi[i].baslama_yili);
                printf("Maaş: %.2f\n", kisi[i].maas);
                printf("Telefon: %s\n", kisi[i].telefon); // Telefon numarasını ekledik
                printf("-------------------------\n");

                // Kişiyi sil
                for (int j = i; j < mevcut - 1; j++) {
                    kisi[j] = kisi[j + 1];
                }

                // Son kişinin bilgilerini temizle
                strcpy(kisi[mevcut - 1].isim, "");
                strcpy(kisi[mevcut - 1].soyisim, "");
                strcpy(kisi[mevcut - 1].il, "");
                kisi[mevcut - 1].baslama_yili = 0;
                kisi[mevcut - 1].maas = 0;
                strcpy(kisi[mevcut - 1].telefon, ""); // Telefon numarasını ekledik

                mevcut--;

                printf("Kişi başarıyla silindi.\n");
                bulunan = 1;
                break; // Silme işlemi tamamlandı, döngüden çık
            }
        }

        if (!bulunan) {
            printf("Kişi bulunamadı.\n");
        }
    }
    printf("\n");
    system("pause");
}
