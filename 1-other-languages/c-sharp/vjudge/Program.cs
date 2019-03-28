using System;

namespace vjudge
{
    class Program
    {
          private static int ReadInt()
        {
            return Convert.ToInt32(Console.ReadLine());
        }

        private static long ReadLong()
        {
            return Convert.ToInt64(Console.ReadLine());
        }

        private static int[] ReadArray()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), m => Convert.ToInt32(m));
        }
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");
            int n,count, a,b,x,y,minimus, maximus, temp;

            n = ReadInt();
            a=0; b=0;
            count = 1;
            int[] A;
            for(int i=0; i<n; i++){
                // x = Convert.ToInt32(Console.ReadLine()); y=Convert.ToInt32(Console.ReadLine());
                A = ReadArray();
                x=A[0]; y=A[1];
                //minimus = x; if(y<minimus){ minimus=y; }
                //maximus = a; if(b > maximus){   maximus = b; }
                minimus = Math.Min(x,y);
                maximus = Math.Max(a,b);
                temp=0; if(a!=b){   temp=1; }

                count =count+ Math.Max((minimus-maximus)+temp, 0);
                a=x; b=y;
            }

            Console.Write("{0}\n",count);
        }
    }
}
