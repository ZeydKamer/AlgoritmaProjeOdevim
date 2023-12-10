# AlgoritmaProjeOdevim
# Ön Bilgi
- Ben bu kodu Dev-C++ 5.11 C programı ile yazdım. Başka bir program kullanacaksanız hatalar verebilir ve kodun çalışmasını görebilmek için düzenlemeniz gerekmektedir.
## Program Hakkında Genel Bilgiler
- Yazdığım şifreleme programı girdiğiniz tam sayı Kadar girdiğiniz metni ileri ya da geriye doğru ötelemektedir.
- Programı çalıştırdığınızda 3 adet seçenek göreceksiniz Şifreleme, Deşifreleme ve Programı Sonlandırma seçenekleridir.
- Eğer dosyadan okuma yapmak veya dosyaya yazma işlemlerini yapmak istiyorsanız program sizi yönlendirecektir. Dosyadalar da aynı şekilde yazdığım kurallara uyacak şekilde yazılmıştır.

**Not:** Program, sadece İngiliz alfabesini içerir. Türkçe veya tanımlı olmayan karakterleri kullandığınızda hata alabilir veya öteleme işlemi beklenildiği gibi gerçekleşmeyebilir.
## İşlemlerin Kullanımı
- Sifreleme işlemi metni girdiğiniz sayı kadar alfabe sınırları içerisinde ileriye öteleme yapar. Örneğin siz "MerhabaDunya" metnini girerseniz ve öteleme miktarı olarak da 4 sayısını - girerseniz kod size "QivlefeHyrce" metnini verir.
- Bu çıktı da sizin girmiş olduğunuz metnin her bir harfinin 4 kez ileriye ötelenmiş halidir.
- Sifrecozme işlemi metne girdiğiniz sayı kadar alfabe sınırları içerisinde geri öteler.
- Yani tekrardan anlaşılması açısından yukarıda verdiğim örneği kullanırsak ve şifreyi tekrar anlamlı bir metne dönüştürmek istersek "QivlefeHyrce" metninin her bir harfini 4 kez geri ötelemeniz gerekir.
- Buna göre programda Sifrecozme işlemini seçtiğimizde, "QivlefeHyrce" metnini yazdığımızda ve öteleme miktarını 4 olarak girerseniz kod size "MerhabaDunya" metnini verir.
## Dosyaları Okuma ve Yazma
- Aynı dosya okuma ve yazma işlemleri için hem Sifreleme hem de Sifrecozme işlemleri çalışmaktadır.
- Eğer ki bir dosyanız yoksa dosya oluşturma seçeneğini seçerek kodunuz için bir 'dosya.txt' dosyası oluşturulacaktır.
- Kendi dosyanızı oluşturmak için main.exe'nin olduğu klasörden kendiniz dosyanızı oluşturabilirsiniz.
- Kendi oluşturduğunuz farklı isimdeki bir dosyayı okutabilmek için yazdığım kodun içindeki dosyayı ( dosya.txt )'yi kendiniz değiştirebilirsiniz.
## Kod İçeriği
#include <stdio.h>
#include <string.h>

void sifrele(char metin[], int oteleme) {
    unsigned int uzunluk = strlen(metin);	// Dizinin Uzunluğunu tutacağımız değer
	
	// Şifreleme Bölümü
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
char dosyaIslemleri(char metin[]) {
    FILE *dosya;
    int cevap;

    printf("Dosya olusturup okutmak icin : 1\nDosyayi okutmak icin : 0'a basiniz \n");
    scanf("%d", &cevap);

    if (cevap == 1) {	// Cevaba göre okuyup yazma
        dosya = fopen("dosya.txt", "w");

        if (dosya == NULL) {
            printf("Dosya acilamadi\n");	// Dosyanın doğruluğunu kontrol etme
            return 1;
        }

        printf("Lutfen dosyanin icerigini giriniz\n");
        scanf("%s", metin);					// Kullanıcıdan metni alma
        fprintf(dosya, "%s", metin);		// Alınan metni dosyaya yazdırma
        fclose(dosya);						// Dosyayı kapatma
    }

    dosya = fopen("dosya.txt", "r");		// Okuma işlemi için dosyayı açma

    if (dosya == NULL) {
        printf("Dosya bulunamadi\n");
        return 2;
    }

    fscanf(dosya, "%s", metin);		// Dosyayı okuma ve metin'e atma
    fclose(dosya);

    return 0;
}

char sifreCozmeIslemi() {
    int otelememiktari, cevap;
    char metin[100];

    printf("Islemi dosya ile yapacaksaniz 1\nYapmayacaksaniz 0 tusuna basiniz\n");
    scanf("%d", &cevap);			//Kullanıcının dosyayla mı yoksa normal yolla mı işlem yapacağını sorgulama

    if (cevap == 1) {
        dosyaIslemleri(metin);

        if (strlen(metin) == 0) {	//Dosyayla yapılacak işlemde dosya bulunamadıysa sonlandırma
            return 1;
        }
    } else {
        printf("Lutfen kirilacak sifreyi girin\nSifrenin max uzunlugu 100 karakter olmalidir\n");	// Normal yolla yapılacak işlem için kullanıcıdan şifre alma 

        tekrariste:
        scanf("%s", metin);

        if (strlen(metin) > 100) {		// Girilen şifre 100 karakterden uzunsa şifreyi tekrar isteme
            printf("Sifre 100 karakterden buyuk olamaz\n");
            goto tekrariste;
        }
    }

    printf("Lutfen geri oteleme miktarini giriniz\n");

    tekrarsayiiste:
    if (scanf("%d", &otelememiktari) != 1) {	// Kullanıcıdan ne kadar öteleme yapılacaksa o miktarı almak ve girilenin sayı olup olmadığını kontrol etme 
        fflush(stdin);
        printf("Lutfen Sayi Giriniz\n");
        goto tekrarsayiiste;
    }
	
	// Alınan verileri şifresini çözme işlemi
    sifreCoz(metin, otelememiktari);
    printf("Sifresi cozulen metin: %s\n\n\n", metin);	// Şifresi çözülen metni yazma

    return 0;
}

char sifrelemeIslemi() {	// Şifreleme operasyonuyla aynı işlemler
    char metin[100];
    int cevap, otelememiktari;

    printf("Islemi dosyayla yapacaksaniz 1\nYapmayacaksaniz 0 tusuna basiniz\n");
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
            printf("Metin 100 karakterden buyuk olamaz\n");
            fflush(stdin);
            goto tekrariste;
        }
    }

    printf("Lutfen oteleme miktarini giriniz\n");

    tekrarsayiisteme:
    if (scanf("%d", &otelememiktari) != 1) {
        fflush(stdin);
        printf("Lutfen sayi giriniz\n");
        goto tekrarsayiisteme;
    }

    sifrele(metin, otelememiktari);
    printf("Sifrelenen metin: %s\n\n", metin);

    return 0;
}

int main() {
    int islem;

    printf("Lutfen yapmak istediginiz islemi secin:\n");	// Kullanıcıdan yapmasını istediği işlemi seçme

    tekrarsor:
    printf("1=Sifreleme\n"
           "2=SifreCozme\n"
           "3=Programi Sonlandirma\n");

    if (scanf("%d", &islem) != 1) {		// Girilen değerin sayı olduğunu kontrol etme
        printf("Lutfen sadece sayi giriniz (Örnek: 1, 5, 8)\n");
        fflush(stdin);
        goto tekrarsor;
    }
	
	// Kullanıcının seçtiği işleme göre yapılacak işlemi seçme
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

