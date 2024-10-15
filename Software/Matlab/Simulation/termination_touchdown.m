function [value, isterminal, direction] = termination_touchdown(t, X)
value = ((X(3)<=0.46*cos(X(7)) && X(6)<0) || X(3)<0);   
isterminal = 1;
direction  = 0;
end