#include "application.hpp"
#include "configuration.hpp"
#include "terminal-widget.hpp"
#include "terminal-settings.hpp"

const std::string WINDOW_TITLE = "Midnight Commander";
const std::string WINDOW_ICON = "MidnightCommander";
const std::string CONSOLE_COMMAND = "/usr/bin/mc";

int main(int argc, char *argv[])
{
    Configuration config(WINDOW_TITLE, WINDOW_ICON);
    Application app(config);
    return app.run(CONSOLE_COMMAND);
}
