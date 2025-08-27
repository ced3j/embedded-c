#define TRIG 9
#define ECHO 10


#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7

#define BUZZ 8





void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);  // Trig sinyal gönderdiğimiz
  pinMode(ECHO, INPUT); // Echo dönüş aldığımız
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(BUZZ, OUTPUT);

}

void loop() {
  // 1. trig pinine kısa bir darbe gönder
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // 2. echo pininden süreyi al
  long sure = pulseIn(ECHO, HIGH);
        // pulseIn(ECHO, HIGH) → Echo pininin HIGH kaldığı süreyi ölçer.

  // 3. mesafe hesapla (cm cinsinden)
  long mesafe = sure * 0.034 / 2;

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  if(mesafe < 10){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    tone(BUZZ, 1000); // Buzzer'ı yüksek tonda çalıştır
  }else if(mesafe < 25){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    tone(BUZZ, 500); // Buzzer'ı düşük tonda çalıştır
  }else if(mesafe < 40){ 
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    noTone(BUZZ);
  }else{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    noTone(BUZZ);
  }


  delay(500);

}
