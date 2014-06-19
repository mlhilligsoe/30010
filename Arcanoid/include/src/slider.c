#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#define ESC 0x1B

char BTN1;
char BTN2;
char BTN3;
int AJOY;
int i;

void main() {

	init_uart(_UART0, _DEFFREQ, _DEFBAUD);

	PBDD = 0x2A; // port PB1, PB3, PB5 som knap input.
	PBAF = 0x80; // port  PB7 er ADC

	while (1) {

		BTN1 = PBIN & 0x02; // Isolerer BTN1
		BTN2 = PBIN & 0x08; //  Isolerer BTN2
		BTN3 = PBIN & 0x20; //  Isolerer BTN3

		if (BTN1 == 0) {
			gotoxy(1, 3);
			printf("BTN 1 active");
		} else {
			gotoxy(1, 3);
			printf("BTN 1 OFF    ");
		}

		if (BTN2 == 0) {
			gotoxy(1, 5);
			printf("BTN 2 active");
		} else {
			gotoxy(1, 5);
			printf("BTN 2 OFF    ");
		}

		if (BTN3 == 0) {
			gotoxy(1, 7);
			printf("BTN 3 active");
		} else {
			gotoxy(1, 7);
			printf("BTN 2 OFF    ");
		}

		gotoxy(1, 7);
		ADCCTL = 0xB7; //Initialisering af ADC på pin PB7,
		i = 0;
		while (i < 300) { //Efter ca. 256 cycles er udlæsningen klar, vi kan evt. fifle lidt med tallet.
			i++;
		}

		AJOY = 0;
		AJOY = ((int) ADCD_H << 2);
		AJOY |= ((int) ADCD_L >> 6);
		gotoxy(1, 10);
		printf("AJOY_int = %04d", AJOY);
	}
}

}
