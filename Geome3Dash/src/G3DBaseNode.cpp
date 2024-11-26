#include "pch.h"
#include "../pch.h"

#include "G3DBaseNode.h"

#include "Sus3D/ShaderProgram.h"
#include "Sus3D/Model.h"
#include "Sus3D/Shaders.h"
#include "Sus3D/Shader.h"
#include "Sus3D/Mesh.h"

#include "Helper/OpenGLStateHelper.h"

namespace g3d
{
    glm::vec3 G3DBaseNode::generateUniqueColor(int objectID, int meshID) {
        int uniqueID = (objectID + 1) << 16 | (meshID + 1);

        GLuint r = (uniqueID >> 16) & 0xFF;
        GLuint g = (uniqueID >> 8) & 0xFF;
        GLuint b = uniqueID & 0xFF;

        return glm::vec3(r / 255.0f, g / 255.0f, b / 255.0f);
    }
    std::pair<int, int> G3DBaseNode::getObjectAndMeshIDFromColor(const GLubyte* pixelColor) {
        int uniqueID = (pixelColor[0] << 16) | (pixelColor[1] << 8) | pixelColor[2];

        int objectID = ((uniqueID >> 16) & 0xFFFF) - 1;
        int meshID = (uniqueID & 0xFFFF) - 1;

        return { objectID, meshID };
    }

    std::pair<int, int> G3DBaseNode::getObjectIDByMousePosition(int mouseX, int mouseY) {
        OpenGLStateHelper::saveState();
        glEnable(GL_DEPTH_TEST);

        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        getObjectIDByMousePositionShader->use();
        for (int modelIndex = 0; modelIndex < models.size(); modelIndex++) {
            glm::mat4 model = models[modelIndex]->prepareModelMatrix();
            for (size_t meshIndex = 0; meshIndex < models[modelIndex]->meshes.size(); meshIndex++) {
                glm::vec3 uniqueColor = generateUniqueColor(modelIndex, meshIndex);

                getObjectIDByMousePositionShader->setMat4("model", model);
                getObjectIDByMousePositionShader->setMat4("view", camera.getViewMat());
                getObjectIDByMousePositionShader->setMat4("projection", camera.getProjectionMat());

                getObjectIDByMousePositionShader->setVec3("color", uniqueColor);

                models[modelIndex]->meshes[meshIndex]->render(getObjectIDByMousePositionShader);
            }
        }
        glFlush();
        glDisable(GL_DEPTH_TEST);

        GLubyte pixelColor[3];
        glReadPixels(mouseX, mouseY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColor);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        OpenGLStateHelper::pushState();

        auto ids = getObjectAndMeshIDFromColor(pixelColor);

        return std::make_pair(ids.first, ids.second);
    }


    void G3DBaseNode::draw() {
        OpenGLStateHelper::saveState();

        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);

        glm::mat4 view = camera.getViewMat();

        glm::mat4 projection = camera.getProjectionMat();

        for (auto model : models) {
            model->render(view, light.getPosition(), light.getColor(), camera.getPosition(), projection);
        }

        glDisable(GL_DEPTH_TEST);

        OpenGLStateHelper::pushState();
    }

    G3DBaseNode::~G3DBaseNode() {
        for (auto model : models) {
            delete model;
        }
    }

    bool G3DBaseNode::init() {
        if (!CCNode::init()) return false;

        getObjectIDByMousePositionShader = sus3d::ShaderProgram::create(
            sus3d::Shader::createWithString(sus3d::shaders::idBufferingVertexShader, sus3d::ShaderType::kVertexShader),
            sus3d::Shader::createWithString(sus3d::shaders::idBufferingFragmentShader, sus3d::ShaderType::kFragmentShader));

        OpenGLStateHelper::saveState();
        auto size = CCDirector::sharedDirector()->m_obResolutionInPixels;

        glGenFramebuffers(1, &framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, static_cast<GLsizei>(size.width), static_cast<GLsizei>(size.height), 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

        glGenRenderbuffers(1, &renderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, static_cast<GLsizei>(size.width), static_cast<GLsizei>(size.height));
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {

        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        OpenGLStateHelper::pushState();

        return true;
    }

    G3DBaseNode* G3DBaseNode::create() {
        auto node = new G3DBaseNode;
        if (node && node->init()) {
            node->autorelease();
        }
        else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }
}