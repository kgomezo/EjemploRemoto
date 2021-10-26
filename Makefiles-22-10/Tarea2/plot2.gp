set xlabel 'N términos'; set ylabel 'Error Relativo'; set title 'Error respecto a suma 3'
plot 'datos2.txt' u 1:2 with lines title "Suma 1", 'datos2.txt' u 1:3 with lines title "Suma2"
set term pdf; set out "fig.pdf"