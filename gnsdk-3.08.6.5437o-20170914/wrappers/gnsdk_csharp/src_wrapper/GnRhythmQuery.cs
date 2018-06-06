
namespace GracenoteSDK {

/**
* \class GnRhythmQuery
* Provides services for generating Rhythm Recommendations
*/
public class GnRhythmQuery : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnRhythmQuery(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnRhythmQuery obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnRhythmQuery() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnRhythmQuery(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Constructs a Rhythm query object with a Gracenote user and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicId request
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/
  public GnRhythmQuery(GnUser user, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnRhythmQuery__SWIG_0(GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnRhythmQuery(GnUser user) : this(gnsdk_csharp_marshalPINVOKE.new_GnRhythmQuery__SWIG_1(GnUser.getCPtr(user)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Adds a Seed to the GnRhythmQuery object.
*  @param seed			[in] GnDataObject to be used as seed, can be a GnTrack, GnAlbum, or GnArtist object
*/
  public void AddSeed(GnDataObject seed) {
    gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_AddSeed(swigCPtr, GnDataObject.getCPtr(seed));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Generates a set of recommendations based on seeds set into the query handle.
*  @return An instance of GnResponseAlbums, response contains one Album per Recommended Track.
*  <p><b>Remarks:</b></p>
*  The Matched Track on each Album in the GnResponseAlbums is the Recommended Track
*/
  public GnResponseAlbums GenerateRecommendations(GnRhythmFilter filter) {
    GnResponseAlbums ret = new GnResponseAlbums(gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_GenerateRecommendations__SWIG_0(swigCPtr, GnRhythmFilter.getCPtr(filter)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Generates a set of recommendations based on seeds set into the query handle.
*  @return An instance of GnResponseAlbums, response contains one Album per Recommended Track.
*  <p><b>Remarks:</b></p>
*  The Matched Track on each Album in the GnResponseAlbums is the Recommended Track
*/
  public GnResponseAlbums GenerateRecommendations() {
    GnResponseAlbums ret = new GnResponseAlbums(gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_GenerateRecommendations__SWIG_1(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Get the event handler provided on construction
* @return Event handler
*/
  public GnStatusEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_EventHandler(swigCPtr);
    GnStatusEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnStatusEventsDelegate(cPtr, false);
    return ret;
  }

/**
* Get GnRhythmQuery options object. Use to configure your GnRhythmQuery instance.
* @return Options object
*/
  public GnRhythmQueryOptions Options() {
    GnRhythmQueryOptions ret = new GnRhythmQueryOptions(gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_Options(swigCPtr), false);
    return ret;
  }

/**
* Set cancel state
* @param bCancel   [in] Cancel state
*/
  public virtual void SetCancel(bool bCancel) {
    gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_SetCancel(swigCPtr, bCancel);
  }

/**
* Get cancel state.
* @return Cancel state
*/
  public virtual bool IsCancelled() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnRhythmQuery_IsCancelled(swigCPtr);
    return ret;
  }

}

}
