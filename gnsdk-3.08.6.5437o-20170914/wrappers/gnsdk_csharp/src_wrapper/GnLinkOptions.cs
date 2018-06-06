
namespace GracenoteSDK {

public class GnLinkOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLinkOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLinkOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLinkOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLinkOptions(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/** Set this link query lookup mode.
* @param lookupMode		Lookup mode
* @ingroup Link_Options
*/
  public void LookupMode(GnLookupMode lookupMode) {
    gnsdk_csharp_marshalPINVOKE.GnLinkOptions_LookupMode(swigCPtr, (int)lookupMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Explicitly identifies the track of interest by its ordinal number. This option takes precedence
*   over any provided by track indicator.
*  @ingroup Link_Options
*/
  public void TrackOrdinal(uint number) {
    gnsdk_csharp_marshalPINVOKE.GnLinkOptions_TrackOrdinal(swigCPtr, number);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  This option sets the source provider of the content (for example, "Acme").
*  @ingroup Link_Options
*/
  public void DataSource(string datasource) {
    gnsdk_csharp_marshalPINVOKE.GnLinkOptions_DataSource(swigCPtr, datasource);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  This option sets the type of the provider content (for example, "cover").
*  @ingroup Link_Options
*/
  public void DataType(string datatype) {
    gnsdk_csharp_marshalPINVOKE.GnLinkOptions_DataType(swigCPtr, datatype);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup Link_Options
*/
  public void NetworkInterface(string intfName) {
    gnsdk_csharp_marshalPINVOKE.GnLinkOptions_NetworkInterface__SWIG_0(swigCPtr, intfName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Return network interface being use with this object's connections if one has been set. 
* If no specific network interface has been set this option will return an empty string.
*  @ingroup Link_Options
*/
  public string NetworkInterface() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnLinkOptions_NetworkInterface__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Clears all options currently set for a given Link query.
*  <p><b>Remarks:</b></p>
*  As Link query handles can be used to retrieve multiple enhanced data items, it may be appropriate
*   to specify different options between data retrievals. You can use this function to clear all options
*   before setting new ones.
*  @ingroup Link_Options
*/
  public void Clear() {
    gnsdk_csharp_marshalPINVOKE.GnLinkOptions_Clear(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
