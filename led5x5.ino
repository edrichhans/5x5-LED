#include "commands.h"
#include "play.h"
#define beats 120
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  Serial.begin(9600);
  
}

void loop() {
  countdown(beats);//
  bars(beats);//
  blinds(beats);//
  snake_on(beats/2);//
  snake_off(beats/2);//
  burst(beats);//
  collapse(beats);//
  burst(beats);
  collapse(beats);
  strobe(beats);//
  strobe(beats);
  positive_diagonal_wipe(beats);//
  positive_diagonal_wipe_reverse(beats);//
  negative_diagonal_wipe(beats);//
  negative_diagonal_wipe_reverse(beats);//
  lateral_wipe(beats); //
  lateral_wipe_reverse(beats);//
}

