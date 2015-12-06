#include "notes.h"
void play(){
  tone(12, NOTE_C7, 10000);        //port 12
  delay(1000);
  noTone(12);
  digitalWrite(12, LOW);
}
