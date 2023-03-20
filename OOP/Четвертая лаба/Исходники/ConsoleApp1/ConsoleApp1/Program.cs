// See https://aka.ms/new-console-template for more information

void  write(Double temp){
    Console.Write(temp.ToString() + "  ");
}

async Task write_as(Double temp) { 
    await Task.Run(()=>write(temp)); 
}



const int  n_count = 100000000;
Double n = 1; Double temp;
for (Double i = 2; i < n_count; i++)
{
    if (i % 2 == 0)
    {
        temp = -(1 / i);
       n -= 1 / i;
        
    }
    else { n += 1 / i;
        temp = (1 / i);
    }
    write_as(temp);
}
Console.WriteLine("\n\n   РЕЗУЛЬТАТ " + n.ToString());
Console.ReadKey();


