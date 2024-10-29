inputs := what_is_lug

all: $(inputs) copy

.PHONY: what_is_lug
$(inputs):
	make -C $@

copy:
	mkdir -p presentations
	cp -f **/out/*.pdf presentations/

clean:
	rm -rf **/out presentations
