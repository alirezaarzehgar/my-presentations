inputs := $(dir $(wildcard */))
inputs := $(filter-out presentations/,$(inputs))

all: $(inputs) copy

.PHONY: $(inputs)
$(inputs):
	make -C $@

copy:
	mkdir -p presentations
	cp -f **/out/*.pdf presentations/

clean:
	rm -rf **/out presentations
