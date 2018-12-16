#include <iostream>
#include <armadillo>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Template works!");
	tgui::Gui gui(window);

	sf::Texture background;
	if(!background.loadFromFile("resources/background.jpg")){
		std::cout << "Could not find image" << std::endl;
		return -1;
	}
	background.setSmooth(true);

	if (!sf::Shader::isAvailable())
	{
		// shaders are not available...
		std::cout << "Shaders not available" << std::endl;
		return -1;
	}

	sf::Shader shader;
	if(!shader.loadFromFile("fragment_shader.frag", sf::Shader::Fragment)){
		std::cout << "Coulnd't load shader" << std::endl;
		return -1;
	}
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f( background.getSize() ));
	rect.setTexture(&background);
	sf::View view;
	sf::Clock time;
	while (window.isOpen())
	{
		float curr_time = time.getElapsedTime().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type){
				case sf::Event::Closed:
					window.close();
					break;
				//case sf::Event::MouseLeft:
					//view.zoom(0.5);
				case sf::Event::Resized:
				{
					// update the view to the new size of the window
					sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
					view = sf::View(visibleArea);
					window.setView(view);
				}
				default:
					break;
			}
		}

		shader.setUniform("time", curr_time);
		shader.setUniform("u_resolution", sf::Vector2f( window.getSize() ));
		window.clear();
		window.draw(rect, &shader);
		window.display();
	}
}
