#ifndef buzzer_included
#define buzzer_included

// G String Notes

#define GG 5102  // G on G string (196 Hz)

#define GA 4545  // A on G string (220 Hz)

#define GB 4057  // B on G string (246.94 Hz)

#define GC 3831  // C on G string (261.63 Hz)



// D String Notes

#define DD 3409  // D on D string (293.66 Hz)

#define DE 3030  // E on D string (329.63 Hz)

#define DF 2865  // F on D string (349.23 Hz)

#define DG 2540  // G on D string (392 Hz)



// A String Notes

#define AA 2272  // A on A string (440 Hz)

#define AB 2143  // B on A string (466.16 Hz)

#define AC 1908  // C on A string (523.25 Hz)

#define AD 1707  // D on A string (587.33 Hz)



// E String Notes

#define EE 1512  // E on E string (659.25 Hz)

#define EF 1430  // F on E string (698.46 Hz)

#define EG 1283  // G on E string (783.99 Hz)

#define EA 1136  // A on E string (880 Hz)

#define Q 500    // Quarter note
#define H 1000   // Half note
#define W 2000

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_off();
void delay(unsigned int milliseconds);


#endif
