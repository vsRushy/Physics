#pragma once
#include "Module.h"
#include "Globals.h"

#include "Box2D\Box2D\Box2D.h"

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

	// Static big circle
	b2BodyDef groundBodyDef;
	b2Body* groundBody;
	b2CircleShape sCircle;

	// Dynamic little circle
	b2BodyDef bodyDef;
	b2Body* body;
	b2CircleShape dCircle;
	b2FixtureDef fixtureDef;
};