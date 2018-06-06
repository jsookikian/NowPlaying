
package com.gracenote.gnsdk;

/** 
* @enum {@link GnFingerprintType} 
* Fingerprint algorithm type. 
*/ 
 
public enum GnFingerprintType {
/** 
* Invalid fingerprint type 
*/ 
 
  kFingerprintTypeInvalid(0),
/** 
* Specifies a fingerprint data type for generating MusicID-File fingerprints. 
* <p><b>Remarks:</b></p> 
* A file's beginning 16 seconds are used for a MusicID-File fingerprint. 
* <p><b>Note:</b></p> 
* Do NOT submit only 16 seconds of a file - your 
* application must submit data until the GNSDK indicates it has received enough input. 
* Use this fingerprint type when identifying audio from a file source (MusicID-File). 
*/ 
 
  kFingerprintTypeFile,
/** 
*  Specifies a fingerprint used for identifying a ~3-second audio stream excerpt. 
*  Use this when identifying a continuous stream of audio data and when retrieving 
*  Track Match Position values. The fingerprint represents a 
*  specific audio stream point in time. 
*  <p><b>Note:</b></p> 
*  Do NOT submit only 3 seconds of audio data - your 
*  application must submit audio data until the GNSDK indicates it has received enough input. 
*  You must use this fingerprint, or its 6-second counterpart, to get results containing match position. 
*  The usage of this type of fingerprint must be configured to your specific User ID, otherwise queries 
*  of this type will not succeed. 
*/ 
 
  kFingerprintTypeStream3,
/** 
*  Specifies a fingerprint used for identifying a ~6-second audio stream excerpt. 
*  This is the same as kFingerprintTypeStream3, but requires more audio data to generate, 
*  which can be more accurate. 
*  For additional information, see kFingerprintTypeStream3. 
*/ 
 
  kFingerprintTypeStream6,
/** 
*  Specifies a fingerprint to identify an audio stream. 
*  The usage of this type of fingerprint must be configured to your specific User ID, otherwise queries 
*  of this type will not succeed. 
*/ 
 
  kFingerprintTypeStreamFP,
/** 
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release. 
*      Use kFingerprintTypeFile instead. 
*/ 
 
  kFingerprintTypeCMX,
/** 
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release. 
*      Use kFingerprintTypeStream3 or kFingerprintTypeStream6 instead. 
*/ 
 
  kFingerprintTypeGNFPX;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnFingerprintType swigToEnum(int swigValue) {
    GnFingerprintType[] swigValues = GnFingerprintType.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnFingerprintType swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnFingerprintType.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnFingerprintType() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnFingerprintType(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnFingerprintType(GnFingerprintType swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

