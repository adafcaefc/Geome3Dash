#pragma once

namespace g3d
{
    class CustomKeyboardDelegate {
        static int uidCounter;
    public:
        int uid = 0;
        CustomKeyboardDelegate();
        ~CustomKeyboardDelegate();
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) {};
        virtual void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {};
    };

    class CustomKeyboardManager {
        static std::vector<CustomKeyboardDelegate*> delegates;
    public:
        static void addDelegate(CustomKeyboardDelegate* obj);
        static void removeDelegate(CustomKeyboardDelegate* obj);
        static void onKey(enumKeyCodes key, bool pressed, bool holding);
        static void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };
}