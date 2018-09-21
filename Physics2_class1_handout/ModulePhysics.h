#pragma once
#include "Module.h"
#include "Globals.h"

#define METERS_TO_PIXELS( A ) A / 100
#define PIXELS_TO_METERS( A ) A * 100  

class b2World;
class b2Body;

class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

private:
	bool debug;
	
	b2World* world;
	b2Body* groundBody;
};