#include <stdio.h>
#include <string.h>

void sifrele(char metin[], int oteleme) {
    unsigned int uzunluk = strlen(metin);	// Dizinin Uzunlu�unu tutaca��m�z de�er
	
	// �ifreleme B�l�m�
    int i;
    for (i = 0; i < uzunluk; i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + ((metin[i] - 'a' + oteleme % 26) + 26) % 26;
        }	// E�er harf k���kse if b�l�m�, e�er harf b�y�kse else if b�l�m� kullan�lacak  
		else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + ((metin[i] - 'A' + oteleme % 26) + 26) % 26;
        }
    }
}

void sifreCoz(char metin[], int geriyeoteleme) {
    sifrele(metin, -geriyeoteleme);	// �ifre ��zme algoritmas�n�n negatif hali
}

// Dosyaya yazma veya dosyaya okuma b�l�m�
char dosyaIslemleri(char metin[]) {
    FILE *dosya;
    int cevap;

    printf("Dosya olusturup okutmak icin : 1\nDosyayi okutmak icin : Herhangi Bir Tusa Basin \n");
    scanf("%d", &cevap);

    if (cevap == 1) {	// Cevaba g�re okuyup yazma
        dosya = fopen("dosya.txt", "w");

        if (dosya == NULL) {
            printf("Dosya acilamadi\n");	// Dosyan�n do�rulu�unu kontrol etme
            return 1;
        }

        printf("Lutfen dosyanin icerigini giriniz\n");
        scanf("%s", metin);					// Kullan�c�dan metni alma
        fprintf(dosya, "%s", metin);		// Al�nan metni dosyaya yazd�rma
        fclose(dosya);						// Dosyay� kapatma
    }

    dosya = fopen("dosya.txt", "r");		// Okuma i�lemi i�in dosyay� a�ma

    if (dosya == NULL) {
        printf("Dosya bulunamadi\n");
        return 2;
    }

    fscanf(dosya, "%s", metin);		// Dosyay� okuma ve metin'e atma
    fclose(dosya);

    return 0;
}

char sifreCozmeIslemi() {
    int otelememiktari, cevap;
    char metin[100];

    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz Herhangi Bir Tusa Basin\n");
    scanf("%d", &cevap);			//Kullan�c�n�n dosyayla m� yoksa normal yolla m� i�lem yapaca��n� sorgulama

    if (cevap == 1) {
        dosyaIslemleri(metin);

        if (strlen(metin) == 0) {	//Dosyayla yap�lacak i�lemde dosya bulunamad�ysa sonland�rma
            return 1;
        }
    } else {
        printf("Lutfen Kirilacak Sifreyi Girin\nSifrenin Max Uzunlugu 100 Karakter Olmalidir\n");	// Normal yolla yap�lacak i�lem i�in kullan�c�dan �ifre alma 

        tekrariste:
        scanf("%s", metin);

        if (strlen(metin) > 100) {		// Girilen �ifre 100 karakterden uzunsa �ifreyi tekrar isteme
            printf("Sifre 100 Karakterden Buyuk Olamaz\n");
            goto tekrariste;
        }
    }

    printf("Lutfen Geri Oteleme Miktarini Giriniz\n");

    tekrarsayiiste:
    if (scanf("%d", &otelememiktari) != 1) {	// Kullan�c�dan ne kadar �teleme yap�lacaksa o miktar� almak ve girilenin say� olup olmad���n� kontrol etme 
        fflush(stdin);
        printf("Lutfen Sayi Giriniz\n");
        goto tekrarsayiiste;
    }
	
	// Al�nan verileri �ifresini ��zme i�lemi
    sifreCoz(metin, otelememiktari);
    printf("Sifresi cozulen metin: %s\n\n\n", metin);	// �ifresi ��z�len metni yazma

    return 0;
}

char sifrelemeIslemi() {	// �ifreleme operasyonuyla ayn� i�lemler
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

    printf("Lutfen yapmak istediginiz islemi secin:\n");	// Kullan�c�dan yapmas�n� istedi�i i�lemi se�me

    tekrarsor:
    printf("1=Sifreleme\n"
           "2=SifreCozme\n"
           "3=Programi Sonlandirma\n");

    if (scanf("%d", &islem) != 1) {		// Girilen de�erin say� oldu�unu kontrol etme
        printf("Lutfen sadece sayi giriniz (�rnek: 1, 5, 8)\n");
        fflush(stdin);
        goto tekrarsor;
    }
	
	// Kullan�c�n�n se�ti�i i�leme g�re yap�lacak i�lemi se�me
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

