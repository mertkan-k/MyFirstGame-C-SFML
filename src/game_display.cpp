#include "include/Button.hpp"
#include "include/game.hpp"

void sayPressed(sf::Event::MouseButtonEvent& event);
void sayPressed(sf::Event::MouseButtonEvent& event)
{
	std::cout << __func__ << event.button << std::endl;
}

void sayReleased(sf::Event::MouseButtonEvent& event);
void sayReleased(sf::Event::MouseButtonEvent& event)
{
	std::cout << __func__ << event.button << std::endl;
}

void sayButton(sf::Event::MouseButtonEvent& event);
void sayButton(sf::Event::MouseButtonEvent& event)
{
	std::cout << __func__ << event.button << std::endl;
}

void Game::InitializeWindow()
{
	this->window = new sf::RenderWindow(this->config.video_mode, "SFML works!");
	platform.setIcon(this->window->getSystemHandle());

	this->gui = new Gui(this->window);
	this->gui->setSize(sf::Vector2f(config.video_mode.width, config.video_mode.height));

	Button* btn = new Button();
	btn->setSize(sf::Vector2f(120, 50));
	btn->setPosition(sf::Vector2f(30, 50));
	btn->SetFillColor(Button::State::NORMAL, sf::Color::Blue);
	btn->SetFillColor(Button::State::ON_OVER, sf::Color::Red);
	btn->SetText("SelamM");
	this->gui->AddChild(btn);
	btn->SetName("my main button");
	// btn->SetMouseButtonPressedEvent(sayPressed);
	// btn->SetMouseButtonReleasedEvent(sayReleased);
	btn->SetMouseButtonEvent(sayButton);
	// btn->Show();

	// Button* btn2 = new Button(this->gui);
	// btn2->SetPosition(200, 200);
	// btn2->SetSize(120, 50);
	// btn2->SetFillColor(Button::State::NORMAL, sf::Color::Black);
	// btn2->SetFillColor(Button::State::ON_OVER, sf::Color::White);
	// btn2->SetName("button2");
	// btn2->Show();
	// windows.insert(btn2);
}

void Game::Render()
{
	// sf::CircleShape shape(this->window->getSize().x / 2);
	// shape.setFillColor(sf::Color::White);

	// sf::Texture shapeTexture;
	// shapeTexture.loadFromFile("content/sfml.png");
	// shape.setTexture(&shapeTexture);
	this->window->draw(*this->gui);

	this->gui->Draw();
}