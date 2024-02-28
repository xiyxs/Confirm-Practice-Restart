#include <Geode/Geode.hpp>

#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;
class $modify(PauseLayer) {  
	bool r = false;

	// Practice
	void onPracticeMode(CCObject* sender) {
		if (PlayLayer::get()->m_isPracticeMode || m_fields->r) {
            PauseLayer::onPracticeMode(sender);
            return;
        }
		geode::createQuickPopup(
			"Practice",
			"Are you sure you want to <cg>practice</c>?",
			"Cancel", "Practice",			
			[this, sender](auto, bool btn2) {
				if (btn2) {
					this->m_fields->r = true;
					this->onPracticeMode(sender);
					this->m_fields->r = false;
				}
			}
		);
	} 

	// Restart
		void onRestart(CCObject* sender) {
		if (m_fields->r) {
            PauseLayer::onRestart(sender);
            return;
        }
		geode::createQuickPopup(
			"Restart",
			"Are you sure you want to <cr>restart</c>?",
			"Cancel", "Restart",
			[this, sender](auto, bool btn2) {
				if (btn2) {
					this->m_fields->r = true;
					this->onRestart(sender);
					this->m_fields->r = false;
				}
			}
		);
	} 

	// Full Restart
		void onRestartFull(CCObject* sender) {
		if (m_fields->r) {
            PauseLayer::onRestartFull(sender);
            return;
        }
		geode::createQuickPopup(
			"Full Restart",
			"Are you sure you want to <cr>full restart</c>?\n<cy>This will reset checkpoints\nand persistent item IDs.</c>",
			"Cancel", "Restart",
			[this, sender](auto, bool btn2) {
				if (btn2) {
					this->m_fields->r = true;
					this->onRestartFull(sender);
					this->m_fields->r = false;
				}
			}
		);
	} 
};