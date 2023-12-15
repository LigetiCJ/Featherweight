#version 330 core

out vec4 FragColor;

in vec3 vertexColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

uniform vec4 deltaTime;

void main(){
	FragColor = texture(ourTexture, TexCoord);
	//FragColor = vec4(vertexColor,1.0f);
}