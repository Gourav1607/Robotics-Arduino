void setup()
{
    pinMode(5, INPUT);
    pinMode(12, OUTPUT);
}

void loop()
{
    byte Read = digitalRead(5);
    if (Read == 1)
        digitalWrite(12, HIGH);
    else
        digitalWrite(12, LOW);
}
