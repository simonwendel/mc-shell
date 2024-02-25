#include "application.hpp"
#include "terminal-widget.hpp"
#include "terminal-settings.hpp"

const std::string WINDOW_NAME = "mc-shell-main-window";
const std::string WINDOW_TITLE = "Midnight Commander";
const std::string APPLICATION_ID = "se.simonwendel.mc-shell";
const std::string DEFAULT_COMMAND = "/usr/bin/mc";

int main(int argc, char *argv[])
{
    auto app = create_main_application(APPLICATION_ID);
    auto window = create_main_window(WINDOW_TITLE, WINDOW_NAME);
    auto terminal = add_vte_terminal_to_app_window(window, app);

    clone_terminal_colors_to_vte(terminal);
    clone_terminal_font_to_vte(terminal);
    clone_terminal_size_to_vte(terminal);
    window.show_all();

    run_command_in_terminal(terminal, DEFAULT_COMMAND);
    return app->run(window);
}
