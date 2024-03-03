#include "application.hpp"

Glib::RefPtr<Gtk::Application> create_main_application(const Configuration &config);

Gtk::Window create_main_window(const Configuration &config);

int Application::run(std::string command)
{
    auto app = create_main_application(config);
    auto window = create_main_window(config);
    auto settings = DefaultTerminalSettingsFactory::create();

    TerminalWidget terminal(settings);
    terminal.add_to(window);
    terminal.run(command);

    window.show_all();
    return app->run(window);
}

Gtk::Window create_main_window(const Configuration &config)
{
    Gtk::Window window;
    window.set_title(config.window_title);
    window.set_name(config.window_name);
    window.set_icon_name(config.window_icon);
    return window;
}

Glib::RefPtr<Gtk::Application> create_main_application(const Configuration &config)
{
    return Gtk::Application::create(config.application_id);
}
