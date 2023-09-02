#include <Time.h>
#include <TimeAlarms.h>
#include <Wire.h> 
#include <DS1307RTC.h> 
void setup()
{
  Serial.begin(9600);
  /*setTime(11,48,00,5,12,19);// H,M,S,D,M,A
  RTC.set(now());*/
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if (timeStatus() != timeSet) 
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");   
      //Rele 1 introduce aire
Alarm.alarmRepeat(7, 28, 0, ssr1ON);
   Alarm.alarmRepeat(7, 29, 0, ssr1OFF);
   Alarm.alarmRepeat(9, 28, 0, ssr1ON);
   Alarm.alarmRepeat(9, 29, 0, ssr1OFF);
Alarm.alarmRepeat(11, 28, 0, ssr1ON);
   Alarm.alarmRepeat(11, 29, 0, ssr1OFF);
   Alarm.alarmRepeat(13, 28, 0, ssr1ON);
   Alarm.alarmRepeat(13, 29, 0, ssr1OFF);
Alarm.alarmRepeat(15, 28, 0, ssr1ON);
   Alarm.alarmRepeat(15, 29, 0, ssr1OFF);
   Alarm.alarmRepeat(17, 28, 0, ssr1ON);
   Alarm.alarmRepeat(17, 29, 0, ssr1OFF);
Alarm.alarmRepeat(19, 28, 0, ssr1ON);
   Alarm.alarmRepeat(19, 29, 0, ssr1OFF);
//rele 2 ventilación interna
Alarm.alarmRepeat(7, 35, 0, ssr2ON);
   Alarm.alarmRepeat(7, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(8, 35, 0, ssr2ON);
   Alarm.alarmRepeat(8, 45, 0, ssr2OFF);
Alarm.alarmRepeat(9, 35, 0, ssr2ON);
   Alarm.alarmRepeat(9, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(10, 35, 0, ssr2ON);
   Alarm.alarmRepeat(10, 45, 0, ssr2OFF);
Alarm.alarmRepeat(11, 35, 0, ssr2ON);
   Alarm.alarmRepeat(11, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(12, 35, 0, ssr2ON);
   Alarm.alarmRepeat(12, 45, 0, ssr2OFF);
Alarm.alarmRepeat(13, 35, 0, ssr2ON);
   Alarm.alarmRepeat(13, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(14, 35, 0, ssr2ON);
   Alarm.alarmRepeat(14, 45, 0, ssr2OFF);
Alarm.alarmRepeat(15, 35, 0, ssr2ON);
   Alarm.alarmRepeat(15, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(16, 35, 0, ssr2ON);
   Alarm.alarmRepeat(16, 45, 0, ssr2OFF);
Alarm.alarmRepeat(17, 35, 0, ssr2ON);
   Alarm.alarmRepeat(17, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(19, 35, 0, ssr2ON);
   Alarm.alarmRepeat(19, 45, 0, ssr2OFF);
Alarm.alarmRepeat(20, 35, 0, ssr2ON);
   Alarm.alarmRepeat(20, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(21, 35, 0, ssr2ON);
   Alarm.alarmRepeat(21, 45, 0, ssr2OFF);
Alarm.alarmRepeat(22, 35, 0, ssr2ON);
   Alarm.alarmRepeat(22, 45, 0, ssr2OFF);
   Alarm.alarmRepeat(23, 35, 0, ssr2ON);
   Alarm.alarmRepeat(23, 45, 0, ssr2OFF);

    pinMode(8, OUTPUT); //declarar pin 8 como salida RELE 1
    digitalWrite(8, HIGH); // apagar RELE 1 
    Serial.print("RELE 1 se apago a la/las: ");
    digitalClockDisplay();
    Serial.println();
    pinMode(6, OUTPUT);
    digitalWrite(6, HIGH); 
    Serial.print("RELE 2 se apago a la/las: ");
    digitalClockDisplay();
  
}
void  loop(){  
  digitalClockDisplay();
  Alarm.delay(20000);
}

void ssr1ON(){
Serial.print("RELE 1 encendido a la/las: ");
digitalClockDisplay();
digitalWrite(8, LOW); 
Serial.println(); 
}

void ssr1OFF(){
Serial.print("RELE 1 apagado a la/las: ");
digitalClockDisplay();
digitalWrite(8, HIGH); 
Serial.println(); 
}

void ssr2ON(){
Serial.print("RELE 2 encendido a la/las: ");
digitalClockDisplay();
digitalWrite(6, LOW); 
Serial.println(); 
}

void ssr2OFF(){
Serial.print("RELE 2 apagado a la/las: ");
digitalClockDisplay();
digitalWrite(6, HIGH); 
Serial.println(); 
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
