#include "GameObject.h"

GameObject::GameObject()
{
}

void GameObject::Draw(sf::RenderTarget & rt) const
{
	rt.draw(*ptDraw);
}
