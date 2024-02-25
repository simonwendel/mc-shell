#include "application.hpp"

Glib::RefPtr<Gtk::Application> create_main_application(const std::string &application_id);

Gtk::Window create_main_window(const std::string &window_title, const std::string &window_name);

int Application::run()
{
    auto app = create_main_application(config.application_id);
    auto window = create_main_window(config.window_title, config.window_name);

    auto settings = DefaultTerminalSettingsFactory::create();
    auto terminal = add_vte_terminal_to_app_window(window, app);
    settings.apply_to(terminal);

    run_command_in_terminal(terminal, config);

    window.show_all();
    return app->run(window);
}

Gtk::Window create_main_window(const std::string &window_title, const std::string &window_name)
{
    Gtk::Window window;
    window.set_title(window_title);
    window.set_name(window_name);
    return window;
}

Glib::RefPtr<Gtk::Application> create_main_application(const std::string &application_id)
{
    return Gtk::Application::create(application_id);
}
