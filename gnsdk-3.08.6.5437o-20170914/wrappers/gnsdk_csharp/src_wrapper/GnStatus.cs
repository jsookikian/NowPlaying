
namespace GracenoteSDK {

/** @internal GnStatus @endinternal
*  @enum GnStatus
*  Indicates messages that can be received in status callbacks.
* @ingroup StatusCallbacks_TypesEnums
*/
public enum GnStatus {
/** @internal kStatusUnknown @endinternal
* Status unknown.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusUnknown = 0,
/** @internal kStatusBegin @endinternal
* Function call has begun, percentage complete == 0.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusBegin,
/** @internal kStatusProgress @endinternal
* Function call in progress. Issued 10 times per call. Percentage complete range == 1-100.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusProgress,
/** @internal kStatusComplete @endinternal
* Function call is complete.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusComplete,
/** @internal kStatusErrorInfo @endinternal
* Error has occurred, call #gnsdk_manager_error_info().
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusErrorInfo,
/** @internal kStatusConnecting @endinternal
* Connecting to network.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusConnecting,
/** @internal kStatusSending @endinternal
* Uploading.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusSending,
/** @internal kStatusReceiving @endinternal
* Downloading.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusReceiving,
/** @internal kStatusDisconnected @endinternal
* Disconnected from network.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusDisconnected,
/** @internal kStatusReading @endinternal
* Reading from storage.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusReading,
/** @internal kStatusWriting @endinternal
* Writing to storage.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusWriting,
/** @internal kStatusCancelled @endinternal
* Transaction/query is cancelled.
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusCancelled,
/** @internal kStatusCancelCheck @endinternal
* Issued when transaction/query is wating for network operation to complete
* @ingroup StatusCallbacks_TypesEnums
*/
  kStatusCancelCheck
}

}
