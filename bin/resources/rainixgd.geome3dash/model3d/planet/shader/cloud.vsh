#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float iTime;

void main() {
    float offsetX = sin(aPos.x * 10.0 + iTime) * 0.15;
	float offsetY = cos(aPos.y * 10.0 + iTime) * 0.15;
	float offsetZ = -sin(aPos.z * 10.0 + iTime) * 0.15;

	vec3 modifiedPos = aPos + vec3(offsetX, offsetY, offsetZ);

    FragPos = vec3(model * vec4(modifiedPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    TexCoord = aTexCoord;
    gl_Position = projection * view * model * vec4(modifiedPos, 1.0);
}