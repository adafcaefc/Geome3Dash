#include "pch.h"

#include "G3DBaseNode.h"

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"

#include "helper/OpenGLStateHelper.h"
#include "helper/CommonHelper.h"

#include "manager/ModelManager.h"

namespace g3d
{
    std::pair<int, int> G3DBaseNode::getObjectIDByMousePosition() {
        auto glView = CCDirector::sharedDirector()->m_pobOpenGLView;
        int mouseX = static_cast<int>(glView->m_fMouseX);
        int mouseY = glView->getFrameSize().height - static_cast<int>(glView->m_fMouseY);

        OpenGLStateHelper::saveState();
        glEnable(GL_DEPTH_TEST);

        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        auto idBufferSP = ModelManager::get()->getIdBufferSP();

        idBufferSP->use();
        for (int modelIndex = 0; modelIndex < models.size(); modelIndex++) {
            glm::mat4 model = models[modelIndex]->prepareModelMatrix();
            for (int meshIndex = 0; meshIndex < models[modelIndex]->meshes.size(); meshIndex++) {
                glm::vec3 uniqueColor = generateUniqueColor(modelIndex, meshIndex);

                idBufferSP->setMat4("model", model);
                idBufferSP->setMat4("view", camera.getViewMat());
                idBufferSP->setMat4("projection", camera.getProjectionMat());

                idBufferSP->setVec3("color", uniqueColor);

                models[modelIndex]->meshes[meshIndex]->render(idBufferSP);
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
        CCNode::draw();
        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::mat4 view = camera.getViewMat();
        glm::mat4 projection = camera.getProjectionMat();

        for (auto model : models) {
            model->render(
                shaderProgram, 
                view, 
                light.getPosition(), 
                light.getColor(), 
                camera.getPosition(), 
                projection);
        }

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    G3DBaseNode::~G3DBaseNode() 
    {

    }

    bool G3DBaseNode::init() {
        if (!CCNode::init()) return false;

        OpenGLStateHelper::saveState();

        auto bms = ModelManager::get();

        shaderProgram = bms->getBlockSP();

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

        this->setID("g3d-layer-planet");

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