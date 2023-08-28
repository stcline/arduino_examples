/* Sketch converts a string from serial to an array of integers
 *  This part of the code is for a larger project utilizing wifi control and the Blynk app
 *  motor control based on https://tronixlabs.com.au/news/tutorial-l298n-dual-motor-controller-module-2a-and-arduino/
 *  
 *  by Steve Cline on 3 August 2018
 */

// Variables to store incoming data over Serial
const byte numChars = 9;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// Variables to store motor control values
int stopComm = 0;
int reverseComm = 0;
int fastComm = 0;
int rMotor = 0;
int lMotor = 0;
boolean newData = false;

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10; // connect the enA pin on UNO to DC motor 1 on L298N
int in1 = 9;  // connect the in1 pin on UNO to IN1 on L298N
int in2 = 8;  // connect the in2 pin on UNO to IN2 on L298N
// motor two
int enB = 5;  // connect the enB pin on UNO to DC motor 2 on L298N
int in3 = 7;  // connect the in3 pin on UNO to IN3 on L298N
int in4 = 6;  // connect the in4 pin on UNO to IN4 on L298N

// Optional pin with indicator LED attached.  This is useful in determining if logical variables are working
//int testPin = 3;

void setup() {
  // Set all motor pins to outputs
  pinMode(enA, OUTPUT); //Right Motor
  pinMode(enB, OUTPUT); //Left Motor
  pinMode(in1, OUTPUT); //Right motor direction 
  pinMode(in2, OUTPUT); //Right motor direction
  pinMode(in3, OUTPUT); //Left motor direction
  pinMode(in4, OUTPUT); //Left motor direction
  // pinMode(testPin, OUTPUT); // Use for debugging switches
  // digitalWrite(testPin, LOW);
  
  Serial.begin(115200);
}

void loop() {
  // Receive the char string, convert to int arrat, print the values
  recvWithStartEndMarkers();  
  if (newData == true){
    convertCharToInt();
    motorControl();
    newData = false;
  }  
}

// Receive the char string
void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

// Convert chars to ints
void convertCharToInt (){
  stopComm = receivedChars[0];
  reverseComm = receivedChars[1];
  fastComm = receivedChars[2];
  rMotor = ((int)receivedChars[3]);
  lMotor = ((int)receivedChars[4]);;   
}

// Calculate the motor controls
void motorControl(){
  if (stopComm == 1){
     analogWrite (enA, 0);
     analogWrite (enB, 0);    
  }

  if (fastComm == 1){
    if (reverseComm){
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      analogWrite (enA, (rMotor * 2.5));
      analogWrite (enB, (lMotor * 2.5));
    }
    else {
      digitalWrite (in1, LOW);
      digitalWrite (in2, HIGH);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
      analogWrite (enA, (rMotor * 2.5));
      analogWrite (enB, (lMotor * 2.5));
    }
  }

  else {
    if (reverseComm){
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      analogWrite (enA, (rMotor * 1.5));
      analogWrite (enB, (lMotor * 1.5));
    }
    else {
      digitalWrite (in1, LOW);
      digitalWrite (in2, HIGH);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
      analogWrite (enA, (rMotor * 1.5));
      analogWrite (enB, (lMotor * 1.5));
    }  
  }
}

