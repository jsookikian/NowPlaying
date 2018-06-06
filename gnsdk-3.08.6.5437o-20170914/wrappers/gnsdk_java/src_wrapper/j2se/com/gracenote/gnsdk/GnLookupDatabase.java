
package com.gracenote.gnsdk;

public class GnLookupDatabase {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnLookupDatabase(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLookupDatabase obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLookupDatabase(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/**  
* Open Local Database - database is a set of related gracenote storages. This call will create new or open 
* existing database based on configuration given. 
* @param identifier [in] Local Database identifier  
* @param config [in] {@link GnConfig} object 
*/ 
 
  public GnLookupDatabase(String identifier, GnConfig config) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnLookupDatabase(identifier, GnConfig.getCPtr(config), config), true);
  }

/**  
* Add record to database.  
* @param db_identifier [in] database identifer  
* @param album			[in] {@link GnAlbum} object 
*/ 
 
  public void addRecord(GnAlbum album) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupDatabase_addRecord__SWIG_0(swigCPtr, this, GnAlbum.getCPtr(album), album);
  }

/**  
* Add record to database.  
* @param db_identifier [in] database identifer  
* @param contributor	[in] {@link GnContributor} object 
*/ 
 
  public void addRecord(GnContributor contributor) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupDatabase_addRecord__SWIG_1(swigCPtr, this, GnContributor.getCPtr(contributor), contributor);
  }

  public void addImage(byte[] image_buffer, long image_buffer_size, GnAsset asset) {
    gnsdk_javaJNI.GnLookupDatabase_addImage(swigCPtr, this, image_buffer, image_buffer_size, GnAsset.getCPtr(asset), asset);
  }

/**  
* Get databse size. 
* @return - database size in bytes 
*/ 
 
  public java.math.BigInteger size() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupDatabase_size(swigCPtr, this);
  }

/**  
* Get databse info. 
* @return - {@link GnDataObject} with DB information 
*/ 
 
  public GnLookupDatabaseInfo info() throws com.gracenote.gnsdk.GnException {
    return new GnLookupDatabaseInfo(gnsdk_javaJNI.GnLookupDatabase_info(swigCPtr, this), true);
  }

/**  
* Close lookup local database - will wait if any threads have outstanding queries with this database.   
* If this API is not called, all open databases will be closed on when {@link GnManager} object goes out of scope. 
* @param db_identifier [in] database identifer  
*/ 
 
  public void close() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupDatabase_close(swigCPtr, this);
  }

/** 
* Deletes the local database files.  Database must be closed before calling this method. 
* Note that only lookup related GDB files are deleted. 
* @param config [in] {@link GnConfig} object - database configuration.  
*/ 
 
  public static void delete(GnConfig config) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupDatabase_delete(GnConfig.getCPtr(config), config);
  }

}
