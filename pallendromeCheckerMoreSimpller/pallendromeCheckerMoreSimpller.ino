String data_until_now = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0);
  String input = Serial.readString();
  data_until_now += input;
  Serial.println(data_until_now);
  if(checker(data_until_now))
     digitalWrite(LED_BUILTIN, HIGH);
  else 
     digitalWrite(LED_BUILTIN, LOW);
}

bool checker(String data_until_now) {
   for(int i = 0, j = data_until_now.length() - 1; i <= j; ++i, --j) {
      if(data_until_now.charAt(i) == data_until_now.charAt(j))
        continue;
      else
        return false;
   }return true;  
}
