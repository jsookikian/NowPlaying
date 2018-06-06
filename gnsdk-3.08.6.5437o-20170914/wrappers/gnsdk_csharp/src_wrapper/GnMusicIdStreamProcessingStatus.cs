
namespace GracenoteSDK {

/**
* @enum GnMusicIdStreamProcessingStatus
* GnMusicIdStreamProcessingStatus is currently considered to be experimental.
* An application should only use this option if your Gracenote representative advises you to do so.
* Contact your Gracenote representative with any questions about this enhanced functionality.
* @ingroup Music_MusicIDStream_TypesEnums
*/
public enum GnMusicIdStreamProcessingStatus {

  kStatusProcessingInvalid = 0,

  kStatusProcessingAudioNone,

  kStatusProcessingAudioSilence,

  kStatusProcessingAudioNoise,

  kStatusProcessingAudioSpeech,

  kStatusProcessingAudioMusic,

  kStatusProcessingTransitionNone,

  kStatusProcessingTransitionChannelChange,

  kStatusProcessingTransitionContentToContent,

  kStatusProcessingErrorNoClassifier,

  kStatusProcessingAudioStarted,

  kStatusProcessingAudioEnded,

  kStatusProcessingEqProfileChanged
}

}
