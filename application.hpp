#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <gtkmm.h>
#include <vte/vte.h>

Gtk::Window create_main_window(std::string title, std::string name);
Glib::RefPtr<Gtk::Application> create_main_application(std::string application_id);

#endif // APPLICATION_HPP
