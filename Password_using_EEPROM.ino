#include <EEPROM.h>

const int button_A = 2;
const int button_B = 3;
const int clear_button = 5;

int clear_state;
int state_A;
int state_B;

bool reset_mode = false;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(button_A, INPUT);
  pinMode(button_B, INPUT);
  pinMode(clear_button, INPUT);

  EEPROM.write(0,1);   // my initial password : 10110
  EEPROM.write(1,0);
  EEPROM.write(2,1);
  EEPROM.write(3,1);
  EEPROM.write(4,0);
}

// Function to print the value stored in EEPROM
void print_eeprom_val() {  
  //Serial.println(" ");
  for(int i = 0; i < 5; i++) {
      int bit_val = EEPROM.read(i);
      Serial.print(bit_val);
      //delay(500);
  }
  Serial.println(" ");
  //delay(500);
}

// Function to clear the EEPROM value
void eeprom_clear() {
  for(int i = 0; i < 5; i++) {
    EEPROM.write(i,0);
  }
}

// actual loop
void loop() {
  // put your main code here, to run repeatedly:
  state_A = digitalRead(button_A);
  state_B = digitalRead(button_B);

  clear_state = digitalRead(clear_button);
  delay(500);

  //Serial.print("button state:");
  //Serial.print(clear_state);

  if(clear_state == 1 && reset_mode == false) {
    Serial.println("Reset Mode On:");
    Serial.print("Old Password: ");
    print_eeprom_val();

    eeprom_clear();
    counter = 0;
    reset_mode = true;
    delay(500);
  }
  if(reset_mode == true) {
    if(state_A == 1) {
      EEPROM.write(counter,0);
      Serial.println("0 entered");
      counter++;
      delay(300);
    }
    if(state_B == 1) {
      EEPROM.write(counter,1);
      Serial.println("1 entered");
      counter++;
      delay(300);
    }
    if(counter >= 5) {
      Serial.print("New Password: ");
      print_eeprom_val();

      Serial.println("Password Updated!");

      reset_mode = false;
      counter = 0;
    }
  }

}
