# HAFI
HAFI.h - Arduino'da araba kontrolünü kolaylaştırmayı sağlayan ilk Türkçe araba kütüphanesi

## HAFI nedir?

HAFI, yaptığımız arabaya verdiğimiz isimdir, arabamız ismini okulumuzun ismi(Hafize Özal Ortaokulu)'nden almıştır ve bir süre sonra yeniden başka bir araba yaptığımızda aynı kodları tekrardan yazmak çok sıkıcı geldiği ve insanların daha kolay bir şekilde Arduino ile araba yapabilmeleri için bu kütüphane oluşturulmuştur.

## Kullanım

### 1. Fonksiyonlar

#### kur()
`sag` ya da `sol` fonksiyonlarında herhangi bir sorun olmaması için bunu yaptık, yani örnek verecek olursak; eğer sizin sağ ön motorunuz 3 numaralı motor ise, bu bir karışıklık yaratacaktır. Bu problemi çözmek için bu fonksiyonu geliştirdik.

Kullanım: `<HAFI>.kur(motorSayısı, motor1Pin, motor2Pin, motor3Pin, motor4Pin);`
NOT: Eğer motor 3 ve 4 yoksa, onları 0 olarak yazmalısınız.

<hr>

#### ileri()
Bu fonksiyon sayesinde arabamız ileri gider.

Kullanım: `<HAFI>.ileri()`

<hr>

#### sag()
Bu fonksiyon sayesinde arabamız sağa gider.

Kullanım: `<HAFI>.sag()`

<hr>

#### sol()
Bu fonksiyon sayesinde arabamız sola gider.

Kullanım: `<HAFI>.sol()`

<hr>

#### geri()
Bu fonksiyon sayesinde arabamız geriye gider.

Kullanım: `<HAFI>.geri()`

<hr>

#### dur()
Bu fonksiyon sayesinde arabamız durur.

Kullanım: `<HAFI>.dur()`

<hr>

#### dans()
Bu fonksiyon sayesinde arabamız dans eder.

Kullanım: `<HAFI>.dans()`

<hr>

#### hiz()
Bu fonksiyon sayesinde arabamızın hızını ayarlayabiliriz.

Kullanım: `<HAFI>.hiz(100)`

<hr>

#### serbestMod()
Bu fonksiyon sayesinde arabamızın serbest modda mı yoksa bizim kontrolümüzle mi hareket edeceğini belirleyebiliriz.

Kullanım: `<HAFI>.serbestMod(true)`

</hr>

#### engeldenKac()
Bu fonksiyon sayesinde tek satır kod ile engelden kaçan araba yapabiliriz.

Kullanım: `<HAFI>.engeldenKac(önSensörTrigPin, önSensörEchoPin, arkaSensörTrigPin, arkaSensörEchoPin, minimumSensörDeğeri, dönüşYönü)`
Bu fonksiyonda `minimumSensörDeğeri`'ni ön ya da arka sensör alırsa, arabamız `dönüşYönü`'ne döner.
NOT: Dönüş yönü `0` ise sağa, `1` ise sola döner.

<hr>

#### bluetoothKur()
Bu fonksiyon sayesinde bluetooth modülümüzü daha kolay kontrol edebilmek için bluetooth ayarlarımızı belirleyebiliriz.

Kullanım: `<HAFI>.bluetoothKur(txPin, rxPin)`

<hr>

#### bluetoothKontrol()
Bu fonksiyon sayesinde bluetootha gelen sinyalleri okur ve `<HAFI>.bluetoothVeri` değişkenine atarız.

Kullanım: `<HAFI>.bluetoothKontrol()`

<hr>

#### mesafeOlc()
Bu fonksiyonu HC-SR04 ile mesafe ölçerken kolaylık olması için geliştirdik.

Kullanım: `<HAFI>.mesafeOlc(trigPin, echoPin)`
