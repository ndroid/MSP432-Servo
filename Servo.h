#ifndef SERVO_H
#define SERVO_H

#include "Energia.h"
#include <inttypes.h>
#include <ti/sysbios/hal/Timer.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Error.h>
//#include <ti/sysbios/family/arm/msp432/Timer.h>

// Hardware limitations information
#define MIN_SERVO_PULSE_WIDTH 		600
#define MAX_SERVO_PULSE_WIDTH 		2400
#define DEFAULT_SERVO_PULSE_WIDTH   1500
#define REFRESH_INTERVAL 		    20000

// Other defines
#define SERVOS_PER_TIMER 	8
#define INVALID_SERVO 		255

typedef struct
{
	unsigned int pin_number;
	unsigned int pulse_width;
	bool enabled;
} servo_t;

class Servo
{
private:
	unsigned int index;
	int min;
	int max;
public:
	Servo();
	static Timer_Params timerParams;
	static Timer_Handle timerHandle;
	unsigned int attach(unsigned int pin, int min = MIN_SERVO_PULSE_WIDTH, int max = MAX_SERVO_PULSE_WIDTH);
	void detach();
	void writeMicroseconds(int value);
	int readMicroseconds();
	void write(int value);
	int read();
	bool attached();
};

extern "C" Void ServoIntHandler(UArg arg0);

#endif // SERVO_H
