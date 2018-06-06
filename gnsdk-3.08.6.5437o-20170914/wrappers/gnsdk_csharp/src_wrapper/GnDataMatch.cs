
namespace GracenoteSDK {

/**
*  Represents a match to query where any type of match is desired, album or contributor.
*/
public class GnDataMatch : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnDataMatch(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnDataMatch_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnDataMatch obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnDataMatch() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnDataMatch(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
*  Flag indicating if match is album
*  @return True if album is a match, false otherwise
*/
  public bool IsAlbum() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnDataMatch_IsAlbum(swigCPtr);
    return ret;
  }

/**
*  Flag indicating if match is contributor
*  @return True if result is a contributor, false otherwise
*/
  public bool IsContributor() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnDataMatch_IsContributor(swigCPtr);
    return ret;
  }

/**
*  If album, get match as album object
*  @return Album
*/
  public GnAlbum GetAsAlbum() {
    GnAlbum ret = new GnAlbum(gnsdk_csharp_marshalPINVOKE.GnDataMatch_GetAsAlbum(swigCPtr), true);
    return ret;
  }

/**
*  Flag indicating if response contains full (true) or partial (false) metadata.
*  @return True if full result, false if partial result
* <p><b>Note:</b></p>
*   What constitutes a full result varies among the individual response types and results, and also
*  depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/
  public bool IsFullResult() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnDataMatch_IsFullResult(swigCPtr);
    return ret;
  }

/**
*  If contributor, get match as contributor object
*  @return Contributor
*/
  public GnContributor GetAsContributor() {
    GnContributor ret = new GnContributor(gnsdk_csharp_marshalPINVOKE.GnDataMatch_GetAsContributor(swigCPtr), true);
    return ret;
  }

}

}
