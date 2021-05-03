clear;reset;
set xrange[0:1];
set yrange[0:1.2];
set title 'iU(0,1)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'iU01.eps'
plot 'res2.txt'  w l lc 7

