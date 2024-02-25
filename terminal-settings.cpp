#include "terminal-settings.hpp"

Glib::RefPtr<Gio::Settings> get_default_terminal_settings();

void clone_terminal_size_to_vte(VteTerminal *terminal)
{
    auto settings = get_default_terminal_settings();
    auto size_rows = settings->get_int("default-size-rows");
    auto size_columns = settings->get_int("default-size-columns");
    vte_terminal_set_size(terminal, size_columns, size_rows);
}

void clone_terminal_font_to_vte(VteTerminal *terminal)
{
    auto settings = get_default_terminal_settings();
    auto pango_font = settings->get_string("font");
    vte_terminal_set_font(terminal, pango_font_description_from_string(pango_font.c_str()));
}

void clone_terminal_colors_to_vte(VteTerminal *terminal)
{
    auto settings = get_default_terminal_settings();
    auto foreground_color = Gdk::RGBA(settings->get_string("foreground-color"));
    auto background_color = Gdk::RGBA(settings->get_string("background-color"));

    auto palette_colors = settings->get_string_array("palette");
    auto palette = std::vector<GdkRGBA>(palette_colors.size());
    std::transform(
        palette_colors.begin(), palette_colors.end(), palette.begin(),
        [](std::string color)
        { return *Gdk::RGBA(color).gobj(); });

    vte_terminal_set_colors(terminal, foreground_color.gobj(), background_color.gobj(), palette.data(), palette.size());
}

Glib::RefPtr<Gio::Settings> get_default_terminal_settings()
{
    auto profiles = Gio::Settings::create("org.gnome.Terminal.ProfilesList");
    auto default_profile = profiles->get_string("default");

    auto settings = Gio::Settings::create("org.gnome.Terminal.Legacy.Profile", "/org/gnome/terminal/legacy/profiles:/:" + default_profile + "/");
    return settings;
}
