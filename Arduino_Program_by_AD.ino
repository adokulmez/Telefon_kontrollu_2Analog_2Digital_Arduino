/*This program written by Abdullah Dokulmez*/
#include <Servo.h>  //Servo kütüphanesi eklendi

#define led1 12     // tanımlamalar yapıldı
#define led2 13
#define motor 10 

Servo servo1;       // kullanılacak servolar tanıdtıldı
Servo servo2;
     
    const int potmeter1 = A1;     // Potansiyometreler için girişler tanımlandı
    const int potmeter2 = A0;      
    int buton1=2;                 // 2 numaralı pine buton1 ismi verildi
    int buton2=4;                 // 4 numaralı pine buton2 ismi verildi
    int a,b;                      // toggle fonksiyonları için a,b değişkenleri kullanıldı
    int pot1,pot2;                // Hberleşmede kullanılmak üzere pot 1 ve 2 değişkenleri hazırlandı
    
void setup() {
  
      Serial.begin(9600);
      
      pinMode(led1,OUTPUT);   // ledler çıkış olarak tanıtıldı
      pinMode(led2,OUTPUT);   
      pinMode(potmeter1, INPUT); //Potansiyometre pini giriş olarak belirtildi
      pinMode(potmeter2, INPUT); //Potansiyometre pini giriş olarak belirtildi
      pinMode(buton1,INPUT);// buton1 pini giriş pini olarak belirlendi
      pinMode(buton2,INPUT);// buton2 pini giriş pini olarak belirlendi
      servo1.attach(11);      //Servo 11. ve 3. bacaklara bağlanacak
      servo2.attach(3);
}

void loop() {  // ANA DÖNGÜDÜR
potoku();
bilgileri_seri_porta_yaz();
}

void potoku(){  // Bu fonksiyonda kart üstündeki potlardan gelen analog bilgiyi okuduk ve 
 pot1 = analogRead(potmeter1);      // haberleşme için yeni değişkenlere atan ayrıca ledleri
 pot2= analogRead(potmeter2);       // kontrol etmek için tersleme fonksiyon değişkenlerini belirledik
 pot1 = map(pot1, 0, 1023, 0, 1023);   
 pot2 = map(pot2, 0, 1023, 1024, 2047); 
 a=digitalRead(buton1);
 b=digitalRead(buton2);
}

void bilgileri_seri_porta_yaz(){  // Bu fonksiyonda elimizde bulunan bilgileri bluetooth
 Serial.print(" " );              // üstünden yollamak üzere seri porta yönlendirdik.
 Serial.println(pot1);            // Bekleme süreleri android uygulaması için gerekliydi.
 delay(100);               
 Serial.print(" " );      
 Serial.println(pot2);       
 delay(100);
}
