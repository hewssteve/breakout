
#version 330

uniform mat4 mvp_mat;

layout(location = 0) in vec3 in_pos;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_tex_coord;

void main()
{
	gl_Position = mvp_mat * vec4(in_pos,1.0);
}

