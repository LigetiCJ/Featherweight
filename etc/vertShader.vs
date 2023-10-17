#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform float deltaTime;

out vec3 vertexColor;

void main(){
	//do rotation around z axis
	float newX = cos(deltaTime)*aPos.x - sin(deltaTime)*aPos.z;
	float newZ = sin(deltaTime)*aPos.x + cos(deltaTime)*aPos.z;
	
	

	vertexColor = aCol;

	gl_Position = vec4(newX, aPos.y, newZ, 1.0);
}