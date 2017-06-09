all: html pdf

help:
	@echo "The documentation can be generated with one of the following commands:"
	@echo "    make html"
	@echo "    make pdf"
	@echo ""
	@echo "The following dependencies need to be installed:"
	@echo "    plantuml: for generating images from UML diagrams"
	@echo "    rst2html: for HTML output"
	@echo "    rst2pdf: for PDF output"

uml_diagrams := $(patsubst %.plantuml,%.svg,$(wildcard *.plantuml))
%.svg: %.plantuml
	plantuml -tsvg $<

html_output := $(patsubst %.rst,%.html,$(wildcard *.rst))
%.html: %.rst
	rst2html $< $@

pdf_output := $(patsubst %.rst,%.pdf,$(wildcard *.rst))
%.pdf: %.rst
	rst2pdf -o $@ $<

$(html_output): $(uml_diagrams)
html: $(html_output) $(uml_diagrams)

$(pdf_output): $(uml_diagrams)
pdf: $(pdf_output) $(uml_diagrams)

clean:
	-rm -f $(uml_diagrams)
	-rm -f $(html_output)
	-rm -f $(pdf_output)

.PHONY: clean

