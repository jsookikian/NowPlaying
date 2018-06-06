
namespace GracenoteSDK {

/**
* @enum GnUserRegisterMode
* Gracenote user registration mode
*/
public enum GnUserRegisterMode {
/**
* Register a user via a netowrk connection with Gracenote Service. A user
* must be registered online before any online queries can be made against the
* Gracenote Service.
*/
  kUserRegisterModeOnline = 1,
/**
* Register a user for local use only. Users registered locally can only
* perform queries against local databases and not against the Gracenote
* Service.
*/
  kUserRegisterModeLocalOnly
}

}
