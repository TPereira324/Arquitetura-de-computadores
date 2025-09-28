#define LED_PIN 12    // Define the pin for the LED
#define SOUND_PIN 13  // Define the pin for the sound
#define BUTTON_PIN 7  // Define the pin for the button
#define SENSOR_PIN 8  // Define the pin for the sensor (Digital)

bool lastButtonState = LOW;
bool currentButtonState = LOW;
bool ledState = LOW;
bool soundState = LOW;
bool sensorState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SOUND_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {

  currentButtonState = digitalRead(BUTTON_PIN);
  sensorState = digitalRead(SENSOR_PIN);
  Serial.print("Sensor State: ");
  Serial.println(sensorState);

  if (currentButtonState == HIGH && lastButtonState == LOW) {

    if(sensorState == HIGH) { // Sensor ativo
      tone(SOUND_PIN, 880, 1000); // Tom mais alto
      digitalWrite(LED_PIN, HIGH);
      delay(500); // LED pisca mais rápido
      digitalWrite(LED_PIN, LOW);
    } else { // Sensor inativo
      tone(SOUND_PIN, 440, 1000); // Tom normal
      digitalWrite(LED_PIN, HIGH);
      delay(1000); // LED pisca mais lento
      digitalWrite(LED_PIN, LOW);
    }
  }

  lastButtonState = currentButtonState;
}
