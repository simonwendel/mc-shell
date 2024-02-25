#ifndef TERMINAL_SETTINGS_HPP
#define TERMINAL_SETTINGS_HPP

#include <gtkmm.h>
#include <vte/vte.h>

void clone_terminal_font_to_vte(VteTerminal *terminal);
void clone_terminal_size_to_vte(VteTerminal *terminal);
void clone_terminal_colors_to_vte(VteTerminal *terminal);

#endif // TERMINAL_SETTINGS_HPP
