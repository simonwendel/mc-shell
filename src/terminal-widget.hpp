#ifndef TERMINAL_WIDGET_HPP
#define TERMINAL_WIDGET_HPP

#include <gtkmm.h>
#include <vte/vte.h>
#include "configuration.hpp"

void run_command_in_terminal(VteTerminal *terminal, const Configuration &config);
VteTerminal *add_vte_terminal_to_app_window(Gtk::Window &window, const Glib::RefPtr<Gtk::Application> app);

#endif // TERMINAL_WIDGET_HPP
