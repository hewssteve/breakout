#version 410

uniform vec4 mat_color;
uniform float mat_intensity;

out vec4 out_color;

void main() {
	out_color = mat_color * mat_intensity;
}
