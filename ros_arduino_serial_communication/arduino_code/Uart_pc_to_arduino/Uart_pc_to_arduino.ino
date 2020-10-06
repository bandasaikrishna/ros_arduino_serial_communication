int ledpin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);   
}

void loop()
{
  if(Serial.available() >0){
    String info;
    info= Serial.readStringUntil('x');
    if(info.equals("ON")){
      digitalWrite(ledpin, HIGH);
      Serial.print("LED is on");
    }
    else if(info.equals("OFF")){
      digitalWrite(ledpin, LOW);
      Serial.print("LED is off");
    }
  }
}

