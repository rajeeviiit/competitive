#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char * str = "7\nAli";
	int t, n, wlen;
	char * strptr;
	// get int and str
	n = (int) strtod( str, &strptr );
	strptr++;
	printf("%s\n", strptr);
	// start proc
	wlen = strlen(strptr);
	int mems[n];
	for (t=0; t<n; t++)
		mems[t] = 0;
	int curp=-1, curm=n; // curp contains to start
	// enum
	while (curm>1){
		for (t=0; t<wlen; t++){
			curp++;
			curp = curp % n;
			if ( mems[curp] == 1 ){
				t--;
				continue;
			} // go back or skip
		}
		mems[curp] = 1; // out
		curm--;
	}
	// out
	for (t=0; t<n; t++){
		if ( mems[t] == 0 ){
			curp = t+1;
			break;
		}
	}
	printf("%d", curp);
    return 0;
}