int store[100];
int count = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        store[count] = Serial.read();

        if (store[count] == 13)
            for (int i = count - 1; i >= 0; i--)
                Serial.write(store[i]);
            count = 0;
        else
            count++;
    }
}
