override SHELL := /bin/bash

URL := $(shell cat wayland-protocols.url)

default: libxdg-shell.a

libxdg-shell.a: xdg-shell.o

xdg-shell.c: xdg-shell-unstable-v6.xml
	wayland-scanner public-code $< $@

xdg-shell.h: xdg-shell-unstable-v6.xml
	wayland-scanner client-header $< $@

xdg-shell.o: xdg-shell.h xdg-shell.c

xdg-shell-unstable-v6.xml:
	curl -O $(URL)/plain/unstable/xdg-shell/$@

install: libxdg-shell.a
	install -Dm644 -t $(PREFIX)/include xdg-shell.h
	install -Dm644 -t $(PREFIX)/lib libxdg-shell.a

uninstall:
	$(RM) $(PREFIX)/include/xdg-shell.h $(PREFIX)/lib/libxdg-shell.a

clean:
	$(RM) libxdg-shell.a xdg-shell.{c,h,o} xdg-shell-unstable-v6.xml

.PHONY: install uninstall clean

lib%.a: %.o
	$(AR) $(ARFLAGS) $@ $<
