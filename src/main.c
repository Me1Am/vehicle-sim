#include <raylib.h>

#include <stdint.h>
#include <stdio.h>

#include "../include/graphics.h"
#include "../include/car.h"



Car car;

struct EngineState {
	WindowDef window;
} globalState;

int main(int argc, char** argv) {
	printf("start\n");

    // Initialize Raylib
    {
		globalState = (struct EngineState) {
			(WindowDef) {
				.title = "Game\0",
				.width = 640,
				.height = 480,
				.maxFPS = 60,
			}
		};

		GraphicsInit(globalState.window);
    }

    // Test Objects
    {
		car = (Car) {
			.engineForce = 0,
			.brakeForce = 0,

			.pos = (Vector2) {
				globalState.window.width / 2.f,
				globalState.window.height / 2.f,
			},
			.accel = (Vector2) { 0.f, 0.f },
			.vel = (Vector2) { 0.f, 0.f },
			.rot = 0.f,

			.dragRes = 0.4257,
			.rollRes = 12.8,
			.mass = 1500
		};
    }

    // Main loop
    while(!WindowShouldClose()) {
        // Runtime logic
        {
            if(IsKeyDown(KEY_W)) {
				//car.vel.y -= 32 * GetFrameTime();
				car.engineForce += 10000 * GetFrameTime();
            } else if(IsKeyDown(KEY_S)) {
                //car.vel.y += 32 * GetFrameTime();
				car.engineForce -= 10000 * GetFrameTime();
            }
            if(IsKeyDown(KEY_A)) {
				car.rot -= 64 * GetFrameTime();
            } else if(IsKeyDown(KEY_D)) {
				car.rot += 64 * GetFrameTime();
            }
			if(IsKeyDown(KEY_SPACE)) {
				car.brakeForce += 5000 * GetFrameTime();
			} else {
				car.brakeForce = 0;
			}

			CarUpdate(&car, GetFrameTime());
        }

        // Render
        {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			GraphicsDrawCar(&car);
			GraphicsDrawHUD(&car);

			EndDrawing();
        }
    }

    CloseWindow();

	printf("end\n");
   	return 0;
}
