clear;reset;
set xrange[-4:4];
set yrange[0:0.4];
set samples 1000
set title 'N(0,1)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'N01.eps'
xg=1**0.5
u=0
plot (2*pi)**(-0.5)*(xg**(-1))*exp(-(x-u)**2/(2*xg**2)) w l lc 10

