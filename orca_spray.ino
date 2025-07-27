int trigPin = 11;
int echoPin = 12;
int light = 13;
long duration, distance;

int buzzerPin = 8;

#define NOTE_G4 392
#define NOTE_DS4 311
#define NOTE_C4  262

int melody[] = {
  NOTE_G4, NOTE_DS4, NOTE_C4
};

int noteDurations[] = {
  500, 500, 1500
};

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(light, OUTPUT);


}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * 0.0343) /2;

  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();

  if (distance <= 100 && distance > 50){
    for (int thisNote = 0; thisNote <= 2; thisNote++) {
      int noteDuration = noteDurations[thisNote];
      tone(buzzerPin, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      noTone(buzzerPin);
    }
  } else if (distance <= 50) {
    digitalWrite(light, HIGH);
  }
  else{
    digitalWrite(light, LOW);
  }

  delay(1000);
}
