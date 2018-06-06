
package com.gracenote.gnsdk;

/** 
* 	@enum {@link GnLookupData} 
* Types of data that can be delivered in a search response 
*/ 
 
public enum GnLookupData {
/** 
* Invalid lookup data 
*/ 
 
  kLookupDataInvalid(0),
/** 
* Response should include data for use in fetching content (like images). 
* <p><b>Remarks:</b></p> 
* Your application's client ID must be entitled to retrieve this specialized data. See your 
*	Gracenote representative for more information. 
*/ 
 
  kLookupDataContent,
/** 
* Response should include any associated classical music data. 
* <p><b>Remarks:</b></p> 
* Your application's license must be entitled to retrieve this specialized data. See your 
* Gracenote representative for more information. 
*/ 
 
  kLookupDataClassical,
/** 
* Response should include any associated sonic attribute data. 
* <p><b>Remarks:</b></p> 
* Your application's license must be entitled to retrieve this specialized data. See your 
* Gracenote representative for more information. 
*/ 
 
  kLookupDataSonicData,
/** 
* Response should include associated attribute data for GNSDK Playlist. 
* <p><b>Remarks:</b></p> 
* Your application's license must be entitled to retrieve this specialized data. See your 
* Gracenote representative for more information. 
*/ 
 
  kLookupDataPlaylist,
/** 
* Response should include external IDs (third-party IDs). 
* <p><b>Remarks:</b></p> 
* External IDs are third-party IDs associated with the results (such as an Amazon ID), 
*	configured specifically for your application. 
* Your application's client ID must be entitled to retrieve this specialized data. See your 
* Gracenote representative for more information. 
* External IDs can be retrieved from applicable query response objects. 
*/ 
 
  kLookupDataExternalIds,
/** 
* Response should include global IDs. 
*/ 
 
  kLookupDataGlobalIds,
/** 
* Response should include additional credits. 
*/ 
 
  kLookupDataAdditionalCredits,
/** 
* Response should include sortable data for names and titles 
*/ 
 
  kLookupDataSortable;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnLookupData swigToEnum(int swigValue) {
    GnLookupData[] swigValues = GnLookupData.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnLookupData swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnLookupData.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnLookupData() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnLookupData(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnLookupData(GnLookupData swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

