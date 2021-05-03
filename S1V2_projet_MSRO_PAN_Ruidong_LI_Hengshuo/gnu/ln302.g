clear;reset;
set xrange[1:5];
set yrange[0:1];
set samples 1000
set title 'N(3,0.2)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'N302.eps'
xg=(0.2)**0.5
u=3
plot (2*pi)**(-0.5)*(xg**(-1))*exp(-(x-u)**2/(2*xg**2)) w l lc 10

