#ifndef TERMINAL_WIDGET_HPP
#define TERMINAL_WIDGET_HPP

#include <gtkmm.h>
#include <vte/vte.h>

#include "configuration.hpp"
#include "terminal-settings.hpp"

class TerminalWidget
{
public:
    TerminalWidget(const TerminalSettings &settings)
        : settings(settings)
    {
    }

    void add_to(Gtk::Window &window);
    void run(std::string command);

private:
    TerminalSettings settings;
    VteTerminal *terminal;
};

// void
// run_command_in_terminal(VteTerminal *terminal, const Configuration &config);
// VteTerminal *add_vte_terminal_to_app_window(Gtk::Window &window, const Glib::RefPtr<Gtk::Application> app);

#endif // TERMINAL_WIDGET_HPP
