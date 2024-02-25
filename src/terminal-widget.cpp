
#include "terminal-widget.hpp"

VteTerminal *add_vte_terminal_to_app_window(Gtk::Window &window, Glib::RefPtr<Gtk::Application> app)
{
    auto terminal = vte_terminal_new();
    window.add(*Glib::wrap(GTK_WIDGET(terminal)));
    g_signal_connect(
        terminal,
        "child-exited",
        G_CALLBACK(+[](VteTerminal *, int, gpointer user_data)
                   {
                       static_cast<Gtk::Application *>(user_data)->quit();
                   }),
        app.get());
    return VTE_TERMINAL(terminal);
}

void run_command_in_terminal(VteTerminal *terminal, std::string command)
{
    const char *command_array[] = {command.c_str(), nullptr};
    vte_terminal_spawn_async(
        terminal,
        VTE_PTY_DEFAULT,
        nullptr,
        const_cast<char **>(command_array),
        nullptr,
        G_SPAWN_SEARCH_PATH,
        nullptr, nullptr,
        nullptr,
        -1,
        nullptr,
        nullptr, nullptr);
}
