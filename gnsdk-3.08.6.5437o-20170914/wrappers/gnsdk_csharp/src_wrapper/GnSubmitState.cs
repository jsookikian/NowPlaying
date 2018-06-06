
namespace GracenoteSDK {

/**
* @enum GnSubmitState
*/
public enum GnSubmitState {

  kSubmitStateUnknown = 0,

  kSubmitStateNothingToDo,

  kSubmitStateReadyForAudio,

  kSubmitStateProcessingError,

  kSubmitStateReadyToUpload,

  kSubmitStateUploadSucceeded,

  kSubmitStateUploadPartiallySucceeded,

  kSubmitStateUploadFailed
}

}
