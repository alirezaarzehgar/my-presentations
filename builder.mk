MAIN ?= $(wildcard *.tex)
LATEX ?= pdflatex

all: out
	${LATEX} -output-directory=out/ ${MAIN}

out:
	mkdir -p out

view:
	evince -s out/*.pdf

clean:
	rm -rf out
