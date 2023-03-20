using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;


namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            long k = 0;
            long n = 0;
            ulong result = 0;
            int vibor = 0;
            Console.WriteLine("Введите общее колличество N -->");
            n = Convert.ToInt64(Console.ReadLine());
            Console.WriteLine("Введите общее колличество K -->");
            k = Convert.ToInt64(Console.ReadLine());
            Console.WriteLine("Порядок выбранных элементов важен ? 0 - нет, 1 - да ");
            vibor = Convert.ToInt32(Console.ReadLine());
            if (vibor == 0)
            {
                Console.WriteLine("Среди выбранных элементов есть повторение ? 0 - нет, 1 - да ");
                vibor = Convert.ToInt32(Console.ReadLine());
                if (vibor == 0)
                {
                    Console.WriteLine("Сочетание");
                    result = ()
                }
                else
                {
                }
            } else { 
            }  

        }
    }
}
