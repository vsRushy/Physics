#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	circles_list.clear();
	boxes_list.clear();
	ricks_list.clear();

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 4: Move all creation of bodies on 1,2,3 key press here in the scene
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		circles_list.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 25));
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		boxes_list.add(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 100, 50));
	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		App->physics->CreateChain(App->input->GetMouseX(), App->input->GetMouseY(), points, 24);
	}

	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN)
	{
		ricks_list.add(App->physics->CreateChain(App->input->GetMouseX(), App->input->GetMouseY(), rick_head, 90));
	}
	// TODO 6: Draw all the circles using "circle" texture
	//HOMEWORK
	p2List_item<PhysBody*>* item = circles_list.getFirst();
	while (item != NULL)
	{
		int x, y;
		item->data->GetPosition(x, y);
		App->renderer->Blit(circle, x, y, NULL, 1.0f, item->data->GetRotation());
		item = item->next;
	}

	item = boxes_list.getFirst();
	while (item != NULL)
	{
		int x, y;
		item->data->GetPosition(x, y);
		App->renderer->Blit(box, x, y, NULL, 1.0f, item->data->GetRotation());
		item = item->next;
	}

	item = ricks_list.getFirst();
	while (item != NULL)
	{
		int x, y;
		item->data->GetPosition(x, y);
		App->renderer->Blit(rick, x, y, NULL, 1.0f, item->data->GetRotation());
		item = item->next;
	}

	return UPDATE_CONTINUE;
}
