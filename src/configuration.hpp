#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>
#include "constants.h"

class Configuration
{
public:
    const std::string window_title;
    const std::string window_icon;
    const std::string window_name;
    const std::string application_id;

    Configuration(const std::string &window_title, const std::string window_icon);
};

#endif // CONFIGURATION_HPP