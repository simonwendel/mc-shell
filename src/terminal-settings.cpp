#include "terminal-settings.hpp"

Glib::RefPtr<Gio::Settings> get_default_terminal_settings();

void TerminalSettings::apply_to(VteTerminal *terminal)
{
    Gdk::RGBA foreground_color(foreground);
    Gdk::RGBA background_color(background);

    auto palette_colors = std::vector<GdkRGBA>(palette.size());
    std::transform(
        palette.begin(), palette.end(), palette_colors.begin(),
        [](std::string color)
        { return *Gdk::RGBA(color).gobj(); });

    vte_terminal_set_size(terminal, size_columns, size_rows);
    vte_terminal_set_font(terminal, pango_font_description_from_string(font.c_str()));
    vte_terminal_set_colors(terminal, foreground_color.gobj(), background_color.gobj(), palette_colors.data(), palette_colors.size());
}

TerminalSettings DefaultTerminalSettingsFactory::create()
{
    auto settings = get_default_terminal_settings();
    auto size_rows = settings->get_int("default-size-rows");
    auto size_columns = settings->get_int("default-size-columns");
    auto font = settings->get_string("font");
    auto foreground = settings->get_string("foreground-color");
    auto background = settings->get_string("background-color");
    auto palette = settings->get_string_array("palette");
    return TerminalSettings(font, foreground, background, palette, size_rows, size_columns);
}

Glib::RefPtr<Gio::Settings> get_default_terminal_settings()
{
    auto profiles = Gio::Settings::create("org.gnome.Terminal.ProfilesList");
    auto default_profile = profiles->get_string("default");

    auto settings = Gio::Settings::create("org.gnome.Terminal.Legacy.Profile", "/org/gnome/terminal/legacy/profiles:/:" + default_profile + "/");
    return settings;
}
