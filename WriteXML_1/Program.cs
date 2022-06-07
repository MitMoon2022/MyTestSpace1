using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace WriteXML_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            string filename = "D:\\jftMit1\\Employee.xml";

            XmlTextWriter xmlWriter = new XmlTextWriter(filename, System.Text.Encoding.UTF8);

            xmlWriter.Formatting = Formatting.Indented;

            xmlWriter.WriteStartDocument();

            xmlWriter.WriteComment("Creating an XML file using C#");

            xmlWriter.WriteStartElement("EmployeeInfo");

            for (int i = 0; i < 3; i++)
            {
                xmlWriter.WriteStartElement("Employee");

                Console.WriteLine("Enter the ID for Employee " + i);
                xmlWriter.WriteElementString("ID", Console.ReadLine());

                Console.WriteLine("Enter the Name for Employee " + i);
                xmlWriter.WriteElementString("Name", Console.ReadLine());

                Console.WriteLine("Enter the Department for Employee " + i);
                xmlWriter.WriteElementString("Department", Console.ReadLine());

            }

            xmlWriter.WriteEndElement();
            xmlWriter.WriteEndDocument();
            xmlWriter.Flush();
            xmlWriter.Close();

        }
    }
}
