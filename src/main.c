int main(void) {
	const int screenWidth = 800;
    	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Raylib");

	InitAudioDevice(); // Initialize audio device
	Music music = LoadMusicStream("assets/music/lost.ogg");

	PlayMusicStream(music);

	// width, height
	Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2 };
	Vector2 playerSize = { (float)60, (float)60 };

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
	
	SetMusicVolume(music, 0.2);
	
	// bool WindowShouldClose(void) -> Check if KEY_ESCAPE pressed or Close icon pressed
	#pragma unroll
    	while (!WindowShouldClose()) { // gameplay loop
        	/* Game Loop */
		/* Keybindings */
		if (IsKeyDown(KEY_RIGHT)) {
			playerPosition.x += 2.0f;
		}
        	if (IsKeyDown(KEY_LEFT)) { 
			playerPosition.x -= 2.0f;
		}
        	if (IsKeyDown(KEY_UP)) { 
			playerPosition.y -= 2.0f;
		}
        	if (IsKeyDown(KEY_DOWN)) {
			playerPosition.y += 2.0f;
		}

		/* Player Boundaries */
		// left boundary
        	if (playerPosition.x < 0) {
            		playerPosition.x = 0;
        	}
        	// right boundary
        	if (playerPosition.x + playerSize.x > screenWidth) {
            		playerPosition.x = screenWidth - playerSize.x;
        	}
        	// bottom boundary
        	if (playerPosition.y + playerSize.y > screenHeight) {
            		playerPosition.y = screenHeight - playerSize.y;
        	}
        	// top boundary
        	if (playerPosition.y < 0) {
            		playerPosition.y = 0;
        	}

		UpdateMusicStream(music);   // Update music buffer with new stream data
        	BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
			// drawRectangleV(Vector2 position, Vector2 size, Color color)
			DrawRectangleV(playerPosition, playerSize, PURPLE);
		EndDrawing();
    	}


	UnloadMusicStream(music); // Unload music stream buffers from RAM
    	CloseAudioDevice(); // Close audio device (music streaming is automatically stopped)
    	CloseWindow(); // Close window and OpenGL context

    	return 0;
}

