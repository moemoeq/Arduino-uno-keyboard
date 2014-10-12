uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */
 
#define PIN_UP 2
#define PIN_RT 3
#define PIN_DN 4
#define PIN_LT 5
#define PIN_B1 8
#define PIN_B2 9
#define PIN_B3 10
#define PIN_B4 11
 
int state = 1;
int bState[400] = {0, };
 
void setup() 
{
  Serial.begin(9600);
 
  pinMode(PIN_UP, INPUT);
  pinMode(PIN_RT, INPUT);
  pinMode(PIN_DN, INPUT);
  pinMode(PIN_LT, INPUT);
  // Enable internal pull-ups
  digitalWrite(PIN_UP, 1); 
  digitalWrite(PIN_RT, 1);
  digitalWrite(PIN_DN, 1); 
  digitalWrite(PIN_LT, 1); 
}
 
 
void loop() 
{
  state = digitalRead(PIN_UP);
  if (bState[PIN_UP] != state) {
    buf[2] = 82;   
    
    if(state) {
      Serial.write(buf, 8);
    } else {
      releaseKey();
    }
    
    bState[PIN_UP] = state;
  }
 
  state = digitalRead(PIN_RT);
  if (state != 1) {
    buf[2] =  79;    

    Serial.write(buf, 8);
    releaseKey();
  } 
 
  state = digitalRead(PIN_DN);
  if (state != 1) {
    buf[2] = 81;    
    Serial.write(buf, 8);
    releaseKey();
  } 
  state = digitalRead(PIN_LT);
  if (state != 1) {
    buf[2] = 80;    
    Serial.write(buf, 8);
    releaseKey();
  } 
}
 
void releaseKey() 
{
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
       delay(100);
}
