#include "pch.h"
#include "../pch.h"
#include "basicShaders.h"

namespace g3d
{
    namespace shaders
    {
        const char* basicVertexShader = R"(
            #version 330 core

            layout(location = 0) in vec3 aPos;

            void main()
            {
                gl_Position = vec4(aPos, 1.0);
            }
        )";

        const char* idBufferingFragmentShader = R"(
            #version 330 core

            uniform vec3 color;
            out vec4 FragColor;

            void main() {
                FragColor = vec4(color, 1.0);
            }
        )";

        const char* idBufferingVertexShader = R"(
            #version 330 core
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

            void main() {
                FragPos = vec3(model * vec4(aPos, 1.0));
                Normal = mat3(transpose(inverse(model))) * aNormal;
                TexCoord = aTexCoord;
                gl_Position = projection * view * model * vec4(aPos, 1.0);
            }
        )";

        const char* fragmentShaderSource = R"(
            #version 330 core

            in vec2 TexCoord;
            in vec3 Normal;
            in vec3 FragPos;

            uniform sampler2D texture1;
            uniform int isTexture;
            uniform vec3 Ka; // Ambient reflectivity
            uniform vec3 Kd; // Diffuse reflectivity
            uniform vec3 Ks; // Specular reflectivity
            uniform vec3 lightColor; // Light color
            uniform vec3 lightPos; // Light position
            uniform vec3 viewPos; // View position
            uniform float shininess; // Shininess factor

            out vec4 FragColor;

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
                if (isTexture == 1) {
                    vec4 texColor = texture(texture1, TexCoord);
                    color = texColor * vec4(result, 1.0);
                } else {
                    color = vec4(result, 1.0);
                }
    
                FragColor = color;
            }
        )";
    }
}
