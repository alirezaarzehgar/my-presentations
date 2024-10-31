MAIN ?= $(wildcard *.tex)

all: out
	pdflatex -output-directory=out/ ${MAIN}

out:
	mkdir -p out

view:
	evince -s out/*.pdf

clean:
	rm -rf out
