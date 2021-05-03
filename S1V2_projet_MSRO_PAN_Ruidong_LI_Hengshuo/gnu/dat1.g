clear;reset;
set xrange[-4:4];
set yrange[0:0.4];
set title 'iN(0,1)'
set xlabel 'x'
set ylabel 'f(x)'
set key off
set term postscript enhanced font 'Time-roman,22'
set output 'iN01.eps'
plot 'res1.txt'   w l lc 7

