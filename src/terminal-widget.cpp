#include "terminal-widget.hpp"

void apply_settings(VteTerminal *terminal, TerminalSettings &settings);

void connect_exit_signal(GtkWidget *terminal, Gtk::Window &window);

void TerminalWidget::add_to(Gtk::Window &window)
{
    auto widget = vte_terminal_new();
    window.add(*Glib::wrap(GTK_WIDGET(widget)));
    connect_exit_signal(widget, window);
    this->terminal = VTE_TERMINAL(widget);
    apply_settings(terminal, settings);
}

void TerminalWidget::run(std::string command)
{
    const char *command_array[] = {command.c_str(), nullptr};
    vte_terminal_spawn_async(
        this->terminal,
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

void apply_settings(VteTerminal *terminal, TerminalSettings &settings)
{
    settings.apply_to(terminal);
}

void connect_exit_signal(GtkWidget *widget, Gtk::Window &window)
{
    g_signal_connect(
        widget,
        "child-exited",
        G_CALLBACK(
            +[](GtkWidget *, int, gpointer user_data)
            {
                auto window = static_cast<Gtk::Window *>(user_data);
                auto app = window->property_application().get_value();
                app->quit();
            }),
        &window);
}
