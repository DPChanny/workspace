using System;
using System.Collections.Generic;
using System.IO;

namespace UnicoderCMD
{
    class Program
    {

        private const int EXCEPTION = -1;
        private const int SENTENCE = 1;
        private const int FILE = 2;
        private const int EXIT = 3;
        private const int Decrypt = 2;
        private const int Encrypt = 1;

        private const string PROGRAM_NAME = "Unicoder";

        private const string PASSWORD = "password";

        static void Main(string[] args)
        {
            Console.Write("Password: ");
            string pass = "";
            do
            {
                ConsoleKeyInfo key = Console.ReadKey(true);
                if (key.Key != ConsoleKey.Backspace && key.Key != ConsoleKey.Enter)
                {
                    pass += key.KeyChar;
                    Console.Write("*");
                }
                else
                {
                    if (key.Key == ConsoleKey.Backspace && pass.Length > 0)
                    {
                        pass = pass.Substring(0, (pass.Length - 1));
                        Console.Write("\b \b");
                    }
                    else if (key.Key == ConsoleKey.Enter)
                    {
                        break;
                    }
                }
            } while (true);

            if (pass == PASSWORD)
            {
                while (true)
                {
                    if (PrintMainMenu(out int answer))
                    {
                        if (answer == SENTENCE)
                        {
                            while (true)
                            {
                                if (PrintSentenceMenu(out int answerSentence))
                                {
                                    if (answerSentence == Encrypt)
                                    {
                                        try
                                        {
                                            Console.Clear();
                                            Console.Write("Enter Sentence: ");
                                            string input = Console.ReadLine();
                                            List<int> encrypted = Unicoder.Encrypt(input);
                                            Console.WriteLine(Unicoder.IntArrayToStr(encrypted));
                                            wait();
                                        }
                                        catch (Exception e)
                                        {
                                            Console.WriteLine("Failed To Encrypt");
                                            Console.WriteLine(e.Message);
                                            wait();
                                        }
                                    }
                                    if (answerSentence == Decrypt)
                                    {
                                        try
                                        {
                                            Console.Clear();
                                            Console.Write("Enter Encrypted Sentence: ");
                                            string input = Console.ReadLine();
                                            List<int> decrypted;
                                            if (Unicoder.EncryptedStrToIntArray(input, out decrypted))
                                            {
                                                string decryptedStr = Unicoder.Decrypt(decrypted);
                                                Console.WriteLine(decryptedStr);
                                            }
                                            else
                                            {
                                                Console.WriteLine("Failed To Decrypt");
                                                wait();
                                            }
                                            wait();
                                        }
                                        catch (Exception e)
                                        {
                                            Console.WriteLine("Failed To Decrypt");
                                            Console.WriteLine(e.Message);
                                            wait();
                                        }
                                    }
                                    if (answerSentence == EXIT)
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                        if (answer == FILE)
                        {
                            while (true)
                            {
                                if (PrintFileMenu(out int answerFile))
                                {
                                    if (answerFile == Encrypt)
                                    {
                                        try
                                        {
                                            Console.Clear();
                                            if (GetFile(out FileStream file, FileMode.Open, "Enter File Name To Encrypt"))
                                            {
                                                StreamReader fileStream = new StreamReader(file);
                                                Console.WriteLine("Reading...");
                                                string fileStr = fileStream.ReadToEnd();
                                                fileStream.Close();
                                                List<int> fileStrEncryptedInt = Unicoder.Encrypt(fileStr);
                                                Console.WriteLine("Encrypting...");
                                                string fileStrEncryptedStr = Unicoder.IntArrayToStr(fileStrEncryptedInt);
                                                Console.WriteLine("Converting To String...");
                                                Console.WriteLine("Saving File As " + file.Name + ".ue ...");
                                                StreamWriter encryptedStream = new StreamWriter(file.Name + ".ue");
                                                file.Close();
                                                encryptedStream.Write(fileStrEncryptedStr);
                                                encryptedStream.Close();
                                                Console.WriteLine("Encrypted: " + fileStrEncryptedStr);
                                                wait();
                                            }
                                            else
                                            {
                                                Console.WriteLine("Failed To Open File");
                                                wait();
                                            }
                                        }
                                        catch (Exception e)
                                        {
                                            Console.WriteLine("Failed To Encrypt");
                                            Console.WriteLine(e.Message);
                                            wait();
                                        }
                                    }
                                    if (answerFile == Decrypt)
                                    {
                                        try
                                        {
                                            Console.Clear();
                                            if (GetFile(out FileStream file, FileMode.Open, "Enter File Name To Decrypt"))
                                            {
                                                StreamReader fileStream = new StreamReader(file);
                                                Console.WriteLine("Reading...");
                                                string fileStr = fileStream.ReadToEnd();
                                                fileStream.Close();
                                                Console.WriteLine("Converting To Int Array...");
                                                if (Unicoder.EncryptedStrToIntArray(fileStr, out List<int> fileStrEncryptedInt))
                                                {
                                                    Console.WriteLine("Decrypting...");
                                                    string decrypted = Unicoder.Decrypt(fileStrEncryptedInt);
                                                    Console.WriteLine("Saving File As " + file.Name + ".ud ...");
                                                    StreamWriter decryptedStream = new StreamWriter(file.Name + ".ud");
                                                    file.Close();
                                                    decryptedStream.Write(decrypted);
                                                    decryptedStream.Close();
                                                    Console.WriteLine("Decrypted: " + decrypted);
                                                    wait();
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Failed To Decrypt");
                                                    wait();
                                                }
                                            }
                                            else
                                            {
                                                Console.WriteLine("Failed To Open File");
                                                wait();
                                            }
                                        }
                                        catch (Exception e)
                                        {
                                            Console.WriteLine("Failed To Decrypt");
                                            Console.WriteLine(e.Message);
                                            wait();
                                        }
                                    }
                                    if (answerFile == EXIT)
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                        if (answer == EXIT)
                        {
                            break;
                        }
                    }
                }
            }
        }

        private static bool PrintMainMenu(out int answer)
        {
            Console.Clear();
            Console.WriteLine(PROGRAM_NAME + " - MainMenu");
            Console.WriteLine(SENTENCE.ToString() + ": Sentence");
            Console.WriteLine(FILE.ToString() + ": File");
            Console.WriteLine(EXIT.ToString() + ": Exit");
            Console.Write("Answer: ");
            string answerStr = Console.ReadLine();
            if (int.TryParse(answerStr, out int answerInt))
            {
                answer = answerInt;
                return true;
            }
            else
            {
                answer = EXCEPTION;
                return false;
            }
        }

        private static bool PrintSentenceMenu(out int answer)
        {
            Console.Clear();
            Console.WriteLine(PROGRAM_NAME + " - Sentence");
            Console.WriteLine(Encrypt.ToString() + ": Encrypt");
            Console.WriteLine(Decrypt.ToString() + ": Decrypt");
            Console.WriteLine(EXIT.ToString() + ": Exit");
            Console.Write("Answer: ");
            string answerStr = Console.ReadLine();
            if (int.TryParse(answerStr, out int answerInt))
            {
                answer = answerInt;
                return true;
            }
            else
            {
                answer = EXCEPTION;
                return false;
            }
        }

        private static bool PrintFileMenu(out int answer)
        {
            Console.Clear();
            Console.WriteLine(PROGRAM_NAME + " - File");
            Console.WriteLine(Encrypt.ToString() + ": Encrypt");
            Console.WriteLine(Decrypt.ToString() + ": Decrypt");
            Console.WriteLine(EXIT.ToString() + ": Exit");
            Console.Write("Answer: ");
            string answerStr = Console.ReadLine();
            if (int.TryParse(answerStr, out int answerInt))
            {
                answer = answerInt;
                return true;
            }
            else
            {
                answer = EXCEPTION;
                return false;
            }
        }

        private static bool GetFile(out FileStream file, FileMode mode, string log)
        {
            Console.Write(log + ": ");
            string input = Console.ReadLine();
            try
            {
                file = File.Open(input, mode);
                return true;
            }
            catch
            {
                file = null;
                return false;
            }
        }

        private static void wait()
        {
            Console.Write("press any key to continue...");
            Console.ReadKey();
        }
    }

    class Unicoder
    {
        public static List<int> Encrypt(string answer)
        {
            int seed = new Random().Next();
            List<int> encrypted = new List<int>();
            Random rand = new Random(seed);
            encrypted.Add(seed);
            for (int i = 0; i < answer.Length; i++)
            {
                encrypted.Add(Convert.ToInt32(answer[i]) + rand.Next(0, 5000));
            }

            return encrypted;
        }

        public static string Decrypt(List<int> answer)
        {
            string decrypted = "";
            int seed = answer[0];
            Random rand = new Random(seed);
            for (int i = 1; i < answer.Count; i++)
            {
                decrypted += Convert.ToChar(answer[i] - rand.Next(0, 5000));
            }

            return decrypted;
        }

        public static bool EncryptedStrToIntArray(string encryptedStr, out List<int> encrypted)
        {
            List<int> result = new List<int>();
            foreach (string item in encryptedStr.Split(" "))
            {
                if (int.TryParse(item, out int currentEncrypted))
                {
                    result.Add(currentEncrypted);
                }
                else
                {
                    encrypted = null;
                    return false;
                }
            }
            encrypted = result;
            return true;
        }

        public static string IntArrayToStr(List<int> list)
        {
            string result = "";
            for (int i = 0; i < list.Count; i++)
            {
                result += list[i].ToString();
                if (i != list.Count - 1)
                {
                    result += " ";
                }
            }
            return result;
        }
    }

}
