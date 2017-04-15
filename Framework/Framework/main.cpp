#include <SFML/Graphics.hpp>

#include "Window.h"

int main() {
	sf::RenderWindow wnd(sf::VideoMode(Window::ScreenWidth, Window::ScreenHeight),L"Application",sf::Style::Titlebar|sf::Style::Close);
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

		wnd.clear();
		wnd.display();
	}
}