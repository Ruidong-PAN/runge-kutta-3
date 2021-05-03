clear;reset;
set title 'iN(3,0.2)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'iN302.eps'
plot 'res5.txt'   w l lc 7

