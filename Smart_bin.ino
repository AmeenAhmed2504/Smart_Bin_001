#include <Servo.h>   // Servo library

Servo servo;
const int trigPin = 5;
const int echoPin = 6;
const int servoPin = 7;
const int ledPin = 10;
const int statusLedPin = 9;
const int buzzerPin = 8;

long duration, dist;
long aver[5];  // Averaging for stability
bool binOpen = false;

void setup() {
    Serial.begin(9600);
    servo.attach(servoPin);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(statusLedPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    servo.write(150);
    delay(100);
    Serial.println("Bin lid is closed");
}

long getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    return (duration / 2) / 29.1;
}

void loop() {
    for (int i = 0; i < 5; i++) {
        aver[i] = getDistance();
        delay(10);
    }
    dist = (aver[0] + aver[1] + aver[2] + aver[3] + aver[4]) / 5;

    if (dist < 15) {
        for (int pos = 150; pos >= 0; pos -= 5) {
            servo.write(pos);
            delay(15);
        }
        digitalWrite(ledPin, LOW);
        digitalWrite(statusLedPin, HIGH);
        digitalWrite(buzzerPin, HIGH);

        if (!binOpen) {
            Serial.println("Bin lid is open");
            binOpen = true;
        }
    } else {
        for (int pos = 0; pos <= 150; pos += 5) {
            servo.write(pos);
            delay(15);
        }
        digitalWrite(statusLedPin, LOW);
        digitalWrite(buzzerPin, LOW);

        if (binOpen) {
            Serial.println("Bin lid is closed");
            binOpen = false;
        }
        for (int i = 0; i < 3; i++) {
            digitalWrite(ledPin, HIGH);
            delay(200);
            digitalWrite(ledPin, LOW);
            delay(200);
        }
    }
    Serial.print("Distance: ");
    Serial.print(dist);
    Serial.println(" cm");
    delay(200);
}
