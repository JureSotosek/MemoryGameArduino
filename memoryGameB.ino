const int buttonPINNumber = 4; //number of button pins
int buttonPIN[buttonPINNumber] = {5, 7, 9, 11}; //button  pins
int buttonState[buttonPINNumber] = {1, 2, 3, 4}; //button states

const int ledPINNumber = 4; //number of led pins
int ledPIN[ledPINNumber] = {4, 6, 8, 10}; //led pins

int ledGreen = 12; //wining led
int ledRed = 2; //losing led

const int memoryNumber = 9; //number of memoryslots/all cycles
int memory[memoryNumber]; //wining combinations

int cycle = 0; //varieble for storing the curent cycle

unsigned long time;

int winLose; //win/lose variable

void setup() {
  
  Serial.begin(9600);
  
  for (int i = 1; i <= buttonPINNumber; i++){ //set button pins to INPUT
    pinMode(buttonPIN[i-1], INPUT);
  }
  
  for (int o = 1; o <= ledPINNumber; o++){ //set led pins to OUTPUT
  pinMode(ledPIN[o-1], OUTPUT);
  }
  
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  
}

void loop() {
  int a;
  int b;
  int c;
  int d;
  
  for(b = 1; b <= 4; b++){
        digitalWrite(ledPIN[b-1], HIGH);
      }
      delay(100);
      for(c = 1; c <= 4; c++){
        digitalWrite(ledPIN[c-1], LOW);
      }
      delay(100);
  
  for(b = 1; b <= 4; b++){
        digitalWrite(ledPIN[b-1], HIGH);
      }
  
  while(digitalRead(buttonPIN[0]) == LOW && digitalRead(buttonPIN[1]) == LOW && digitalRead(buttonPIN[2]) == LOW && digitalRead(buttonPIN[3]) ==LOW) { //wait for the button 0 to be pressed
      }
    
  for(c = 1; c <= 4; c++){ 
        digitalWrite(ledPIN[c-1], LOW);
      }
     
  time = millis();
 
  for(int p = 1; p <= memoryNumber; p++){ //assain a random number from 1 to 4 to all of the memory veriables
    memory[p-1] = ((random(100, time))%4) + 1;
  }
  
   for (int y = 0; y < memoryNumber; y++){
    Serial.print(memory[y]);
    Serial.print(".");
  }
  
  Serial.print("\n");
    
  delay(100);
 
  if (cycle == 0){ //starting anmimation 
    
    for(int s = 0; s < 4; s++){ //blink lights from left to right
      digitalWrite(ledPIN[s], HIGH);
      delay(150);
      digitalWrite(ledPIN[s], LOW);
    }
    
    for(a = 1; a <= 2; a++){ //blink all leds twice
      for(b = 1; b <= 4; b++){
        digitalWrite(ledPIN[b-1], HIGH);
      }
      delay(100);
      for(c = 1; c <= 4; c++){
        digitalWrite(ledPIN[c-1], LOW);
      }
      delay(100);
    }
    
  }
  
  delay(250);
  
  for(cycle = 0; cycle < memoryNumber; cycle++){ //repeat for the number of numbers stored in memory
     delay(500);
    
     for(d = 0; d <= cycle; d++){ //repeat for number of the cycle we are curently in/display the numbers=cycles of random numbers on leds
       digitalWrite(ledPIN[memory[d]-1], HIGH);
       delay(200);
       digitalWrite(ledPIN[memory[d]-1], LOW);
       delay(200);
      
     }
     
     for(d = 0; d <= cycle; d++){ //check if the input from butons matches random numbers    
     while(digitalRead(buttonPIN[0]) == LOW && digitalRead(buttonPIN[1]) == LOW && digitalRead(buttonPIN[2]) == LOW && digitalRead(buttonPIN[3]) ==LOW){}
       if (digitalRead(buttonPIN[0]) == HIGH && memory[d] == 1) {
         digitalWrite(ledGreen, HIGH);
         delay(50);
         digitalWrite(ledGreen, LOW);
       }else if (digitalRead(buttonPIN[1]) == HIGH && memory[d] == 2) {
         digitalWrite(ledGreen, HIGH);
         delay(50);
         digitalWrite(ledGreen, LOW);
       }else if (digitalRead(buttonPIN[2]) == HIGH && memory[d] == 3) {
         digitalWrite(ledGreen, HIGH);
         delay(50);
         digitalWrite(ledGreen, LOW);
       }else if (digitalRead(buttonPIN[3]) == HIGH && memory[d] == 4) {
         digitalWrite(ledGreen, HIGH);
         delay(50);
         digitalWrite(ledGreen, LOW);
       }else{ //if it doesnt change the win/lose variable to 1-lose
         winLose = 1;
         break;
       }
       
       delay(200);
       
     while(digitalRead(buttonPIN[0]) == HIGH || digitalRead(buttonPIN[1]) == HIGH || digitalRead(buttonPIN[2]) == HIGH || digitalRead(buttonPIN[3]) == HIGH){}
     }
     if (winLose == 1){
     break;
     }
     
     for (int j = 0; j < 5; j++){
      digitalWrite(ledGreen, HIGH);
      delay(50);
      digitalWrite(ledGreen, LOW);
      delay(50);
        }
    
  }

  if (winLose == 1) {
    for (int j = 0; j < 5; j++){
      digitalWrite(ledRed, HIGH);
      delay(50);
      digitalWrite(ledRed, LOW);
      delay(50);
    }
  }else if (winLose == 0) {
     for (int j = 0; j < 2; j++){
       
       for(a = 1; a <= 2; a++){ //blink all leds twice
      for(b = 1; b <= 4; b++){
        digitalWrite(ledPIN[b-1], HIGH);
      }
      delay(100);
      
      digitalWrite(ledGreen, HIGH);
      delay(50);
      digitalWrite(ledGreen, LOW);
      delay(50);
      
      for(c = 1; c <= 4; c++){
        digitalWrite(ledPIN[c-1], LOW);
      }
      delay(100);
        }
      }
  }

  delay(1000);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  cycle = 0;
  winLose = 0;
}
