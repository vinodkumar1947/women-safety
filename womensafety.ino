#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // configure software serial port
 
void setup()
{
  SIM900.begin(9600); 
  Serial.begin(9600);              
  //SIM900power();  
 // delay(2000);  // give time to log on to network. 
  pinMode(9, OUTPUT);      // sets the digital pin 13 as output
  pinMode(25, INPUT); 
  
}
 
void SIM900power()
// software equivalent of pressing the GSM shield "power" button
{
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  delay(500);
}
 
void callSomeone()
{
  SIM900.println("ATD + +918494859500;"); // dial IN (+91) 8494859500
  digitalWrite(9, HIGH);
  Serial.println("first number calling;");
  delay(100);
  SIM900.println();
  delay(30000);            // wait for 30 seconds...
  SIM900.println("ATH");   // hang up
  digitalWrite(9, LOW);
  
  Serial.println("HANG UP first number");
}
void calltwo()
{
  SIM900.println("ATD + +918970209900;"); // dial IN (+91) 8494859500
  digitalWrite(9, HIGH);
  Serial.println("Second number calling;");
  delay(100);
  SIM900.println();
  delay(30000);            // wait for 30 seconds...
  SIM900.println("ATH");   // hang up
  digitalWrite(9, LOW);
  Serial.println("HANG UP Second number");
}
void sendSMS()
{
  Serial.println(" Message Initiated");
  digitalWrite(9, HIGH);
  SIM900.print("AT+CMGF=1\r");                                                        // AT command to send SMS message
  delay(200);
  SIM900.println("AT+CMGS=\"+918494859500\"");                                     // recipient's mobile number, in international format
  delay(200);
  SIM900.println("13.038913, 77.573496");        // message to send
  Serial.println("https://www.google.co.in/maps/place/13%C2%B002'16.1%22N+77%C2%B034'24.2%22E/@13.037815,77.57338,18z/data=!3m1!4b1!4m2!3m1!1s0x0:0x0?hl=en");
  delay(200);
  SIM900.println((char)26);                       // End AT command with a ^Z, ASCII code 26
  delay(200); 
  SIM900.println();
  delay(1000);                                     // give module time to send SMS
  digitalWrite(9, LOW);
  Serial.println(" Message Sent");
  }
 
void loop()
{
int  val = digitalRead(25);   // read the input pin
//deSerial.println("");
Serial.println(val);
 delay(100);
  digitalWrite(9, val);    // sets the LED to the button's value
if(val==HIGH)
 {
  delay(1000); 
   sendSMS();
   delay(2000);
    Serial.println(" Call Initiated");
   callSomeone(); // call someone
    delay(1000); 
    calltwo();  
     
 }
  //SIM900power();   // power off GSM shield
 //do {} while (1); // do nothing */
}
