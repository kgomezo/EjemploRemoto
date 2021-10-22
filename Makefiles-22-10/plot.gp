set xlabel 'Nterm'; set ylabel 'Diff%'
plot 'datos.txt' w l t 'Diferencia porcentual'
set term pdf; set out "fig.pdf"