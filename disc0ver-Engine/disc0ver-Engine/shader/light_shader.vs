#version 420 core
layout(location = 0 ) in vec3 aPos;     //本地——顶点坐标

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}