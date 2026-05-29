/// Common.cs

public static class Common
{
    public struct ParsedInt
    {
        public int Value;
        public bool Success;
        public ParsedInt(int _int, bool bool_success)
        {
            Value = _int; Success = bool_success;
        }
    }
    public static ParsedInt SafeIntParsing(string _int)
    {
        int x = 0;
        try
        {
            x = Convert.ToInt16(_int);
            return new ParsedInt(x, true);
        }
        catch
        {
            return new ParsedInt(0, false);
        }
    }

    public static bool IsPowerOfTwo(int x)
    {
        int n = 0;
        while (MathF.Pow(2, n) < x)
        {
            n++;
        }
        return MathF.Pow(2, n) == x;
    }

    public static bool IsInInterval(int x, int min, int max)
    {
        return x>=min&& x <= max;
    }

    public static float[] MultiplyVector(float[] vect, float Y)
    {
        for (int i = 0; i < vect.Length; i++) { vect[i] *= Y; };
        return vect;    
    }

    public static int SafeIntReading(string info)
    {
        int x = 0;
        bool _continue = true;
        while (_continue)
        {
            Console.Write(info);
            ParsedInt _x = SafeIntParsing(Console.ReadLine());
            if (!_x.Success)
            {
                Console.WriteLine("Failed to parse integer!");
            }
            else
            {
                x = _x.Value;
                _continue = false;
            }
        }
        return x;
    }
}