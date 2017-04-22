#include "Scene.h"
#include "Window.h"

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
	this->fixUpdateDuration = 1.0f / framePerSecond;
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

void Scene::SceneDraw()
{
	for (auto it = defaultLayer.begin();
		it != defaultLayer.end();
		it++) {
		(*it)->Draw(Window::wnd);
	}
}

void Scene::RegisterLayer(std::shared_ptr<GameObject> gameObj, uint32_t flag)
{
	if (flag | (uint32_t)0x00000001) {
		defaultLayer.insert(gameObj);
	}
}

void Scene::RemoveFromLayer(std::shared_ptr<GameObject> gameObj, uint32_t flag)
{
	if (flag | (uint32_t)0x00000001) {
		defaultLayer.erase(gameObj);
	}
}

void Scene::Start()
{
	for (auto it = defaultLayer.begin();
		it != defaultLayer.end();
		it++) {
		(*it)->Start();
	}
}

void Scene::Update(float& dt)
{
	for (auto it = defaultLayer.begin();
		it != defaultLayer.end();
		it++) {
		(*it)->Update(dt);
	}
}

void Scene::FixedUpdate(float& dt)
{
	for (auto it = defaultLayer.begin();
		it != defaultLayer.end();
		it++) {
		std::shared_ptr<GameObject> gameObj = *it;
		gameObj->FixedUpdate(dt);
	}
}
