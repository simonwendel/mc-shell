#include "application.hpp"
#include "configuration.hpp"
#include "terminal-widget.hpp"
#include "terminal-settings.hpp"

const std::string WINDOW_TITLE = "Midnight Commander";
const std::string CONSOLE_COMMAND = "/usr/bin/mc";

int main(int argc, char *argv[])
{
    Configuration config(WINDOW_TITLE, CONSOLE_COMMAND);
    Application app(config);
    return app.run();
}
