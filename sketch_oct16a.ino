const int LED_RED = 8;   
const int LED_GREEN = 9; 
const int WATER_PIN = 7; 
const int BUZZER_PIN = 3; 

void setup() {
  pinMode(WATER_PIN, INPUT);   
  pinMode(LED_RED, OUTPUT);   
  pinMode(LED_GREEN, OUTPUT);  
  pinMode(BUZZER_PIN, OUTPUT); 

  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  int wet = digitalRead(WATER_PIN); 


  if (wet == HIGH) {  
    digitalWrite(LED_RED, HIGH);  
    digitalWrite(LED_GREEN, LOW); 
    playMelody();  
  } else {  
    digitalWrite(LED_RED, LOW);   
    digitalWrite(LED_GREEN, HIGH);
    noTone(BUZZER_PIN);  
  }

  delay(100); 
}


void playMelody() {
  int melody[] = { 262, 294, 330, 349, 392, 440, 494, 523 };  
  int noteDuration = 500;  

  for (int i = 0; i < 8; i++) {
    tone(BUZZER_PIN, melody[i], noteDuration); 
    delay(noteDuration);  
  }
}