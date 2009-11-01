//String functions

#include <system.h>

size_t strlen(const char *text)
{
	size_t retval;
	for(retval=0; *text != '\0'; text++) retval++;
	return retval;
}

void strcat(char *target, char *source)
{
	int i, n;
	int tlen = strlen(target);
	int slen = strlen(source);

	for(i=tlen, n=0; n<slen; i++, n++){
		target[i] = source[n];
	}
}

void itoa(char *buf, int base, int d)
{
	char *p = buf;
	char *p1, *p2;
	ulong ud = d;
	int divisor = 10;
	
	if(base == 'd' && d < 0){
		*p++ = '-';
		buf++;
		ud = -d;
	}
	
	else if(base=='X'){
		divisor = 16;
	}
	
	do{
		int remaind = ud % divisor;
		*p++ = (remaind < 10) ? remaind + '0' : remaind + 'a' - 10;
	}while(ud /= divisor);
	
	*p = 0;
	
	p1 = buf;
	p2 = p - 1;
	
	while(p1 < p2){
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}
}

