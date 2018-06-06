
package com.gracenote.gnsdk;

/** 
*  @enum {@link GnStatus} 
*  Indicates messages that can be received in status callbacks. 
* 
*/ 
 
public enum GnStatus {
/** 
* Status unknown. 
* 
*/ 
 
  kStatusUnknown(0),
/** 
* Function call has begun, percentage complete == 0. 
* 
*/ 
 
  kStatusBegin,
/** 
* Function call in progress. Issued 10 times per call. Percentage complete range == 1-100. 
* 
*/ 
 
  kStatusProgress,
/** 
* Function call is complete. 
* 
*/ 
 
  kStatusComplete,
/** 
* Error has occurred, call #gnsdk_manager_error_info(). 
* 
*/ 
 
  kStatusErrorInfo,
/** 
* Connecting to network. 
* 
*/ 
 
  kStatusConnecting,
/** 
* Uploading. 
* 
*/ 
 
  kStatusSending,
/** 
* Downloading. 
* 
*/ 
 
  kStatusReceiving,
/** 
* Disconnected from network. 
* 
*/ 
 
  kStatusDisconnected,
/** 
* Reading from storage. 
* 
*/ 
 
  kStatusReading,
/** 
* Writing to storage. 
* 
*/ 
 
  kStatusWriting,
/** 
* Transaction/query is cancelled. 
* 
*/ 
 
  kStatusCancelled,
/** 
* Issued when transaction/query is wating for network operation to complete 
* 
*/ 
 
  kStatusCancelCheck;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnStatus swigToEnum(int swigValue) {
    GnStatus[] swigValues = GnStatus.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnStatus swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnStatus.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnStatus() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnStatus(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnStatus(GnStatus swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

