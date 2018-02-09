#define CLEAR_DISPLAY 0X01
#define CURSOR_OFF 0x0c

/*#define RS 12
#define ENABLE 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2*/

void sendMyString(char *str);
void writeData(char c);
void sendComand(char c);
void sendChar(char c);
void displayInit(int R,int E,int pino4, int pino5,int pino6,int pino7);
void lcd_goto(char y, char x);
