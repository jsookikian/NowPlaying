
namespace GracenoteSDK {

/**
* Collection of data match results received in response to a data match query.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  .../docs/html-oo > index.html > Data Models
*
*  The above topic displays all the metadata returned from a recognition event.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/
public class GnResponseDataMatches : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnResponseDataMatches(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnResponseDataMatches obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnResponseDataMatches() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnResponseDataMatches(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static string GnType() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_GnType();
    return ret;
  }

  public static GnResponseDataMatches From(GnDataObject obj) {
    GnResponseDataMatches ret = new GnResponseDataMatches(gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_From(GnDataObject.getCPtr(obj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Result count - number of matches returned
*  @return Count
*/
  public uint ResultCount() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_ResultCount(swigCPtr);
    return ret;
  }

/**
*  Range start - ordinal value of first match in range total
*  @return Range start
*/
  public uint RangeStart() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_RangeStart(swigCPtr);
    return ret;
  }

/**
*  Range end - ordinal value of last match in range total
*  @return Range end
*/
  public uint RangeEnd() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_RangeEnd(swigCPtr);
    return ret;
  }

/**
*  Range total - total number of matches that could be returned
*  @return Range total
*/
  public uint RangeTotal() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_RangeTotal(swigCPtr);
    return ret;
  }

/**
*  Flag indicating if response needs user or app decision - either multiple matches returned or less than perfect single match
*  @return True is user decision needed, false otherwise
*/
  public bool NeedsDecision() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_NeedsDecision(swigCPtr);
    return ret;
  }

  public GnDataMatchEnumerable DataMatches {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnResponseDataMatches_DataMatches_get(swigCPtr);
      GnDataMatchEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnDataMatchEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
