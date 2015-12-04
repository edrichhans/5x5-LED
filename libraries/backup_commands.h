void on(int n){
  digitalWrite(n%5+2, HIGH);
  digitalWrite((n/5)+7, LOW);
}
void off(int n){
  digitalWrite(n%5+2, LOW);
  digitalWrite((n/5)+7, HIGH);
}
void on_row(int row){
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite((row/5)+7, LOW);
}
void off_row(int row){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(2, LOW);
  digitalWrite((row/5)+7, HIGH);
}
void on_col(int col){
  digitalWrite(col%5+2, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void off_col(int col){
  digitalWrite(col%5+2, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}
void blink(int n){
  on(n);
  delay(1);
  off(n);
}

void lateral_wipe(int bpm){
  int sec = 60000/bpm; 
  on_col(0);
  delay(sec/5);
  off_col(0);
  on_col(1);
  delay(sec/5);
  off_col(1);
  on_col(2);
  delay(sec/5);
  off_col(2);
  on_col(3);
  delay(sec/5);
  off_col(3);
  on_col(4);
  delay(sec/5);
  off_col(4);
}

void lateral_wipe_reverse(int bpm){
  int sec = 60000/bpm; 
  on_col(4);
  delay(sec/5);
  off_col(4);
  on_col(3);
  delay(sec/5);
  off_col(3);
  on_col(2);
  delay(sec/5);
  off_col(2);
  on_col(1);
  delay(sec/5);
  off_col(1);
  on_col(0);
  delay(sec/5);
  off_col(0);
}

void positive_diagonal_wipe(int bpm){
  int sec = 60000/bpm;
  sec = sec/7;
  long t = millis();
  while(1){
    blink(20);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(21);
    blink(15);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(10);
    blink(16);
    blink(22);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(5);
    blink(11);
    blink(17);
    blink(23);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(0);
    blink(6);
    blink(12);
    blink(18);
    blink(24);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(1);
    blink(7);
    blink(13);
    blink(19);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(2);
    blink(8);
    blink(14);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(3);
    blink(9);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(4);
    if(millis() > t+sec) break;
  }
}

void positive_diagonal_wipe_reverse(int bpm){
  long sec = 60000/bpm;
  sec = sec/7;
  long t = millis();
  while(1){
    blink(4);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(3);
    blink(9);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(2);
    blink(8);
    blink(14);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(1);
    blink(7);
    blink(13);
    blink(19);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(0);
    blink(6);
    blink(12);
    blink(18);
    blink(24);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(5);
    blink(11);
    blink(17);
    blink(23);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(10);
    blink(16);
    blink(22);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(15);
    blink(21);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(20);
    if(millis() > t+sec) break;
  }
}
void negative_diagonal_wipe(int bpm){
  long sec = 60000/bpm;
  sec = sec/7;
  long t = millis();
  while(1){
    blink(24);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(23);
    blink(19);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(22);
    blink(18);
    blink(14);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(21);
    blink(17);
    blink(13);
    blink(9);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(20);
    blink(16);
    blink(12);
    blink(8);
    blink(4);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(15);
    blink(11);
    blink(7);
    blink(3);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(10);
    blink(6);
    blink(2);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(5);
    blink(1);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(0);
    if(millis() > t+sec) break;
  }
}
void negative_diagonal_wipe_reverse(int bpm){
  int sec = 60000/bpm;
  sec = sec/7;
  long t = millis();
  while(1){
    blink(0);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(1);
    blink(5);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(10);
    blink(6);
    blink(2);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(15);
    blink(11);
    blink(7);
    blink(3);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(20);
    blink(16);
    blink(12);
    blink(8);
    blink(4);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(21);
    blink(17);
    blink(13);
    blink(9);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(22);
    blink(18);
    blink(14);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(23);
    blink(19);
    if(millis() > t+sec) break;
  }
  t = millis();
  while(1){
    blink(24);
    if(millis() > t+sec) break;
  }
}