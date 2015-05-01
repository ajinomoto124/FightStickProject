 
//#include <HID.cpp> 

JoyState_t joystick;
//structure
int downPressed = 0;
int timeSince = 0;
int switchState = 0;
int facing = 0; //0 for right, 1 for left
unsigned int buttons;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  //analogs being read as digital
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

//  Keyboard.begin(); 
}

void loop(){

  buttons = 0x0000;
  
  int up = digitalRead(A0);
  int down = digitalRead(A1);
  int right = digitalRead(A2);
  int left = digitalRead(A3);
  int mode = digitalRead(A4);
  
  int lp = digitalRead(2);
  int mp = digitalRead(3);
  int mk = digitalRead(4);
  int lk = digitalRead(5);
  int hk = digitalRead(6);
  int hp = digitalRead(7);
  int alt2 = digitalRead(8);
  int alt1 = digitalRead(9);
  int start = digitalRead(10);
  int select = digitalRead(11);
  int esc = digitalRead(12);
  joystick.hatSw1 = 8;
  joystick.hatSw2 = 8;
  joystick.xAxis = 254/2;
  joystick.yAxis = 254/2;
  joystick.xRotAxis = 254/2;
  joystick.yRotAxis = 254/2;
  if(up == LOW){
    joystick.hatSw1 = 0;
    if(right == LOW){
      joystick.hatSw1 = 1;
    }
    if(left == LOW){
      joystick.hatSw1 = 7;
    }
  }
  else if(down == LOW){
    joystick.hatSw1 = 4;
    if(right == LOW){
      joystick.hatSw1 = 3;
    }
    if(left == LOW){
      joystick.hatSw1 = 5;
    }
  }
  else if(right == LOW){
    joystick.hatSw1 = 2;
  }
  else if(left == LOW){
   joystick.hatSw1 = 6;
  }
  if(lp == LOW){//button 1 = square
    buttons += 0x0001;
  }
  if(mp == LOW){//4 =triangle
    buttons += 0x0008;
  }
  if(hp == LOW){//5 = l1
    buttons += 0x0010;
  }
  if(lk == LOW){//2 = X
    buttons += 0x0002;
  }
  if(mk == LOW){//3 = CIRCLE
    buttons += 0x0004;
  }
  if(hk == LOW){//7 = l2
    buttons += 0x0040;
  }
  if(alt1 == LOW){//6 = r1
    buttons += 0x0020;
  }
  if(alt2 == LOW){//8 = r2
    buttons += 0x0080;
  }
  if(start == LOW){//10 = start
    buttons += 0x0200;
  }
  if(select == LOW){//9 = select
    buttons += 0x0100;
  }
  if(esc == LOW){//
    buttons += 0x1000;
  }
  if(mode == LOW){//15
    buttons += 0x2000;
  }
  joystick.buttons = buttons;
  Joystick.setState(&joystick);
delay(5);
}

