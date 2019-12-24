#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

// build-in
uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord);
}