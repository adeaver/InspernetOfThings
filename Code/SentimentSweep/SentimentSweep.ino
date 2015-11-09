// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
#include <SD.h>
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int pushButton = 3; // assign the fourth pin to the push button
int index = 0; // variable to store which index should be accessed
 
void setup() 
{ 
  SD.begin(); // Initialize the SD card
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pushButton, INPUT); // assign the pushButton pin as an input to the board
} 
 
 
void loop() 
{ 

}

float readSentiment() {
 system("python /media/mmcblk0p1/sentiment.py " + index);
 File sentimentText = SD.read("/media/mmcblk0p1/sentiment.txt"); // attempt to open the file
 String sentimentString = "";
 char floatBuffer[32]; // floatBuffer is used for string to float conversion
 
 if(sentimentText) { // This executes if the file was successfully opened
   while(sentimentText.available()) {
      sentimentString += (char) sentimentText.read(); 
   }
   
   sentimentString.toCharArray(floatBuffer, sizeof(floatBuffer));
   float sent = atof(floatBuffer);
   
   sentimentText.close();
   return sent;
  } else {
    sentimentText.close();
   return 0;
  }
  
}
