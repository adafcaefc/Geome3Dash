#pragma once

namespace g3d
{
    class CustomMouseDelegate {
        static int uidCounter;
    public:
        int uid = 0;
        CustomMouseDelegate();
        ~CustomMouseDelegate();
        virtual void rightKeyDown() {}
        virtual void rightKeyUp() {}
        virtual void scrollWheel(float x, float y) {}
    };

    class CustomMouseManager {
        static std::vector<CustomMouseDelegate*> delegates;
    public:
        static void addDelegate(CustomMouseDelegate* obj);
        static void removeDelegate(CustomMouseDelegate* obj);
        static void scrollWheel(float x, float y);
    };
}