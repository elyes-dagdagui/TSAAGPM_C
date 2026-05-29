using System.Runtime.InteropServices;

[StructLayout(LayoutKind.Sequential)]
public struct color4
{
    public float r;
    public float g;
    public float b;
    public float a;
}

[StructLayout(LayoutKind.Sequential)]
public struct matsc
{
    public int res_w;
    public int res_h;
    public IntPtr pixels;
}

public static class Architecture
{
    private const string DllName = "architectureC.dll";

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_color4(ref color4 c, float r, float g, float b, float a);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void init(ref matsc M, int res_w, int res_h);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void fill(ref matsc M, color4 color, int res_w, int res_h);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void save(matsc M, int res_w, int res_h, string name);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void slope2color(ref matsc screen, color4 color1, color4 color2);
}