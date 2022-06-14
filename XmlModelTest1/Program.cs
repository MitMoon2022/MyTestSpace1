using System;
using System.IO;
using System.Runtime.Serialization.Formatters;
using System.Xml.Serialization;
using System.Collections.Generic;

namespace XmlModelTest1
{



    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start of Program!");

            XmlSerializer serializer = new XmlSerializer(typeof(TestModel));

            //MemoryStream stream = new MemoryStream();
            FileStream stream = File.OpenWrite("D:\\jftMit1\\test.xml");

            serializer.Serialize(stream, new TestModel() { a1 = "test1", a2 = "test2", a3 = new List<string>() { "1", "2", "3" } });
            stream.Dispose();

            FileStream streamread = File.OpenRead("D:\\jftMit1\\test.xml");

            var result = (TestModel)(serializer.Deserialize(streamread));

            Console.Read();

        }
    }

    public class TestModel
    {
        public string a1 { get; set; }
        public string a2 { get; set; }
        public List<string> a3 { get; set; }


    }



}
