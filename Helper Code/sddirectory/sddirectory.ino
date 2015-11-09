#include <SD.h>

void setup() {
  // put your setup code here, to run once:
  SD.begin();
  File testFile = SD.open("thisIsATestFileWithALongName.txt", FILE_WRITE);
  testFile.close();
  
  system("find / 'thisIsATestFileWithALongName.txt' | grep 'thisIsATestFileWithALongName.txt' > /dev/ttyGS0");
  
  SD.remove("thisIsATestFileWithALongName.txt");
}

void loop() {
  // put your main code here, to run repeatedly:

}
