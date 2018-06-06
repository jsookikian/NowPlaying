
namespace GracenoteSDK {

/**
* @enum GnMusicIdInfo
* Represents the different information types that can be retrieved from
* a GnMusicId object.
* @ingroup Music_MusicID_TypesEnums
*/
public enum GnMusicIdInfo {
/** If Audio Suitability Processing enabled this information type
* indicates if the received audio is suitable for music identification
* query. If not the query is less likely to return a match.
* This info type is experimental and subject to change.
*/
  kInfoInvalid = 0,

  kInfoSuitableForQuery
}

}
