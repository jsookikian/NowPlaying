
namespace GracenoteSDK {

/**
* Managed immutable string as returned by GNSDK.
*/
public class GnString : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnString(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnString obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnString() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnString(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

		public override string
		ToString( )
		{
			string str = c_str( );
			return str;
		}
	
/**
* Construct an empty GnString object
*/
  public GnString() : this(gnsdk_csharp_marshalPINVOKE.new_GnString__SWIG_0(), true) {
  }

/**
* Construct a GnString object from a native constant string
* @param str [in] Native string
*/
  public GnString(string str, uint len) : this(gnsdk_csharp_marshalPINVOKE.new_GnString__SWIG_1(str, len), true) {
  }

  public GnString(string str) : this(gnsdk_csharp_marshalPINVOKE.new_GnString__SWIG_2(str), true) {
  }

/**
* Construct a GnString object from an existing GnString object
* @param str [in] GnString object
*/
  public GnString(GnString copy) : this(gnsdk_csharp_marshalPINVOKE.new_GnString__SWIG_3(GnString.getCPtr(copy)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public string c_str() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnString_c_str(swigCPtr);
    return ret;
  }

  public uint size() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnString_size(swigCPtr);
    return ret;
  }

/**
* Get flag indicating if string object contains no string
* @return True of empty, false otherwise
*/
  public bool IsEmpty() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnString_IsEmpty(swigCPtr);
    return ret;
  }

/**
* Internally used factory for special SDK-managed strings.
* Do not use for strings that do not originate from the GNSDK libraries.
* This will assume ownership of the SDK-managed string, i.e. the refcount will not be incremented.
* It is not necessary to release the string manually.
* @param str	[in] Native string
* @return Managed string
*/
  public static GnString manage(string gnsdk_managed_string) {
    GnString ret = new GnString(gnsdk_csharp_marshalPINVOKE.GnString_manage(gnsdk_managed_string), true);
    return ret;
  }

}

}
