#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

class Configuration
{
public:
    const std::string window_title;
    const std::string console_command;
    const std::string window_name;
    const std::string application_id;

    Configuration(const std::string &window_title, const std::string &console_command);
};

#endif // CONFIGURATION_HPP