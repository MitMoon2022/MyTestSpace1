using System;
using System.IO;
using System.Text;
using System.Linq;



namespace ConsoleFileCopy1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Main Start!");

            // Creating two files
            string sourceFile = @"file.txt";
            string destinationFile = @"gfg.txt";
            try
            {
                // Copying source file's contents to
                // destination file
                File.Copy(sourceFile, destinationFile, true);   //set overwrite to be true.
            }
            catch (IOException iox)
            {
                Console.WriteLine(iox.Message);
            }
            //---------------------------------------------
            Console.WriteLine("Copying process has been done.");





        }
    }
}
