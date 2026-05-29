using OpenTK.Graphics.OpenGL;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.Desktop;
using OpenTK.Windowing.GraphicsLibraryFramework;

public static class GLTRendering
{
    public static int DrawRectangle(float[] vertices, uint[] indices)
    {
        int VertexArrayObject;
        int VertexBufferObject;
        int IndexBufferObject;

        // 1. Generate and bind a VAO (stores state)
        VertexArrayObject = GL.GenVertexArray();
        GL.BindVertexArray(VertexArrayObject);

        // 2. Generate and bind a VBO (stores vertex data)
        VertexBufferObject = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ArrayBuffer, VertexBufferObject);
        GL.BufferData(BufferTarget.ArrayBuffer, vertices.Length * sizeof(float), vertices, BufferUsageHint.StaticDraw);

        // 3. Generate and bind an IBO (stores index data)
        IndexBufferObject = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ElementArrayBuffer, IndexBufferObject);
        GL.BufferData(BufferTarget.ElementArrayBuffer, indices.Length * sizeof(uint), indices, BufferUsageHint.StaticDraw);

        // 4. Tell OpenGL how to interpret the vertex data (using a shader attribute, e.g, position at layout 0)
        // Assumes you have a basic shader program set up.
        int positionLocation = 0;
        GL.VertexAttribPointer(positionLocation, 3, VertexAttribPointerType.Float, false, 5 * sizeof(float), 0);
        GL.EnableVertexAttribArray(positionLocation);

        // (Optional) Configure texture coordinates if included in vertices
        int texCoordLocation = 1; // Or retrieve dynmaically from your shader
        GL.VertexAttribPointer(texCoordLocation, 2, VertexAttribPointerType.Float, false, 5 * sizeof(float), 3 * sizeof(float));
        GL.EnableVertexAttribArray(texCoordLocation);

        return VertexArrayObject;
    }

    public static void OnRenderRectangle(uint[] indices)
    {
        GL.DrawElements(PrimitiveType.Triangles, indices.Length, DrawElementsType.UnsignedInt, 0);
    }


}