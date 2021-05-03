clear;reset;
set title 'iN(3,0.6)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'iN306.eps'
plot 'res4.txt'   w l lc 7

