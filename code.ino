int motor1Pins[2]={A0,A1};
int motor2Pins[2]={A2,A3};
int motor3Pins[2]={6,7};
int motorMask[4] = {9, 3, 6, 12};
int servo = 0;
int servot = A4;
int angle;
int pwm;
int numOfMix = 0 ;
int revelotion = 1000;
#define  redled  2
#define reddec 4
#define  yallowdec 3
#define KEYPAd A5
int keypadholds[4]={929,774,852,720};
char keypad[4]={'1','2','3','4'};
bool s = false;
void setup()
{
 Serial.begin(9600);
// Declare pins of servo as output:
 pinMode(servo, OUTPUT);
 pinMode(servot, OUTPUT);    
// Declare pins mixer motor as output:
 pinMode(A0, OUTPUT);
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);
 pinMode(A3, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(redled, OUTPUT);
 pinMode(KEYPAd,INPUT);
 pinMode(reddec, OUTPUT);
 pinMode(yallowdec, OUTPUT);
}

void loop ()
{
MixTheCake();
 revelotion = 400;
 BakingTheCake();
 s = false;
  while(!s){
 DecTheCake();}
 
}

void servoPulse (int angle ,int serv)
{
 pwm = (angle*9) + 500;      // Convert angle to microseconds
 digitalWrite(serv, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(serv, LOW);
}

void motorMovement (int motorPins[]){
for (int i = 0; i < 4; i++){
  for (int j = 0; j < 2 ; j++){
    digitalWrite(motorPins[j], (motorMask[i] & (1 << j)));
    delayMicroseconds(revelotion);
    }
   }
}

void MixTheCake()
  {
    ADDComponent("Add Egg",500);
    for(int j =0 ; j< 5 ; j++)
    {
      for(int i =0 ; i< 90 ; i++)
      {
        motorMovement(motor1Pins);
      }
     numOfMix+=1;
     Serial.println(numOfMix);
    }
    ADDComponent("Add Vanilla",200);
    for(int j =0 ; j< 4 ; j++)
    {
      for(int i =0 ; i< 90 ; i++)
      {
        motorMovement(motor1Pins);
      }
     numOfMix+=1;
     Serial.println(numOfMix);
    }
    ADDComponent("Add Sugar",100); 
    for(int j =0 ; j< 10 ; j++)
    {
      for(int i =0 ; i< 90 ; i++)
      {
        motorMovement(motor1Pins);
      }
     numOfMix+=1;
     Serial.println(numOfMix);
    }
    revelotion=4;
    Serial.println("Speed red.");
    for (int i = 0; i < 3; i++)
    {
      AddFlour();
    }
    Serial.println("finish mix");
    numOfMix = 0;
  }

void ADDComponent(String Component, int period){
  Serial.println(Component);
  servoPulse(20 ,servo);
  servoPulse(180,servo);
  delay(period);
  servoPulse(20,servo);
}
void AddFlour()
{   
    ADDComponent("add Flour",100); 
    for(int j =0 ; j< 4 ; j++)
    {
      for(int i =0 ; i< 90 ; i++)
      {
        motorMovement(motor1Pins);
      }
     numOfMix+=1;
     Serial.println(numOfMix);
    }
}

void BakingTheCake()
{
  for(int i =0 ; i< 90 ; i++)
    {
     motorMovement(motor2Pins);
    }
  digitalWrite(redled, HIGH);
  delay(1000); 
  digitalWrite(redled, LOW);
  for(int i =0 ; i< 90 ; i++)
    {
     motorMovement(motor2Pins);
    }
  delay(1000); 
}

void DecTheCake()
{

 int value = analogRead(KEYPAd);
 int key;
for(int i = 0; i< 4 ; i++)
 {
  if(value == keypadholds[i])
  {
    int key = keypadholds[i];
    int value = (int)keypad[i];
    value = value - 48;
    Serial.print(value);
    Serial.print(value);
    switch (value) 
    {
  case 1:
    Serial.println("key 1 pressed");
    decor1();
    s = true;
    break;
  case 2:
      Serial.println("key 2 pressed");
      decor2();
      s = true;
    break;
  case 3:
      Serial.println("key 3 pressed");
      decor3();
      s = true;
    break;
  case 4:
      Serial.println("key 4 pressed");
      decor4();
      s = true;
    break;
  default:
     Serial.println("none");
    break;
    }
  }
 }


}

void decor1()
{
  servoPulse(10,servot);
  digitalWrite(reddec, HIGH);
  for(int i =0 ; i< 140 ; i++)
    {
     motorMovement(motor3Pins);
    }
  digitalWrite(reddec, LOW);
  digitalWrite(yallowdec, HIGH);
  servoPulse(90,servot);
  for(int j =0 ; j< 140 ; j++)
    {
     motorMovement(motor3Pins);
    }
  digitalWrite(yallowdec,LOW);
  servoPulse(0,servot);
}

void decor2()
{
  servoPulse(10 ,servot);
  for(int i =0 ; i< 4 ; i++)
  {
    digitalWrite(reddec, HIGH);
    for(int j =0 ; j< 17 ; j++)
    {
      motorMovement(motor3Pins);
    }
    digitalWrite(reddec, LOW);
    for(int q =0 ; q< 17 ; q++)
    {
      motorMovement(motor3Pins);
    }
  }
  digitalWrite(reddec, LOW);
  servoPulse(90,servot);
  for(int w =0 ; w< 4 ; w++)
  {
    digitalWrite(yallowdec,LOW);
    for(int e =0 ; e< 17 ; e++)
    {
      motorMovement(motor3Pins);
    }
    digitalWrite(yallowdec, HIGH);
    for(int r =0 ; r< 17 ; r++)
    {
      motorMovement(motor3Pins);
    }
  }
  digitalWrite(yallowdec,LOW);
  servoPulse(0 ,servot);
}
void decor3()
{
  servoPulse(10 ,servot);
  digitalWrite(reddec, HIGH);
  for(int i =0 ; i< 14 ; i++)
  {
    for(int j =0 ; j< 10 ; j++)
    {
      motorMovement(motor3Pins);
    }
    delay(500);
  }
  digitalWrite(reddec, LOW);
  digitalWrite(yallowdec, HIGH);
  servoPulse(120,servot);
  for(int q =0 ; q< 1 ; q++)
  {
    for(int w =0 ; w< 10 ; w++)
    {
      motorMovement(motor3Pins);
    }
    delay(1000);
  }
  digitalWrite(yallowdec,LOW);
  servoPulse(0 ,servot);
}
void decor4()
{
  servoPulse(10 ,servot);
  
  for(int i =0 ; i< 7 ; i++)
  {
    digitalWrite(reddec, HIGH);
    for(int j =0 ; j< 10 ; j++)
    {
      motorMovement(motor3Pins);
    }
    delay(500);
    digitalWrite(reddec, LOW);
    digitalWrite(yallowdec, HIGH);
    for(int k =0 ; k< 10 ; k++)
    {
      motorMovement(motor3Pins);
    }
    delay(1000);
    digitalWrite(yallowdec,LOW);
  }
  digitalWrite(yallowdec,LOW);
  digitalWrite(reddec, LOW);
  servoPulse(100,servot);
  digitalWrite(reddec, HIGH);
    for(int w =0 ; w< 140 ; w++)
    {
      motorMovement(motor3Pins);
    }
  digitalWrite(reddec, LOW);
  servoPulse(0 ,servot);
}
