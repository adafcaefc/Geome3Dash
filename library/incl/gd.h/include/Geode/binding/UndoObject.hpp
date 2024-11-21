#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class UndoObject : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "UndoObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(UndoObject, cocos2d::CCObject)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     UndoObject();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    virtual  ~UndoObject();
    
private:
    [[deprecated("UndoObject::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xc7594
     * @note[short] Android
     */
    static UndoObject* create(GameObject* p0, UndoCommand p1);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static UndoObject* createWithArray(cocos2d::CCArray* arrOfObjects, UndoCommand command);
    
private:
    [[deprecated("UndoObject::createWithTransformObjects not implemented")]]
    /**
     * @note[short] Android
     */
    static UndoObject* createWithTransformObjects(cocos2d::CCArray* p0, UndoCommand p1);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    bool init(cocos2d::CCArray* array, UndoCommand command);

    /**
     * @note[short] MacOS (ARM): 0xca710
     * @note[short] Windows: 0x2db040
     * @note[short] Android
     */
    bool init(GameObject* p0, UndoCommand p1);
    
private:
    [[deprecated("UndoObject::initWithTransformObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn initWithTransformObjects(cocos2d::CCArray* p0, UndoCommand p1);
public:
    
private:
    [[deprecated("UndoObject::setObjects not implemented")]]
    /**
     * @note[short] Android
     */
    void setObjects(cocos2d::CCArray* p0);
public:
    GameObjectCopy* m_objectCopy;
    UndoCommand m_command;
    cocos2d::CCArray* m_objects;
    bool m_redo;
    GJTransformState m_transformState;
};
