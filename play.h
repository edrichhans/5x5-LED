#include "notes.h"
void play(){
  tone(12, NOTE_C7, 250);        //port 12
  delay(300);
  noTone(12);
}
