../bin/IIES4-LOA-romain.beaumont.pdf:IIES4-LOA-romain.beaumont.tex
	cp IIES4-LOA-romain.beaumont.tex ../temp/IIES4-LOA-romain.beaumont.tex
	cp minted.sty ../temp
	cd ../temp ; pdflatex -shell-escape IIES4-LOA-romain.beaumont.tex && pdflatex -shell-escape IIES4-LOA-romain.beaumont.tex && pdflatex -shell-escape IIES4-LOA-romain.beaumont.tex && pdflatex -shell-escape IIES4-LOA-romain.beaumont.tex
	mv ../temp/IIES4-LOA-romain.beaumont.pdf ../bin/IIES4-LOA-romain.beaumont.pdf
	
run:../bin/IIES4-LOA-romain.beaumont.pdf
	evince ../bin/IIES4-LOA-romain.beaumont.pdf
	
clean:
	rm -f ../temp/*
	rm -f ../bin/*