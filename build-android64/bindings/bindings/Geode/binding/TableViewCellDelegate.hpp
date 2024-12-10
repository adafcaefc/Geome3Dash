#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class TableViewCellDelegate {
public:
    static constexpr auto CLASS_NAME = "TableViewCellDelegate";

    /**
     * @note[short] Android
     */
    virtual bool cellPerformedAction(TableViewCell* p0, int p1, CellAction p2, cocos2d::CCNode* p3);

    /**
     * @note[short] Android
     */
    virtual int getSelectedCellIdx();

    /**
     * @note[short] Android
     */
    virtual bool shouldSnapToSelected();

    /**
     * @note[short] Android
     */
    virtual int getCellDelegateType();
};
