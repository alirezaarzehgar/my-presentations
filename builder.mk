MAIN ?= $(wildcard *.tex)

all: out
	xelatex -output-directory=out/ ${MAIN}
	xelatex -output-directory=out/ ${MAIN}

out:
	mkdir -p out

view:
	evince -s out/*.pdf

clean:
	rm -rf out
