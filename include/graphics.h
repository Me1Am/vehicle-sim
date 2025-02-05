#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <raylib.h>

#include <stdint.h>

#include "car.h"



typedef struct {
	uint32_t width;
	uint32_t height;
	uint32_t maxFPS;

	char* title;
} WindowDef;



void GraphicsInit(WindowDef windowDef);

void GraphicsDrawCar(Car* car);

void GraphicsDrawHUD(Car* car);

#endif
