#include <iostream>
#include <filesystem>
#include <string>

#include "raylib.h"
#include "SceneManager.h"


// Window Parameters
//--------------------------------------------------------------------------------------
const int screenWidth = 576;
const int screenHeight = 624;
//--------------------------------------------------------------------------------------

// Size Box
//--------------------------------------------------------------------------------------
int size_box{ 32 };
//--------------------------------------------------------------------------------------

// Size Box
//--------------------------------------------------------------------------------------
bool GameExit{ false };
//--------------------------------------------------------------------------------------

// Game Path
//--------------------------------------------------------------------------------------
std::string path_source{
	std::filesystem::current_path().string().erase(std::filesystem::current_path().string().find_last_of('\\'))
};
//--------------------------------------------------------------------------------------


int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "Maze");

	SceneManager::GetInstance().Init();
	SceneManager::GetInstance().SetActiveScene(SceneUpdate::MAIN);

	SetTargetFPS(144);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose() && !GameExit)
	{
		// Update
		//----------------------------------------------------------------------------------

		SceneManager::GetInstance().Update(GetFrameTime());
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		SceneManager::GetInstance().Draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return EXIT_SUCCESS;
}
