#pragma once
#include "Module.h"
#include "Globals.h"

#include "Box2D\Box2D\Box2D.h"

// 1 meter = 100 pixels
// Needs to be a float
#define METERS_TO_PIXELS( A ) A / 0.01
#define PIXELS_TO_METERS( A ) A * 0.01 

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

	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 8;
	int32 positionIterations = 3;

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