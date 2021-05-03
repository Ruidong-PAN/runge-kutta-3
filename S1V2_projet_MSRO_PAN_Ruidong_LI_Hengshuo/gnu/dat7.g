clear;reset;
set title 'iN(-5,20)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'iN-520.eps'
plot 'res7.txt'   w l lc 7

