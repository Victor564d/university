function y = fun1(x)
% Вычисление двух функций
% y(1) = 200 sin(x)/x, y(2) = x2.
y(:,1) = 200*sin(x)./ x;
y(:,2) = x .^2;
end