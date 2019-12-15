#include "PlayNormalUiLayer.h"

PlayNormalUiLayer::PlayNormalUiLayer() {

}

PlayNormalUiLayer::~PlayNormalUiLayer() {

}

bool PlayNormalUiLayer::init() {
	combo_printing = false;
	grade_printing = false;

	Singleton<GameManager>::GetInst()->escButton->setPosition(
			ccp(
					-CCDirector::sharedDirector()->getWinSize().width / 2
							+ Singleton<GameManager>::GetInst()->escButton->getContentSize().width
									/ 2 + 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 20));

	Singleton<GameManager>::GetInst()->pauseButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->escButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->escButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 20));

	Singleton<GameManager>::GetInst()->x14SpeedButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->pauseButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->pauseButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->x12SpeedButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->x14SpeedButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->x14SpeedButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->x1SpeedButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->x12SpeedButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->x12SpeedButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->x2SpeedButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->x1SpeedButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->x1SpeedButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->acousticButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->x2SpeedButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->x2SpeedButton->getContentSize().width
							+ 710,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->brightButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->acousticButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->acousticButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->chorusButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->brightButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->brightButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->electricButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->chorusButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->chorusButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->hongkyButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->electricButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->electricButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	Singleton<GameManager>::GetInst()->rhodesButton->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->hongkyButton->getPositionX()
							+ Singleton<GameManager>::GetInst()->hongkyButton->getContentSize().width
							+ 10,
					CCDirector::sharedDirector()->getWinSize().height / 2
							- Singleton<GameManager>::GetInst()->escButton->getContentSize().height
									/ 2 - 18));

	this->addChild(Singleton<GameManager>::GetInst()->menu, -4);

	Singleton<GameManager>::GetInst()->comboImg->setVisible(false);
	Singleton<GameManager>::GetInst()->comboImg->setAnchorPoint(
			ccp(0.0f, 0.0f));
	Singleton<GameManager>::GetInst()->comboImg->setPosition(
			ccp(
					CCDirector::sharedDirector()->getWinSize().width / 2
							- Singleton<GameManager>::GetInst()->comboImg->getContentSize().width
									/ 2, 100));
	this->addChild(Singleton<GameManager>::GetInst()->comboImg, -3);

	Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(false);
	Singleton<GameManager>::GetInst()->comboBackImg1->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->comboImg->getPositionX()
							+ Singleton<GameManager>::GetInst()->comboBackImg1->getContentSize().width
									/ 2 + 40,
					Singleton<GameManager>::GetInst()->comboImg->getPositionY()
							- 10));

	this->addChild(Singleton<GameManager>::GetInst()->comboBackImg1, -2);

	Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(false);
	Singleton<GameManager>::GetInst()->comboBackImg2->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->comboImg->getPositionX()
							+ Singleton<GameManager>::GetInst()->comboBackImg1->getContentSize().width
									/ 2 + 40,
					Singleton<GameManager>::GetInst()->comboImg->getPositionY()
							- 10));

	this->addChild(Singleton<GameManager>::GetInst()->comboBackImg2, -2);

	Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(false);
	Singleton<GameManager>::GetInst()->comboBackImg3->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->comboImg->getPositionX()
							+ Singleton<GameManager>::GetInst()->comboBackImg1->getContentSize().width
									/ 2 + 40,
					Singleton<GameManager>::GetInst()->comboImg->getPositionY()
							- 10));

	this->addChild(Singleton<GameManager>::GetInst()->comboBackImg3, -2);

	Singleton<GameManager>::GetInst()->combo_count_label->setVisible(false);
	Singleton<GameManager>::GetInst()->combo_count_label->setString("0");
	Singleton<GameManager>::GetInst()->combo_count_label->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->comboBackImg1->getPositionX()
							- Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().width
									/ 2,
					Singleton<GameManager>::GetInst()->comboImg->getPositionY()
							- Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().height
									/ 2 - 70));

	this->addChild(Singleton<GameManager>::GetInst()->combo_count_label, -1);

	Singleton<GameManager>::GetInst()->grade->setVisible(false);
	Singleton<GameManager>::GetInst()->grade->setPosition(
			ccp(CCDirector::sharedDirector()->getWinSize().width / 2,
					CCDirector::sharedDirector()->getWinSize().height / 2
							+ CCDirector::sharedDirector()->getWinSize().height
									/ 4 + 20));

	Singleton<GameManager>::GetInst()->grade->setScale(2.0);
	this->addChild(Singleton<GameManager>::GetInst()->grade, 0);

	Singleton<GameManager>::GetInst()->hp_bar->setPosition(
			ccp(280, CCDirector::sharedDirector()->getWinSize().height - 202));
	this->addChild(Singleton<GameManager>::GetInst()->hp_bar, 0);

	Singleton<GameManager>::GetInst()->timeBar->setPosition(
			ccp(CCDirector::sharedDirector()->getWinSize().width / 2 + 26,
					CCDirector::sharedDirector()->getWinSize().height - 52));
	//Singleton<GameManager>::GetInst()->timeBar->runAction(Singleton<GameManager>::GetInst()->progressToZero);
	this->addChild(Singleton<GameManager>::GetInst()->timeBar, 2);

	Singleton<GameManager>::GetInst()->perfect_count_bottom_label->setString(
			"0");

	Singleton<GameManager>::GetInst()->perfect_count_bottom_label->setPosition(
			ccp(
					CCDirector::sharedDirector()->getWinSize().width / 2
							- Singleton<GameManager>::GetInst()->perfect_count_bottom_label->getContentSize().width
									/ 2 - 180,
					CCDirector::sharedDirector()->getWinSize().height - 110));

	this->addChild(
			Singleton<GameManager>::GetInst()->perfect_count_bottom_label, 4);

	Singleton<GameManager>::GetInst()->good_count_bottom_label->setString("0");

	Singleton<GameManager>::GetInst()->good_count_bottom_label->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->perfect_count_bottom_label->getPositionX()
							+ Singleton<GameManager>::GetInst()->perfect_count_bottom_label->getContentSize().width
							+ 140,
					CCDirector::sharedDirector()->getWinSize().height - 110));

	this->addChild(Singleton<GameManager>::GetInst()->good_count_bottom_label,
			4);

	Singleton<GameManager>::GetInst()->bad_count_bottom_label->setString("0");

	Singleton<GameManager>::GetInst()->bad_count_bottom_label->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->good_count_bottom_label->getPositionX()
							+ Singleton<GameManager>::GetInst()->good_count_bottom_label->getContentSize().width
							+ 130,
					CCDirector::sharedDirector()->getWinSize().height - 110));

	this->addChild(Singleton<GameManager>::GetInst()->bad_count_bottom_label,
			4);

	Singleton<GameManager>::GetInst()->miss_count_bottom_label->setString("0");
	Singleton<GameManager>::GetInst()->miss_count_bottom_label->setPosition(
			ccp(
					Singleton<GameManager>::GetInst()->bad_count_bottom_label->getPositionX()
							+ Singleton<GameManager>::GetInst()->bad_count_bottom_label->getContentSize().width
							+ 130,
					CCDirector::sharedDirector()->getWinSize().height - 110));

	this->addChild(Singleton<GameManager>::GetInst()->miss_count_bottom_label,
			5);

	//泥���� 踰���쇱��移�
	Singleton<GameManager>::GetInst()->remoteOverImage(
			Singleton<GameManager>::GetInst()->remotePosition);
	Singleton<GameManager>::GetInst()->remoteController(
			Singleton<GameManager>::GetInst()->remotePosition);

	//��쇱����� 誘몃━ ������
	if (Singleton<GameManager>::GetInst()->pianoSelectValue == ACOUSTIC_MODE) {
		Singleton<GameManager>::GetInst()->acousticButtonPress();
	} else if (Singleton<GameManager>::GetInst()->pianoSelectValue
			== BRIGHT_MODE) {
		Singleton<GameManager>::GetInst()->brightButtonPress();
	} else if (Singleton<GameManager>::GetInst()->pianoSelectValue
			== CHORUS_MODE) {
		Singleton<GameManager>::GetInst()->chorusButtonPress();
	} else if (Singleton<GameManager>::GetInst()->pianoSelectValue
			== ELECTRIC_MODE) {
		Singleton<GameManager>::GetInst()->electricButtonPress();
	} else if (Singleton<GameManager>::GetInst()->pianoSelectValue
			== HONGKY_MODE) {
		Singleton<GameManager>::GetInst()->hongkyButtonPress();
	} else if (Singleton<GameManager>::GetInst()->pianoSelectValue
			== RHODES_MODE) {
		Singleton<GameManager>::GetInst()->rhodesButtonPress();
	} else {
		Singleton<GameManager>::GetInst()->acousticButtonPress();
	}

	if (Singleton<GameManager>::GetInst()->gameSpeedValue == X1_MODE) {
		Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
	} else if (Singleton<GameManager>::GetInst()->gameSpeedValue == X2_MODE) {
		Singleton<GameManager>::GetInst()->x2SpeedButtonPress();
	} else if (Singleton<GameManager>::GetInst()->gameSpeedValue == X12_MODE) {
		Singleton<GameManager>::GetInst()->x12SpeedButtonPress();
	} else if (Singleton<GameManager>::GetInst()->gameSpeedValue == X14_MODE) {
		Singleton<GameManager>::GetInst()->x14SpeedButtonPress();
	} else {
		Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
	}

	/*
	 Singleton<GameManager>::GetInst()->max_combo_label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-170,
	 CCDirector::sharedDirector()->getWinSize().height-185));


	 this->addChild(Singleton<GameManager>::GetInst()->max_combo_label,6);
	 */
	Singleton<GameManager>::GetInst()->total_score_label->setString("00000");
	Singleton<GameManager>::GetInst()->total_score_label->setPosition(
			ccp(CCDirector::sharedDirector()->getWinSize().width - 300,
					Singleton<GameManager>::GetInst()->max_combo_label->getPositionY()
							+ CCDirector::sharedDirector()->getWinSize().height
							- 200));

	this->addChild(Singleton<GameManager>::GetInst()->total_score_label, 6);

	Singleton<GameManager>::GetInst()->npc_sprite->setAnchorPoint(ccp(0, 0));
	Singleton<GameManager>::GetInst()->npc_sprite->setPosition(
			ccp(
					CCDirector::sharedDirector()->getWinSize().width
							- Singleton<GameManager>::GetInst()->npc_sprite->getContentSize().width
							- 200, 20));
	this->addChild(Singleton<GameManager>::GetInst()->npc_spritebatch, 7);

	Singleton<GameManager>::GetInst()->npc_sprite_green->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->npc_sprite_green->setPosition(
			ccp(
					CCDirector::sharedDirector()->getWinSize().width
							- Singleton<GameManager>::GetInst()->npc_sprite->getContentSize().width
							+ 100, 20));
	this->addChild(Singleton<GameManager>::GetInst()->npc_spritebatch_green, 7);

	Singleton<GameManager>::GetInst()->npc_sprite_pink->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->npc_sprite_pink->setPosition(
			ccp(
					CCDirector::sharedDirector()->getWinSize().width
							- Singleton<GameManager>::GetInst()->npc_sprite->getContentSize().width
							- 350, 20));
	this->addChild(Singleton<GameManager>::GetInst()->npc_spritebatch_pink, 7);

	Singleton<GameManager>::GetInst()->block_way->setAnchorPoint(ccp(0, 0));
	Singleton<GameManager>::GetInst()->block_way->setPosition(ccp(0, 320));
	this->addChild(Singleton<GameManager>::GetInst()->block_way, 8);

	/*
	 Singleton<GameManager>::GetInst()->block_way_effect->setVisible(false);
	 Singleton<GameManager>::GetInst()->block_way_effect->setAnchorPoint(ccp(0, 0));
	 Singleton<GameManager>::GetInst()->block_way_effect->setPosition(ccp(0,370));
	 this->addChild(Singleton<GameManager>::GetInst()->block_way_effect,8);
	 */

	Singleton<GameManager>::GetInst()->redBlock->setAnchorPoint(ccp(0, 0));
	Singleton<GameManager>::GetInst()->redBlock->setPosition(ccp(-70, 330));
	this->addChild(Singleton<GameManager>::GetInst()->redBlock, 9);

	Singleton<GameManager>::GetInst()->greenBlock->setAnchorPoint(ccp(0, 0));
	Singleton<GameManager>::GetInst()->greenBlock->setPosition(ccp(140, 330));
	this->addChild(Singleton<GameManager>::GetInst()->greenBlock, 9);

	Singleton<GameManager>::GetInst()->yellowBlock->setAnchorPoint(ccp(0, 0));
	Singleton<GameManager>::GetInst()->yellowBlock->setPosition(ccp(350, 330));
	this->addChild(Singleton<GameManager>::GetInst()->yellowBlock, 9);

	Singleton<GameManager>::GetInst()->redBlock_Press->setVisible(false);
	Singleton<GameManager>::GetInst()->redBlock_Press->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->redBlock_Press->setPosition(ccp(0, 330));
	this->addChild(Singleton<GameManager>::GetInst()->redBlock_Press, 9);

	Singleton<GameManager>::GetInst()->greenBlock_Press->setVisible(false);
	Singleton<GameManager>::GetInst()->greenBlock_Press->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->greenBlock_Press->setPosition(
			ccp(210, 330));
	this->addChild(Singleton<GameManager>::GetInst()->greenBlock_Press, 9);

	Singleton<GameManager>::GetInst()->yellowBlock_Press->setVisible(false);
	Singleton<GameManager>::GetInst()->yellowBlock_Press->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->yellowBlock_Press->setPosition(
			ccp(420, 330));
	this->addChild(Singleton<GameManager>::GetInst()->yellowBlock_Press, 9);

	Singleton<GameManager>::GetInst()->beginner_syllable_names_bg->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->beginner_syllable_names_bg->setPosition(
			ccp(50, 50));
	this->addChild(
			Singleton<GameManager>::GetInst()->beginner_syllable_names_bg, 9);

	Singleton<GameManager>::GetInst()->beginner_syllable_image->setVisible(
			false);
	Singleton<GameManager>::GetInst()->beginner_syllable_image->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->beginner_syllable_image->setPosition(
			ccp(62, 70));
	this->addChild(Singleton<GameManager>::GetInst()->beginner_syllable_image,
			9);

	Singleton<GameManager>::GetInst()->pianoKeyCode_a0->setColor(
			ccc3(208, 94, 50));
	Singleton<GameManager>::GetInst()->pianoKeyCode_a0->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->pianoKeyCode_a0->setPosition(
			ccp(
					430
							- Singleton<GameManager>::GetInst()->pianoKeyCode_a0->getContentSize().width
									/ 2, 150));
	this->addChild(Singleton<GameManager>::GetInst()->pianoKeyCode_a0, 9);

	// Singleton<GameManager>::GetInst()->pianoKeyCode_do->setFontSize(80);
	Singleton<GameManager>::GetInst()->pianoKeyCode_do->setColor(
			ccc3(90, 39, 18));
	Singleton<GameManager>::GetInst()->pianoKeyCode_do->setAnchorPoint(
			ccp(0, 0));
	Singleton<GameManager>::GetInst()->pianoKeyCode_do->setPosition(
			ccp(413, 70));
	this->addChild(Singleton<GameManager>::GetInst()->pianoKeyCode_do, 9);

	/*
	 beginner_syllable_names_bg;
	 beginner_syllable_image;
	 beginner_image_ti;
	 beginner_image_sol;
	 beginner_image_re;
	 beginner_image_mi;
	 beginner_image_la;
	 beginner_image_fa;
	 beginner_image_do;
	 */

	Singleton<GameManager>::GetInst()->start_count->setScale(2);
	Singleton<GameManager>::GetInst()->start_count->setString("3");
	Singleton<GameManager>::GetInst()->start_count->setPosition(
			ccp(
					CCDirector::sharedDirector()->getVisibleSize().width / 2
							- Singleton<GameManager>::GetInst()->start_count->getContentSize().width,
					CCDirector::sharedDirector()->getVisibleSize().height / 2
							- Singleton<GameManager>::GetInst()->start_count->getContentSize().height
							- 20));

	this->addChild(Singleton<GameManager>::GetInst()->start_count, 10);
	start_count_num = 4;
	this->start_count_display();

	Singleton<GameManager>::GetInst()->stopButton->setVisible(false);
	Singleton<GameManager>::GetInst()->stopButton->setAnchorPoint(ccp(0, 0));
	Singleton<GameManager>::GetInst()->stopButton->setPosition(ccp(0, 0));
	this->addChild(Singleton<GameManager>::GetInst()->stopButton, 11);

	return true;
}

void PlayNormalUiLayer::start_count_display() {
	--start_count_num;
	sprintf(str, "%d", start_count_num);
	Singleton<GameManager>::GetInst()->start_count->setString(str);
//    CCLog("start_count_num : %d",start_count_num);
	if (start_count_num == -1) {
		Singleton<GameManager>::GetInst()->tutorialMode = false;
		Singleton<GameManager>::GetInst()->gameStart = true;
		Singleton<GameManager>::GetInst()->start_count->setVisible(false);

	} else {
		CCDelayTime *delayAction = CCDelayTime::create(1);
		CCCallFuncN *callSelectorAction = CCCallFuncN::create(this,
				callfuncN_selector(PlayNormalUiLayer::start_count_display));
		Singleton<GameManager>::GetInst()->start_count->runAction(
				CCSequence::create(delayAction, callSelectorAction, NULL));
	}
}
void PlayNormalUiLayer::combo_hidden() {
	Singleton<GameManager>::GetInst()->combo_count_label->setVisible(false);
	Singleton<GameManager>::GetInst()->comboImg->setVisible(false);

	Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(false);
	Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(false);
	Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(false);

	CCLog("combo_hidden");

	Singleton<GameManager>::GetInst()->block_way->setVisible(true);
	/*
	 Singleton<GameManager>::GetInst()->perfect_inWay->setVisible(true);
	 Singleton<GameManager>::GetInst()->good_inWay->setVisible(true);
	 Singleton<GameManager>::GetInst()->bad_inWay->setVisible(true);

	 Singleton<GameManager>::GetInst()->perfect_inWay_effect->setVisible(false);
	 Singleton<GameManager>::GetInst()->good_inWay_effect->setVisible(false);
	 Singleton<GameManager>::GetInst()->bad_inWay_effect->setVisible(false);
	 */
	combo_printing = false;
	grade_printing = false;
}
void PlayNormalUiLayer::grade_hidden() {
	CCLog("grade_hidden");

	Singleton<GameManager>::GetInst()->block_way->setVisible(true);
	/*
	 Singleton<GameManager>::GetInst()->perfect_inWay->setVisible(true);
	 Singleton<GameManager>::GetInst()->good_inWay->setVisible(true);
	 Singleton<GameManager>::GetInst()->bad_inWay->setVisible(true);

	 Singleton<GameManager>::GetInst()->perfect_inWay_effect->setVisible(false);
	 Singleton<GameManager>::GetInst()->good_inWay_effect->setVisible(false);
	 Singleton<GameManager>::GetInst()->bad_inWay_effect->setVisible(false);
	 */

	Singleton<GameManager>::GetInst()->redBlock->setVisible(true);
	Singleton<GameManager>::GetInst()->redBlock_Press->setVisible(false);

	Singleton<GameManager>::GetInst()->greenBlock->setVisible(true);
	Singleton<GameManager>::GetInst()->greenBlock_Press->setVisible(false);

	Singleton<GameManager>::GetInst()->yellowBlock->setVisible(true);
	Singleton<GameManager>::GetInst()->yellowBlock_Press->setVisible(false);

	Singleton<GameManager>::GetInst()->grade->setVisible(false);

	combo_printing = false;
	grade_printing = false;
}
void PlayNormalUiLayer::update(float dt) {
	if (Singleton<GameManager>::GetInst()->comboImg->isVisible()
			&& !combo_printing) {
		combo_printing = true;

		CCDelayTime *delayAction = CCDelayTime::create(1);
		CCCallFuncN *callSelectorAction = CCCallFuncN::create(this,
				callfuncN_selector(PlayNormalUiLayer::combo_hidden));
		this->runAction(
				CCSequence::create(delayAction, callSelectorAction, NULL));
	}
	if (Singleton<GameManager>::GetInst()->grade->isVisible()
			&& !grade_printing) {
		grade_printing = true;

		CCDelayTime *delayAction = CCDelayTime::create(1);
		CCCallFuncN *callSelectorAction = CCCallFuncN::create(this,
				callfuncN_selector(PlayNormalUiLayer::grade_hidden));
		this->runAction(
				CCSequence::create(delayAction, callSelectorAction, NULL));
	}

	sprintf(str, "%d", Singleton<GameManager>::GetInst()->combo_count);
	Singleton<GameManager>::GetInst()->combo_count_label->setString(str);

	Singleton<GameManager>::GetInst()->pianoKeyCode_a0->setString(
			Singleton<GameManager>::GetInst()->pianoStr_a0.c_str());
	Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString(
			Singleton<GameManager>::GetInst()->pianoStr_do);

	sprintf(str, "%05d", Singleton<GameManager>::GetInst()->maxScore);
	Singleton<GameManager>::GetInst()->total_score_label->setString(str);

	sprintf(str, "%d",
			Singleton<GameManager>::GetInst()->perfectSocre
					+ Singleton<GameManager>::GetInst()->perfectSocre_copy);
	Singleton<GameManager>::GetInst()->perfect_count_bottom_label->setString(
			str);

	sprintf(str, "%d",
			Singleton<GameManager>::GetInst()->goodSocre
					+ Singleton<GameManager>::GetInst()->goodSocre_copy);
	Singleton<GameManager>::GetInst()->good_count_bottom_label->setString(str);

	sprintf(str, "%d",
			Singleton<GameManager>::GetInst()->badSocre
					+ Singleton<GameManager>::GetInst()->badSocre_copy);
	Singleton<GameManager>::GetInst()->bad_count_bottom_label->setString(str);

	sprintf(str, "%d",
			Singleton<GameManager>::GetInst()->missSocre
					+ Singleton<GameManager>::GetInst()->missSocre_copy);
	Singleton<GameManager>::GetInst()->miss_count_bottom_label->setString(str);
}

