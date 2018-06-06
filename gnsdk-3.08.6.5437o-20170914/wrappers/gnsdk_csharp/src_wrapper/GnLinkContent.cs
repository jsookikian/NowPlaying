
namespace GracenoteSDK {

/**
* GnLinkContent
*/
public class GnLinkContent : GnByteObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnLinkContent(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnLinkContent_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLinkContent obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLinkContent() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLinkContent(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

      public byte[] DataBuffer
      {
        get
        {
          byte[] dataBytes = new byte[DataSize];
          System.Runtime.InteropServices.Marshal.Copy((System.IntPtr)ContentData, dataBytes, 0, (int)DataSize);
          return dataBytes;
        }
      }
    
  public GnLinkContent(byte[] contentData, uint dataSize, GnLinkContentType contentType, GnLinkDataType dataType) : this(gnsdk_csharp_marshalPINVOKE.new_GnLinkContent(contentData, dataSize, (int)contentType, (int)dataType), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Retrieves content data buffer size
*/
  public uint DataSize {
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnLinkContent_DataSize_get(swigCPtr);
      return ret;
    } 
  }

/**
* Retrieves content data type
*/
  public GnLinkDataType DataType {
    get {
      GnLinkDataType ret = (GnLinkDataType)gnsdk_csharp_marshalPINVOKE.GnLinkContent_DataType_get(swigCPtr);
      return ret;
    } 
  }

  public System.IntPtr ContentData {get{System.IntPtr res = gnsdk_csharp_marshalPINVOKE.GnLinkContent_ContentData_get(swigCPtr); ; return res;}
  }

}

}
