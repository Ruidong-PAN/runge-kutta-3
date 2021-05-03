clear;reset;
set title 'iN(-5,10)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'iN-510.eps'
plot 'res6.txt'   w l lc 7

