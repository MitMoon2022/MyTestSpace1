using System;
using System.Text;
using System.Xml;

namespace ReadXML1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start Program!");

            XmlDocument doc = new XmlDocument();
            string filePath = "D:\\jftMit1\\MyTestSpace1\\ReadXML1\\plants.xml";
            doc.Load(filePath);

            
            XmlNode northernSpecimen = doc.SelectSingleNode("/plant/specimens/specimen[latitude>0]/comments");
            string comments = northernSpecimen.InnerText;
            Console.WriteLine(comments);
            XmlNodeList oldChildren = doc.DocumentElement.ChildNodes;
            foreach (XmlNode oldChild in oldChildren)
                Console.WriteLine(oldChild.InnerText);                                            //Console.WriteLine(oldChild.InnerText); InnerXml, OuterXml.
            Console.WriteLine("----------------------------------------------------------------------------------");
            XmlNodeList specimens = doc.SelectNodes("/plant/specimens/specimen");
            foreach (XmlNode specimen in specimens)
                Console.WriteLine(specimen.InnerText);

            //https://csharp.net-tutorials.com/xml/working-with-the-xmlnode-class/
            //XmlDocument xmlDoc = new XmlDocument();
            //xmlDoc.LoadXml("<user name=\"John Doe\" age=\"42\"></user>");
            //if (xmlDoc.DocumentElement.Attributes["name"] != null)
            //    Console.WriteLine(xmlDoc.DocumentElement.Attributes["name"].Value);
            //if (xmlDoc.DocumentElement.Attributes["age"] != null)
            //    Console.WriteLine(xmlDoc.DocumentElement.Attributes["age"].Value);
            //Console.ReadKey();



            Console.ReadKey();
        }
    }
}
