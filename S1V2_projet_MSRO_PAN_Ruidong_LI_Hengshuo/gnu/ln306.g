clear;reset;
set xrange[-1:7];
set yrange[0:0.6];
set samples 1000
set title 'N(3,0.6)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'N306.eps'
xg=(0.6)**0.5
u=3
plot (2*pi)**(-0.5)*(xg**(-1))*exp(-(x-u)**2/(2*xg**2)) w l lc 10

