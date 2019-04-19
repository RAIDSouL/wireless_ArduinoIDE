int analog_value = 0;
void setup()
{
     Serial.begin(9600);
}

void loop()
{
     analog_value = analogRead(36);
      if(analog_value > 1000){
        analog_value = 1000;
      }
      int ll = (1000 - analog_value)*100/1000;
      Serial.println(ll);
      delay(500);
}
