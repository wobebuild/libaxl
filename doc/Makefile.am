EXTRA_DIST = axl-doc.doxygen axl.css main-page-logo.png body_back.gif \
             axl-doc-footer.html axl_babel_reading.png axl-components.png \
	     axl-doc-header.html image01.png ns_example.c ns_shaper.xml bg.png aspl-logo.png

bin_SCRIPTS = initial_build_doc

help:
	@echo 
	@echo " Documentaticd on not built!:"
	@echo " ~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo " --> Doxygen documentation wasn't built because an stamp was detected: doc.stamp"
	@echo " --> To regenerate or force doc building type make build_doc or remove doc.stamp";
	@echo

initial_build_doc:
	@echo "checking documenation stamp..";
	@test -e doc.stamp & make help
	@test -e doc.stamp || make build_doc
	@test -e doc.stamp || touch doc.stamp

build_doc:
	rm -rf html/
	@echo "Generating module documentation..";
	doxygen axl-doc.doxygen
	cp $(top_srcdir)/doc/hacha-100x171.png html
	cp $(top_srcdir)/doc/axl.css html
	cp $(top_srcdir)/doc/bg.png html
	cp $(top_srcdir)/doc/main-page-logo.png html
	cp $(top_srcdir)/doc/aspl-logo.png html
	cp $(top_srcdir)/doc/body_back.gif html

