#include <Minhabibliotecadisplayled.h>

#define RS 12
#define ENABLE 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

void setup() {
  displayInit(RS,ENABLE,D4, D5,D6,D7);
  sendMyString("Gustavo Riposati");
}

void loop() {
  
}
