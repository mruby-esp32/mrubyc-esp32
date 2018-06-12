COMPONENT_DEPENDS = mrubyc

COMPONENT_EXTRA_CLEAN := mrb_code.h

main.o: mrb_code.h

mrb_code.h: $(COMPONENT_PATH)/resource/$(MRUBY_SCRIPT)
	$(MRUBY_PATH)/bin/mrbc -E -B mrb_code -o $@ $^

.PHONY: mrb_code.h
