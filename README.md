# AlgoritmaProjeOdevim
## Program Hakkında Genel Bilgiler
- Yazdığım şifreleme programı girdiğiniz tam sayı Kadar girdiğiniz metni ileri ya da geriye doğru ötelemektedir.
- Programı çalıştırdığınızda 3 adet seçenek göreceksiniz Şifreleme, Deşifreleme ve Programı Sonlandırma seçenekleridir.
- Eğer dosyadan okuma yapmak veya dosyaya yazma işlemlerini yapmak istiyorsanız program sizi yönlendirecektir. Dosyadalar da aynı şekilde yazdığım kurallara uyacak şekilde yazılmıştır.

**Not:** Program, sadece İngiliz alfabesini içerir. Türkçe veya tanımlı olmayan karakterleri kullandığınızda hata alabilir veya öteleme işlemi beklenildiği gibi gerçekleşmeyebilir.
## İşlemlerin Kullanımı
- Sifreleme işlemi metni girdiğiniz sayı kadar alfabe sınırları içerisinde ileriye öteleme yapar. Örneğin siz "MerhabaDunya" metnini girerseniz ve öteleme miktarı olarak da 4 sayısını - girerseniz kod size "QivlefeHyrce" metnini verir.
- Bu çıktı da sizin girmiş olduğunuz metnin her bir harfinin 4 kez ileriye ötelenmiş halidir.
- Sifrecozme işlemi metne girdiğiniz sayı kadar alfabe sınırları içerisinde geri öteler.
- Yani tekrardan anlaşılması açısından yukarıda verdiğim örneği kullanırsak ve şifreyi tekrar anlamlı bir metne dönüştürmek istersek "QivlefeHyrce" metninin her bir harfini 4 kez geri ötelememiz gerekir.
- Buna göre programda Sifrecozme işlemini seçtiğimizde, "M_no_uyn_ikjsiybew" metnini yazdığımızda ve öteleme miktarını 4 olarak girerseniz kod size "MerhabaDunya" metnini verir.
- Başka bir örnek olarak
## Dosyaları Okuma ve Yazma
- Aynı dosya okuma ve yazma işlemleri için hem Sifreleme hem de Sifrecozme işlemleri çalışmaktadır.
- Eğer ki bir dosyanız yoksa dosya oluşturma seçeneğini seçerek kodunuz için bir 'dosya.txt' dosyası oluşturulacaktır.
- Kendi dosyanızı oluşturmak için main.exe'nin olduğu klasörden kendiniz dosyanızı oluşturabilirsiniz.
- Kendi oluşturduğunuz farklı isimdeki bir dosyayı okutabilmek için yazdığım kodun içindeki dosyayı ( dosya.txt )'yi kendiniz değiştirebilirsiniz.
