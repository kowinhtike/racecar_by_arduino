#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void stopMove(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopTurn(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void forward(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,HIGH);
}

void backward(){

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4,LOW);
}

void right(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void left(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600); // HC-05 default baud rate
}

void loop() {
  if(Serial.available()){
    char command = Serial.read();
    if(command == 'F'){
      forward();
    }else if(command == 'B'){
      backward();
    }else if(command == 'R'){
      right();
    }else if(command == 'L'){
      left();
    }else if(command == 'S'){
      stopMove();
    }else if(command == 's'){
      stopTurn();
    }
  }

}
