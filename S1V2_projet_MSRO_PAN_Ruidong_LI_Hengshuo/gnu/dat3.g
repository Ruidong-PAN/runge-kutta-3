clear;reset;
set hidden3d
set dgrid3d splines
set xlabel 'x'
set ylabel 'y'
set zlabel 'f(x,y)'
set title 'dimension 2 iN(0,1)'
set ticslevel 0
set ztics 0,0.09,0.18
set key off
set term postscript enhanced font 'Time-roman,22'
set output '2iN01.eps'
splot 'res3.txt'

