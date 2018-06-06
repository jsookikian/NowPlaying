
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitState} 
*/ 
 
public enum GnSubmitState {
 
 
  kSubmitStateUnknown(0),
 
 
  kSubmitStateNothingToDo,
 
 
  kSubmitStateReadyForAudio,
 
 
  kSubmitStateProcessingError,
 
 
  kSubmitStateReadyToUpload,
 
 
  kSubmitStateUploadSucceeded,
 
 
  kSubmitStateUploadPartiallySucceeded,
 
 
  kSubmitStateUploadFailed;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitState swigToEnum(int swigValue) {
    GnSubmitState[] swigValues = GnSubmitState.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitState swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitState.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitState() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitState(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitState(GnSubmitState swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

