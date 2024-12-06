#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include <fmod.hpp>
#include "FMODAudioState.hpp"
#include "FMODSoundState.hpp"
#include "FMODMusic.hpp"
#include "FMODSound.hpp"
#include "FMODQueuedEffect.hpp"
#include "FMODQueuedMusic.hpp"
#include "FMODSoundTween.hpp"

class FMODAudioEngine : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "FMODAudioEngine";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(FMODAudioEngine, cocos2d::CCNode)

    /**
     * @note[short] Windows: 0x530d0
     * @note[short] Android
     */
     FMODAudioEngine();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static FMODAudioEngine* get();

    /**
     * @note[short] MacOS (ARM): 0x352964
     * @note[short] MacOS (Intel): 0x3c9e70
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static FMODAudioEngine* sharedEngine();

    /**
     * @note[short] MacOS (ARM): 0x3542a0
     * @note[short] MacOS (Intel): 0x3cc160
     * @note[short] Windows: 0x55390
     * @note[short] iOS: 0x13becc
     * @note[short] Android
     */
    virtual void update(float p0);
    
private:
    [[deprecated("FMODAudioEngine::activateQueuedMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn activateQueuedMusic(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x355668
     * @note[short] MacOS (Intel): 0x3cd8a0
     * @note[short] Windows: 0x58480
     * @note[short] Android
     */
    FMOD::Channel* channelForChannelID(int p0);
    
private:
    [[deprecated("FMODAudioEngine::channelForUniqueID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn channelForUniqueID(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::channelIDForUniqueID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn channelIDForUniqueID(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::channelLinkSound not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn channelLinkSound(int p0, FMODSound* p1);
public:
    
private:
    [[deprecated("FMODAudioEngine::channelStopped not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn channelStopped(FMOD::Channel* p0, bool p1);
public:
    
private:
    [[deprecated("FMODAudioEngine::channelUnlinkSound not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn channelUnlinkSound(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x353b90
     * @note[short] MacOS (Intel): 0x3cb330
     * @note[short] Windows: 0x552e0
     * @note[short] Android
     */
    void clearAllAudio();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int countActiveEffects();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int countActiveMusic();
    
private:
    [[deprecated("FMODAudioEngine::createStream not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createStream(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void disableMetering();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void enableMetering();
    
private:
    [[deprecated("FMODAudioEngine::fadeInBackgroundMusic not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3d4840
     * @note[short] Android
     */
    TodoReturn fadeInBackgroundMusic(float p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x35b38c
     * @note[short] MacOS (Intel): 0x3d4f80
     * @note[short] Windows: 0x5c3c0
     * @note[short] Android
     */
    void fadeInMusic(float p0, int p1);
    
private:
    [[deprecated("FMODAudioEngine::fadeMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn fadeMusic(float p0, int p1, float p2, float p3);
public:

    /**
     * @note[short] MacOS (ARM): 0x35d940
     * @note[short] MacOS (Intel): 0x3d7e20
     * @note[short] Windows: 0x5c500
     * @note[short] Android
     */
    float fadeOutMusic(float p0, int p1);
    
private:
    [[deprecated("FMODAudioEngine::getActiveMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getActiveMusic(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x356984
     * @note[short] MacOS (Intel): 0x3cf390
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    FMOD::Channel* getActiveMusicChannel(int musicChannel);

    /**
     * @note[short] MacOS (ARM): 0x35ad68
     * @note[short] MacOS (Intel): 0x3d4880
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    float getBackgroundMusicVolume();

    /**
     * @note[short] Windows: 0x56b20
     * @note[short] Android
     */
    FMOD::ChannelGroup* getChannelGroup(int p0, bool p1);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    float getEffectsVolume();

    /**
     * @note[short] MacOS (ARM): 0x35dce4
     * @note[short] MacOS (Intel): 0x3d82b0
     * @note[short] Windows: 0x5cdb0
     * @note[short] Android
     */
    gd::string getFMODStatus(int p0);
    
private:
    [[deprecated("FMODAudioEngine::getMeteringValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x35805c
     * @note[short] MacOS (Intel): 0x3d10a0
     * @note[short] Android
     */
    float getMeteringValue();
public:
    
private:
    [[deprecated("FMODAudioEngine::getMusicChannelID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMusicChannelID(int p0);
public:

    /**
     * @note[short] Windows: 0x5c330
     * @note[short] Android
     */
    unsigned int getMusicLengthMS(int channel);
    
private:
    [[deprecated("FMODAudioEngine::getMusicTime not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMusicTime(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x35d310
     * @note[short] MacOS (Intel): 0x3d7660
     * @note[short] Windows: 0x5c2d0
     * @note[short] Android
     */
    unsigned int getMusicTimeMS(int channel);
    
private:
    [[deprecated("FMODAudioEngine::getNextChannelID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getNextChannelID();
public:
    
private:
    [[deprecated("FMODAudioEngine::getTweenContainer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTweenContainer(AudioTargetType p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::isAnyPersistentPlaying not implemented")]]
    /**
     * @note[short] Android
     */
    bool isAnyPersistentPlaying();
public:
    
private:
    [[deprecated("FMODAudioEngine::isChannelStopping not implemented")]]
    /**
     * @note[short] Android
     */
    bool isChannelStopping(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::isEffectLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    bool isEffectLoaded(gd::string path);
public:

    /**
     * @note[short] MacOS (ARM): 0x35aeb0
     * @note[short] MacOS (Intel): 0x3d4a20
     * @note[short] Windows: 0x59ee0
     * @note[short] Android
     */
    bool isMusicPlaying(gd::string path, int p1);

    /**
     * @note[short] MacOS (ARM): 0x35ada4
     * @note[short] MacOS (Intel): 0x3d48f0
     * @note[short] Windows: 0x59d00
     * @note[short] Android
     */
    bool isMusicPlaying(int channel);
    
private:
    [[deprecated("FMODAudioEngine::isPersistentMatchPlaying not implemented")]]
    /**
     * @note[short] Android
     */
    bool isPersistentMatchPlaying(gd::string p0, int p1);
public:
    
private:
    [[deprecated("FMODAudioEngine::isSoundReady not implemented")]]
    /**
     * @note[short] Android
     */
    bool isSoundReady(FMOD::Sound* sound);
public:
    
private:
    [[deprecated("FMODAudioEngine::lengthForSound not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn lengthForSound(gd::string path);
public:
    
private:
    [[deprecated("FMODAudioEngine::loadAndPlayMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadAndPlayMusic(gd::string p0, unsigned int p1, int p2);
public:
    
private:
    [[deprecated("FMODAudioEngine::loadAudioState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadAudioState(FMODAudioState& p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x356464
     * @note[short] MacOS (Intel): 0x3ced40
     * @note[short] Windows: 0x5a280
     * @note[short] Android
     */
    void loadMusic(gd::string path, float speed, float p2, float volume, bool shouldLoop, int p5, int p6);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void loadMusic(gd::string path);
    
private:
    [[deprecated("FMODAudioEngine::loadMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadMusic(gd::string p0, float p1, float p2, float p3, bool p4, int p5, int p6, bool p7);
public:

    /**
     * @note[short] MacOS (ARM): 0x353afc
     * @note[short] MacOS (Intel): 0x3cb290
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void pauseAllAudio();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void pauseAllEffects();

    /**
     * @note[short] MacOS (ARM): 0x35ade0
     * @note[short] MacOS (Intel): 0x3d4930
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void pauseAllMusic(bool force);
    
private:
    [[deprecated("FMODAudioEngine::pauseEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn pauseEffect(unsigned int p0);
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void pauseMusic(int musicChannel);
    
private:
    [[deprecated("FMODAudioEngine::pitchForIdx not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn pitchForIdx(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x358870
     * @note[short] MacOS (Intel): 0x3d1ba0
     * @note[short] Windows: 0x56e10
     * @note[short] Android
     */
    void playEffect(gd::string path, float speed, float p2, float volume);

    /**
     * @note[short] MacOS (ARM): 0x3587c0
     * @note[short] MacOS (Intel): 0x3d1b10
     * @note[short] Windows: 0x56d90
     * @note[short] Android
     */
    void playEffect(gd::string path);

    /**
     * @note[short] MacOS (ARM): 0x356ac0
     * @note[short] MacOS (Intel): 0x3cf550
     * @note[short] Windows: 0x56f00
     * @note[short] Android
     */
    void playEffectAdvanced(gd::string path, float speed, float p2, float volume, float pitch, bool fastFourierTransform, bool reverb, int startMillis, int endMillis, int fadeIn, int fadeOut, bool loopEnabled, int p12, bool override, bool p14, int p15, int uniqueID, float minInterval, int sfxGroup);
    
private:
    [[deprecated("FMODAudioEngine::playEffectAsync not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playEffectAsync(gd::string path);
public:

    /**
     * @note[short] MacOS (ARM): 0x35b20c
     * @note[short] MacOS (Intel): 0x3d4dc0
     * @note[short] Windows: 0x5a110
     * @note[short] Android
     */
    void playMusic(gd::string path, bool shouldLoop, float fadeInTime, int channel);

    /**
     * @note[short] MacOS (ARM): 0x3531c4
     * @note[short] MacOS (Intel): 0x3ca980
     * @note[short] Windows: 0x59260
     * @note[short] Android
     */
    FMODSound& preloadEffect(gd::string path);
    
private:
    [[deprecated("FMODAudioEngine::preloadEffectAsync not implemented")]]
    /**
     * @note[short] Android
     */
    void preloadEffectAsync(gd::string path);
public:

    /**
     * @note[short] MacOS (ARM): 0x35b618
     * @note[short] MacOS (Intel): 0x3d5220
     * @note[short] Windows: 0x5c790
     * @note[short] Android
     */
    FMOD::Sound* preloadMusic(gd::string path, bool p1, int p2);
    
private:
    [[deprecated("FMODAudioEngine::printResult not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn printResult(FMOD_RESULT p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::queuedEffectFinishedLoading not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn queuedEffectFinishedLoading(gd::string p0);
public:

    /**
     * @note[short] Windows: 0x57920
     * @note[short] Android
     */
    TodoReturn queuePlayEffect(gd::string p0, float p1, float p2, float p3, float p4, bool p5, bool p6, int p7, int p8, int p9, int p10, bool p11, int p12, bool p13, int p14, float p15, int p16);

    /**
     * @note[short] MacOS (ARM): 0x35bdb8
     * @note[short] MacOS (Intel): 0x3d5af0
     * @note[short] Windows: 0x5aa70
     * @note[short] Android
     */
    void queueStartMusic(gd::string audioFilename, float p1, float p2, float p3, bool p4, int ms, int p6, int p7, int p8, int p9, bool p10, int p11, bool p12, bool p13);
    
private:
    [[deprecated("FMODAudioEngine::registerChannel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn registerChannel(FMOD::Channel* p0, int p1, int p2);
public:
    
private:
    [[deprecated("FMODAudioEngine::releaseRemovedSounds not implemented")]]
    /**
     * @note[short] Android
     */
    void releaseRemovedSounds();
public:

    /**
     * @note[short] MacOS (ARM): 0x353b48
     * @note[short] MacOS (Intel): 0x3cb2e0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void resumeAllAudio();

    /**
     * @note[short] MacOS (ARM): 0x35aa2c
     * @note[short] MacOS (Intel): 0x3d44b0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void resumeAllEffects();

    /**
     * @note[short] MacOS (ARM): 0x35ae5c
     * @note[short] MacOS (Intel): 0x3d49c0
     * @note[short] Windows: 0x59e80
     * @note[short] Android
     */
    void resumeAllMusic();

    /**
     * @note[short] MacOS (ARM): 0x3539c0
     * @note[short] MacOS (Intel): 0x3cb150
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void resumeAudio();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void resumeEffect(unsigned int p0);

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void resumeMusic(int musicChannel);
    
private:
    [[deprecated("FMODAudioEngine::reverbToString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x353648
     * @note[short] MacOS (Intel): 0x3caea0
     * @note[short] Android
     */
    TodoReturn reverbToString(FMODReverbPreset p0);
public:

    /**
     * @note[short] Windows: 0x558f0
     * @note[short] Android
     */
    TodoReturn saveAudioState(FMODAudioState& p0);

    /**
     * @note[short] MacOS (ARM): 0x35ad70
     * @note[short] MacOS (Intel): 0x3d4890
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void setBackgroundMusicVolume(float volume);
    
private:
    [[deprecated("FMODAudioEngine::setChannelPitch not implemented")]]
    /**
     * @note[short] Android
     */
    void setChannelPitch(int p0, AudioTargetType p1, float p2);
public:
    
private:
    [[deprecated("FMODAudioEngine::setChannelVolume not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3d0f40
     * @note[short] Android
     */
    void setChannelVolume(int p0, AudioTargetType p1, float p2);
public:

    /**
     * @note[short] Windows: 0x58f80
     * @note[short] Android
     */
    void setChannelVolumeMod(int p0, AudioTargetType p1, float p2);

    /**
     * @note[short] MacOS (ARM): 0x35ad90
     * @note[short] MacOS (Intel): 0x3d48d0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void setEffectsVolume(float volume);

    /**
     * @note[short] MacOS (ARM): 0x357488
     * @note[short] MacOS (Intel): 0x3d0290
     * @note[short] Windows: 0x5c190
     * @note[short] Android
     */
    void setMusicTimeMS(unsigned int p0, bool p1, int p2);

    /**
     * @note[short] MacOS (ARM): 0x352b4c
     * @note[short] MacOS (Intel): 0x3ca220
     * @note[short] Windows: 0x53bc0
     * @note[short] Android
     */
    void setup();

    /**
     * @note[short] MacOS (Intel): 0x3ca670
     * @note[short] Windows: 0x540a0
     * @note[short] Android
     */
    void setupAudioEngine();

    /**
     * @note[short] Windows: 0x55280
     * @note[short] Android
     */
    void start();
    
private:
    [[deprecated("FMODAudioEngine::startMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn startMusic(int p0, int p1, int p2, int p3, bool p4, int p5, bool p6, bool p7);
public:
    
private:
    [[deprecated("FMODAudioEngine::stop not implemented")]]
    /**
     * @note[short] Android
     */
    void stop();
public:

    /**
     * @note[short] MacOS (ARM): 0x353c3c
     * @note[short] MacOS (Intel): 0x3cb410
     * @note[short] Windows: 0x598b0
     * @note[short] Android
     */
    void stopAllEffects();

    /**
     * @note[short] MacOS (ARM): 0x353f28
     * @note[short] MacOS (Intel): 0x3cbbf0
     * @note[short] Windows: 0x59d70
     * @note[short] Android
     */
    void stopAllMusic(bool p0);
    
private:
    [[deprecated("FMODAudioEngine::stopAndGetFade not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x35a2bc
     * @note[short] Android
     */
    TodoReturn stopAndGetFade(FMOD::Channel* p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::stopAndRemoveMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopAndRemoveMusic(int p0);
public:

    /**
     * @note[short] Windows: 0x58810
     * @note[short] Android
     */
    void stopChannel(FMOD::Channel* p0, bool p1, float p2);
    
private:
    [[deprecated("FMODAudioEngine::stopChannel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopChannel(int p0, AudioTargetType p1, bool p2, float p3);
public:
    
private:
    [[deprecated("FMODAudioEngine::stopChannel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopChannel(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::stopChannelTween not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopChannelTween(int p0, AudioTargetType p1, AudioModType p2);
public:
    
private:
    [[deprecated("FMODAudioEngine::stopChannelTweens not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopChannelTweens(int p0, AudioTargetType p1);
public:
    
private:
    [[deprecated("FMODAudioEngine::stopMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopMusic(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::stopMusicNotInSet not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopMusicNotInSet(std::unordered_set<int, std::hash<int>, std::equal_to<int>, std::allocator<int> >& p0);
public:

    /**
     * @note[short] Windows: 0x59510
     * @note[short] Android
     */
    TodoReturn storeEffect(FMOD::Sound* sound, gd::string path);
    
private:
    [[deprecated("FMODAudioEngine::swapMusicIndex not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn swapMusicIndex(int p0, int p1);
public:
    
private:
    [[deprecated("FMODAudioEngine::testFunction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn testFunction(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::triggerQueuedMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerQueuedMusic(FMODQueuedMusic p0);
public:

    /**
     * @note[short] Windows: 0x59aa0
     * @note[short] Android
     */
    TodoReturn unloadAllEffects();
    
private:
    [[deprecated("FMODAudioEngine::unloadEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unloadEffect(gd::string path);
public:
    
private:
    [[deprecated("FMODAudioEngine::unregisterChannel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unregisterChannel(int p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::updateBackgroundFade not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBackgroundFade();
public:
    
private:
    [[deprecated("FMODAudioEngine::updateChannel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateChannel(int p0, AudioTargetType p1, AudioModType p2, float p3, float p4);
public:
    
private:
    [[deprecated("FMODAudioEngine::updateChannelTweens not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3cd220
     * @note[short] Android
     */
    TodoReturn updateChannelTweens(float p0);
public:
    
private:
    [[deprecated("FMODAudioEngine::updateMetering not implemented")]]
    /**
     * @note[short] Android
     */
    void updateMetering();
public:

    /**
     * @note[short] Windows: 0x5aec0
     * @note[short] Android
     */
    void updateQueuedEffects();
    
private:
    [[deprecated("FMODAudioEngine::updateQueuedMusic not implemented")]]
    /**
     * @note[short] Android
     */
    void updateQueuedMusic();
public:

    /**
     * @note[short] MacOS (Intel): 0x3cac50
     * @note[short] Windows: 0x54400
     * @note[short] Android
     */
    void updateReverb(FMODReverbPreset p0, bool p1);

    /**
     * @note[short] MacOS (Intel): 0x3cc820
     * @note[short] Windows: 0x5b410
     * @note[short] Android
     */
    void updateTemporaryEffects();
    
private:
    [[deprecated("FMODAudioEngine::waitUntilSoundReady not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn waitUntilSoundReady(FMOD::Sound* p0);
public:
    gd::unordered_map<int, FMODMusic> m_musicChannels;
    gd::unordered_map<gd::string, FMODMusic> m_unkMap180;
    gd::unordered_set<gd::string> m_unkMap1c0;
    float m_musicVolume;
    float m_sfxVolume;
    int m_unusedInt164;
    int m_unusedInt168;
    float m_pulse1;
    float m_pulse2;
    float m_pulse3;
    int m_pulseCounter;
    bool m_metering;
    FMOD::ChannelGroup* m_backgroundMusicChannel;
    FMOD::System* m_system;
    FMOD::DSP* m_mainDSP;
    FMOD::DSP* m_globalChannelDSP;
    FMOD::ChannelGroup* m_globalChannel;
    FMOD::ChannelGroup* m_channelGroup2;
    FMOD_RESULT m_lastResult;
    int m_sampleRate;
    bool m_reducedQuality;
    bool m_allAudioPaused;
    int m_musicOffset;
    bool m_unkBool1a8;
    int m_unkInt1ac;
    FMODAudioState m_audioState;
    gd::vector<FMOD::Sound*> m_unkSoundVector;
    gd::unordered_map<int, FMOD::DSP*> m_unkDSPMap384;
    gd::unordered_map<int, FMOD::Channel*> m_channelIDToChannel;
    gd::unordered_set<int> m_unkIntSet3bc;
    FMODReverbPreset m_reverbPreset;
    gd::unordered_map<int, int> m_unkMapIntInt3dc;
    gd::unordered_map<int, int> m_unkMapIntInt3f8;
    gd::unordered_map<int, gd::string> m_unkMapIntString414;
    gd::vector<FMODQueuedEffect> m_queuedEffects;
    gd::unordered_map<gd::string, FMOD::Sound*> m_unkMapStringSound43c;
    gd::unordered_map<int, FMOD::ChannelGroup*> m_unkMapIntChannelGroup458;
    gd::unordered_map<int, FMOD::ChannelGroup*> m_unkMapIntChannelGroup474;
    int m_unkInt490;
    int m_unkInt494;
    int m_unkInt498;
    int m_unkInt49c;
    int m_unkInt4a0;
    int m_unkInt4a4;
    int m_unkInt4a8;
    int m_unkInt4ac;
};
