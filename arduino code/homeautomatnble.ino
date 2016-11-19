String voice;
#define relayLight 2 //pin connected to input1 of relay
#define relayFan 3   //pin connected to input1 of relay
void setup() 
{
 Serial.begin(9600);
 pinMode(relayLight,OUTPUT);
 pinMode(relayFan,OUTPUT);
 digitalWrite(relayLight,HIGH); //initially turn off the light
 digitalWrite(relayFan,HIGH);  //initially turn off the fan
 } 

 void loop() {  
  while(Serial.available())
  {
    delay(10); 
    char c = Serial.read();  
    if(c=='#')
 {    break;  
 }
   voice +=c; 
 }
 if(voice.length()>0) 
 {
  Serial.println(voice); 
  if(voice=="*light on")
  { 
    lighton(); 
   }
   else if(voice=="*light off")
   { 
    lightoff(); 
    }
    else if(voice=="*fan on")
    { 
      fanon(); 
    } 
  else if(voice=="*fan stop")
  { 
    fanoff();   
   }
   voice="";  
   }
 } 
 
void lighton()
{ 
  digitalWrite(relayLight,LOW);
 }
 void lightoff() 
 {
  digitalWrite(relayLight,HIGH);
  } 
 
void fanon()
{   digitalWrite(relayFan,LOW);
}
void fanoff()
{  
  digitalWrite(relayFan,HIGH);
  } 
