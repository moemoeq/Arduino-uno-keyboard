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
          releaseKey();
    } else {
      Serial.write(buf, 8);
    }
    bState[PIN_UP] = state;
  }
 
  state = digitalRead(PIN_RT);
  if (bState[PIN_RT] != state) {
    buf[2] = 79;   
    if(state) {
          releaseKey();
    } else {
      Serial.write(buf, 8);
    }
    bState[PIN_RT] = state;
  }
 
    state = digitalRead(PIN_DN);
  if (bState[PIN_DN] != state) {
    buf[2] = 81;   
    if(state) {
          releaseKey();
    } else {
      Serial.write(buf, 8);
    }
    bState[PIN_DN] = state;
  }
  state = digitalRead(PIN_LT);00
  if (bState[PIN_LT] != state) {
    buf[2] = 80;   
    if(state) {
          releaseKey();
    } else {
      Serial.write(buf, 8);
    }
    bState[PIN_LT] = state;
  }
}
 
void releaseKey() 
{
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
       delay(100);
}