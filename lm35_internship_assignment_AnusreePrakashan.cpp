#define lm35 A0
#define led 13
int ledState = LOW

void setup(){
	pinMode(led,OUTPUT);
	pinMode(lm35,INPUT);
	Serial.begin(9600);
}

void loop(){
	int value = analogRead(lm35);
	float temp = (value*5.0/1024.0)*100.0;
	
	if(temp<30.0){
		ledBlink(250);
	}
	else{
		ledBlink(500);
	}
	Serial.print("Temperature : ");
	Serial.print(temp);
	Serial.println(" °C");
}

void ledBlink(int blinkDelay){
	static long lastBlinkTime = 0;
	long currentTime=0;
	
	while(1){
		currentTime+=100;
		if(currentTime-lastBlinkTime>=blinkDelay){
			lastBlinkTime=currentTime;
			ledState=(ledState==LOW)?HIGH:LOW;
			digitalWrite(led,ledState);
		}
	}
}
