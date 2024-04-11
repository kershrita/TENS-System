#define adjustTime 2
#define adjustMode 3
#define adjustFrequency 4
#define adjustCycle 5
#define channel1Inc 6
#define channel1Dec 7
#define channel2Inc 8
#define channel2Dec 9

const String modes[6] = {"TENS asymmetrical",
                  "Microcurrent", 
                  "Diadynamic", 
                  "NMS Burst", 
                  "IFC-Int-etferential", 
                  "Russain"};



int t = 0;
String m = "NULL"; int idxm = 0;

int channel1Frequency = 0;
int channel2Frequency = 0;

void setup() {
  Serial.begin(9600);           // Serial monitor for debugging

  delay(2000);
  
  pinMode(adjustTime, OUTPUT);
  pinMode(adjustMode, OUTPUT);
  pinMode(adjustFrequency, OUTPUT);
  pinMode(adjustCycle, OUTPUT);
  
  pinMode(channel1Inc, OUTPUT);
  pinMode(channel1Dec, OUTPUT);
}

void loop() {
  // Check if data is available on Bluetooth
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();

    // Process the received data
    switch (receivedChar) {
      case 't':  // Command for time adjustment
        digitalWrite(adjustTime, HIGH);
        t = (t + 5) % 35; // Update time by 5 minutes, reset to 0 after 35 minutes
        Serial.print("Time: ");
        Serial.println(t);

        delay(100);
        
        digitalWrite(adjustTime, LOW);
        break;
        
      case 'm':  // Command for mode adjustment
        digitalWrite(adjustMode, HIGH);
        if (idxm > 5) {idxm = 0;}
        m = modes[idxm];
        Serial.print("Mode: ");
        Serial.println(m);

        idxm++;

        delay(100);
        
        digitalWrite(adjustMode, LOW);
        break;

      case 'f':  // Command for frequency mode adjustment
        digitalWrite(adjustFrequency, HIGH);
        
        delay(100);
        
        digitalWrite(adjustFrequency, LOW);
        break;

      case 'c':  // Command to start the cycle
        digitalWrite(adjustCycle, HIGH);

        delay(100);
        
        digitalWrite(adjustCycle, LOW);
        break;

      case 'i':  // Command to increase frequency for channel 1
        channel1Frequency = min(channel1Frequency + 1, 16);
        
        digitalWrite(channel1Inc, HIGH);
        
        Serial.print("Channel 1 Strength: ");
        Serial.println(channel1Frequency);
       
        delay(100);
        digitalWrite(channel1Inc, LOW);
        break;
        
      case 'd':  // Command to decrease frequency for channel 1
        channel1Frequency = max(channel1Frequency - 1, 0);
        
        digitalWrite(channel1Dec, HIGH);
        
        Serial.print("Channel 1 Strength: ");
        Serial.println(channel1Frequency);
        
        delay(100);
        digitalWrite(channel1Dec, LOW);
        break;

        case '+':  // Command to increase frequency for channel 1
        channel2Frequency = min(channel2Frequency + 1, 16);
        
        digitalWrite(channel2Inc, HIGH);
        
        Serial.print("Channel 2 Strength: ");
        Serial.println(channel2Frequency);
       
        delay(100);
        digitalWrite(channel2Inc, LOW);
        break;
        
      case '-':  // Command to decrease frequency for channel 1
        channel2Frequency = max(channel2Frequency - 1, 0);
        
        digitalWrite(channel2Dec, HIGH);
        
        Serial.print("Channel 2 Strength: ");
        Serial.println(channel2Frequency);
        
        delay(100);
        digitalWrite(channel2Dec, LOW);
        break;
    }
  }
}
