#include <TVout.h>

struct COLUMN { int Y, LENGTH; };

TVout TV;
String CHARACTERS = "1234567890qwertyuiopasdfghjklzxcvbnm,.-_<>!#$%&/()=?¡";
COLUMN COLUMNS[18];

void setup() {
  randomSeed(analogRead(5));
  TV.start_render(_NTSC);
  TV.clear_screen(); 

  for (int C=0; C<18; C++) { COLUMNS[C].Y = random(-80, 0); COLUMNS[C].LENGTH=random(25, 80); }
}

void loop() { 
  for (int C=0; C<18; C++) { 
    if (COLUMNS[C].Y-COLUMNS[C].LENGTH>0) { TV.draw_line(C*7, COLUMNS[C].Y-COLUMNS[C].LENGTH, (C*7)+7, COLUMNS[C].Y-COLUMNS[C].LENGTH, 0); }
    if (COLUMNS[C].Y>0 && COLUMNS[C].Y<TV.vert_res()) { TV.print_char(C*7, COLUMNS[C].Y, (char)CHARACTERS.charAt(random(0, strlen(CHARACTERS.c_str())))); }
    COLUMNS[C].Y++; 
  }
  for (int C=0; C<18; C++) { 
    if (COLUMNS[C].Y>TV.vert_res()+COLUMNS[C].LENGTH) { COLUMNS[C].Y = random(-80, 0); COLUMNS[C].LENGTH=random(25, 80); }
  }
}
