
namespace GracenoteSDK {

/**
* Encapsulates information about a GnLocale instance. Used where GNSDK delivers a locale description such as
* iterating the available locales or when querying a GnLocale instance for information.
*/
public class GnLocaleInfo : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLocaleInfo(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLocaleInfo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLocaleInfo() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLocaleInfo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Construct GnLocaleInfo object with default values.
* @param GnLocaleGroup group - locale group
* @param GnLanguage language - locale language
* @param GnRegion region - locale region
* @param GnDescriptor descriptor - locale descriptor
*/
  public GnLocaleInfo(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor) : this(gnsdk_csharp_marshalPINVOKE.new_GnLocaleInfo((int)group, (int)language, (int)region, (int)descriptor), true) {
  }

  public GnDescriptor Descriptor() {
    GnDescriptor ret = (GnDescriptor)gnsdk_csharp_marshalPINVOKE.GnLocaleInfo_Descriptor(swigCPtr);
    return ret;
  }

  public GnLocaleGroup Group {
    get {
      GnLocaleGroup ret = (GnLocaleGroup)gnsdk_csharp_marshalPINVOKE.GnLocaleInfo_Group_get(swigCPtr);
      return ret;
    } 
  }

  public GnDescriptor Langauge {
    get {
      GnDescriptor ret = (GnDescriptor)gnsdk_csharp_marshalPINVOKE.GnLocaleInfo_Langauge_get(swigCPtr);
      return ret;
    } 
  }

  public GnRegion Region {
    get {
      GnRegion ret = (GnRegion)gnsdk_csharp_marshalPINVOKE.GnLocaleInfo_Region_get(swigCPtr);
      return ret;
    } 
  }

  public GnLanguage Language {
    get {
      GnLanguage ret = (GnLanguage)gnsdk_csharp_marshalPINVOKE.GnLocaleInfo_Language_get(swigCPtr);
      return ret;
    } 
  }

}

}
