#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform vec4 deltaTime;

out vec3 vertexColor;

void main(){
	//do rotation around z axis
	float newX = cos(deltaTime.r)*aPos.x - sin(deltaTime.r)*aPos.y;
	float newY = sin(deltaTime.r)*aPos.x + cos(deltaTime.r)*aPos.y;

	vertexColor = aCol;

	gl_Position = vec4(newX, newY, aPos.z, 1.0);
}