using System;

namespace EnhanceIfStatementCsharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start Program!");

            int inputTemperature = 0;
            string tempMess = string.Empty;
            string inputValue = string.Empty;
            //takes ip from console
            Console.Write("Enter the current temperature : ");
            inputValue = Console.ReadLine();

            //Validate the ip.
            bool validInteger = int.TryParse(inputValue, out inputTemperature);

            // (condition) ? iftrue : iffalse;
            if(validInteger)
            {
                tempMess = inputTemperature <= 15 ?
                    // true
                    "it is too cold here" :
                    // false
                    (inputTemperature >= 16 && inputTemperature <= 28) ?
                    // true
                    "it is cold here" :
                    // false
                    inputTemperature > 28 ? 
                    // true
                    "it is hot here" :
                    // false
                    "Empty";

                Console.WriteLine(tempMess);
            }
            else
            {

                Console.WriteLine("Not a valid Temperature.");
            }







        }
    }
}
