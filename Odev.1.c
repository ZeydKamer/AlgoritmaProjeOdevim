#include <stdio.h>
#include <string.h>

void sifrele(char metin[], int oteleme) {
    unsigned int uzunluk = strlen(metin);	// Dizinin Uzunluðunu tutacaðýmýz deðer
	
	// Þifreleme Bölümü
    int i;
    for (i = 0; i < uzunluk; i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + ((metin[i] - 'a' + oteleme % 26) + 26) % 26;
        }	// Eðer harf küçükse if bölümü, eðer harf büyükse else if bölümü kullanýlacak  
		else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + ((metin[i] - 'A' + oteleme % 26) + 26) % 26;
        }
    }
}

void sifreCoz(char metin[], int geriyeoteleme) {
    sifrele(metin, -geriyeoteleme);	// Þifre çözme algoritmasýnýn negatif hali
}

// Dosyaya yazma veya dosyaya okuma bölümü
char dosyaIslemleri(char metin[]) {
    FILE *dosya;
    int cevap;

    printf("Dosya olusturup okutmak icin : 1\nDosyayi okutmak icin : Herhangi Bir Tusa Basin \n");
    scanf("%d", &cevap);

    if (cevap == 1) {	// Cevaba göre okuyup yazma
        dosya = fopen("dosya.txt", "w");

        if (dosya == NULL) {
            printf("Dosya acilamadi\n");	// Dosyanýn doðruluðunu kontrol etme
            return 1;
        }

        printf("Lutfen dosyanin icerigini giriniz\n");
        scanf("%s", metin);					// Kullanýcýdan metni alma
        fprintf(dosya, "%s", metin);		// Alýnan metni dosyaya yazdýrma
        fclose(dosya);						// Dosyayý kapatma
    }

    dosya = fopen("dosya.txt", "r");		// Okuma iþlemi için dosyayý açma

    if (dosya == NULL) {
        printf("Dosya bulunamadi\n");
        return 2;
    }

    fscanf(dosya, "%s", metin);		// Dosyayý okuma ve metin'e atma
    fclose(dosya);

    return 0;
}

char sifreCozmeIslemi() {
    int otelememiktari, cevap;
    char metin[100];

    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz Herhangi Bir Tusa Basin\n");
    scanf("%d", &cevap);			//Kullanýcýnýn dosyayla mý yoksa normal yolla mý iþlem yapacaðýný sorgulama

    if (cevap == 1) {
        dosyaIslemleri(metin);

        if (strlen(metin) == 0) {	//Dosyayla yapýlacak iþlemde dosya bulunamadýysa sonlandýrma
            return 1;
        }
    } else {
        printf("Lutfen Kirilacak Sifreyi Girin\nSifrenin Max Uzunlugu 100 Karakter Olmalidir\n");	// Normal yolla yapýlacak iþlem için kullanýcýdan þifre alma 

        tekrariste:
        scanf("%s", metin);

        if (strlen(metin) > 100) {		// Girilen þifre 100 karakterden uzunsa þifreyi tekrar isteme
            printf("Sifre 100 Karakterden Buyuk Olamaz\n");
            goto tekrariste;
        }
    }

    printf("Lutfen Geri Oteleme Miktarini Giriniz\n");

    tekrarsayiiste:
    if (scanf("%d", &otelememiktari) != 1) {	// Kullanýcýdan ne kadar öteleme yapýlacaksa o miktarý almak ve girilenin sayý olup olmadýðýný kontrol etme 
        fflush(stdin);
        printf("Lutfen Sayi Giriniz\n");
        goto tekrarsayiiste;
    }
	
	// Alýnan verileri þifresini çözme iþlemi
    sifreCoz(metin, otelememiktari);
    printf("Sifresi cozulen metin: %s\n\n\n", metin);	// Þifresi çözülen metni yazma

    return 0;
}

char sifrelemeIslemi() {	// Þifreleme operasyonuyla ayný iþlemler
    char metin[100];
    int cevap, otelememiktari;

    printf("Islemi dosyayla yapacaksaniz 1\nYapmayacaksaniz farkli bir tusa basiniz\n");
    scanf("%d", &cevap);

    if (cevap == 1) {
        dosyaIslemleri(metin);

        if (strlen(metin) == 0) {
            return 1;
        }
    } else {
        printf("Lutfen sifrelenecek olan metni giriniz\n");

        tekrariste:
        scanf("%s", metin);

        if (strlen(metin) > 100) {
            printf("Metin 100 Karakterden Buyuk Olamaz\n");
            fflush(stdin);
            goto tekrariste;
        }
    }

    printf("Lutfen oteleme miktarini giriniz\n");

    tekrarsayiisteme:
    if (scanf("%d", &otelememiktari) != 1) {
        fflush(stdin);
        printf("Lutfen Sayi Giriniz\n");
        goto tekrarsayiisteme;
    }

    sifrele(metin, otelememiktari);
    printf("Sifrelenen metin: %s\n\n", metin);

    return 0;
}

int main() {
    int islem;

    printf("Lutfen yapmak istediginiz islemi secin:\n");	// Kullanýcýdan yapmasýný istediði iþlemi seçme

    tekrarsor:
    printf("1=Sifreleme\n"
           "2=SifreCozme\n"
           "3=Programi Sonlandirma\n");

    if (scanf("%d", &islem) != 1) {		// Girilen deðerin sayý olduðunu kontrol etme
        printf("Lutfen sadece sayi giriniz (Örnek: 1, 5, 8)\n");
        fflush(stdin);
        goto tekrarsor;
    }
	
	// Kullanýcýnýn seçtiði iþleme göre yapýlacak iþlemi seçme
    switch (islem) {
        case 1:
            sifrelemeIslemi();
            printf("Lutfen diger islemi seciniz\n");
            goto tekrarsor;
        case 2:
            sifreCozmeIslemi();
            printf("Lutfen diger islemi seciniz\n");
            goto tekrarsor;
        case 3:
            break;
        default:
            printf("Tanimsiz bir islem girdiniz\n\tLutfen tekrar deneyiniz\n");
            goto tekrarsor;
    }

    return 0;
}

