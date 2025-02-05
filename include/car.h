#ifndef CAR_H
#define CAR_H

#include <raylib.h>
#include <raymath.h>



typedef struct {
	float engineForce;
	float brakeForce;


	// Transform variables
	Vector2 pos;	// World position
	Vector2 accel;	// Local acceleration (x+ right, y+ forward)
	Vector2 vel;	// Local velocity (x+ right, y+ forward)
	float rot;		// World rotaiton, degrees
	
	// Constants
	float dragRes;
	float rollRes;
	float mass;		// Kilograms
} Car;



/// Update the car's state
/// deltaT in seconds
void CarUpdate(Car* car, float deltaT);

#endif
