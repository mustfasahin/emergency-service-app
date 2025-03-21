# Acil Servis Yönetim Sistemi

Bu program, bir acil servisin hasta kayıt ve yönetim işlemlerini gerçekleştirmek için tasarlanmış basit bir C uygulamasıdır.

## Özellikler

- **Hasta Kaydı**: Hasta bilgilerini (ad-soyad, yaş, şikayetler) ve triyaj önceliklerini kaydeder.
- **Triyaj Sıralama**: Hastaları öncelik sırasına göre sıralar (1-5 arası, 1 en yüksek öncelik).
- **Reçete Yazma**: Kayıtlı hastalara reçete oluşturma.
- **Kişisel Hasta Bilgileri**: ID'ye göre belirli bir hastanın tüm bilgilerini görüntüleme.
- **Tüm Hasta Bilgileri**: Öncelik sırasına göre düzenlenmiş tüm hasta listesini görüntüleme.

## Teknik Detaylar

- Program en fazla 100 hasta kaydı tutabilir.
- Hasta ID'leri 1-1000 arasında rastgele atanır.
- Triyaj önceliği 1-5 arası değer alır (1 en yüksek, 5 en düşük öncelik).

## Kurulum

1. Kaynak kodunu derleyin:
   ```bash
   gcc acil_servis.c -o acil_servis
   ```

2. Programı çalıştırın:
   ```bash
   ./acil_servis
   ```

## Kullanım

Program çalıştığında aşağıdaki menü görüntülenir:

```
ACIL SERVIS SISTEMI

---------------------

1 --> HASTA KAYDI
2 --> TRIYAJ SIRALAMA
3 --> RECETE YAZMA
4 --> KISISEL HASTA BILGILERI
5 --> TUM HASTA BILGILERI
6 --> CIKIS

Seciminiz: 
```

### 1. Hasta Kaydı
Yeni hasta bilgilerini sisteme kaydeder. Gerekli bilgileri girdikten sonra sistem otomatik olarak bir ID atar.

### 2. Triyaj Sıralama
Tüm hastaları triyaj önceliğine göre (1-5) sıralar.

### 3. Reçete Yazma
Hasta ID'si ile arama yaparak hastaya reçete düzenler.

### 4. Kişisel Hasta Bilgileri
Hasta ID'si girerek belirli bir hastanın tüm bilgilerini görüntüler.

### 5. Tüm Hasta Bilgileri
Sistemdeki tüm hastaların temel bilgilerini öncelik sırasına göre listeler.

### 6. Çıkış
Programdan çıkış yapar.

## Sınırlamalar ve Bilinen Sorunlar

- Program maksimum 100 hasta kaydı tutabilir.
- Hasta bilgileri program çalıştığı sürece hafızada tutulur, program kapatıldığında veriler kaybolur.
- Aynı ID'ye sahip iki hasta olma ihtimali vardır (düşük ihtimalle).

## Gelecek Geliştirmeler İçin Öneriler

- Hasta verilerinin dosyada saklanarak kalıcı hale getirilmesi
- Benzersiz ID oluşturma mekanizmasının iyileştirilmesi
- Hasta arama fonksiyonunun eklenmesi (isim, yaş gibi kriterlere göre)
- Arayüz iyileştirmeleri
- Hasta kaydı silme ve güncelleme fonksiyonlarının eklenmesi
