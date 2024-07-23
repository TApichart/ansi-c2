#include <stdio.h>

enum ansiColor { aBLK, aRED, aGRN, aYEL, aBLU, aMAG, aCYN, aWHT };


#define RST "\x1b[0m"
#define pRST() printf (RST)
#define clrscr() printf ("\x1b[2J")
#define gotoxy(_x,_y) printf ("\x1b[%d;%dH", _y, _x)
#define setFgBg(_fg,_bg) printf ("\x1b[4%d;3%dm", _bg, _fg)
#define setFolor(_fg) printf ("\x1b[38;5;%dm", _fg)
#define setBolor(_bg) printf ("\x1b[48;5;%dm", _bg)
#define xyprint(_x,_y,_s) gotoxy(_x,_y); printf (_s)

int main (int argc, char* argv[]) {
	clrscr ();
	setFgBg (aWHT, aRED);
	xyprint (1, 1, "ANSI Escape Sequences Code");
	pRST ();
	putchar ('\n');
	int ic;
	for (ic=0; ic<256; ic++) {
		setFolor (ic);
		printf ("%d ", ic);
	}	printf ("\n\n");
	for (ic=0; ic<256; ic++) {
		setBolor (ic);
		printf ("%d ", ic);
	}	printf ("\n\n");
	for (ic=0; ic<256; ic++) {
		setBolor (ic);
		setFolor (255 ^ ic);
		printf ("%d ", ic);
	}	printf ("\n\n");
	for (ic=0; ic<256; ic++) {
		setFolor (ic);
		setBolor (255 ^ ic);
		printf ("%d ", ic);
	}	putchar ('\n');
	pRST ();
	return 0;
}
