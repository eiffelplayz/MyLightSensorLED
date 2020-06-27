void setup() {
    // Setup serial port baud rate
    Serial.begin(115200);
    pinMode(9, OUTPUT);
}

void loop()
{
    // Read photo resistor value from A1 pin
	int light = analogRead(A1);
    // The map() function uses integer math so will not generate fractions, 
    // when the math might indicate that it should do so. 
    // Fractional remainders are truncated, and are not rounded or averaged.
    // map(value, fromLow, fromHigh, toLow, toHigh)
    if( light < 400 ) light = 400;
    if ( light > 900 ) light = 900;

    int brightness = map(light, 400, 900, 255, 0);
    
    Serial.print(light);
    Serial.print(" => ");
    Serial.println(brightness);
    
    // Analog write to LED D9 pin
    analogWrite(9, brightness); 
    delay(2);
}
