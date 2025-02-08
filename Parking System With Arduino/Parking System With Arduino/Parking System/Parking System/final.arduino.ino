#include <LiquidCrystal.h>
#include <Servo.h>
#include <Arduino.h>

// Pin Definitions
const int buttonPin = 13;
const int buzzerPin = 9;
const int redPin = 6;
const int greenPin = 7;
const int bluePin = 8;
const int normal_led= A2;
const int potRgbPin = A0;
const int potLcdPin = A1;
const int triggerPin = 10;
const int echoPin = 11;
const int servoPin = 12;

const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo servo;
int maxSpace = 6;

void lcd_init() {
    lcd.begin(16, 2);  
}

void display_lcd() {
    lcd.clear();
    char buffer[10];  
    if (maxSpace == 0) {
        lcd.setCursor(0, 0);
        lcd.print("Parking Full");
    } else {
        lcd.setCursor(0, 0);
        lcd.print("Vacant Spot: ");
        itoa(maxSpace, buffer, 10);  
        lcd.setCursor(0, 1);  
        lcd.print(buffer);  
    }
    delay(500);
}

long measure_distance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(triggerPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.0343) / 2;
    return distance;
}

void move_servo(int angle) {
    servo.attach(servoPin);
    servo.write(angle);  
    delay(1000);  

void rgb_led() {
    int potValue = analogRead(potRgbPin);
    int stage = potValue / (1024 / 3);
    int redValue, greenValue, blueValue;

    if (stage == 0) {
        redValue = 255;
        greenValue = 0;
        blueValue = 0;
        digitalWrite(normal_led, HIGH);
    } else if (stage == 1) {
        redValue = 0;
        greenValue = 255;
        blueValue = 0;
        digitalWrite(normal_led, LOW);
    } else {
        redValue = 0;
        greenValue = 0;
        blueValue = 255;
        digitalWrite(normal_led, LOW);
    }
    
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}

void reset() {
    if (digitalRead(buttonPin) == HIGH) {
        maxSpace = 6;
        lcd.setCursor(0, 0);
        lcd.print("System Reset");
        delay(1000);
    }
}

void warning() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(buzzerPin, HIGH);
        delay(100);
        digitalWrite(buzzerPin, LOW);
        delay(100);
    }
}

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(normal_led, OUTPUT);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(servoPin, OUTPUT);
    lcd_init();  
}

void loop() {
    if (maxSpace > 0) {
        long distance = measure_distance();
        if (distance < 10) {  
            if (maxSpace > 0) {
                maxSpace--;  
                warning();  
                move_servo(90);  
                delay(2000);     
                move_servo(0);   
            }
            delay(1000);  
        }
        rgb_led();
        display_lcd();
        reset();
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Parking Full");
        delay(500);
        reset();
    }
    delay(100);
}
