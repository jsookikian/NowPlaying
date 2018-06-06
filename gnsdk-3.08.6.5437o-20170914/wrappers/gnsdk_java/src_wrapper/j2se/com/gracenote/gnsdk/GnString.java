
package com.gracenote.gnsdk;

/** 
* Managed immutable string as returned by GNSDK. 
*/ 
 
public class GnString {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnString(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnString obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnString(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

		public String
		toString( )
		{
			String str = cStr( );
			return str;
		}
	
/** 
* Construct an empty {@link GnString} object 
*/ 
 
  public GnString() {
    this(gnsdk_javaJNI.new_GnString__SWIG_0(), true);
  }

/** 
* Construct a {@link GnString} object from a native constant string 
* @param str [in] Native string 
*/ 
 
  public GnString(String str, long len) {
    this(gnsdk_javaJNI.new_GnString__SWIG_1(str, len), true);
  }

  public GnString(String str) {
    this(gnsdk_javaJNI.new_GnString__SWIG_2(str), true);
  }

/** 
* Construct a {@link GnString} object from an existing {@link GnString} object 
* @param str [in] {@link GnString} object 
*/ 
 
  public GnString(GnString copy) {
    this(gnsdk_javaJNI.new_GnString__SWIG_3(GnString.getCPtr(copy), copy), true);
  }

  public GnString set(GnString other) {
    return new GnString(gnsdk_javaJNI.GnString_set__SWIG_0(swigCPtr, this, GnString.getCPtr(other), other), false);
  }

  public GnString set(String other) {
    return new GnString(gnsdk_javaJNI.GnString_set__SWIG_1(swigCPtr, this, other), false);
  }

  public String cStr() {
    return gnsdk_javaJNI.GnString_cStr(swigCPtr, this);
  }

  public long size() {
    return gnsdk_javaJNI.GnString_size(swigCPtr, this);
  }

/** 
* Get flag indicating if string object contains no string 
* @return True of empty, false otherwise 
*/ 
 
  public boolean isEmpty() {
    return gnsdk_javaJNI.GnString_isEmpty(swigCPtr, this);
  }

/** 
* Internally used factory for special SDK-managed strings. 
* Do not use for strings that do not originate from the GNSDK libraries. 
* This will assume ownership of the SDK-managed string, i.e. the refcount will not be incremented. 
* It is not necessary to release the string manually. 
* @param str	[in] Native string 
* @return Managed string 
*/ 
 
  public static GnString manage(String gnsdk_managed_string) {
    return new GnString(gnsdk_javaJNI.GnString_manage(gnsdk_managed_string), true);
  }

}
