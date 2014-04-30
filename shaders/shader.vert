#version 410

uniform mat4 mvp_mat;

layout(location = 0) in vec2 in_pos;

out gl_PerVertex {
  vec4 gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[];
};

void main() {
	gl_Position = mvp_mat * vec4(in_pos , 0.0 , 1.0);
}
