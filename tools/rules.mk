%.out:
	mkdir -p $(build_dir)
	$(RM) $< > $(build_dir)/$@
	chmod a+x $(build_dir)/$@
