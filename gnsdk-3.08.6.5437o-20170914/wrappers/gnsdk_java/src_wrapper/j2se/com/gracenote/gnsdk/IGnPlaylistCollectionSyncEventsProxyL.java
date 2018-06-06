/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

class IGnPlaylistCollectionSyncEventsProxyL {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected IGnPlaylistCollectionSyncEventsProxyL(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(IGnPlaylistCollectionSyncEventsProxyL obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_IGnPlaylistCollectionSyncEventsProxyL(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  protected void swigDirectorDisconnect() {
    swigCMemOwn = false;
    delete();
  }

  protected void swigReleaseOwnership() {
    swigCMemOwn = false;
    gnsdk_javaJNI.IGnPlaylistCollectionSyncEventsProxyL_change_ownership(this, swigCPtr, false);
  }

  protected void swigTakeOwnership() {
    swigCMemOwn = true;
    gnsdk_javaJNI.IGnPlaylistCollectionSyncEventsProxyL_change_ownership(this, swigCPtr, true);
  }

    private long getCancellerCPtrFromCancellable(IGnCancellable cancellable) {
    	if ( cancellable instanceof IGnCancellableProxy ){
    		IGnCancellableProxy canceller = (IGnCancellableProxy)cancellable;
    		return IGnCancellableProxy.getCPtr(canceller);
    	}
    	return 0;
    }

  public void onUpdate(GnPlaylistCollection collection, GnPlaylistIdentifier identifier, GnPlaylistEventsIdentiferStatus status, IGnCancellable canceller) {
IGnCancellableProxy iGnCanceller = (canceller instanceof IGnCancellableProxy)?(IGnCancellableProxy)canceller:null;
    {
      gnsdk_javaJNI.IGnPlaylistCollectionSyncEventsProxyL_onUpdate(swigCPtr, this, GnPlaylistCollection.getCPtr(collection), collection, GnPlaylistIdentifier.getCPtr(identifier), identifier, status.swigValue(), getCancellerCPtrFromCancellable(canceller), iGnCanceller);
    }
  }

  public IGnPlaylistCollectionSyncEventsProxyL() {
    this(gnsdk_javaJNI.new_IGnPlaylistCollectionSyncEventsProxyL(), true);
    gnsdk_javaJNI.IGnPlaylistCollectionSyncEventsProxyL_director_connect(this, swigCPtr, swigCMemOwn, true);
  }

}
