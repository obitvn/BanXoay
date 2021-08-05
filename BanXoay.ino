
uint16_t var_duty = 0;
uint16_t motor_duty = 0;
float duty = 0;
uint16_t mode, chay_lien, giat_cuc, chay_ngan;
void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
Serial.begin(9600);
}

void scan_mode()
{
  if(digitalRead(2)==0)
  {
    while(digitalRead(2)==0) {};
    chay_lien++;
    if(chay_lien>1) chay_lien=0;
    chay_ngan=0;
    giat_cuc=0;
  }
  else if(digitalRead(3)==0)
  {
    while(digitalRead(3)==0) {};
    giat_cuc++;
    if(giat_cuc>1) giat_cuc=0;
    chay_ngan=0;
    chay_lien=0;
  }
  else if(digitalRead(4)==0)
  {
    while(digitalRead(4)==0) {};
    chay_ngan++;
    if(chay_ngan>1) chay_ngan=0;
    giat_cuc=0;
    chay_lien=0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  scan_mode();
  if(chay_lien)
  {
 var_duty = analogRead(A4);
 duty = (255*var_duty)/1023;
 motor_duty = duty;
 analogWrite(5,var_duty/4);
  }
  else if(giat_cuc)
  {
     var_duty = analogRead(A4);
     duty = (255*var_duty)/1023;
     motor_duty =(uint8_t) duty;
     analogWrite(5,var_duty/4);
     delay(1000);
     analogWrite(5,0);
     delay(1000);
  }
  else if(chay_ngan)
  {
    var_duty = analogRead(A4);
     duty = (255*var_duty)/1023;
     motor_duty =(uint8_t) duty;
     analogWrite(5,var_duty/4);
     delay(500);
     analogWrite(5,0);
     delay(500);
     while(chay_ngan)
     {
      scan_mode();
     }
  }
 // mode = digitalRead(A0);
 Serial.println(chay_ngan);
 Serial.println(chay_lien);
 Serial.println(giat_cuc);
 //Serial.println(duty);
  //Serial.println(motor_duty);
}
