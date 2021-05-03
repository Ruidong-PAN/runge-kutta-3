clear;reset;
set xrange[-25:15];
set yrange[0:0.1];
set samples 1000
set title 'N(-5,20)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'N-520.eps'
xg=(20)**0.5
u=-5
plot (2*pi)**(-0.5)*(xg**(-1))*exp(-(x-u)**2/(2*xg**2)) w l lc 10

