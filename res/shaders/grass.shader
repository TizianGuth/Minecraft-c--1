#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 texCoord;

out vec3 v_TexCoord;

uniform mat4 u_MVP;

void main() {
	gl_Position = u_MVP * position;
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_TexCoord;

uniform samplerCube u_Texture;
uniform samplerCube u_Overlay;
uniform vec4 u_Color;

void main() {

	vec4 overlay = texture(u_Overlay, v_TexCoord) * u_Color;
	vec4 layer = texture(u_Texture, v_TexCoord);
	color = mix(layer, overlay, overlay.a);

};