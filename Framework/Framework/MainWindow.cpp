#include <SFML/Graphics.hpp>
#include "Scene.h"

#include "Window.h"

#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")

int main() {
	Scene mainScene(30);
	FrameTimer ft;
	
	while (Window::wnd.isOpen()) {
		sf::Event event;
		while (Window::wnd.pollEvent(event)) {
			sf::Event::EventType eventType = event.type;
			switch (eventType) {
			case sf::Event::Closed:
				Window::wnd.close();
				break;
			}
		}
		
		mainScene.SceneUpdate();

		Window::wnd.clear();
		Window::wnd.display();
	}
	
}