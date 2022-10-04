#include <gtkmm-3.0/gtkmm.h>
#include <gtkmm-3.0/gtkmm/application.h>
#include <gtkmm-3.0/gtkmm/container.h>
#include <gtkmm-3.0/gtkmm/main.h>

int main(int argc, char **argv) {

  Gtk::Main kit(argc,argv);
  Gtk::Window window;
  window.set_default_size(600,400);
  window.set_title("Exemplo de app GTK");

  Gtk::Label label;
  label.set_text("primeira label");
  window.add(label);

  window.show_all();

  Gtk::Main::run(window);

  return 0;
}

// compile g++ simplegtk.cpp -o simple $(pkg-config gtkmm-3.0 --cflags --libs)