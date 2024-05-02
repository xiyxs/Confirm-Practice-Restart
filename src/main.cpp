#include <Geode/Geode.hpp>

#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;
class $modify(PauseLayer) {  
	bool r = false;
	bool o = false;

	
	// Practice
	void onPracticeMode(CCObject* sender) {
		if (PlayLayer::get()->m_isPracticeMode || m_fields->r || Mod::get()->getSettingValue<bool>("practice") == false || Mod::get()->getSettingValue<bool>("enable") == false) {
            PauseLayer::onPracticeMode(sender);
            return;
        }
		if (!o) {
			o = true;
			geode::createQuickPopup(
				"Practice",
				"Are you sure you want to <cg>practice</c>?",
				"Cancel", "Practice",			
				[this, sender](auto, bool btn2) {
					o = false;
					if (btn2) {
						this->m_fields->r = true;
						this->onPracticeMode(sender);
						this->m_fields->r = false;
					}
				}
			);
		}
	} 
// Quit
		void onQuit(CCObject* sender) {
		if (m_fields->r || Mod::get()->getSettingValue<bool>("quit") == false || Mod::get()->getSettingValue<bool>("enable") == false) {
            PauseLayer::onQuit(sender);
            return;
        }
		if (!o) {
			o = true;
			geode::createQuickPopup(
				"Quit",
				"Are you sure you want to <cr>quit</c>?",
				"Cancel", "Quit",
				[this, sender](auto, bool btn2) {
					o = false;
					if (btn2) {
						this->m_fields->r = true;
						this->onQuit(sender);
						this->m_fields->r = false;
					}
				}
			);
		}
	} 
	// Restart
		void onRestart(CCObject* sender) {
		if (m_fields->r || Mod::get()->getSettingValue<bool>("restart") == false || Mod::get()->getSettingValue<bool>("enable") == false) {
            PauseLayer::onRestart(sender);
            return;
        }
		if (!o) {
			o = true;
			geode::createQuickPopup(
				"Restart",
				"Are you sure you want to <cr>restart</c>?",
				"Cancel", "Restart",
				[this, sender](auto, bool btn2) {
					o = false;
					if (btn2) {
						this->m_fields->r = true;
						this->onRestart(sender);
						this->m_fields->r = false;
					}
				}
			);
		}
	} 

	// Full Restart
		void onRestartFull(CCObject* sender) {
		if (m_fields->r || Mod::get()->getSettingValue<bool>("fullrestart") == false || Mod::get()->getSettingValue<bool>("enable") == false) {
            PauseLayer::onRestartFull(sender);
            return;
        }
		if (!o) {
			o = true;
			geode::createQuickPopup(
				"Full Restart",
				"Are you sure you want to <cr>full restart</c>?\n<cy>This will reset checkpoints\nand persistent item IDs.</c>",
				"Cancel", "Restart",
				[this, sender](auto, bool btn2) {
					o = false;
					if (btn2) {
						this->m_fields->r = true;
						this->onRestartFull(sender);
						this->m_fields->r = false;
					}
				}
			);
		}
	} 
};
