
package com.gracenote.gnsdk;

/** 
* <b>Experimental</b>: {@link GnMoodgrid} 
* <p> 
*  The {@link GnMoodgrid} class allows applications to generate playlists and user interfaces based on Gracenote Mood descriptors. 
* <p> 
* <b>SDK Documentation</b> 
* <p> 
* Topic: Implementing Applications (All Platforms) > Discovery Features > Implementing Moodgrid 
* <p> 
* For more information on using {@link GnMoodgrid}, see the above topic which covers: 
* <ul> 
*     <li>Implementing Moodgrid in an application</li> 
*     <li>Enumerating data sources using Mood providers<ul> 
*     <li>Code samples for enumerating data sources</li></ul></li> 
*     <li>Creating and populating a Mood presentation<ul> 
*     <li>Code samples for creating and populating a Mood presentation</li></ul></li> 
*     <li>Iterating through a Mood presentation<ul> 
*     <li>Code samples for iterating through a Mood presentation</li></ul></li> 
*     <li>Filtering mood results<ul> 
*     <li>Code samples for filtering mood results</li></ul></li> 
* </ul> 
* <p> 
* <b>Sample App</b> 
* <p> 
*     - .../samples/moodgrid 
* <p> 
* <b>Overiew</b> 
* <p> 
* Topic: Concepts > Discovery Features > Mood Overview 
*/ 
 
public class GnMoodgrid {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMoodgrid(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMoodgrid obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMoodgrid(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnMoodgrid() {
    this(gnsdk_javaJNI.new_GnMoodgrid(), true);
  }

/** 
* Version information for the library 
* @return version 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnMoodgrid_version();
  }

/** 
* Build Date for the library 
* @return build date 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnMoodgrid_buildDate();
  }

/** 
* Enumeration of all providers currently available for the moodgrid. 
* @return iterable container of moodgrid providers. 
*/ 
 
  public GnMoodgridProviderIterable providers() {
    return new GnMoodgridProviderIterable(gnsdk_javaJNI.GnMoodgrid_providers(swigCPtr, this), true);
  }

/** 
* Creates a Presentation that represents the type of moodgrid layout to  generate recommendations for. A presentation 
* object is the way to access all Mood names and recommendations supported by its layout. 
* @param user [in] : valid user 
* @param type [in] : enum value representing the Presentation type . 
* @param coordinate [in] : enum value representing the coordinate type for the presentation layout. 
* @return presentation. 
*/ 
 
  public GnMoodgridPresentation createPresentation(GnUser user, GnMoodgridPresentationType type, GnMoodgridCoordinateType coordinate) throws com.gracenote.gnsdk.GnException {
    return new GnMoodgridPresentation(gnsdk_javaJNI.GnMoodgrid_createPresentation(swigCPtr, this, GnUser.getCPtr(user), user, type.swigValue(), coordinate.swigValue()), true);
  }

/** 
* Retrieves a data point representing the dimensions of the presentation e.g. 5,5 
* @return datapoint. 
*/ 
 
  public GnMoodgridDataPoint dimensions(GnMoodgridPresentationType type) throws com.gracenote.gnsdk.GnException {
    return new GnMoodgridDataPoint(gnsdk_javaJNI.GnMoodgrid_dimensions(swigCPtr, this, type.swigValue()), true);
  }

}
