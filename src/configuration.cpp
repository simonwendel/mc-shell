#include "configuration.hpp"

const std::string WINDOW_NAME = "mc-shell-main-window";
const std::string APPLICATION_ID = "se.simonwendel.mc-shell";

Configuration::Configuration(const std::string &window_title, const std::string &console_command)
    : window_title(window_title),
      console_command(console_command),
      application_id(APPLICATION_ID),
      window_name(WINDOW_NAME)
{
}
