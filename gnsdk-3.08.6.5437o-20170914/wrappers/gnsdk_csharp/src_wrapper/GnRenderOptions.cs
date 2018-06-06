
namespace GracenoteSDK {

/**
* \class GnRenderOptions
* Rendering options (e.g., JSON, XML)
*/
public class GnRenderOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnRenderOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnRenderOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnRenderOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnRenderOptions(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Construct GnRenderOptions object
*/
  public GnRenderOptions() : this(gnsdk_csharp_marshalPINVOKE.new_GnRenderOptions(), true) {
  }

/**
* Specify render format of XML
* @return Render options object
*/
  public GnRenderOptions Xml() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Xml(swigCPtr), false);
    return ret;
  }

/**
* Specify render format of JSON
* @return Render options object
*/
  public GnRenderOptions Json() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Json(swigCPtr), false);
    return ret;
  }

  public GnRenderOptions Standard() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Standard(swigCPtr), false);
    return ret;
  }

/**
* Specify rendered output include Credits
* @return Render options object
*/
  public GnRenderOptions Credits() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Credits(swigCPtr), false);
    return ret;
  }

/**
* Specify rendered output include Sortable information
* @return Render options object
*/
  public GnRenderOptions Sortable() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Sortable(swigCPtr), false);
    return ret;
  }

  public GnRenderOptions SerialGdos() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_SerialGdos(swigCPtr), false);
    return ret;
  }

/**
* Specify rendered output include Product IDs
* @return Render options object
*/
  public GnRenderOptions ProductIds() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_ProductIds(swigCPtr), false);
    return ret;
  }

/**
* Specify rendered output include raw TUIs
* @return Render options object
*/
  public GnRenderOptions RawTuis() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_RawTuis(swigCPtr), false);
    return ret;
  }

/**
* Specify rendered output include Gracenote IDs
* @return Render options object
*/
  public GnRenderOptions GnIds() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_GnIds(swigCPtr), false);
    return ret;
  }

  public GnRenderOptions GnUIds() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_GnUIds(swigCPtr), false);
    return ret;
  }

/**
* Specify rendered output include Genre descriptors for specified level
* @param level	[in] Data level
* @return Render options object
*/
  public GnRenderOptions Genres(GnDataLevel level) {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Genres(swigCPtr, (int)level), false);
    return ret;
  }

  public GnRenderOptions Default() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Default(swigCPtr), false);
    return ret;
  }

  public GnRenderOptions Full() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Full(swigCPtr), false);
    return ret;
  }

  public GnRenderOptions Descriptors() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Descriptors(swigCPtr), false);
    return ret;
  }

/**
* Clear render options
* @return Render options object
*/
  public GnRenderOptions Clear() {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Clear(swigCPtr), false);
    return ret;
  }

/**
* Specify format version of output to render
* @return Render options object
*/
  public GnRenderOptions Version(uint ver) {
    GnRenderOptions ret = new GnRenderOptions(gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Version__SWIG_0(swigCPtr, ver), false);
    return ret;
  }

/**
* Get the format version  
* @return format version setting
*/
  public uint Version() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnRenderOptions_Version__SWIG_1(swigCPtr);
    return ret;
  }

}

}
