
package com.gracenote.gnsdk;

public class GnLookupDatabaseInfo extends GnDataObject {
  private transient long swigCPtr;

  protected GnLookupDatabaseInfo(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnLookupDatabaseInfo_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLookupDatabaseInfo obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLookupDatabaseInfo(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnLookupDatabaseInfo() {
    this(gnsdk_javaJNI.new_GnLookupDatabaseInfo(), true);
  }

}
