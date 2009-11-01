/*
/
/	video.c
/All of the video functions to print text to screen
/
/
*/

#include <system.h>
#include <string.h>

//text color and postion of current character on screen
int color = 0x0f;
int x=0, y=0;


unsigned short *textptr = (unsigned short *)0xb8000;
unsigned short temp = 0;


void change_textcolor(int fore, int back)
{
	color = (back << 4) | (fore & 0x0f);
}

void scroll()
{
	//blank = ' ' or a space
	//scrolls up one line on the screen
	unsigned blank;
	blank = 0x20 | (color << 8);
	
	if(y>=25){
		temp = y -25 +1;
		memcpy(textptr, textptr +temp * 80, (25-temp) * 80 *2);
		memsetw(textptr + (25-temp) * 80, blank, 80);
		y = 25-1;
	}
}

void move_cursor()
{
	temp = y * 80 + x;
	outb(0x3d4, 14);
	outb(0x3d5, temp >> 8);
	outb(0x3d4, 15);
	outb(0x3d5, temp);
}

void putch(uchar c)
{
	unsigned short *where;
	unsigned att = color << 8;
	
	if(c==0x08){
		//Backspace
		if(x != 0){
			x--;
			putch(' ');
			x--;
		}
	}
	
	else if(c=='\r'){
		//Carriage Return
		x = 0;
	}
	
	else if(c=='\n'){
		//Newline
		x = 0;
		y++;
	}

	else if(c=='\t'){
		//tab
		if(x+5>80){
			x=0;
			y++;
		}else{
			x+=5;
		}
	}
	
	else if(c>=' '){
		//anything else
		where = textptr + (y * 80 + x);
		*where = c | att;
		x++;
	}
	
	if(x>= 80){
		x = 0;
		y++;
	}
	
	move_cursor();
	scroll();
}

void cls()
{
	int i, n;
	unsigned short *tmp;

	for(i=0; i<25; i++){
		tmp = textptr + i * 80;
		for(n=80; n!=0; n--){
			*tmp++ = 0x20;
		}
	}
	x = 0; y = 0;
	move_cursor();
}

void printk(const char *format, ...)
{
	char **arg = (char **) &format;
	int c;
	char buf[20];
	
	arg++;
	
	while((c = *format++) != 0){
		if(c!='%'){
			putch(c);
		}else{
			char *p;
			
			c = *format++;
			switch(c){
				//integer 
				case 'i':
				case 'd':
				case 'u':
					itoa(buf, c, *((int *) arg++));
					p = buf;
					goto string;
					break;
				//hex
				case 'x':
					itoa(buf, 'X', *((int *) arg++));
					p = buf;
					goto string;
					break;
				//string
				case 's':
					p = *arg++;
					if(!p){
						p = "(null)";
					}
				
					string:
						while(*p){
							putch(*p++);
						}
					break;
				
				default:
					putch(*((int *) arg++));
					break;
			}
		}
	}
}


