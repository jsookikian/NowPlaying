
namespace GracenoteSDK {

/**
* <b>Experimental</b>: GnMoodgrid
*
*  The GnMoodgrid class allows applications to generate playlists and user interfaces based on Gracenote Mood descriptors.
*
* <b>SDK Documentation</b>
*
* Topic: Implementing Applications (All Platforms) > Discovery Features > Implementing Moodgrid
*
* For more information on using GnMoodgrid, see the above topic which covers:
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
*
* <b>Sample App</b>
*
*     - .../samples/moodgrid
*
* <b>Overiew</b>
*
* Topic: Concepts > Discovery Features > Mood Overview
*/
public class GnMoodgrid : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgrid(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgrid obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgrid() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgrid(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnMoodgrid() : this(gnsdk_csharp_marshalPINVOKE.new_GnMoodgrid(), true) {
  }

/**
* Creates a Presentation that represents the type of moodgrid layout to  generate recommendations for. A presentation
* object is the way to access all Mood names and recommendations supported by its layout.
* @param user [in] : valid user
* @param type [in] : enum value representing the Presentation type .
* @param coordinate [in] : enum value representing the coordinate type for the presentation layout.
* @return presentation.
*/
  public GnMoodgridPresentation CreatePresentation(GnUser user, GnMoodgridPresentationType type, GnMoodgridCoordinateType coordinate) {
    GnMoodgridPresentation ret = new GnMoodgridPresentation(gnsdk_csharp_marshalPINVOKE.GnMoodgrid_CreatePresentation(swigCPtr, GnUser.getCPtr(user), (int)type, (int)coordinate), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Retrieves a data point representing the dimensions of the presentation e.g. 5,5
* @return datapoint.
*/
  public GnMoodgridDataPoint Dimensions(GnMoodgridPresentationType type) {
    GnMoodgridDataPoint ret = new GnMoodgridDataPoint(gnsdk_csharp_marshalPINVOKE.GnMoodgrid_Dimensions(swigCPtr, (int)type), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Version information for the library
* @return version
*/
  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMoodgrid_Version_get(swigCPtr) );
	} 

  }

/**
* Build Date for the library
* @return build date
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMoodgrid_BuildDate_get(swigCPtr) );
	} 

  }

  public GnMoodgridProviderEnumerable Providers {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnMoodgrid_Providers_get(swigCPtr);
      GnMoodgridProviderEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnMoodgridProviderEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
