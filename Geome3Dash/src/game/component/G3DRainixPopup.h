#pragma once

namespace g3d
{
	class G3DRainixPopup : public geode::Popup<const std::vector<std::string>&> 
	{
	protected:
		bool setup(const std::vector<std::string>& strings) override;
		static std::vector<std::string> strings;
		CCLayer* parentLayer;
	public:
		static void scene(const std::vector<std::string>& strings, CCLayer* parentLayer);
		virtual void onClose(CCObject* sender) override;
	};
}

