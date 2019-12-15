#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"
#include "Singleton.h"
#include "AppMacros.h"
#include "Block.h"
//#include "FCMidi.h"
#include "MIDIFileLoader.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "platform/android/jni/JniHelper.h"
#endif

#include "cocos-ext.h"



#define END_FALSE 0
#define END_DELAY -1
#define END_TRUE 1

//#define PianoSpeed 12.6
#define TIMEDELAY 8
#define PianoSpeed 100

#define MAP_STAGE_COUNT 6
#define BASE_BOX       88
#define BOX_WIDTH      95
#define BOX_HEIGHT     32
#define GAME_DEBUG     YES
#define FEVERTIME 5

#define BLACK_PIANO_COUNT 36
#define WHITE_PIANO_COUNT 52
#define TOTAL_PIANO_COUNT 88
#define PIANO_HEIGHT 328
#define PIANO_LONG_BLOCK_DIST 500
#define PIANO_BLOCK_DIST 500
#define FREE_MODE_PIANO_HEIGHT 244
#define HIT_LINE 380

#define LINE_OPACITY 60
#define ENERGY_INIT 23.1

#define GAME_VERSION   @"1.0"
#define GAME_DATA_KEY  @"SHFACTORY"
using namespace cocos2d;
using namespace extension;


struct Start_Loading_Structure
{
    CCScene *GameScene_Linker;
    
};

enum game_scene {
    GAME_SCENE_NONE = 0,
    
    GAME_SCENE_MENU,
    GAME_SCENE_PLAY,
    GAME_EASY_SCENE_PLAY,
    GAME_NORMAL_SCENE_PLAY,
    GAME_SCENE_STARTLOAD,
    
    GAME_SCENE_MAX,
    PIANO_SCENE_PLAY
};
enum Npc_state {
    Npc_STATE_NONE = 0,
    Npc_STATE_IDLE,
    Npc_STATE_CRY,
    Npc_STATE_HURT,
    Npc_STATE_DEAD
};

enum game_mode {
    SINGE_GAME = 0,
    SINGE_FREE,
    ANG_GAME,
    ANG_FREE,
    EASY_GAME,
    NORMAL_GAME
};
enum piano_mode {
    NORMAL_MODE = 0,
    MARK_MODE,
    RAINBOW_MODE
};
enum piano_Sound_mode {
    ACOUSTIC_MODE = 0,
    BRIGHT_MODE,
    CHORUS_MODE,
    ELECTRIC_MODE,
    HONGKY_MODE,
    RHODES_MODE
};

enum game_Speed_mode {
    X14_MODE = 0,
    X12_MODE,
    X1_MODE,
    X2_MODE
};



class GameManager : public CCNode, Singleton<GameManager>
{
    friend class Singleton<GameManager>;
    
    protected:
        GameManager();
    private:
        ~GameManager();
    public:
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        jobject javaObj;
#endif
        char str[100];
        char midiPath[512];
    
        bool playNormalScene;
        bool playEasyScene;
        bool playAngFreeScene;
        bool playFreeScene;
        bool playGameScene;
        bool playAngGameScene;
    
        CCSize block_WinSize;
        CCSize WinSize;
        
        CCPoint block_WinOrign;
        CCPoint WinOrign;
        float halfWidth;
        
        float SCREEN_SIZE_WHITE_halfBlockWidth;
        float SCREEN_SIZE_WHITE_halfBlockHeight;
        
        float WHITE_halfBlockWidth;
        float WHITE_halfBlockHeight;
        
        float BLACK_halfBlockWidth;
        float BLACK_halfBlockHeight;
        
        float WHITE_BlockWidth;
        //float WHITE_BlockHeight;
        
        float SCREEN_SIZE_WHITE_BlockWidth;
        
        float SCREEN_2X_SIZE_WHITE_BlockWidth;
        float SCREEN_2X_SIZE_WHITE_BlockHeight;
        
        float BLACK_BlockWidth;
        // float BLACK_BlockHeight;
        
        
        float BlockCenterPoint;
        float startBlockPoint;
        float startBlockPoint_copy;
        
        float nodeYpos_timeMillis;//釉���� 媛�寃�
        
        CCPoint halfLineStartPoint;
        CCPoint halfLineEndPoint;
        
        CCPoint EndLineStartPoint;
        CCPoint EndLineEndPoint;

    
        int pianoSelectValue;
        int pianoCoverValue;
        int gameSpeedValue;
    
        float minTime;
    
        bool feverMode;
        int firstPrintNodeCount;//泥���� 異���λ����� ��몃�� 媛����
        bool feverTimer;//��쇳�����..   game scene update������ ��������� ��⑥�� ���踰�留� 遺�瑜닿린 ������
        float gameSpeed;//釉���� ������ 議곗��
        double maxTime; //total ���媛�
        double stateTime;//������遺���� ������ ��⑹�� 珥� ���媛�
        int PIANO_FINISH_TIME;
        int musicPlayLine;
    
    
        int combo_count;
        int max_combo_count;
        int block_count;
        

    
        int maxScore;
        int perfectSocre;
        int missSocre;
        int goodSocre;
        int badSocre;
        int nodePrintingCount; //������ 異���λ��怨� ������ ��몃�� 移댁�댄��
        int nodeGuidingCount; //������ 媛���대�� 怨���곕��怨� ������ ��몃�� 移댁�댄��
        int totalNodeCount; //���泥� ��몃�� ���
        int matchingNodeCount; //留�異� ��몃�� ���

    
        bool gameStart;
        //CCLabelAtlas *start_count_copy;
        
        int combo_count_copy;
        int max_combo_count_copy;
        int block_count_copy;
        int block_count_copy_copy;
        int start_count_num_copy;
        
        int maxScore_copy;
        int perfectSocre_copy;
        int missSocre_copy;
        int goodSocre_copy;
        int badSocre_copy;
        int totalNodeCount_copy; //���泥� ��몃�� ���
        int matchingNodeCount_copy; //留�異� ��몃�� ���
    
        float load_timeBar;
        bool loding_complete;
    
        //game scene
        int dataIndex;//�����ν�대����� 梨���� 援щ��
        int dataIndex_copy;//�����ν�대����� 梨���� 援щ��
        int printRealNoteCount;
    
        int gameMode;
        int pianoMode;
        int firstDeviceID;  //������濡���대�� ������釉� 愿����
    
    
    
        //��쇱�� 洹몃━湲�
        int _collision_boxes_count;
        int _collision_boxes_count_copy;
    
        //float pianoSelect[128][2];
        //float pianoSelect_copy[128][2];
        
        int totalLoadImage;
        int LoadImageCount;
    
        int breakLine;
        int equalLineBlockCount;
    
        //float hit_yellow_effect_rotate[88];
    
        CCProgressTimer *load_timeBar_gaze;
    
        std::vector<std::vector<noteData> > midiChannel;
        std::vector<int> midiChannel_seq;
        std::vector<double> saveTime;//異���λ��湲곗�� ���媛�
        std::vector<bool> firstTimeDelay;//異���λ��湲곗�� ��������� ��щ��
    
//        std::vector<float> gameTotalTime;
        std::vector<int> removeNodeCount; //������ 遺����吏� ��몃�� 媛����
        std::vector<int> guidePrintCount; //媛���대�� ������
        std::vector<int> removeNodeCount_copy;
        std::vector<int> printChannel;       //遺���� 異���λ����� 梨���� ������
        std::vector<int> deleteGuideCount;       //吏����吏� ��몃�� ��쇱�� ���
        std::vector<int> deleteGuideCount_copy;
        std::vector<int> nodePrintCount_Channel; //������ 肉���ㅼ��怨� ������ ��몃�� 移댁�댄��
        std::vector<int> nodePrintCount_Channel_copy;
        std::vector<int> eraseCount; //梨����蹂� 吏����吏� ��몃��
        std::vector<int> guideCount; //梨����蹂� 媛���대�� ������
        std::vector<CCArray *>         guide_Total_Array_channel;
        std::vector<CCArray *>         guide_Total_Array_channel_copy;
        std::map<int, float> gameTotalTime;
    
       // std::map<double, Block *>::iterator Iter_Erase_Node_Pos; //������������ ��ъ�����
        std::map<double, Block *> _erase_print_blocks;  //���泥� ������ ������ ��몃�� ������..

        std::map<double, Block *> _guide_print_blocks;  //���泥� 媛���대�� ��몃�� ������..
        std::map<double, Block *>::iterator Iter_Guide_Node_Pos; //留�吏�留���쇰�� 媛���대�� 怨���곕�� ��ъ�����

        std::map<double, Block *>::iterator Iter_Print_Node_Pos; //留�吏�留���쇰�� 異���λ�� ��ъ�����
        std::map<double, Block *> _print_blocks;  //���泥� 異���μ�����媛� �����щ�� ��몃��..
    
        std::vector<Block *> _collision_boxes;
        std::vector<Block *> _collision_boxes_copy;
        std::vector<std::vector<Block *> > _collision_boxes_Channel;
        std::vector<std::vector<Block *> > _collision_boxes_Channel_copy;

    
    
        CCLabelAtlas *combo_count_label;
        CCLabelAtlas *perfect_count_bottom_label;
        CCLabelAtlas *good_count_bottom_label;
        CCLabelAtlas *bad_count_bottom_label;
        CCLabelAtlas *miss_count_bottom_label;
        CCLabelAtlas *max_combo_label;
        CCLabelAtlas *total_score_label;
        CCLabelAtlas *combo_count_label_copy;
        CCLabelAtlas *perfect_count_bottom_label_copy;
        CCLabelAtlas *good_count_bottom_label_copy;
        CCLabelAtlas *bad_count_bottom_label_copy;
        CCLabelAtlas *miss_count_bottom_label_copy;
        CCLabelAtlas *max_combo_label_copy;
        CCLabelAtlas *total_score_label_copy;
        
        CCLabelAtlas *start_count;

        
        CCArray*         line_block_collect_array;          //��ㅻ낫��� ������ 愿����
        CCArray*         line_block_collect_array_copy;
    
        CCLayer *coverLayer;
    
        CCLayer *effect_layer;
        CCLayer *effect_layer_copy;
    
        CCLayer *controll_layer;
        CCLayer *controll_layer_copy;
        CCLayer *line_layer;
        CCLayer *line_layer_copy;
    
        CCLayer *block_layer;
        CCLayer *normal_block_layer;
        CCLayer *normal_block_cover_layer;
    
    
        CCScene *GameScene;
    
        CCTexture2D *btn_key_yellow_press_1;
        CCTexture2D *btn_key_yellow_press_2;
        CCTexture2D *btn_key_yellow_press_3;
        CCTexture2D *btn_key_yellow_press_4;
        CCTexture2D *btn_black_key_press;
    
        CCTexture2D *btn_key_guide_press_1;
        CCTexture2D *btn_key_guide_press_2;
        CCTexture2D *btn_key_guide_press_3;
        CCTexture2D *btn_key_guide_press_4;
        CCTexture2D *btn_black_key_guide_press;
    
        CCTexture2D *bar_blue;
        CCTexture2D *bar_blue_long;
    
        CCTexture2D *bar_yellow;
        CCTexture2D *bar_yellow_long;
    
        CCTexture2D *perfect;
        CCTexture2D *miss;
        CCTexture2D *good;
        CCTexture2D *bad;
        CCTexture2D *load_timer_gaze_tex[4];
    
        int remoteOverPosition[3];
        int remotePosition;
       // int remoteRealPosition;
        int remoteUpDownPosition;
        int remoteUpDownOverPosition;
        int FreeRemotePosition;
    
       // CCParticleSystem*    m_emitter;
    
        CCSprite *piano_press_sprite[88];
        CCSprite *piano_press_sprite_copy[88];
        CCSprite *piano_guid_sprite[88];
        CCSprite *piano_guid_sprite_copy[88];
        CCSprite *piano_rainbow_press_sprite[88];
        CCSprite *piano_rainbow_press_sprite_copy[88];
        
        CCSprite *draw_line[88];
        CCSprite *draw_line_copy[88];
        
        CCSprite *hit_yellow_effect[88];
        CCSprite *hit_yellow_effect_copy[88];
    
        CCSprite* load_timer_gaze[18];
    
    
        CCSprite* LoadBG;
        CCSprite* LoadBG_Free;
      //  CCSprite* papi;
        CCSprite* LoadBG_Free_copy;
        
        CCSprite* load_line;
        CCSprite* blackcover;
        CCLabelTTF *tutorialMent1;
        CCLabelTTF *tutorialMent2;
        CCLabelTTF *tutorialMent3;
        CCLabelTTF *tutorialMent4;
        CCLabelTTF *tutorialMent5;
        CCLabelTTF *tutorialMent6;
        CCLabelTTF *tutorialMent7;
        CCLabelTTF *tutorialMent8;
        CCSprite* tutorial_bg;
        CCSprite* tutorial_piano[7];
        CCSprite* normal_bg;
    
        CCSprite *hitLine;
        CCSprite *hitLine_copy;
    
        CCSprite *pianoBG;
        CCSprite *pianoBG_copy;
        CCTexture2D *pianoBG_tex[3];
    
        CCSprite *GameBG;
        CCSprite *GameBG_copy;
        CCSprite *comboImg;
        CCSprite *comboImg_copy;
        CCSprite *comboBackImg1;
        CCSprite *comboBackImg1_copy;
        CCSprite *comboBackImg2;
        CCSprite *comboBackImg2_copy;
        CCSprite *comboBackImg3;
        CCSprite *comboBackImg3_copy;
    
        CCSpriteBatchNode* spritebatch;
    
        CCAnimate *hit_effect_animate;
    
    
     ////////////////////////////////////////////////////////////////////////////////////
        //easy mode
        CCSprite *image_do;
        CCSprite *image_fa;
        CCSprite *image_mi;
        CCSprite *image_ra;
        CCSprite *image_re;
        CCSprite *image_si;
        CCSprite *image_so;
        CCSprite *practice_bg;
        CCSprite *practice_btn_exit_over;
        CCSprite *practice_btn_exit_press;
        CCSprite *practice_frame;
        CCSprite *practice_logo;
        CCSprite *text_do;
        CCSprite *text_fa;
        CCSprite *text_la;
        CCSprite *text_mi;
        CCSprite *text_re;
        CCSprite *text_so;
        CCSprite *text_ti;
    
        CCTexture2D *note_do_nomal;
        CCTexture2D *note_do_smile;
        CCTexture2D *note_fa_nomal;
        CCTexture2D *note_fa_smile;
        CCTexture2D *note_la_nomal;
        CCTexture2D *note_la_smile;
        CCTexture2D *note_mi_nomal;
        CCTexture2D *note_mi_smile;
        CCTexture2D *note_re_nomal;
        CCTexture2D *note_re_smile;
        CCTexture2D *note_so_nomal;
        CCTexture2D *note_so_smile;
        CCTexture2D *note_ti_nomal;
        CCTexture2D *note_ti_smile;
   
        ////////////////////////////////////////////////////////////////////////////////////
    
        ////////////////////////////////////////////////////////////////////////////////////
        //normal mode
        CCFiniteTimeAction*  action;
    
        std::string pianoStr_a0;
        char pianoStr_do[100];
        CCLabelTTF *pianoKeyCode_a0;
        CCLabelTTF *pianoKeyCode_do;
    
        CCTexture2D *beginner_image_do;
        CCTexture2D *beginner_image_fa;
        CCTexture2D *beginner_image_la;
        CCTexture2D *beginner_image_mi;
        CCTexture2D *beginner_image_re;
        CCTexture2D *beginner_image_sol;
        CCTexture2D *beginner_image_ti;

        CCSprite *beginner_syllable_image;
        CCSprite *beginner_syllable_names_bg;
    

    
        CCSprite *redBlock;
        CCSprite *yellowBlock;
        CCSprite *greenBlock;
    
        CCSprite *redBlock_Press;
        CCSprite *yellowBlock_Press;
        CCSprite *greenBlock_Press;

    
        CCSprite *block_way;
        CCSprite *copy_target;
    
        CCSprite *npc_sprite;
        CCSpriteBatchNode* npc_spritebatch;
        int npc_state;
        CCAnimate *idle_animate;
        CCAnimate *hurt_animate;
        CCAnimate *cry_animate;
    
        CCSprite *npc_sprite_green;
        CCSpriteBatchNode* npc_spritebatch_green;
        int npc_state_green;
        CCAnimate *idle_animate_green;
        CCAnimate *cry_animate_green;
        
        CCSprite *npc_sprite_pink;
        CCSpriteBatchNode* npc_spritebatch_pink;
        int npc_state_pink;
        CCAnimate *idle_animate_pink;
        CCAnimate *cry_animate_pink;
  
        ////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    
        CCSprite *timer_gaze;
     

        CCSprite *stopButton;
        CCSprite *grade;
        CCSprite *grade_copy;
    
        CCSprite *hp_bar;
        CCSprite *hp_bar_copy;
    
        CCProgressTimer *energy_bar;
        CCProgressTimer *energy_bar_copy;
    
        
    
        CCMenuItemImage *escButton;
        CCMenuItemImage *escButton_copy;
        CCMenuItemImage *pauseButton;
        CCMenuItemImage *pauseButton_copy;
  /*
        CCMenuItemImage *x4SpeedButton;
        CCMenuItemImage *x4SpeedButton_copy;
        CCMenuItemImage *x3SpeedButton;
        CCMenuItemImage *x3SpeedButton_copy;
  */
        CCMenuItemImage *x14SpeedButton;
        CCMenuItemImage *x12SpeedButton;
    
        CCMenuItemImage *x1SpeedButton;
        CCMenuItemImage *x1SpeedButton_copy;
        CCMenuItemImage *x2SpeedButton;
        CCMenuItemImage *x2SpeedButton_copy;
  
    
        CCMenuItemImage *acousticButton;
        CCMenuItemImage *acousticButton_copy;
        CCMenuItemImage *brightButton;
        CCMenuItemImage *brightButton_copy;
        CCMenuItemImage *chorusButton;
        CCMenuItemImage *chorusButton_copy;
        CCMenuItemImage *electricButton;
        CCMenuItemImage *electricButton_copy;
        CCMenuItemImage *hongkyButton;
        CCMenuItemImage *hongkyButton_copy;
        CCMenuItemImage *rhodesButton;
        CCMenuItemImage *rhodesButton_copy;
    
        CCMenuItemImage *pianoNormalButton;
        CCMenuItemImage *pianoNormalButton_copy;

        CCMenuItemImage *pianoMarkButton;
        CCMenuItemImage *pianoMarkButton_copy;
    
        CCMenuItemImage *pianoRainbowButton;
        CCMenuItemImage *pianoRainbowButton_copy;
    
        CCMenuItemImage *exitButton;
    
        CCMenu *menu;
        CCMenu *menu_copy;
    
        CCProgressTimer *timeBar;
        CCProgressTimer *timeBar_copy;
        //CCProgressFromTo *progressToZero;
        CCProgressFromTo *progressToZero_copy;
    
    
        bool channelState;//������ 遺���������� 梨����
    
    
        float DownBlockEndPosX[88];
    
        float effectPosX[88];
    
        int whiteInPos(int index);
    
        void pianoEffectInit(CCLayer *layer);
    
        void pianoSpritePositionSet();
        void pianoSpritePositionSet_copy();
    
    
        void downBlockPosInit(int index);
        void pianoSpriteInit(int index);
        void pianoSpriteInit_copy(int index);
        CCSize calSize(CCSize destSize);
    
        void EasyImageloadingCallBack(CCObject *obj);
    
        void runScene(int type);
        bool init();
        
        void resourceGameSceneLoad();
        void resourceGameSceneClean();
    
        void resourceFreeGameSceneLoad();
    
        void resourceEasyGameSceneLoad();
        void resourceNormalGameSceneLoad();
    
        void resourceMenuSceneLoad();
        void resourceMenuSceneClean();
        void resourceLoadSceneLoad();
        void resourceLoadSceneClean();
        void ImageloadingCallBack(CCObject *obj);
        void FreeImageloadingCallBack(CCObject *obj);
        void NormalImageloadingCallBack(CCObject *obj);
    
        void FreeGameScene_Init();
        void GameScene_Init();
        void EasyGameScene_Init();
        void NormalGameScene_Init();

        int checkCollisionBox(int keycode);
        int checkCollisionBox_copy(int keycode);
        int checkCollisionBox(const char *keyCode);
        int checkCollisionBox_copy(const char *keyCode);
        int checkNomalCollisionBox(int keycode);
    
        int gameEnding;
        void game_wait_end();
        void game_end();
        void all_Cleanup();
    
        void escButtonPress();
        void escButtonPress_copy();
        void missMatch();
        void missMatch_copy();
        void perfectMatch(int keycode, int gradeValue);
        void perfectMatch_copy(int keycode, int gradeValue);
        void piano_effect_hide(CCNode* sender);
        void piano_effect_hide_copy(CCNode* sender);
 
        void SetControllLayer(CCLayer *layer);
        void SetControllLayer_copy(CCLayer *layer);
    
        void SetEffectLayer(CCLayer *layer);
        void SetEffectLayer_copy(CCLayer *layer);
    
        void Midi_Load();
    
        void pauseButtonPress();
        void resumeButtonPress();
        void x12SpeedButtonPress();
        void x1SpeedButtonPress();
        void x2SpeedButtonPress();
        void x14SpeedButtonPress();
    
        void acousticButtonPress();
        void brightButtonPress();
        void chorusButtonPress();
        void electricButtonPress();
        void hongkyButtonPress();
        void rhodesButtonPress();
    
 
    
        void pauseButtonPress_copy();
        void resumeButtonPress_copy();
        void x1SpeedButtonPress_copy();
        void x2SpeedButtonPress_copy();

    
        int pianoSpriteSwitch(int i);
        int pianoSpriteSwitch_copy(int i);
        void pianoGuideVisible(int targetNum);
        void pianoGuideVisible_copy(int targetNum);
    
        void makeCollisinoBoxes(int nodeNum,double nodeLong,int blockDivision,int midiDivision,int ch,int _velocity,float elapsedMillis,double timePos);  //��몃�� ������
        void makeCollisinoBoxes_copy(int nodeNum,double nodeLong,int blockDivision,int midiDivision,int ch,int _velocity,float elapsedMillis,double timePos);
    
        void MoveFinished(Block *destBlock);
        void _9Sprite_MoveFinished(Block *destBlock);
        void MoveFinished_copy(Block *destBlock);
        void _9Sprite_MoveFinished_copy(Block *destBlock);
        void gradeHide();
        void gradeHide_copy();
        void key_inputSetting();
    
        void remoteController(int value);
        void FreeremoteController(int value);
    
        void playGameSceneMaker();
        void playFreeSceneMaker();
        void playAngFreeSceneMaker();
        void playAngGameSceneMaker();
        void playEasySceneMaker();
        void playNormalSceneMaker();
        
        void SetLineLayer(CCLayer *layer);
        void SetLineLayer_copy(CCLayer *layer);
    
        void SetBlockLayer(CCLayer *layer);
        void SetNormalBlockLayer(CCLayer *layer);
        void SetNormalBlockLayer(CCLayer *layer,CCLayer *nomalBlocklayer);
        void rainbowColorInit(int i);
 
        void hit_effect_visiable(int index);
        void hit_effect_end(CCNode* sender,int index);
    
        void hit_effect_visiable_copy(int index);
        void hit_effect_end_copy(CCNode* sender,int index);
    
        void pianoNormalButtonPress();
        void pianoMarkButtonPress();
        void pianoRainbowButtonPress();
    
        void remoteOverImage(int value);
        void remoteOverImageFree(int value);
    
        void remoteUpDownController(int value);
        void remoteUpDownOverImage(int value);
    
        void collisionCheck(Block *target,int keycode);
    
        void makeCollisinoBoxes_update(CCNode* sender, int channel);
        //void printNode(int nodeCount, int channel);
    
    
        void printNode(int count);
        void printNodeInit();
    
    
    
        bool keyMatching[7];
        bool tutorialMode;
        
        std::string keyCheck(int keyCode);
        int doremipasolasi(int keyCode);
    
        void start_count_display();
    
        void replaceAnimation(int ani);
        void cry_end();

        Block* makeBlock(Block* block);
        void collision_target_ani_finish(CCNode* sender,int index);
};

#endif


 

 
