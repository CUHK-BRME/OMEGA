function dq = stance_phase_ODE(t,q,m,g,k_spring,l0,p_desired,h_desired,ke,kf,bf,kpos,kp,kd)
%% define state
robot_pos = [q(1);q(2);q(3)];
robot_vel = [q(4);q(5);q(6)];
foot_pos = [q(7);q(8);q(9)];
robot_orient = [q(10);q(11);q(12)];
robot_angvel = [q(13);q(14);q(15)];

%% energy controller
v_desired = kpos*(p_desired-robot_pos);

l = norm(robot_pos-foot_pos);
unit_spring = (robot_pos-foot_pos)/l;
e_desired = 1/2*m*dot(v_desired,v_desired) ... % desried KE
           +m*g*(h_desired); % desired PE
e = 1/2*m*(dot(robot_vel,robot_vel)) ... % current KE
   +1/2*k_spring*(l-l0)^2+m*g*robot_pos(3); % current PE
f_e = ke*(e_desired-e); % force with energy gain
spring_force =-k_spring*(l-l0);
if robot_vel(3)>0
     spring_force = spring_force+f_e;
end
spring_force = spring_force*unit_spring;
hip_torque = kp*robot_orient+kd*robot_angvel;
% hip_torque = hip_torque-dot(hip_torque,unit_spring)*unit_spring;
side_force = cross(hip_torque,(robot_pos-foot_pos))/dot((robot_pos-foot_pos),(robot_pos-foot_pos));
% foot_force = spring_force+side_force;
foot_force = spring_force;

%% state update
dq = zeros([10,1]);
dq(1) = robot_vel(1);
dq(2) = robot_vel(2);
dq(3) = robot_vel(3);
dq(4) = foot_force(1)/m;
dq(5) = foot_force(2)/m;
dq(6) = foot_force(3)/m-g;
dq(7) = 0;
dq(8) = 0;
dq(9) = (-foot_force(3)-kf*foot_pos(3))/bf;
dq(10) = robot_angvel(1);
dq(11) = robot_angvel(2);
dq(12) = robot_angvel(3);
dq(13) = -hip_torque(1);
dq(14) = -hip_torque(2);
dq(15) = 0;
dq(16) = 0; %state
end