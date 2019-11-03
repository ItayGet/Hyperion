#version 330 core

out vec4 fragColor;
layout (std140) uniform hello {
	vec3 col;
};
            
void main()
{
	fragColor = vec4(col, 1.);
}