
namespace GracenoteSDK {

public class GnLookupDatabase : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLookupDatabase(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLookupDatabase obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLookupDatabase() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLookupDatabase(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/** 
* Open Local Database - database is a set of related gracenote storages. This call will create new or open
* existing database based on configuration given.
* @param identifier [in] Local Database identifier 
* @param config [in] GnConfig object
*/
  public GnLookupDatabase(string identifier, GnConfig config) : this(gnsdk_csharp_marshalPINVOKE.new_GnLookupDatabase(identifier, GnConfig.getCPtr(config)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/** 
* Add record to database. 
* @param db_identifier [in] database identifer 
* @param album			[in] GnAlbum object
*/
  public void AddRecord(GnAlbum album) {
    gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_AddRecord__SWIG_0(swigCPtr, GnAlbum.getCPtr(album));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/** 
* Add record to database. 
* @param db_identifier [in] database identifer 
* @param contributor	[in] GnContributor object
*/
  public void AddRecord(GnContributor contributor) {
    gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_AddRecord__SWIG_1(swigCPtr, GnContributor.getCPtr(contributor));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Add image to database. 
* @param db_identifier [in] database identifer 
* @param buffer		 [in] image buffer
* @param buffer_size	 [in] image buffer size in bytes
* @param asset_gdo	 [in] asset gracenote data object to add
*/
  public void AddImage(byte[] image_buffer, uint image_buffer_size, GnAsset asset) {
    gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_AddImage(swigCPtr, image_buffer, image_buffer_size, GnAsset.getCPtr(asset));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public ulong Size() {
    ulong ret = gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_Size(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/** 
* Get databse info.
* @return - GnDataObject with DB information
*/
  public GnLookupDatabaseInfo Info() {
    GnLookupDatabaseInfo ret = new GnLookupDatabaseInfo(gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_Info(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/** 
* Close lookup local database - will wait if any threads have outstanding queries with this database.  
* If this API is not called, all open databases will be closed on when GnManager object goes out of scope.
* @param db_identifier [in] database identifer 
*/
  public void Close() {
    gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_Close(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Deletes the local database files.  Database must be closed before calling this method.
* Note that only lookup related GDB files are deleted.
* @param config [in] GnConfig object - database configuration. 
*/
  public static void Delete(GnConfig config) {
    gnsdk_csharp_marshalPINVOKE.GnLookupDatabase_Delete(GnConfig.getCPtr(config));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
