#include "include/Gui.hpp"
#include "include/Button.hpp"

Gui::Gui(std::string name)
{
	this->name = name;
	// this->parent = parent;
	// if (parent)
	// 	parent->AddChild(this);

	InitEvents();
}
Gui::Gui(sf::RenderWindow* mng)
{
	window_manager = mng;
	this->name = "Main Gui";
	// this->parent = nullptr;

	InitEvents();
}
void Gui::InitEvents()
{
	is_focus_in = false;
	is_show = true;
	mouse_button_func = nullptr;

	// std::uniform_int_distribution<int> d(0, 255);
	// std::random_device rd1; // uses RDRND or /dev/urandom
	// setFillColor(sf::Color(d(rd1), d(rd1), d(rd1), 0));

	srand(time(NULL));
	uint8_t rd1 = rand() % 256, rd2 = rand() % 256, rd3 = rand() % 256;
	setFillColor(sf::Color(rd1, rd2, rd3, 25));

	// setOutlineThickness(5);
	// setFillColor(sf::Color(50, 100, 150, 25));
}

Gui::~Gui()
{
}

void Gui::SetName(std::string name)
{
	this->name = name;
}
std::string& Gui::GetName()
{
	return this->name;
}

/*Gui* Gui::GetParent()
{
	return parent;
}
Gui* Gui::GetAncestor()
{
	return parent ? parent->GetAncestor() : this;
}*/

bool Gui::IsShow() const
{
	return is_show;
}
void Gui::Show()
{
	is_show = true;
}
void Gui::Hide()
{
	is_show = false;
}

bool Gui::IsFocusIn()
{
	return is_focus_in;
}
void Gui::SetFocusIn(bool is)
{
	is_focus_in = is;
}

void Gui::RemoveChild(Gui* child)
{
	children.erase(child);
}
void Gui::AddChild(Gui* child)
{
	children.insert(child);
}

/*sf::Vector2u Gui::GetSize() const
{
	return size;
}

void Gui::SetSize(sf::Vector2u size)
{
	this->size = size;
}*/

void Gui::OnMouseMoved()
{
	auto mousePos = sf::Mouse::getPosition(*this->window_manager);
	std::for_each(children.begin(), children.end(), [&](Gui* gui) {
		sf::Vector2f guiSize, guiPos = gui->getPosition();
		guiSize = gui->getSize();
		if (mousePos.x >= guiPos.x && mousePos.y >= guiPos.y && mousePos.x <= guiPos.x + guiSize.x && mousePos.y <= guiPos.y + guiSize.y)
		{
			if (gui->IsMouseIn())
				gui->OnMouseMoved();
			else
				gui->OnMouseEntered();
		}
		else
		{
			if (gui->IsMouseIn())
				gui->OnMouseLeft();
		}
	});
	// std::cout << name << __func__ << std::endl;
}

void Gui::OnMouseEntered()
{
	Eventable::SetMouseIn(true);
	// std::cout << name << __func__ << std::endl;
}
void Gui::OnMouseLeft()
{
	Eventable::SetMouseIn(false);
	SetFocusIn(false);
	// std::cout << name << __func__ << std::endl;
}

bool Gui::OnMouseButtonPressed(sf::Event::MouseButtonEvent& event)
{
	SetFocusIn(true);

	if (Eventable::OnMouseButtonPressed(event))
		return true;

	bool handled = false;
	std::for_each(children.begin(), children.end(), [&](Gui* w) {
		if (w->IsMouseIn() && !handled)
			handled = w->OnMouseButtonPressed(event);
	});

	return handled;
}

bool Gui::OnMouseButtonReleased(sf::Event::MouseButtonEvent& event)
{
	if (IsFocusIn())
		if (OnMouseButton(event))
			return true;

	if (Eventable::OnMouseButtonReleased(event))
		return true;

	bool handled = false;
	std::for_each(children.begin(), children.end(), [&](Gui* w) {
		if (w->IsMouseIn() && !handled)
			handled = w->OnMouseButtonReleased(event);
	});

	return handled;
}

void Gui::SetMouseButtonEvent(void (*func)(sf::Event::MouseButtonEvent& event))
{
	mouse_button_func = func;
}

bool Gui::OnMouseButton(sf::Event::MouseButtonEvent& event)
{
	if (*mouse_button_func)
	{
		(*mouse_button_func)(event);
		return true;
	}

	bool handled = false;
	std::for_each(children.begin(), children.end(), [&](Gui* w) {
		if (w->IsFocusIn() && !handled)
			handled = w->OnMouseButton(event);
	});

	return handled;
}

void Gui::Draw()
{
	this->window_manager->draw(*this);
	std::for_each(children.begin(), children.end(), [&](Gui* gui) {
		gui->Draw();
		// this->window_manager->draw(*gui);
		/*if (instanceof <Button>(gui))
		{
			if (((Button*)gui)->GetTextObject())
			{
				this->window_manager->draw(*((Button*)gui)->GetTextObject());
			}
		}*/
	});
}