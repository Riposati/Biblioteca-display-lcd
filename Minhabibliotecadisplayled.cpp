#include "Minhabibliotecadisplayled.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Arduino.h"

int ENABLE,RS,D4,D5,D6,D7;

void displayInit(int R,int E,int pino4, int pino5,int pino6,int pino7){

    RS = R;
    ENABLE = E;
    D4 = pino4;
    D5 = pino5;
    D6 = pino6;
    D7 = pino7;

    pinMode(ENABLE,OUTPUT);
    pinMode(RS,OUTPUT);
    pinMode(D4,OUTPUT);
    pinMode(D5,OUTPUT);
    pinMode(D6,OUTPUT);
    pinMode(D7,OUTPUT);
    delay(5000);

    sendComand(0b00000011);
    delayMicroseconds(5400);

    sendComand(0b00000011);
    delayMicroseconds(5400);

    sendComand(0b00000011);
    delayMicroseconds(5400);

    sendComand(0b00000010);
    delayMicroseconds(5400);

    sendComand(0x0D);
    sendComand(0x28);
    delayMicroseconds(100);

    digitalWrite(11,LOW);
    sendComand(CLEAR_DISPLAY);
    delay(500);

    lcd_goto(0,0);
}

void writeData(char c){

    digitalWrite(D4,c&1);
    c=c>>1;
    digitalWrite(D5,c&1);
    c=c>>1;
    digitalWrite(D6,c&1);
    c=c>>1;
    digitalWrite(D7,c&1);
}

void sendComand(char c){
  digitalWrite(RS,LOW);
  writeData((c>>4)&0xff);
  digitalWrite(ENABLE,HIGH);
  delayMicroseconds(5400);
  digitalWrite(ENABLE,LOW);
  digitalWrite(RS,LOW);
  writeData(c&0xff);
  digitalWrite(ENABLE,HIGH);
  delayMicroseconds(5400);
  digitalWrite(ENABLE,LOW);
}

void sendChar(char c){

  digitalWrite(RS,HIGH);
  writeData((c>>4)&0xff);
  digitalWrite(ENABLE,HIGH);
  delayMicroseconds(100);
  digitalWrite(ENABLE,LOW);
  digitalWrite(RS,HIGH);
  writeData(c&0xff);
  digitalWrite(ENABLE,HIGH);
  delayMicroseconds(100);
  digitalWrite(ENABLE,LOW);
}

void sendMyString(char *str){

  int i=0;

  while(str[i]!='\0'){
    sendChar(str[i]);
    i++;
  }
}

void lcd_goto(char y, char x){
    if(y==0)
        sendComand(0x80+x);
    else
        sendComand(0xd+x);
}
