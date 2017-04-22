#pragma once

#include <set>
#include <memory>
#include "FrameTimer.h"
#include "GameObject.h"

class Scene {
public:
	Scene(float fixUpdateMillisecond);
	Scene(int framePerSecond);
	void SceneUpdate();
	void RegisterLayer(std::shared_ptr<GameObject> gameObj, uint32_t flag);
	void RemoveFromLayer(std::shared_ptr<GameObject> gameObj, uint32_t flag);
private:
	void Start();
	void Update(float& dt);
	void FixedUpdate(float& dt);
private:
	bool isSceneEnd = false;
	FrameTimer ft;
	float fixUpdateDuration;
	float culmulativeDuration = 0.0f;
	// unique set not have duplicate element
	std::set<std::shared_ptr<GameObject>> defaultLayer;
};
