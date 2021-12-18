%.out:
	mkdir -p $(build_dir)
	$(RM) $< > $(build_dir)/$@
	chmod +x $(build_dir)/$@
