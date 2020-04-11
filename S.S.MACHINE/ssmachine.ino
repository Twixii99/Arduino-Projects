// لو بتسأل نفسك ليه هنا اتعمل فى file واحد و هناك فى 3 لا مش عشان سبب هو بس عشان التخزين و كده فمكعبلش الدنيا يعنى ...
#define SSMACHINE_LASER 2
#define SSMACHINE_LDR 0

typedef unsigned long ul;
const ul PERIOD = 1500;

const byte initial_output = 0;
byte initial_state = 0;
bool is = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SSMACHINE_LASER, OUTPUT);
  digitalWrite(SSMACHINE_LASER, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  ul t1 = millis();
  while(millis() - t1 <= PERIOD)
     is = analogRead(SSMACHINE_LDR) <= 950;
  bool output = is and initial_state;
  initial_state = is xor initial_state;

  if(output) {
    digitalWrite(SSMACHINE_LASER, HIGH);
    delay(1000);
    digitalWrite(SSMACHINE_LASER, LOW);
  } else digitalWrite(SSMACHINE_LASER, LOW); 
}
