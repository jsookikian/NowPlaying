
package com.gracenote.gnsdk;

/** 
* Only use the CPU for local fingerprint comparison. 
*/ 
 
public enum GnLocalStreamFingerprintProcessingMethod {
/** 
* Use the GPU (if available) for local fingerprint comparison. The GPU is likely 
* faster than using the CPU, but if your app is doing lots of intense graphics it 
* may cause a "stutter" in displayed graphics. 
*/ 
 
  kLocalStreamFingeprintProcessingInvalid(0),
/** 
* Use CUDA on the GPU (if available) for local fingerprint comparison. The GPU is likely 
* faster than using the CPU, but if your app is doing lots of intense graphics it 
* may cause a "stutter" in displayed graphics. 
*/ 
 
  kLocalStreamFingeprintProcessingUseCPU,
 
 
  kLocalStreamFingeprintProcessingUseGPU,
 
 
  kLocalStreamFingeprintProcessingUseGPU_CUDA;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnLocalStreamFingerprintProcessingMethod swigToEnum(int swigValue) {
    GnLocalStreamFingerprintProcessingMethod[] swigValues = GnLocalStreamFingerprintProcessingMethod.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnLocalStreamFingerprintProcessingMethod swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnLocalStreamFingerprintProcessingMethod.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnLocalStreamFingerprintProcessingMethod() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnLocalStreamFingerprintProcessingMethod(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnLocalStreamFingerprintProcessingMethod(GnLocalStreamFingerprintProcessingMethod swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

