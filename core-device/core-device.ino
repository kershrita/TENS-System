#include <SoftwareSerial.h>

#define adjustTime 2
#define adjustMode 3
#define adjustFrequency 4
#define adjustCycle 5
#define channel1Inc 6
#define channel1Dec 7
#define channel2Inc 8
#define channel2Dec 13

// SoftwareSerial bluetoothSerial(2, 3);  // RX, TX pins

struct Variables{
  const int times[7] = {0, 5, 10, 15, 20, 25, 30};
  const String modes[6] = {"TENS asymmetrical",
                    "Microcurrent", 
                    "Diadynamic", 
                    "NMS Burst", 
                    "IFC-Int-etferential", 
                    "Russain"};
  const String frequency[2] = {"LF", "IF"};
  const String cycle[3] = {"IDle", "Running", "Switching"};
};

Variables data;

int t = data.times[0];
String m = "NULL"; int idxm = 0;
String f = data.frequency[0]; int idxf = 0;
String c = data.cycle[0]; int idxc = 0;

int channel1Frequency = 0;
int channel2Frequency = 0;


void setup() {
  Serial.begin(9600);           // Serial monitor for debugging
  // bluetoothSerial.begin(9600);  // Bluetooth module baud rate

  delay(5000);
  
  pinMode(adjustTime, OUTPUT);
  pinMode(adjustMode, OUTPUT);
  pinMode(adjustFrequency, OUTPUT);
  pinMode(adjustCycle, OUTPUT);
  
  pinMode(channel1Inc, OUTPUT);
  pinMode(channel1Dec, OUTPUT);
  pinMode(channel2Inc, OUTPUT);
  pinMode(channel2Dec, OUTPUT);
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

        //bluetoothSerial.print("Time: ");
        //bluetoothSerial.println(t);

        delay(100);
        
        digitalWrite(adjustTime, LOW);
        break;

        
      case 'm':  // Command for mode adjustment
        digitalWrite(adjustMode, HIGH);
        if (idxm < 6) idxm = 0;
        m = data.modes[idxm];
        Serial.print("Mode: ");
        Serial.println(m);

        idxm++;

        //bluetoothSerial.print("Mode: ");
        //bluetoothSerial.println(m);

        delay(100);
        
        digitalWrite(adjustMode, LOW);
        break;

        
      case 'f':  // Command for frequency mode adjustment
        digitalWrite(adjustFrequency, HIGH);
        if (idxm < 2) idxm = 0;
        f = data.frequency[idxf];
        Serial.print("Frequency Mode: ");
        Serial.println(f);

        idxf++;

        //bluetoothSerial.print("Frequency Mode: ");
       // bluetoothSerial.println(f);

        delay(100);
        
        digitalWrite(adjustFrequency, LOW);
        break;

        
      case 'c':  // Command to start the cycle
        digitalWrite(adjustCycle, HIGH);
        if (idxc < 2) idxc = 0;
        c = data.cycle[idxc];
        Serial.print("Device: ");
        Serial.println(c);

        idxc++;

        //bluetoothSerial.print("Device: ");
        //bluetoothSerial.println(c);

        delay(100);
        
        digitalWrite(adjustCycle, LOW);
        break;

        
      case 'i':  // Command to increase frequency for channel 1
        channel1Frequency = min(channel1Frequency + 1, 16);
        
        //pinMode(channel1Inc, OUTPUT);
        digitalWrite(channel1Inc, HIGH);
        
        Serial.print("Channel 1 Strength: ");
        Serial.println(channel1Frequency);
        
        //bluetoothSerial.print("Channel 1 Strength: ");
       ///bluetoothSerial.println(channel1Frequency);

        delay(100);
        digitalWrite(channel1Inc, LOW);
        break;

        
      case 'd':  // Command to decrease frequency for channel 1
        channel1Frequency = max(channel1Frequency - 1, 0);
        
        //pinMode(channel1Dec, OUTPUT);
        digitalWrite(channel1Dec, HIGH);
        
        Serial.print("Channel 1 Strength: ");
        Serial.println(channel1Frequency);
        
        //bluetoothSerial.print("Channel 1 Strength: ");
        //bluetoothSerial.println(channel1Frequency);

        delay(100);
        digitalWrite(channel1Dec, LOW);
        break;

        
      case '+':  // Command to increase frequency for channel 2
        channel2Frequency = min(channel2Frequency + 1, 16);
         
        pinMode(channel2Inc, OUTPUT);
        digitalWrite(channel2Inc, HIGH);
        
        Serial.print("Channel 2 Strength: ");
        Serial.println(channel2Frequency);
        
        //bluetoothSerial.print("Channel 2 Strength: ");
        //bluetoothSerial.println(channel2Frequency);

        delay(100);
        digitalWrite(channel2Inc, LOW);
        
        break;

        
      case '-':  // Command to decrease frequency for channel 2
        channel2Frequency = max(channel2Frequency - 1, 0);

        pinMode(channel2Dec, OUTPUT);
        digitalWrite(channel2Dec, HIGH);
        
        Serial.print("Channel 2 Strength: ");
        Serial.println(channel2Frequency);
        
        //bluetoothSerial.print("Channel 2 Strength: ");
        //bluetoothSerial.println(channel2Frequency);

        delay(100);
        digitalWrite(channel2Dec, LOW);
        
        break;
    }

  }
}
