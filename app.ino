void setup() {
    // Setup serial port baud rate
    Serial.begin(115200);
    pinMode(9, OUTPUT);
}

void loop()
{
    // Read photo resistor value from A1 pin
    int light = analogRead(A1);
    // Programmaticaly set the light value range [400..900]
    if( light < 400 ) light = 400;
    if ( light > 900 ) light = 900;
    // Calculate LED brightness range [0..255] by map function
    int brightness = map(light, 400, 900, 255, 0);
    
    Serial.print(light);
    Serial.print(" => ");
    Serial.println(brightness);
    
    // Analog write brightness to LED D9 pin
    analogWrite(9, brightness); 
    delay(2);
}
