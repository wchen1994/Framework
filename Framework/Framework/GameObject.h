#pragma once

#include<SFML/Graphics.hpp>

class GameObject : public sf::Transformable, public sf::Drawable {
public:
	GameObject();
	virtual void Start() {};
	virtual void Update(float& dt) {};
	virtual void FixedUpdate(float& dt) {};
private:
	sf::VertexArray vertexes;
	sf::Color color;
};
