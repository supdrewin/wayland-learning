#include <iostream>
#include <wayland-server.h>

int main(int, char **) {
  auto display = wl_display_create();
  if (not display) {
    std::cerr << "Unable to create Wayland display.\n";
    return EXIT_FAILURE;
  }

  auto socket = wl_display_add_socket_auto(display);
  if (not socket) {
    std::cerr << "Unable to add socket to Wayland display.\n";
    return EXIT_FAILURE;
  }

  std::cout << "Running Wayland display on " << socket << std::endl;
  wl_display_run(display);

  wl_display_destroy(display);
  return EXIT_SUCCESS;
}
