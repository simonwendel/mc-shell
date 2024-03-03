#include "application.hpp"
#include "constants.hpp"
#include "configuration.hpp"
#include "terminal-widget.hpp"
#include "terminal-settings.hpp"

using namespace Constants;

int main(int argc, char *argv[])
{
    Configuration config(WINDOW_TITLE, WINDOW_ICON);
    Application app(config);
    return app.run(CONSOLE_COMMAND);
}
