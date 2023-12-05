#include <stdio.h>
#include <string.h>

#define MAX_METIN_UZUNLUK 100

void sifrele(char metin[], int oteleme) {
    unsigned int uzunluk = strlen(metin);	// Dizinin Uzunluğunu tutacağımız değer
	
	int i;
    for (i = 0; i < uzunluk; i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + ((metin[i] - 'a' + oteleme % 26) + 26) % 26;
        }	// Eğer harf küçükse if bölümü, eğer harf büyükse else if bölümü kullanılacak 
	else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + ((metin[i] - 'A' + oteleme % 26) + 26) % 26;
        }
    }
}

void sifreCoz(char metin[], int geriyeoteleme) {
    sifrele(metin, -geriyeoteleme);	// Şifre çözme algoritmasının negatif hali
}

// Dosyaya yazma veya dosyaya okuma bölümü
int dosyaIslemleri(char metin[]) {
    FILE *dosya;
    int cevap;

    printf("Dosya olusturup okutmak icin: 1\nDosyayi okutmak icin: 0'a basiniz\n");

    while (1) {
        if (scanf("%d", &cevap) != 1) {
            printf("Gecersiz giris. Lutfen 1 veya 0 tusuna basiniz.\n");
            while (getchar() != '\n'); // Hatalı girişi temizle
            continue;
        }

        if (cevap == 1) {	// Cevaba göre okuyup yazma
            dosya = fopen("dosya.txt", "w");

            if (dosya == NULL) {	// Dosyanın doğruluğunu kontrol etme
                printf("Dosya acilamadi\n");
                return 0;
            }

            printf("Lutfen dosyanin icerigini giriniz\n");
            scanf("%s", metin);			// Kullanıcıdan metni alma
            fprintf(dosya, "%s", metin);	// Alınan metni dosyaya yazdırma
            fclose(dosya);			// Dosyayı kapatma
        }

        dosya = fopen("dosya.txt", "r");	// Okuma işlemi için dosyayı açma

        if (dosya == NULL) {
            printf("Dosya bulunamadi\n");
            return 0;
        }

        fscanf(dosya, "%s", metin);		// Dosyayı okuma ve metin'e atma
        fclose(dosya);

        return 1;
    }
}

int sifreCozmeIslemi() {
    int otelememiktari, cevap;
    char metin[MAX_METIN_UZUNLUK];

    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz 0'a basiniz\n");	//Kullanıcının dosyayla mı yoksa normal yolla mı işlem yapacağını sorgulama

    while (1) {
        if (scanf("%d", &cevap) != 1) {
            printf("Gecersiz giris. Lutfen 1 veya 0 tusuna basiniz.\n");
            while (getchar() != '\n'); // Hatalı girişi temizle
            continue;
        }

        if (cevap == 1) {
            dosyaIslemleri(metin);

            if (strlen(metin) == 0) {		//Dosyayla yapılacak işlemde dosya bulunamadıysa sonlandırma
                return 1;
            }
        } else {
            printf("Lutfen Kirilacak Sifreyi Girin\nSifrenin Max Uzunlugu 100 Karakter Olmalidir\n");	// Normal yolla yapılacak işlem için kullanıcıdan şifre alma 

            while (1) {
                if (scanf("%99[^\n]", metin) != 1) {
                    printf("Gecersiz giris. Lutfen tekrar deneyin.\n");
                    while (getchar() != '\n'); // Hatalı girişi temizle
                    continue;
                }

                if (strlen(metin) > MAX_METIN_UZUNLUK) {	// Girilen şifre MAX_METIN_UZUNLUK'tan uzunsa şifreyi tekrar isteme
                    printf("Metin %d karakterden buyuk olamaz\n", MAX_METIN_UZUNLUK);
                    continue;
                }

                break;
            }
        }

        printf("Lutfen Geri Oteleme Miktarini Giriniz\n");

        while (1) {
            if (scanf("%d", &otelememiktari) != 1) {		// Kullanıcıdan ne kadar öteleme yapılacaksa o miktarı almak ve girilenin sayı olup olmadığını kontrol etme 
                printf("Gecersiz giris. Lutfen sayi giriniz\n");
                while (getchar() != '\n'); // Hatalı girişi temizle
                continue;
            }

            break;
        }
	// Alınan verileri şifresini çözme işlemi
        sifreCoz(metin, otelememiktari);
        printf("Sifresi cozulen metin: %s\n\n\n", metin);	// Şifresi çözülen metni yazma

        return 0;
    }
}

int sifrelemeIslemi() {
    char metin[MAX_METIN_UZUNLUK];
    int cevap, otelememiktari;

    printf("Islemi dosyayla yapacaksaniz 1\nYapmayacaksaniz 0'a basiniz\n");

    while (1) {
        if (scanf("%d", &cevap) != 1) {
            printf("Gecersiz giris. Lutfen 1 veya 0 tusuna basiniz.\n");
            while (getchar() != '\n'); // Hatalı girişi temizle
            continue;
        }

        if (cevap == 1) {
            dosyaIslemleri(metin);

            if (dosyaIslemleri(metin) == 0) {
                return 1;
            }
        } else {
            printf("Lutfen sifrelenecek olan metni giriniz\n");

            while (1) {
                if (scanf("%99[^\n]", metin) != 1) {
                    printf("Gecersiz giris. Lutfen tekrar deneyin.\n");
                    while (getchar() != '\n'); // Hatalı girişi temizle
                    continue;
                }

                if (strlen(metin) > MAX_METIN_UZUNLUK) {
                    printf("Metin %d karakterden buyuk olamaz\n", MAX_METIN_UZUNLUK);
                    continue;
                }

                break;		// Geçerli giriş alındığında döngüden çık
            }
        }

        printf("Lutfen oteleme miktarini giriniz\n");

        while (1) {
            if (scanf("%d", &otelememiktari) != 1) {
                printf("Gecersiz giris. Lutfen sayi giriniz\n");
                while (getchar() != '\n'); // Hatalı girişi temizle
                continue;
            }

            break;		// Geçerli giriş alındığında döngüden çık
        }

        sifrele(metin, otelememiktari);
        printf("Sifrelenen metin: %s\n\n", metin);

        return 0;
    }
}

int main() {
    int islem;

    printf("Lutfen yapmak istediginiz islemi secin:\n");

    while (1) {
        printf("1=Sifreleme\n"
               "2=SifreCozme\n"
               "3=Programi Sonlandirma\n");

        if (scanf("%d", &islem) != 1) {
            printf("Lutfen sadece sayi giriniz (Ornek: 1, 2 veya 3)\n");
            while (getchar() != '\n'); // Hatalı girişi temizle
            continue;
        }

        switch (islem) {
            case 1:
                sifrelemeIslemi();
                printf("Lutfen diger islemi seciniz\n");
                break;
            case 2:
                sifreCozmeIslemi();
                printf("Lutfen diger islemi seciniz\n");
                break;
            case 3:
                return 0;
            default:
                printf("Tanimsiz bir islem girdiniz\n\tLutfen tekrar deneyiniz\n");
                break;
        }
    }
}
