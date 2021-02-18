void setup() {
    Serial.begin(9600);
}

void loop() {
    byte Read = analogRead(A0);
    Serail.write(Read);
}
