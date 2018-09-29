#pragma once
#include "Module.h"
#include "p2List.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;

private:
	p2List<PhysBody*> circles_list;
	p2List<PhysBody*> boxes_list;
	p2List<PhysBody*> ricks_list;

private:
	int points[24] = {
		-38, 80,
		-44, -54,
		-16, -60,
		-16, -17,
		19, -19,
		19, -79,
		61, -77,
		57, 73,
		17, 78,
		20, 16,
		-25, 13,
		-9, 72
	};

	int rick_head[90] = {
		40, 0,
		41, 38,
		13, 35,
		29, 62,
		0, 76,
		28, 90,
		10, 102,
		31, 114,
		24, 124,
		39, 125,
		35, 135,
		45, 131,
		52, 139,
		58, 144,
		64, 146,
		69, 147,
		79, 147,
		84, 146,
		89, 144,
		92, 140,
		96, 136,
		98, 129,
		105, 124,
		103, 118,
		99, 115,
		102, 105,
		102, 100,
		103, 94,
		107, 91,
		109, 85,
		109, 79,
		109, 74,
		117, 67,
		106, 64,
		104, 59,
		111, 34,
		95, 40,
		93, 25,
		89, 12,
		87, 5,
		82, 17,
		79, 24,
		74, 33,
		62, 17,
		50, 6
	};
};
