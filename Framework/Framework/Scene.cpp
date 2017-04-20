#include "Scene.h"

Scene::Scene(float fixUpdateDuration)
	:
	ft()
{
	Start();
	this->fixUpdateDuration = fixUpdateDuration;
}

Scene::Scene(int framePerSecond=30)
	:
	ft()
{
	Start();
	this->fixUpdateDuration = 1000000 / framePerSecond;
}

void Scene::SceneUpdate()
{
	// delta time per frame
	float dt = ft.Mark();
	culmulativeDuration += dt;

	// Update frame
	Update(dt);

	// FixedUpdate for physical objects
	while (culmulativeDuration >= fixUpdateDuration) {
		FixedUpdate(fixUpdateDuration);
		culmulativeDuration -= fixUpdateDuration;
	}
}

void Scene::Start()
{
	for (auto it = gameObjects.begin();
		it != gameObjects.end();
		it++) {
		GameObject* gameObj = *it;
		gameObj->Start();
	}
}

void Scene::Update(float& dt)
{
	for (auto it = gameObjects.begin();
		it != gameObjects.end();
		it++) {
		GameObject* gameObj = *it;
		gameObj->Update(dt);
	}
}

void Scene::FixedUpdate(float& dt)
{
	for (auto it = gameObjects.begin();
		it != gameObjects.end();
		it++) {
		GameObject* gameObj = *it;
		gameObj->FixedUpdate(dt);
	}
}
