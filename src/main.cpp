#include <Arduino.h>
HardwareSerial Serial1(USART1);

#define LIMIT_PIN PB9
#define stepPin PA5
#define dirPin PA6
#define enPin PA7
int status = 0;
void ai();
void setup()
{
    Serial1.begin(115200);
    Serial1.println("Start");

    pinMode(LIMIT_PIN, INPUT);
    // Serial2.println("Serial: 2");
    delay(1000);
    attachInterrupt(digitalPinToInterrupt(LIMIT_PIN), ai, FALLING);

    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);
}
void ai()
{
    if (status == 0)
    {
        status = 1;
    }
    Serial1.println("1");
}
int speed = 3500; //旋转速度
void loop()
{
    if (status == 1)
    {
        digitalWrite(dirPin, HIGH); //HIGH正转 LOW反转
        // 全步模式下 200个脉冲有一圈
        for (int x = 0; x < 200; x++)
        {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(speed); 
            digitalWrite(stepPin, LOW);
            delayMicroseconds(speed);
        }
        delay(500);
        status = 0;
    }
}
