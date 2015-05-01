
int downPressed = 0;
int timeSince = 0;
int switchState = 0;
int facing = 0; //0 for right, 1 for left
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

  //analogs being read as digital
 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  Keyboard.begin(); 
}

void loop(){

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
  if(alt1 == LOW && alt2 == LOW && left == LOW){
    facing = 0;
  }
  else if(alt1 == LOW && alt2 == LOW && right == LOW){
    facing = 1;
  }
  else if(alt1 == LOW && alt2 == HIGH){
    if(lp == LOW){
      demon(facing);
    }
    else if(mp == LOW){
      if(facing == 1){
        qcf();
      }
      else{
        qcb();
      }
      delay(16.67);
      Keyboard.press('u');
      delay(16.67);
      Keyboard.release('u');
    }
    else if(mk == LOW){
      if(facing == 1){
        qcb();
      }
      else{
        qcf();
      }
      delay(16.67);
      Keyboard.press('j');
      delay(16.67);
      Keyboard.release('j');
    }
    else if(hp == LOW){
      hpCombo(facing);
    }
    else{
      if(facing == 1){
      Keyboard.press(KEY_LEFT_SHIFT);
      }
      else{
      Keyboard.press(KEY_RIGHT_SHIFT);
      }
      Keyboard.press('w');
    }
  }
  else if(alt2 == LOW && alt1 == HIGH){
    if(lk == LOW){
      crTech(facing);
    }
    else if(lp == LOW){
      osSweep();
    }
    else{
      if(facing == 0){
      Keyboard.press(KEY_LEFT_SHIFT);
      }
      else{
      Keyboard.press(KEY_RIGHT_SHIFT);
      }
      Keyboard.press('s');
    }
  }
  else if(alt1 == HIGH && alt2 == HIGH){
    if(up == HIGH){
    Keyboard.release('w');
    }
    if(right ==  HIGH && alt2 == HIGH){
    Keyboard.release(KEY_RIGHT_SHIFT);
    }
    if(left == HIGH && alt2 == HIGH){
    Keyboard.release(KEY_LEFT_SHIFT);
    }
  }
   
    if(up != HIGH){
       Keyboard.press('w');
    }
    else if(up == HIGH && alt1 == HIGH){
       Keyboard.release('w');
    }
    if(down != HIGH){
      Keyboard.press('s');
    }
    else if(down == HIGH && alt2 == HIGH){
      Keyboard.release('s');
    }
    if(right != HIGH){
      Keyboard.press(KEY_RIGHT_SHIFT);
    }
    else if (right == HIGH && alt2 == HIGH && alt1 == HIGH){
      Keyboard.release(KEY_RIGHT_SHIFT);
    }
    if(left != HIGH){
      Keyboard.press(KEY_LEFT_SHIFT);
    }
    else if(left == HIGH && alt2 == HIGH && alt1 == HIGH){
      Keyboard.release(KEY_LEFT_SHIFT);
    }
  
    if(lp == LOW && alt2 == HIGH){
      Keyboard.press('y');
    }
    else if(lp == HIGH && alt2 == HIGH){
      Keyboard.release('y');
    }
    if(mp == LOW && alt1 == HIGH){
      Keyboard.press('u');
  }
    else if (mp == HIGH && alt1 == HIGH){
      Keyboard.release('u');
    }
    if(hp == LOW && alt1 == HIGH){
      Keyboard.press('i');
    }
    else if (hp == HIGH && alt1 == HIGH){
      Keyboard.release('i');
    }
    if(lk == LOW && alt2 == HIGH){
      Keyboard.press('h');
    }
    else if(lk == HIGH && alt2 == HIGH){
      Keyboard.release('h');
    }
    if(mk == LOW && alt2 == HIGH){
      Keyboard.press('j');
    }
    else if (mk == HIGH && alt2 == HIGH){
      Keyboard.release('j');
    }
    if(hk == LOW){
      Keyboard.press('k');
    }
    else if (hk == HIGH){
      Keyboard.release('k');
    }
    if(start == LOW){
      Keyboard.press('z');
    }
    else if (start == HIGH){
      Keyboard.release('z');
    }
    if(select == LOW){
        Keyboard.press('w');
        Keyboard.press('d');
      }
    else if (select == HIGH){
        Keyboard.release('w');
        Keyboard.release('d');
    }
    if(esc == LOW){
      Keyboard.press('c');
    }
    else if (esc == HIGH){
      Keyboard.release('c');
    }
delay(5);
}

void qcf(){
      Keyboard.press('s');
      delay(16.67);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(16.67);
      Keyboard.release('s');
      delay(16.67);
      Keyboard.release(KEY_LEFT_SHIFT);
}
void qcb(){
  Keyboard.press('s');
      delay(16.67);
      Keyboard.press(KEY_RIGHT_SHIFT);
      delay(16.67);
      Keyboard.release('s');
      delay(16.67);
      Keyboard.release(KEY_RIGHT_SHIFT);
}
void hpCombo(int dir){
  if(dir == 0){
     Keyboard.press('i');
     delay(16.67);
     Keyboard.release('i');
     Keyboard.press(KEY_LEFT_SHIFT);
     delay(16.67);
     Keyboard.press('s');
     delay(16.67);
     Keyboard.release(KEY_LEFT_SHIFT);
     delay(16.67);
     Keyboard.press(KEY_RIGHT_SHIFT);
     delay(16.67);
     Keyboard.release('s');
     delay(16.67);
     Keyboard.release(KEY_RIGHT_SHIFT);
     Keyboard.press('j');
     delay(16.67);
     Keyboard.release('j');
     Keyboard.press('s');
     delay(1048);
     Keyboard.press('u');
     delay(100.67);
     Keyboard.release('u');
     Keyboard.press(KEY_LEFT_SHIFT);
     delay(16.67);
     Keyboard.release('s');
    delay(16.67);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.press('h');
    delay(16.67);
    Keyboard.release('h');
    delay(750.05);
    Keyboard.press(KEY_RIGHT_SHIFT);
    delay(16.67);
    Keyboard.release(KEY_RIGHT_SHIFT);
    delay(32.67);
    Keyboard.press('s');
    delay(32.67);
    Keyboard.release('s');
    delay(32.67);
    Keyboard.press(KEY_RIGHT_SHIFT);
    delay(16.67);
    Keyboard.release(KEY_RIGHT_SHIFT);
    delay(16.67);
    Keyboard.press('i');
    delay(100);
    Keyboard.release('i');
  }
  else{
   Keyboard.press('i');
     delay(16.67);
     Keyboard.release('i');
     Keyboard.press(KEY_RIGHT_SHIFT);
     delay(16.67);
     Keyboard.press('s');
     delay(16.67);
     Keyboard.release(KEY_RIGHT_SHIFT);
     delay(16.67);
     Keyboard.press(KEY_LEFT_SHIFT);
     delay(16.67);
     Keyboard.release('s');
     delay(16.67);
     Keyboard.release(KEY_LEFT_SHIFT);
     Keyboard.press('j');
     delay(16.67);
     Keyboard.release('j');
     Keyboard.press('s');
     delay(1048);
     Keyboard.press('u');
     delay(100.67);
     Keyboard.release('u');
     Keyboard.press(KEY_RIGHT_SHIFT);
     delay(16.67);
     Keyboard.release('s');
    delay(16.67);
    Keyboard.release(KEY_RIGHT_SHIFT);
    Keyboard.press('h');
    delay(16.67);
    Keyboard.release('h');
    delay(750.05);
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(16.67);
    Keyboard.release(KEY_LEFT_SHIFT);
    delay(32.67);
    Keyboard.press('s');
    delay(32.67);
    Keyboard.release('s');
    delay(32.67);
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(16.67);
    Keyboard.release(KEY_LEFT_SHIFT);
    delay(16.67);
    Keyboard.press('i');
    delay(100);
    Keyboard.release('i');
  }
}
void demon(int dir){
  Keyboard.press('y');
  delay(32);
  Keyboard.release('y');
  delay(32);
  Keyboard.press('y');
  delay(32);
  Keyboard.release('y');
  delay(32);
  if(dir == 0){
    Keyboard.press(KEY_RIGHT_SHIFT);
    delay(32);
    Keyboard.release(KEY_RIGHT_SHIFT);
  }
  else{
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(32);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  delay(32);
  Keyboard.press('h');
  delay(32);
  Keyboard.release('h');
  delay(32);
  Keyboard.press('i');
  delay(32);
  Keyboard.release('i');
}
void osSweep(){
  Keyboard.press('s');
  delay(5);
  Keyboard.press('y');
  delay(16);
  Keyboard.release('y');
  delay(200.67);
  Keyboard.press('y');
  Keyboard.press('k');
  delay(100.67);
  Keyboard.release('y');
  Keyboard.release('k');
  Keyboard.release('s');
}
void crTech(int dir){
  if(dir == 0){
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(5);
    Keyboard.press('s');
    delay(5);
    Keyboard.press('h');
    delay(5);
    Keyboard.press('y');
    delay(100);
    Keyboard.release(KEY_LEFT_SHIFT);
    delay(5);
    Keyboard.release('s');
    delay(5);
    Keyboard.release('h');
    delay(5);
    Keyboard.release('y');
  }
  else{
    Keyboard.press(KEY_RIGHT_SHIFT);
    delay(5);
    Keyboard.press('s');
    delay(5);
    Keyboard.press('h');
    delay(5);
    Keyboard.press('y');
    delay(100);
    Keyboard.release(KEY_RIGHT_SHIFT);
    delay(5);
    Keyboard.release('s');
    delay(5);
    Keyboard.release('h');
    delay(5);
    Keyboard.release('y');
  }
}
