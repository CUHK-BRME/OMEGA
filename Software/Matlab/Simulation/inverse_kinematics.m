function [theta,check,noSol] = inverse_kinematics(x,D,d,r,upLim,lowLim)
%%theta returns angle if IK is possible
%%check returns zero if IK is correct
%% noSol retunrs (0 if have solition) (1 if leg linkage length cannot achieve position) (2 if hit angle limit)
theta = zeros([3,1]);
check = zeros([3,1]);
noSol = zeros([3,1]);

R2 = [cosd(120) -sind(120) 0; sind(120) cosd(120) 0; 0 0 1];
R3 = [cosd(240) -sind(240) 0; sind(240) cosd(240) 0; 0 0 1];

temp = ((r - x(2))^2/2 + D^2/2 - d^2/2 + x(1)^2/2 + x(3)^2/2)/(D*((r - x(2))^2 + x(3)^2)^(1/2));
if abs(temp)>1 %% check leg length
    noSol(1) = 1;
else
    theta(1) = - acos(((r - x(2))^2/2 + D^2/2 - d^2/2 + x(1)^2/2 + x(3)^2/2)/(D*((r - x(2))^2 + x(3)^2)^(1/2))) + atan2(x(3), x(2) - r);
    knee1 =  [0;r;0]+[0;D*cos(theta(1));D*sin(theta(1))];
    check(1) = norm(x-knee1)-d;
    if(theta(1)>upLim) %% check angle bound
        if(theta(1)-2*pi<lowLim)
            noSol = 2;
        end
    elseif(theta(1)<lowLim)
        if(theta(1)+2*pi>upLim)
            noSol = 2;
        end
    end
end

temp = ((r + x(2)/2 + (3^(1/2)*x(1))/2)^2/2 + D^2/2 - d^2/2 + (x(1)/2 - (3^(1/2)*x(2))/2)^2/2 + x(3)^2/2)/(D*((r + x(2)/2 + (3^(1/2)*x(1))/2)^2 + x(3)^2)^(1/2));
if abs(temp)>1
    noSol(2) = 1;
else
    theta(2) = atan2(x(3), - r - x(2)/2 - (3^(1/2)*x(1))/2) - acos(((r + x(2)/2 + (3^(1/2)*x(1))/2)^2/2 + D^2/2 - d^2/2 + (x(1)/2 - (3^(1/2)*x(2))/2)^2/2 + x(3)^2/2)/(D*((r + x(2)/2 + (3^(1/2)*x(1))/2)^2 + x(3)^2)^(1/2)));
    knee2 = R2*([0;r;0]+[0;D*cos(theta(2));D*sin(theta(2))]);
    check(2) = norm(x-knee2)-d;
    if(theta(2)>upLim)
        if(theta(2)-2*pi<lowLim)
            noSol = 2;
        end
    elseif(theta(2)<lowLim)
        if(theta(2)+2*pi>upLim)
            noSol = 2;
        end
    end
end

temp = ((r + x(2)/2 - (3^(1/2)*x(1))/2)^2/2 + D^2/2 - d^2/2 + (x(1)/2 + (3^(1/2)*x(2))/2)^2/2 + x(3)^2/2)/(D*((r + x(2)/2 - (3^(1/2)*x(1))/2)^2 + x(3)^2)^(1/2));
if abs(temp)>1
    noSol(3) = 1;
else
    theta(3) = atan2(x(3), (3^(1/2)*x(1))/2 - x(2)/2 - r) - acos(((r + x(2)/2 - (3^(1/2)*x(1))/2)^2/2 + D^2/2 - d^2/2 + (x(1)/2 + (3^(1/2)*x(2))/2)^2/2 + x(3)^2/2)/(D*((r + x(2)/2 - (3^(1/2)*x(1))/2)^2 + x(3)^2)^(1/2)));
    knee3 = R3*([0;r;0]+[0;D*cos(theta(3));D*sin(theta(3))]);
    check(3) = norm(x-knee3)-d;
    if(theta(3)>upLim)
        if(theta(3)-2*pi<lowLim)
            noSol = 2;
        end
    elseif(theta(3)<lowLim)
        if(theta(3)+2*pi>upLim)
            noSol = 2;
        end
    end
end
end