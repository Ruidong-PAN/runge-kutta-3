clear;reset;
set xrange[-4:4];
set yrange[-4:4];
set isosamples 100,100
set title 'dimension 2 N(0,1)'
set xlabel 'x'
set ylabel 'y'
set zlabel 'f(x,y)'
set dgrid3d splines
set hidden3d
set ticslevel 0
set key off
set term postscript enhanced font 'Time-roman,22'
set output '2N01.eps'
splot (2*pi)**(-1)*exp(-(x**2+y**2)/2) 

