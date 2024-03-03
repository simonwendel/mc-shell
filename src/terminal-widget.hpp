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

#endif // TERMINAL_WIDGET_HPP
