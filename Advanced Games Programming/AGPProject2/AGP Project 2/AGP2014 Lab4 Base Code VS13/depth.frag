// Fragment Shader – file "depth.frag"

#version 330

precision highp float; // needed only for version 1.30

in  vec4 ex_Color;
out vec4 out_Color;

void main(void) {
// simply out's colour
	out_Color = vec4(1.0);

}
