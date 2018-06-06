
package com.gracenote.gnsdk;

/************************************************************************** 
** {@link GnRhythmFilter} class 
*/ 
 
public class GnRhythmFilter {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnRhythmFilter(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnRhythmFilter obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnRhythmFilter(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnRhythmFilter() throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnRhythmFilter(), true);
  }

/** 
*  Set option using list element handle 
*  @param list_element_handle   [in] element handle 
*/ 
 
  public void custom(GnListElement listElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnRhythmFilter_custom(swigCPtr, this, GnListElement.getCPtr(listElement), listElement);
  }

}
