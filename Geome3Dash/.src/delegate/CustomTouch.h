#pragma once

namespace g3d
{
    class CustomTouchDelegate {
        static int uidCounter;
    public:
        int uid = 0;
        CustomTouchDelegate();
        ~CustomTouchDelegate();
        virtual void touch(CCSet* touches, CCEvent* event, unsigned int type) {};
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {};
        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {};
    };

    class CustomTouchManager {
        static std::vector<CustomTouchDelegate*> delegates;
    public:
        static void addDelegate(CustomTouchDelegate* obj);
        static void removeDelegate(CustomTouchDelegate* obj);
        static void updateDelegates(CCSet* touches, CCEvent* event, unsigned int type);
        static void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
        static void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
    };
}