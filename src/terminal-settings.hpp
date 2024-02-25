#ifndef TERMINAL_SETTINGS_HPP
#define TERMINAL_SETTINGS_HPP

#include <gtkmm.h>
#include <vte/vte.h>

class TerminalSettings
{
public:
    const std::string font;
    const std::string foreground;
    const std::string background;
    const std::vector<std::string> palette;
    const ulong size_rows;
    const ulong size_columns;

    TerminalSettings(
        const std::string &font,
        const std::string &foreground,
        const std::string &background,
        const std::vector<std::string> &palette,
        const ulong size_rows,
        const ulong size_columns)
        : font(font),
          foreground(foreground),
          background(background),
          palette(palette),
          size_rows(size_rows),
          size_columns(size_columns)
    {
    }

    void apply_to(VteTerminal *terminal);
};

class DefaultTerminalSettingsFactory
{
public:
    static TerminalSettings create();
};

#endif // TERMINAL_SETTINGS_HPP
