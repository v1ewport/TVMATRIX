#include <TVout.h>

TVout TV;
String CHARACTERS = "1234567890qwertyuiopasdfghjklzxcvbnm,.-_<>!#$%&/()=?¡";

int COLUMN[18];
int COL_LENGTH[18];

void ERASE(int X, int Y) { TV.draw_line(X, Y, X+7, Y, 0); }

void setup() {
  TV.start_render(_NTSC);
  TV.clear_screen(); 
  for (int C=0; C<18; C++) { COL_LENGTH[C]=random(25, 80); }
  for (int C=0; C<18; C++) { COLUMN[C] = random(-80, 0); }
}

void loop() { 
  for (int C=0; C<18; C++) { 
    if (COLUMN[C]-COL_LENGTH[C]>0) { TV.draw_line(C*7, COLUMN[C]-COL_LENGTH[C], (C*7)+7, COLUMN[C]-COL_LENGTH[C], 0); }
    if (COLUMN[C]>0 && COLUMN[C]<TV.vert_res()) { TV.print_char(C*7, COLUMN[C], (char)CHARACTERS.charAt(random(0, strlen(CHARACTERS.c_str())))); }
    COLUMN[C]++; 
  }
  for (int C=0; C<18; C++) { 
    if (COLUMN[C]>TV.vert_res()+COL_LENGTH[C]) { COLUMN[C]=random(-80, 0); COL_LENGTH[C]=random(25, 80); } 
  }
}