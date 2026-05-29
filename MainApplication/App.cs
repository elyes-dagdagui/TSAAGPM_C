/// App.cs
/// TSAAGPM(Techie's shader architecture and graphical processing model) >> 2D Basic shader computation model demo
/// Project GitHub Repos : 
/// Developer Name       : ELYES DAGDAGUI
/// Developer Email      : dagdaguielyes50@gmail.com
/// Developer GitHub     : https://github.com/elyes-dagdagui

using OpenTK.Mathematics;
using static Common;

public class App
{
    public const int min_width = 480;
    public const int min_height = 270;
    public const int max_width = 7680;
    public const int max_height = 4320;
    public static BaseUI UI;
    public static int width;
    public static int height;
    public static matsc DISP;

    public static void ReadResolution() {
        while (width == 0 || height==0 || height%2!=0 || width%2!=0 || !IsInInterval(width,min_width,max_width) || !IsInInterval(height,min_height,max_height))
        {
            width = Common.SafeIntReading("Width=");
            height = Common.SafeIntReading("Height=");
        }
    }

    // Program entry-point
    public static void Main(string[] args)
    {
        ReadResolution();
        UI = new BaseUI(width, height, "TSAAGPM");
        UI.MinimumSize = new Vector2i(width, height);
        UI.MaximumSize = new Vector2i(width, height);

        Architecture.init(ref DISP, width, height);
        
        color4 B=new color4();
        Architecture.set_color4(ref B, 0, 25, 255, 1);

        Architecture.fill(ref DISP,B, width, height);
        Architecture.save(DISP, width, height, "matsc.txt");
        UI.Run();
    }
}