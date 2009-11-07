#include <system.h>

extern void update_caps();
extern void update_scroll();
extern void update_num();

int caps = 0;
int shift = 0;
int numlock = 0;


unsigned int get_scancode()
{
	return inb(0x60);
}

void keyboard_handler(struct regs *r)
{
	unsigned char ch;
	unsigned int scancode = get_scancode();
	
	switch(scancode){
		//hold shift (left)
		case 0xaa: shift = ~shift;
		break;
		
		//release shift (left)
		case 0x2a: shift = ~shift;
		break;
		
		//hold shift (right)
		case 0xb6: shift = ~shift;
		break;
		
		//release shift (right)
		case 0x36: shift = ~shift;
		break;
		
		//caps
		case 58: caps = ~caps;	update_caps();
		break;

		//num lock
		case 0x45: numlock = ~numlock; update_num();
		break;

		//scroll lock
		case 0x46: update_scroll();
		break;	
	}
	
	//printf("%x\n", scancode);
	
	if(shift && caps){
		switch(scancode){
			case 16: ch = 'q';
			break;
			case 17: ch = 'w';
			break;
			case 18: ch = 'e';
			break;
			case 19: ch = 'r';
			break;
			case 20: ch = 't';
			break;
			case 21: ch = 'y';
			break;
			case 22: ch = 'u';
			break;
			case 23: ch = 'i';
			break;
			case 24: ch = 'o';
			break;
			case 25: ch = 'p';
			break;
			case 30: ch = 'a';
			break;
			case 31: ch = 's';
			break;
			case 32: ch = 'd';
			break;
			case 33: ch = 'f';
			break;
			case 34: ch = 'g';
			break;
			case 35: ch = 'h';
			break;
			case 36: ch = 'j';
			break;
			case 37: ch = 'k';
			break;
			case 38: ch = 'l';
			break;
			case 44: ch = 'z';
			break;
			case 45: ch = 'x';
			break;
			case 46: ch = 'c';
			break;
			case 47: ch = 'v';
			break;
			case 48: ch = 'b';
			break;
			case 49: ch = 'n';
			break;
			case 50: ch = 'm';
			break;
			case 2: ch = '!';
			break;
			case 3: ch = '@';
			break;
			case 4: ch = '#';
			break;
			case 5: ch = '$';
			break;
			case 6: ch = '%';
			break;
			case 7: ch = '^';
			break;
			case 8: ch = '&';
			break;
			case 9: ch = '*';
			break;
			case 10: ch = '(';
			break;
			case 11: ch = ')';
			break;
			case 57: ch = ' ';
			break;
			case 28: ch = '\n';
			break;
			case 12: ch = '_';
			break;
			case 13: ch = '+';
			break;
			case 26: ch = '{';
			break;
			case 27: ch = '}';
			break;
			case 122: ch = '/';
			break;
			case 43: ch = '|';
			break;
			case 53: ch = '?';
			break;
			case 15: ch = '\t';
			break;
			case 39: ch = ':';
			break;
			case 40: ch = '"';
			break;
			case 41: ch = '~';
			break;
			case 51: ch = '<';
			break;
			case 52: ch = '>';
			break;
			case 55: ch = '*';
			break;
			case 74: ch = '-';
			break;
			case 78: ch = '+';
			break;
			case 14: ch = '\b';
			break;
		}
	}else
	
	if(shift){
		switch(scancode){
			case 16: ch = 'Q';
			break;
			case 17: ch = 'W';
			break;
			case 18: ch = 'E';
			break;
			case 19: ch = 'R';
			break;
			case 20: ch = 'T';
			break;
			case 21: ch = 'Y';
			break;
			case 22: ch = 'U';
			break;
			case 23: ch = 'I';
			break;
			case 24: ch = 'O';
			break;
			case 25: ch = 'P';
			break;
			case 30: ch = 'A';
			break;
			case 31: ch = 'S';
			break;
			case 32: ch = 'D';
			break;
			case 33: ch = 'F';
			break;
			case 34: ch = 'G';
			break;
			case 35: ch = 'H';
			break;
			case 36: ch = 'J';
			break;
			case 37: ch = 'K';
			break;
			case 38: ch = 'L';
			break;
			case 44: ch = 'Z';
			break;
			case 45: ch = 'X';
			break;
			case 46: ch = 'C';
			break;
			case 47: ch = 'V';
			break;
			case 48: ch = 'B';
			break;
			case 49: ch = 'N';
			break;
			case 50: ch = 'M';
			break;
			case 2: ch = '!';
			break;
			case 3: ch = '@';
			break;
			case 4: ch = '#';
			break;
			case 5: ch = '$';
			break;
			case 6: ch = '%';
			break;
			case 7: ch = '^';
			break;
			case 8: ch = '&';
			break;
			case 9: ch = '*';
			break;
			case 10: ch = '(';
			break;
			case 11: ch = ')';
			break;
			case 57: ch = ' ';
			break;
			case 28: ch = '\n';
			break;
			case 12: ch = '_';
			break;
			case 13: ch = '+';
			break;
			case 26: ch = '{';
			break;
			case 27: ch = '}';
			break;
			case 122: ch = '/';
			break;
			case 43: ch = '|';
			break;
			case 53: ch = '?';
			break;
			case 15: ch = '\t';
			break;
			case 39: ch = ':';
			break;
			case 40: ch = '"';
			break;
			case 41: ch = '~';
			break;
			case 51: ch = '<';
			break;
			case 52: ch = '>';
			break;
			case 55: ch = '*';
			break;
			case 74: ch = '-';
			break;
			case 78: ch = '+';
			break;
			case 14: ch = '\b';
			break;
		}
		//shift = 0;
	}else
	
	if(caps){
		switch(scancode){
			case 16: ch = 'Q';
			break;
			case 17: ch = 'W';
			break;
			case 18: ch = 'E';
			break;
			case 19: ch = 'R';
			break;
			case 20: ch = 'T';
			break;
			case 21: ch = 'Y';
			break;
			case 22: ch = 'U';
			break;
			case 23: ch = 'I';
			break;
			case 24: ch = 'O';
			break;
			case 25: ch = 'P';
			break;
			case 30: ch = 'A';
			break;
			case 31: ch = 'S';
			break;
			case 32: ch = 'D';
			break;
			case 33: ch = 'F';
			break;
			case 34: ch = 'G';
			break;
			case 35: ch = 'H';
			break;
			case 36: ch = 'J';
			break;
			case 37: ch = 'K';
			break;
			case 38: ch = 'L';
			break;
			case 44: ch = 'Z';
			break;
			case 45: ch = 'X';
			break;
			case 46: ch = 'C';
			break;
			case 47: ch = 'V';
			break;
			case 48: ch = 'B';
			break;
			case 49: ch = 'N';
			break;
			case 50: ch = 'M';
			break;
			case 2: ch = '1';
			break;
			case 3: ch = '2';
			break;
			case 4: ch = '3';
			break;
			case 5: ch = '4';
			break;
			case 6: ch = '5';
			break;
			case 7: ch = '6';
			break;
			case 8: ch = '7';
			break;
			case 9: ch = '8';
			break;
			case 10: ch = '9';
			break;
			case 11: ch = '0';
			break;
			case 57: ch = ' ';
			break;
			case 28: ch = '\n';
			break;
			case 12: ch = '-';
			break;
			case 13: ch = '=';
			break;
			case 26: ch = '[';
			break;
			case 27: ch = ']';
			break;
			case 122: ch = '/';
			break;
			case 43: ch = '\\';
			break;
			case 53: ch = '/';
			break;
			case 15: ch = '\t';
			break;
			case 39: ch = ';';
			break;
			case 40: ch = '\'';
			break;
			case 41: ch = '`';
			break;
			case 51: ch = ',';
			break;
			case 52: ch = '.';
			break;
			case 55: ch = '*';
			break;
			case 74: ch = '-';
			break;
			case 78: ch = '+';
			break;
			case 14: ch = '\b';
			break;
		}
	}else{
		
		switch(scancode){
			case 16: ch = 'q';
			break;
			case 17: ch = 'w';
			break;
			case 18: ch = 'e';
			break;
			case 19: ch = 'r';
			break;
			case 20: ch = 't';
			break;
			case 21: ch = 'y';
			break;
			case 22: ch = 'u';
			break;
			case 23: ch = 'i';
			break;
			case 24: ch = 'o';
			break;
			case 25: ch = 'p';
			break;
			case 30: ch = 'a';
			break;
			case 31: ch = 's';
			break;
			case 32: ch = 'd';
			break;
			case 33: ch = 'f';
			break;
			case 34: ch = 'g';
			break;
			case 35: ch = 'h';
			break;
			case 36: ch = 'j';
			break;
			case 37: ch = 'k';
			break;
			case 38: ch = 'l';
			break;
			case 44: ch = 'z';
			break;
			case 45: ch = 'x';
			break;
			case 46: ch = 'c';
			break;
			case 47: ch = 'v';
			break;
			case 48: ch = 'b';
			break;
			case 49: ch = 'n';
			break;
			case 50: ch = 'm';
			break;
			case 2: ch = '1';
			break;
			case 3: ch = '2';
			break;
			case 4: ch = '3';
			break;
			case 5: ch = '4';
			break;
			case 6: ch = '5';
			break;
			case 7: ch = '6';
			break;
			case 8: ch = '7';
			break;
			case 9: ch = '8';
			break;
			case 10: ch = '9';
			break;
			case 11: ch = '0';
			break;
			case 57: ch = ' ';
			break;
			case 28: ch = '\n';
			break;
			case 12: ch = '-';
			break;
			case 13: ch = '=';
			break;
			case 26: ch = '[';
			break;
			case 27: ch = ']';
			break;
			case 122: ch = '/';
			break;
			case 43: ch = '\\';
			break;
			case 53: ch = '/';
			break;
			case 15: ch = '\t';
			break;
			case 39: ch = ';';
			break;
			case 40: ch = '\'';
			break;
			case 41: ch = '`';
			break;
			case 51: ch = ',';
			break;
			case 52: ch = '.';
			break;
			case 55: ch = '*';
			break;
			case 74: ch = '-';
			break;
			case 78: ch = '+';
			break;
			case 14: ch = '\b';
			break;
		}
	}
    
	putch(ch);
}

void init_keyboard()
{
	add_irq(1, keyboard_handler);
}
