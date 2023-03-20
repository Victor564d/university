a = -1;
b = 0;
h = 0.1;
params = 'r:d';

x = a:h:b;
y = ((sin(pi)*x.^4)./sqrt(1-14*x));

plot (x, y, params);

% Настройка внешнего вида
title ('График функции по Варианту');             
legend ('f(x) = (sin(pi)*x.^4)./sqrt(1-14*x)'); 
xlabel ('Ось X');                                 
ylabel ('Ось Y');
grid on;                                          
