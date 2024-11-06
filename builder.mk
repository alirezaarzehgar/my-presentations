MAIN ?= $(wildcard *.tex)
LATEX ?= pdflatex
FLAGS ?= -output-directory=out/

all: out
	${LATEX} ${FLAGS} ${MAIN}

out:
	mkdir -p out

view:
	evince -s out/*.pdf

clean:
	rm -rf out
