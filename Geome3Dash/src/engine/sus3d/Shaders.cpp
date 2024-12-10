#include "Shaders.h"

namespace sus3d
{
    namespace shaders
    {
        const char* basicVertexShader = R"(
            precision highp float;

            layout(location = 0) in vec3 aPos;

            void main()
            {
                gl_Position = vec4(aPos, 1.0);
            }
        )";

        const char* idBufferingFragmentShader = R"(
            precision highp float;

            uniform vec3 color;
            out vec4 FragColor;

            void main() {
                FragColor = vec4(color, 1.0);
            }
        )";

        const char* idBufferingVertexShader = R"(
            precision highp float;
            layout (location = 0) in vec3 aPos;
            layout (location = 1) in vec2 aTexCoord;
            layout (location = 2) in vec3 aNormal;

            uniform mat4 model;
            uniform mat4 view;
            uniform mat4 projection;

            void main() {
                gl_Position = projection * view * model * vec4(aPos, 1.0);
            }
        )";

        const char* vertexShaderSource = R"(
precision mediump float;

attribute vec3 aPos;
attribute vec2 aTexCoord;
attribute vec3 aNormal;

varying vec2 TexCoord;
varying vec3 Normal;
varying vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(model) * aNormal; // Precompute the inverse transpose in the application
    TexCoord = aTexCoord;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}

        )";

        const char* fragmentShaderSource = R"(
 precision mediump float;

varying vec2 TexCoord;
varying vec3 Normal;
varying vec3 FragPos;

uniform sampler2D texture1;
uniform float isTexture; // Use float instead of int
uniform vec3 Ka; // Ambient reflectivity
uniform vec3 Kd; // Diffuse reflectivity
uniform vec3 Ks; // Specular reflectivity
uniform vec3 lightColor; // Light color
uniform vec3 lightPos; // Light position
uniform vec3 viewPos; // View position
uniform float shininess; // Shininess factor
uniform float d; // Opacity

void main() {
    // Ambient
    vec3 ambient = lightColor * Ka;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor * Kd;

    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = spec * lightColor * Ks;

    vec3 result = ambient + diffuse + specular;

    vec4 color;
    if (isTexture > 0.5) { // Check as float
        vec4 texColor = texture2D(texture1, TexCoord);
        color = texColor * vec4(result, d);
    } else {
        color = vec4(result, d);
    }

    gl_FragColor = color;
}

        )";
    }
}
