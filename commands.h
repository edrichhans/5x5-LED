#include <Arduino.h>

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
void on_led(int arr[], int n, int sec){
  long t = millis();
  while(1){
    int i;
    for(i = 0; i < n; i++){
      if(arr[i] >= 0 && arr[i] < 25){
        on(arr[i]);
        delay(1);
      }
      off(arr[i]);
    }
    if(millis() > t+sec) break;
  }
}

void lateral_wipe(int bpm){
  int sec = 60000/bpm;
  sec /= 6;
  int i;
  for(i = 0; i < 5; i++){
    on_col(i);
    delay(sec);
    off_col(i);
  }
  delay(sec);
}

void lateral_wipe_reverse(int bpm){
  int sec = 60000/bpm; 
  sec /= 6;
  int i;
  for(i = 4; i >= 0; i--){ 
    on_col(i);
    delay(sec);
    off_col(i);
  }
  delay(sec);
}

void positive_diagonal_wipe(int bpm){
  int sec = 60000/bpm;
  sec = sec/10;
  int arr[][5] = {{20},{21, 15},{10, 16, 22},{5, 11, 17, 23},{0, 6, 12, 18, 24},{1, 7, 13, 19},{2, 8, 14},{3, 9},{4}};
  int i, j, s;
  for(i = 0; i < 9; i++){
    if(i < 5) s = i + 1;
    else if(i >= 5){
      s = 4-(i-5);
    }
    on_led(arr[i], s, sec);
  }
  delay(sec);
}

void positive_diagonal_wipe_reverse(int bpm){
  int sec = 60000/bpm;
  sec = sec/10;
  int arr[][5] = {{4},{3, 9},{2, 8, 14},{1, 7, 13, 19},{0, 6, 12, 18, 24},{5, 11, 17, 23},{10, 16, 22},{21, 15},{20}};
  int i, j, s;
  for(i = 0; i < 9; i++){
    if(i < 5) s = i + 1;
    else if(i >= 5){
      s = 4-(i-5);
    }
    on_led(arr[i], s, sec);
  }
  delay(sec);
}
void negative_diagonal_wipe(int bpm){
  int sec = 60000/bpm;
  sec = sec/10;
  int arr[][5] = {{24}, {23, 19}, {22, 18, 14}, {21, 17, 13, 9}, {20, 16, 12, 8, 4}, {15, 11, 7, 3}, {10, 6, 2}, {1, 5}, {0}};
  int i, j, s;
  for(i = 0; i < 9; i++){
    if(i < 5) s = i + 1;
    else if(i >= 5){
      s = 4-(i-5);
    }
    on_led(arr[i], s, sec);
  }
  delay(sec);
}
void negative_diagonal_wipe_reverse(int bpm){
  int sec = 60000/bpm;
  sec = sec/10;
  int arr[][5] = {{0}, {1, 5}, {10, 6, 2}, {15, 11, 7, 3}, {20, 16, 12, 8, 4}, {21, 17, 13, 9}, {22, 18, 14}, {23, 19}, {24}};
  int i, j, s;
  for(i = 0; i < 9; i++){
    if(i < 5) s = i + 1;
    else if(i >= 5){
      s = 4-(i-5);
    }
    on_led(arr[i], s, sec);
  }
  delay(sec);
}

void strobe(int bpm){
  int sec = 60000/bpm;
  sec = sec/2;
  int i;
  for(i = 0; i < 5; i++) on_col(i);
  delay(sec);
  for(i = 0; i < 5; i++) off_col(i);
  delay(sec);
}

void burst(int bpm){
  int sec = 60000/bpm;
  sec /= 4;
  int arr1[1] = {12};
  on_led(arr1, 1, sec);
  int arr2[8] = {6, 7, 8, 13, 11, 16, 17, 18};
  on_led(arr2, 8, sec);
  int arr3[16] = {0, 1, 2, 3, 4, 5, 9, 10, 14, 15, 19, 20, 21, 22, 23, 24};
  on_led(arr3, 16, sec);
  delay(sec);
}

void collapse(int bpm){
  int sec = 60000/bpm;
  sec /= 4;
  int arr1[16] = {0, 1, 2, 3, 4, 5, 9, 10, 14, 15, 19, 20, 21, 22, 23, 24};
  on_led(arr1, 16, sec);
  int arr2[8] = {6, 7, 8, 13, 11, 16, 17, 18};
  on_led(arr2, 8, sec);
  int arr3[1] = {12};
  on_led(arr3, 1, sec);
  delay(sec); 
}

void snake_on(int bpm){
  int sec = 60000/bpm;
  sec /= 25;
  int arr[] = {12, 7, 6, 11, 16, 17, 18, 13, 8, 3, 2, 1, 0, 5, 10, 15, 20, 21, 22, 23, 24, 19, 14, 9, 4};
  int i;
  for(i = 0; i < 25; i++){
    on_led(arr, i+1, sec);
  }
}
void snake_off(int bpm){
  int sec = 60000/bpm;
  sec /= 25;
  int arr[] = {12, 13, 18, 17, 16, 11, 6, 7, 8, 9, 14, 19, 24, 23, 22, 21, 20, 15, 10, 5, 0, 1, 2, 3, 4};
  int i;
  for(i = 24; i >= 0; i--){
    on_led(arr, i, sec);
  }
}
void countdown(int bpm){
  int sec = 60000/bpm;
  sec *= 2;
  int arr[][17] = {{0, 5, 10, 15, 20, 2, 3, 4, 7, 9, 12, 14, 17, 19, 22, 23, 24},//10
                   {1, 2, 3, 6, 8, 11, 12, 13, 18, 21, 22, 23},//9
                   {1, 2, 3, 6, 8, 11, 12, 13, 18, 21, 22, 23, 16},//8
                   {1, 2, 3, 8, 13, 18, 23},//7
                   {1, 2, 3, 6, 11, 12, 13, 16, 18, 21, 22, 23},//6
                   {1, 2, 3, 6, 11, 12, 13, 18, 21, 22, 23},//5
                   {1, 3, 6, 8, 11, 12, 13, 18, 23},//4
                   {1, 2, 3, 8, 11, 12, 13, 18, 21, 22, 23},//3
                   {1, 2, 3, 8, 11, 12, 13, 16, 21, 22, 23},//2
                   {2, 7, 12, 17, 22},//1
                   {1, 2, 3, 6, 8, 11, 13, 16, 18, 21, 22, 23}};//0
   int sizes[] = {17, 12, 13, 7, 12, 11, 9, 11, 11, 5, 12};
  int i, j;
  for(i = 0; i < 11; i++){
    on_led(arr[i], sizes[i], sec);
  }
}
void bars(int bpm){
  int sec = 60000/bpm;
  sec /= 4;
  int arr[] = {-3, -2, -1};
  int i;
  for(i = 0; i < 28; i++){
    on_led(arr, 3, sec);
    arr[0] ++;
    arr[1] ++;
    arr[2] ++;
  };
}

void blinds(int bpm){
  int sec = 6000/bpm;
  int arr[][3] = {{-3, -2, -1},//0
                  {10, 11, 12},//5
                  {7, 8, 9},//10
                  {21, 22, 23},//15
                  {17, 18, 19}};//20
  int i, j, k;
  int arrtemp[15];
  for(k = 0; k < 8; k++){
    for(i = 0; i < 5; i++){
      for(j = 0; j < 3; j++){
        if(arr[i][j] >= i*5 && arr[i][j] < i*5+5) arrtemp[((i+1)*3)-j-1] = arr[i][j];
        else arrtemp[((i+1)*3)-j-1] = -1;
        if(i % 2 == 0) arr[i][j] += 1;
        else arr[i][j] -= 1;
      }
    }
    on_led(arrtemp, 15, sec*2);
  }
}
