#include "application.hpp"

Gtk::Window create_main_window(std::string title, std::string name)
{
    Gtk::Window window;
    window.set_title(title);
    window.set_name(name);
    return window;
}

Glib::RefPtr<Gtk::Application> create_main_application(std::string application_id)
{
    return Gtk::Application::create(application_id);
}
