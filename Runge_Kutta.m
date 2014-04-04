%Runge-Kutta.m -- This function uses the fourth Runge-Kutta scheme to solve
%a first order differential equation.
%The user must provide several input values:
%t_o -- the initial time
%t_f -- the final time
%y_o -- the initial condition
%h -- the step size
%The output is in the form of two other vectors, t and y.
%t contains the discrete times where the solution is computed
%y contains the values of the solution at each t.
%'time' is used to denote the current time variable.
%'i' denotes the running index for the solution.
function [t,y] = Runge_Kutta(t_o, t_f, y_o, h)
%Specify the initial values of t, y, and time.
t(1) = t_o;
y(1) = y_o;
time = t_o;
i=1;
%Repeat the Runge-Kutta scheme until the time exceeds t_f.
while ( time <= t_f)
    i = i+1;
    time = time + h;
    t(i) = time;
    %Employ the Runge-Kutta scheme to compute the next solution value.
    %Presently, the program will solve this differential equation:
    %y' = f(t,y) = y. Simply modify the equations below to fit a given
    %initial value problem.
    %These are the current definitions for k1, k2, k3, and k4:
    %k1 = f(t,y) = y.
    k1(i) = y(i-1);
    %k2 = f(t + (h/2), y + (h/2)*k1)
    k2(i) = y(i-1) + (h/2)*k1(i);
    %k3 = f(t + (h/2), y + (h/2)*k2)
    k3(i) = y(i-1) + (h/2)*k2(i);
    %k4 = f(t + h, y + h*k3)
    k4(i) = y(i-1) + h*k3(i);
    
    y(i) = y(i-1) + (h/6)*(k1(i) + 2*k2(i) + 2*k3(i) + k4(i));
end