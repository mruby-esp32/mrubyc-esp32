COMPONENT_ADD_INCLUDEDIRS := mrubyc/src
COMPONENT_SRCDIRS := mrubyc/src mrubyc/src/hal_esp32
COMPONENT_SUBMODULES += mrubyc

$(shell if [ ! -e $(COMPONENT_PATH)/mrubyc/src/hal ]; then ln -s $(COMPONENT_PATH)/mrubyc/src/hal_esp32 $(COMPONENT_PATH)/mrubyc/src/hal; fi)
