#include <raylib.h>

#include <math.h>

#include "../include/graphics.h"



void GraphicsInit(WindowDef windowDef) {
	InitWindow(windowDef.width, windowDef.height, windowDef.title);
	SetTargetFPS(windowDef.maxFPS);
}

void GraphicsDrawCar(Car* car) {
	DrawRectanglePro(
		(Rectangle) { car->pos.x, car->pos.y, 16, 32 },
		(Vector2) { 8, 16 },
		car->rot,
		RED
	);
}

void GraphicsDrawHUD(Car* car) {
	DrawText(TextFormat("Speed: %02f", sqrt(car->vel.x * car->vel.x + car->vel.y * car->vel.y)), 16, 16, 24, RED);
	DrawText(TextFormat("Veclocity: %02f, %02f", car->vel.x, car->vel.y), 16, 48, 24, RED);
	DrawText(TextFormat("Position: %02f, %02f", car->pos.x, car->pos.y), 16, 80, 24, RED);
	DrawText(TextFormat("Rotation: %02fdeg", car->rot), 16, 112, 24, RED);
	DrawText(TextFormat("Engine Force: %02f", car->engineForce), 16, 160, 16, RED);
	DrawText(TextFormat("Brake Force: %02f", car->brakeForce), 16, 176, 16, RED);
}
