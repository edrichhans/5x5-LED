void play_note(){
  tone(12, melody[thisNote], noteDuration);        //port 12
  noTone(12);
}