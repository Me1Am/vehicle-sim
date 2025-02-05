#include <raylib.h>
#include <raymath.h>

#include "../include/car.h"



float magnitude(Vector2 vec);
void updateVel(Car* car, float deltaT);



void CarUpdate(Car* car, float deltaT) {
	// F_t = heading * engineForce
	// Use 1,0 instead of below because this is local space
	// { cos(car->rot * PI / 180), sin(car->rot * PI / 180) };
	Vector2 tractionForce = { 1, 0 };
	tractionForce = Vector2Scale(tractionForce, car->engineForce);

	// F_d = C_drag * vel * mag(vel)
	Vector2	dragResForce = Vector2Scale(car->vel, car->dragRes * magnitude(car->vel));
	// F_r = C_roll * vel
	Vector2 rollResForce = Vector2Scale(car->vel, car->rollRes);



	// Opposite forces
	Vector2 negatives = Vector2Add(dragResForce, rollResForce);
	//negatives = Vector2Add(negatives, brakeForce);

	// Total longtitudinal force
	Vector2 longForce = Vector2Subtract(tractionForce, negatives);
	DrawText(TextFormat("Long Force %02f, %02f", longForce.x, longForce.y), 16, 144, 16, RED);


	// Acceleration, force * mass
	car->accel = Vector2Divide(longForce, (Vector2) { car->mass, car->mass });

	updateVel(car, deltaT);
}

float magnitude(Vector2 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

void updateVel(Car* car, float deltaT) {
	car->vel = Vector2Add(car->vel, Vector2Scale(car->accel, deltaT));

	// Convert local velocity into world space
	float cs = cos(car->rot * PI / 180);
	float sn = sin(car->rot * PI / 180);

	Vector2 wVel = (Vector2) {
        car->vel.x * sn + car->vel.y * cs,
        -car->vel.x * cs - car->vel.y * sn
	};

	car->pos = Vector2Add(car->pos, Vector2Scale(wVel, deltaT));
}
