#include "include/Game.hpp"

void Game::InitInterfaces()
{
	for (size_t i = 0; i < INTERFACE_END; i++)
	{
		Interface interface = (Interface)i;

		Gui* gui = new Gui();

		switch (interface)
		{
			case (MAIN_MENU): {

				gui->SetName("main menu");
				gui->setSize(sf::Vector2f(300, 300));

				Button* button1 = new Button();
				gui->AddChild(button1);
				button1->setSize(sf::Vector2f(120, 50));
				button1->setPosition(30, 50);
				button1->SetFillColor(Button::State::NORMAL, sf::Color::Blue);
				button1->SetFillColor(Button::State::ON_OVER, sf::Color::Red);
				button1->SetFillColor(Button::State::ON_CLICKED, sf::Color::Yellow);
				button1->SetText("Cikis");
				button1->SetName("my main button");
				button1->SetMouseButtonEvent(std::bind(Game::OnMainMenuButton1Click, this));

				Button* button2 = new ToggleButton();
				gui->AddChild(button2);
				button2->setSize(sf::Vector2f(120, 50));
				button2->setPosition(100, 150);
				button2->SetFillColor(Button::State::NORMAL, sf::Color::Blue);
				button2->SetFillColor(Button::State::ON_OVER, sf::Color::Red);
				button2->SetFillColor(Button::State::ON_CLICKED, sf::Color::Yellow);
				button2->SetText("Toggle");
				button2->SetName("my toggle button");
				break;
			}

			case (MAIN_MENU2): {

				gui->SetName("main menu2");
				gui->setSize(sf::Vector2f(300, 300));
				gui->setPosition(300, 0);

				Button* button2 = new Button();
				gui->AddChild(button2);
				button2->setSize(sf::Vector2f(120, 50));
				button2->setPosition(30, 50);
				button2->SetFillColor(Button::State::NORMAL, sf::Color::Blue);
				button2->SetFillColor(Button::State::ON_OVER, sf::Color::Red);
				button2->SetFillColor(Button::State::ON_CLICKED, sf::Color::Yellow);
				button2->SetText("Cikis2");
				button2->SetName("my main button2");
				button2->SetMouseButtonEvent(std::bind(Game::OnMainMenuButton2Click, this));
			}

			break;

			case INTERFACE_END:
			default:
				break;
		}

		interfaces[interface] = gui;
		this->gui->AddChild(gui);
	}
}

void Game::OnMainMenuButton1Click()
{
	interfaces[MAIN_MENU]->Hide();
	interfaces[MAIN_MENU2]->Show();
}

void Game::OnMainMenuButton2Click()
{
	interfaces[MAIN_MENU]->Show();
	interfaces[MAIN_MENU2]->Hide();
}