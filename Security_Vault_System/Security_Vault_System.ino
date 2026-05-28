#include<Servo.h>

Servo gate;
const int btn_A = 2;
const int btn_B = 3;

const int correct_led = 11;
const int wrong_led_buzzer = 10;
int wrong_led = 5;

int correct_pswd[5] = {1,0,1,1,0};
int user_pswd[5];

int counter = 0;
int state1;
int state2;

int attempts = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn_A,INPUT);
  pinMode(btn_B,INPUT);

  pinMode(correct_led, OUTPUT);
  pinMode(wrong_led_buzzer, OUTPUT);
  pinMode(wrong_led, OUTPUT);

  gate.attach(9);
  Serial.begin(9600);

  digitalWrite(correct_led, LOW);
  digitalWrite(wrong_led_buzzer, LOW);
  digitalWrite(wrong_led, LOW);
  gate.write(0);
}

bool check_password() {
  for(int i = 0; i < 5; i++) {
    if(correct_pswd[i] != user_pswd[i]) {
      return false;
    }
  }
  return true;
}

void loop() {
  // put your main code here, to run repeatedly:
  state1 = digitalRead(btn_A);
  state2 = digitalRead(btn_B);

  if(counter == 5) {
    Serial.println(attempts);
    Serial.println("Your Password is:");
    for(int i = 0; i < 5; i++){
      Serial.print(user_pswd[i]);
    }
    Serial.println(" ");
    bool valid = check_password();

    Serial.println(valid);

    if(valid == true & attempts <= 3) {
      digitalWrite(correct_led, HIGH);
      gate.write(180);
      delay(1000);
      attempts = 0;
      delay(500);
      digitalWrite(correct_led, LOW);
      gate.write(0);
    }
    else if(valid == false & attempts < 3) {
      digitalWrite(wrong_led, HIGH);
      delay(1000);
      attempts = attempts + 1;
      digitalWrite(wrong_led, LOW);
      delay(100);
    }
    
    else if(valid == false & attempts == 3) {
      Serial.println("attempts finished");
      for(int t = 0; t < 10; t++) {
        digitalWrite(wrong_led_buzzer, HIGH);
        delay(100);
        digitalWrite(wrong_led_buzzer, LOW);
        delay(100);
      }
      attempts = 0;
      delay(500);
      digitalWrite(wrong_led, LOW);
    }
  
    counter = 0;
    delay(200);
  }

  else {
    if(state1 == 1) {
      user_pswd[counter] = 0;
      Serial.println("0 entered");
      counter++;
      delay(200);
    }
    if(state2 == 1) {
      user_pswd[counter] = 1;
      Serial.println("1 entered");
      counter++;
      delay(200);
    }
  }

}
