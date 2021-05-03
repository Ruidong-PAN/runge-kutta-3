clear;reset;
set xrange[-20:10];
set yrange[0:0.14];
set samples 1000
set title 'N(-5,10)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'N-510.eps'
xg=(10)**0.5
u=-5
plot (2*pi)**(-0.5)*(xg**(-1))*exp(-(x-u)**2/(2*xg**2)) w l lc 10

