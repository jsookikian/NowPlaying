
package com.gracenote.gnsdk;

/** 
* 
*  represents GnCredit's information returned by Gracenote. 
*/ 
 
public class GnCreditEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnCreditEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnCreditEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnCreditEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnCreditEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnCredit gnCredit() {
    return new GnCredit(gnsdk_javaJNI.GnCreditEdit_gnCredit(swigCPtr, this), true);
  }

  public void role(GnListElement roleElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnCreditEdit_role(swigCPtr, this, GnListElement.getCPtr(roleElement), roleElement);
  }

/** 
* 
*  Create an empty object of {@link GnNameEdit} using NAME OFFICIAL. 
*  @return {@link GnNameEdit} 
*/ 
 
  public GnNameEdit name() throws com.gracenote.gnsdk.GnException {
    return new GnNameEdit(gnsdk_javaJNI.GnCreditEdit_name(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnContributorEdit} using CONTRIBUTOR. 
*  @return {@link GnContributorEdit} 
*/ 
 
  public GnContributorEdit contributor() throws com.gracenote.gnsdk.GnException {
    return new GnContributorEdit(gnsdk_javaJNI.GnCreditEdit_contributor(swigCPtr, this), true);
  }

}
