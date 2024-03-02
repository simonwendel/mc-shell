#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

class Configuration
{
public:
    const std::string window_title;
    const std::string window_name;
    const std::string application_id;

    Configuration(const std::string &window_title);
};

#endif // CONFIGURATION_HPP