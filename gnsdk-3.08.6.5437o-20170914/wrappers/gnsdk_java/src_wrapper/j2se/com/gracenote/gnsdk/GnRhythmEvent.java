
package com.gracenote.gnsdk;

/** 
* @enum {@link GnRhythmEvent} 
* Used with the GnRhythmStation::Event method to influence to contents of Rhythm Playlists 
*/ 
 
public enum GnRhythmEvent {
/** 
* <p> 
*  Indicate that the track should be marked as played. 
*  Moves the play queue (drops track being played and adds additional track to end of queue) 
* 
*/ 
 
  kRhythmEventTrackPlayed(1),
/** 
* <p> 
*  Indicate that the track should be marked as skipped. 
*  Moves the play queue (drops track being played and adds additional track to end of queue) 
* 
*/ 
 
  kRhythmEventTrackSkipped,
/** 
* <p> 
*  Indicate that the track should be marked as liked 
*  Does not move the playlist queue. 
* 
*/ 
 
  kRhythmEventTrackLike,
/** 
* <p> 
*  Indicate that the track should be marked as disliked 
*  Refreshes the playlist queue. 
* 
*/ 
 
  kRhythmEventTrackDislike,
/** 
* <p> 
*  Indicate that the artist should be marked as like 
*  Does not move the playlist queue. 
* 
*/ 
 
  kRhythmEventArtistLike,
/** 
* <p> 
*  Indicate that the artist should be marked as disliked 
*  Refreshes the playlist queue. 
* 
*/ 
 
  kRhythmEventArtistDislike;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnRhythmEvent swigToEnum(int swigValue) {
    GnRhythmEvent[] swigValues = GnRhythmEvent.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnRhythmEvent swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnRhythmEvent.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnRhythmEvent() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnRhythmEvent(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnRhythmEvent(GnRhythmEvent swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

