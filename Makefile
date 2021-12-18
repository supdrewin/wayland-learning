override project   := wayland-learning
override src_dir   := $(PWD)/src
override build_dir := $(PWD)/build

default:; @mkdir -p $(build_dir)
	cd $(src_dir)/client && $(MAKE) && mv main $(build_dir)/client.out
	cd $(src_dir)/server && $(MAKE) && mv main $(build_dir)/server.out

clean:
	$(RM) -r $(build_dir)
.PHONY: clean
