function [value, isterminal, direction] = termination_liftoff(t, X)
value = ((norm([X(1);X(2);X(3)]-[X(7);X(8);X(9)])>0.46 && X(6)>0) || X(3)<0);   
isterminal = 1;
direction  = 0;
end