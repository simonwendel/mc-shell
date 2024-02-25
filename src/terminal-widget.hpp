#ifndef TERMINAL_WIDGET_HPP
#define TERMINAL_WIDGET_HPP

#include <gtkmm.h>
#include <vte/vte.h>

void run_command_in_terminal(VteTerminal *terminal, std::string command);
VteTerminal *add_vte_terminal_to_app_window(Gtk::Window &window, Glib::RefPtr<Gtk::Application> app);

#endif // TERMINAL_WIDGET_HPP
