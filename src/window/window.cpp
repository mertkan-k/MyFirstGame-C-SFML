#include "include/window/window.hpp"
#include "include/window/button.hpp"

Window::Window()
{
	this->name = "Unknown";
	this->root = nullptr;
	this->pos = pos;
	this->size = size;
	this->bg_color = bg_color;

	this->is_show = false;

	mouse_enter_func = nullptr;
	is_mouse_in = false;
}

Window::~Window()
{
	/* before delete all chidrens */
	std::for_each(children.begin(), children.end(), std::default_delete<Window>());

	/* after remove from root's list for better memory */
	if (root)
	{
		root->RemoveChild(this);
	}
}

void Window::OnUpdate()
{
	/* before update all chidrens */
	std::for_each(children.begin(), children.end(), [](Window* w) { w->OnUpdate(); });

	/* After update me */
	Update();
}

void Window::Update()
{
	/* after  */
}

void Window::RemoveChild(Window* window)
{
	children.erase(window);
}

void Window::AddChild(Window* window)
{
	children.insert(window);
}

// void Window::Close()
// {
// 	if (root)
// 	{
// 		root->RemoveChild(this);
// 	}
// }

/* Events */
void Window::OnMouseMove(int x, int y)
{
	if (*mouse_enter_func)
		(*mouse_enter_func)();

	/* after update all chidrens */
	std::for_each(children.begin(), children.end(), [&](Window* w) {
		if (x >= w->GetPos().x && y >= w->GetPos().y && x <= (w->GetPos().x + w->GetSize().x) && y <= (w->GetPos().y + w->GetSize().y))
		{
			if (!w->isMouseIn())
				w->OnMouseEnter();
			w->OnMouseMove(x, y);
		}
		else
		{
			if (w->isMouseIn())
				w->OnMouseLeave();
		}
	});
}
void Window::SetMouseMoveEvent(void (*func)(void))
{
	mouse_enter_func = func;
}
void Window::OnMouseEnter()
{
	is_mouse_in = true;
	std::cout << name << ": " << __func__ << std::endl;
}
void Window::OnMouseLeave()
{
	is_mouse_in = false;
	std::cout << name << ": " << __func__ << std::endl;
}