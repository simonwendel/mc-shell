#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <gtkmm.h>
#include <vte/vte.h>

#include "configuration.hpp"
#include "terminal-widget.hpp"
#include "terminal-settings.hpp"

class Application
{
public:
    Application(const Configuration &config)
        : config(config)
    {
    }

    int run(std::string command);

private:
    const Configuration &config;
};

#endif // APPLICATION_HPP
