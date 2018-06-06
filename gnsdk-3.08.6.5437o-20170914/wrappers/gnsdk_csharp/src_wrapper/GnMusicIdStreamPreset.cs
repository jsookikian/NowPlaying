
namespace GracenoteSDK {

/**
* @enum GnMusicIdStreamPreset
* @ingroup Music_MusicIDStream_TypesEnums
*/
public enum GnMusicIdStreamPreset {
/** Application type mobile, i.e. audio is captured by microphone
* @ingroup Music_MusicIDStream_TypesEnums
*/
  kPresetInvalid = 0,
/** Application type radio, i.e. audio is captured at source (e.g. direct from tuner)
* @ingroup Music_MusicIDStream_TypesEnums
*/
  kPresetMicrophone,
/** Custom type for a special case
* @ingroup Music_MusicIDStream_TypesEnums
*/
  kPresetRadio,

  kPresetCustom
}

}
