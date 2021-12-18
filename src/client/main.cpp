#include <iostream>
#include <wayland-client.h>

int main(int, char **) {
  auto display = wl_display_connect(nullptr);
  if (not display) {
    std::cerr << "Failed to connect to Wayland display.\n";
    return EXIT_FAILURE;
  }
  std::cout << "Connection established!\n";

  wl_display_disconnect(display);
  return EXIT_SUCCESS;
}
