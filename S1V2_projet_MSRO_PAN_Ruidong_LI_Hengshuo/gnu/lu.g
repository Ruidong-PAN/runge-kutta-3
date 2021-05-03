clear;reset;
set xrange[0:1];
set yrange[0:1.2];
set samples 1000
set title 'U(0,1)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'U01.eps'
plot 1  w l lc 10

