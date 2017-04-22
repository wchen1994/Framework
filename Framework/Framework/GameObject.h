#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class GameObject : public sf::Transformable{
public:
	GameObject();
	virtual void Start() {};
	virtual void Update(float& dt) {};
	virtual void FixedUpdate(float& dt) {};
	void Draw(sf::RenderTarget& rt) const;
private:
	std::shared_ptr<sf::Drawable> ptDraw;
};
