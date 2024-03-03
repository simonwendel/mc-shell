#include "configuration.hpp"

using namespace Constants;

Configuration::Configuration(const std::string &window_title, const std::string window_icon)
    : window_title(window_title),
      window_icon(window_icon),
      application_id(APPLICATION_ID),
      window_name(WINDOW_NAME)
{
}
