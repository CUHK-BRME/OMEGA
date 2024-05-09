load('accelXneg.mat');
load('accelYneg.mat');
load('accelZneg.mat');
load('accelXpos.mat');
load('accelYpos.mat');
load('accelZpos.mat');
B = reshape(accelXpos, [3, 11192]);
accelXpos = B';
B = reshape(accelXneg, [3, 11070]);
accelXneg = B';
B = reshape(accelYpos, [3, 11586]);
accelYpos = B';
B = reshape(accelYneg, [3, 10825]);
accelYneg = B';
B = reshape(accelZpos, [3, 10853]);
accelZpos = B';
B = reshape(accelZneg, [3, 11102]);
accelZneg = B';
accelXpos_mean = mean(accelXpos);
accelYpos_mean = mean(accelYpos);
accelZneg_mean = mean(accelZneg);
accelXneg_mean = mean(accelXneg);
accelYneg_mean = mean(accelYneg);
accelZpos_mean = mean(accelZpos);
% load('gyroXneg.mat'); gyroXneg_mean = mean(gyroXneg);
% load('gyroYneg.mat'); gyroYneg_mean = mean(gyroYneg);
% load('gyroZneg.mat'); gyroZneg_mean = mean(gyroZneg);
% load('gyroXpos.mat'); gyroXpos_mean = mean(gyroXpos);
% load('gyroYpos.mat'); gyroYpos_mean = mean(gyroYpos);
% load('gyroZpos.mat'); gyroZpos_mean = mean(gyroZpos);
accelZero = (accelXneg_mean + accelYneg_mean + accelZneg_mean + accelXpos_mean + accelYpos_mean + accelZpos_mean)/6
% gyroZero = (gyroXneg_mean + gyroYneg_mean + gyroZneg_mean + gyroXpos_mean + gyroYpos_mean + gyroZpos_mean)/6
accelX = -(accelXpos_mean-accelXneg_mean)/2
accelY = -(accelYpos_mean-accelYneg_mean)/2
accelZ = -(accelZpos_mean-accelZneg_mean)/2
% gyroX = -(gyroXpos_mean-gyroXneg_mean)/2/(2000/12*2*pi/60)
% gyroY = -(gyroYpos_mean-gyroYneg_mean)/2/(2000/12*2*pi/60)
% gyroZ = -(gyroZpos_mean-gyroZneg_mean)/2/(2000/12*2*pi/60)
accel = inv([accelX' accelY' accelZ']);
% gyro = inv([gyroX' gyroY' gyroZ']);
