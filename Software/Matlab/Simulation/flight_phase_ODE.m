function dq = flight_phase_ODE(t,q,g,l0,T,p_desired,kr,klp,kpos)
%% define state
robot_pos = [q(1);q(2);q(3)];
robot_vel = [q(4);q(5);q(6)];
leg_tilt = [q(7);q(8)];
robot_orient = [q(10);q(11);q(12)];
robot_angvel = [q(13);q(14);q(15)];
v_desired = kpos*(p_desired-robot_pos);

%% Raibert stepping controller
step = T/2*[robot_vel(1);robot_vel(2);0]-kr*[v_desired(1);v_desired(2);0];
norm_step = norm(step);
step(3) = -sqrt(l0^2-norm_step^2);
leg_tilt_vel = [klp*(asin(robot_vel(1)*T/2/l0-kr*(v_desired(1)-robot_vel(1)))-leg_tilt(1)); ...
                klp*(asin(robot_vel(2)*T/2/l0-kr*(v_desired(2)-robot_vel(2)))-leg_tilt(2))];

%% state update
dq = zeros([9,1]);
dq(1) = robot_vel(1);
dq(2) = robot_vel(2);
dq(3) = robot_vel(3);
dq(4) = 0;
dq(5) = 0;
dq(6) = -g;
dq(7) = leg_tilt_vel(1);
dq(8) = leg_tilt_vel(2);
dq(10) = robot_angvel(1);
dq(11) = robot_angvel(2);
dq(12) = robot_angvel(3);
dq(13) = 0;
dq(14) = 0;
dq(15) = 0;
dq(9) = 0; %state
end