int one=0, two=0, three=0, four=0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        int store;
        store = Serial.read();

        if (one == 0) {
            one = store;
        } else if (two == 0 && one != 0) {
            two = store;
        } else if (three == 0 && two != 0) {
            three = store;
        } else if (four == 0 && three != 0) {
            four = store;
            Serial.write(four);
            Serial.write(three);
            Serial.write(two);
            Serial.write(one);
            one = two = three = four = 0;
        }
    }
}
