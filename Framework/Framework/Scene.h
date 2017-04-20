#pragma once

#include<set>
#include "FrameTimer.h"
#include "GameObject.h"

class Scene {
public:
	Scene(float fixUpdateMillisecond);
	Scene(int framePerSecond);
	void SceneUpdate();
private:
	void Start();
	void Update(float& dt);
	void FixedUpdate(float& dt);
private:
	bool isSceneEnd = false;
	FrameTimer ft;
	float fixUpdateDuration;
	float culmulativeDuration = 0.0f;
	std::set<GameObject*> gameObjects;
};
