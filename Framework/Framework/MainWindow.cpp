#include <SFML/Graphics.hpp>
#include "Scene.h"

#include "Window.h"

#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")

int main() {
	sf::RenderWindow wnd(sf::VideoMode(Window::ScreenWidth, Window::ScreenHeight),L"Application",sf::Style::Titlebar|sf::Style::Close);
	Scene mainScene(30);
	FrameTimer ft;
	
	while (wnd.isOpen()) {
		sf::Event event;
		while (wnd.pollEvent(event)) {
			sf::Event::EventType eventType = event.type;
			switch (eventType) {
			case sf::Event::Closed:
				wnd.close();
				break;
			}
		}
		
		mainScene.SceneUpdate();

		wnd.clear();
		wnd.display();
	}
}