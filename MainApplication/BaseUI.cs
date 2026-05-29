/// BaseUI.cs

using OpenTK.Graphics.OpenGL;
using OpenTK.Mathematics;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.Desktop;
using OpenTK.Windowing.GraphicsLibraryFramework;

public class BaseUI : GameWindow
{
    public BaseUI(int width, int height, string title) : base(GameWindowSettings.Default, new NativeWindowSettings()
    {Size=(width,height),Title=title}){}

    // define vertices
    float[] vertices = { 
        // Position      // Texture Coords (optional)
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right 
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f // top left
    };

    float[] vertices1 =
    {
        0.1f, 0.1f, 0, 1.0f, 1.0f, // top right
        0.1f, -0.1f, 0, 1.0f, 0.0f, // bottom right 
        -0.1f, -0.1f, 0, 0.0f, 0.0f, // bottom left
        -0.1f, 0.1f, 0, 0.0f, 1.0f // top left
    };

    uint[] indices ={
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle 
    };

    Color4 BGColor = Color4.Crimson;

    public List<Color4> colorSequence = new List<Color4>() { Color4.Crimson, Color4.Blue, Color4.Coral, Color4.Yellow, Color4.Green };

    bool bRenderRectangle = false;

    int VertexArrayObject;
    
    protected override void OnLoad()
    {
        base.OnLoad();
        GL.ClearColor(BGColor);
        VertexArrayObject=GLTRendering.DrawRectangle(vertices1, indices);
    }

    protected override void OnUpdateFrame(FrameEventArgs args)
    {
        base.OnUpdateFrame(args);
        if (KeyboardState.IsKeyDown(Keys.C))
        {
            Close();
        }
        else if (KeyboardState.IsKeyPressed(Keys.F))
        {
            bRenderRectangle = !bRenderRectangle;
            Console.WriteLine(bRenderRectangle);
        }
        
    }

    protected override void OnRenderFrame(FrameEventArgs args)
    {
        base.OnRenderFrame(args); 
        
        GL.Clear(ClearBufferMask.ColorBufferBit);
        
        // Bind the VAO that holds all the buffer and attribute settings
        GL.BindVertexArray(VertexArrayObject);

        if(bRenderRectangle)
            GLTRendering.OnRenderRectangle(indices);
        //Console.WriteLine("Frame Rendered Successfully.");
        
        SwapBuffers();
    }
}