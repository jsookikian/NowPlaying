
namespace GracenoteSDK {

/**
* Delegate interface for retrieving audio data from a raw audio source such as a microphone, audio file,
* or Internet stream.
*
* A number of Gracenote methods consume audio data from audio sources without requiring your application to
* manually pass the data. Using these can simplify your application's implementation. They also allow for
* hot fixes that don't require an entire release cycle.
*
* These methods/consumers currently include:
*
*  <p>// Generate a fingerprint using the audio from a raw audio source</p>
*  void GnMusicId::FingerprintFromSource(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError);
*
*  <p>// Find albums using the audio from a raw audio source</p>
*  metadata::GnResponseAlbums GnMusicId::FindAlbums(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError);
*
* <p>// Add a fingerprint to the file information used to identify a track, album, or library</p>
*  void GnMusicIdFileInfo::FingerprintFromSource(IGnAudioSource& audioSource) throw (GnError);
*
*  <p>// Process the audio stream provided by the raw audio source for identification</p>
*  void GnMusicIdStream::AudioProcessStart(IGnAudioSource& audioSource) throw (GnError);
*
* You are encouraged to implement your own audio source object if, for example, your application
* requires a custom audio file format.
*
* Note that for some platforms (e.g., iOS and Android), Gracenote provides the GnMic helper class
* that implements the IGnAudioSource interface to retrive audio. If available, your application can use this class to process
* streaming audio from a device microphone. Gracenote for Mobile also provides a GnAudioFile delegate for reading raw
* audio from encoded audio files.
*
* <b>SDK Documentation</b>
*
* Topic: .../docs/html-oo > start_here.html > "Implementing Applications..." > Identifying Music > Identifying Streaming Music (MusicID-Stream )
*
* See this topic for more information on implementing an IGnAudioSource interface.
*/
public class IGnAudioSource : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IGnAudioSource(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IGnAudioSource obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~IGnAudioSource() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_IGnAudioSource(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Initialize the audio source. This is invoked prior to any other methods. If initialization
* fails a non-zero value is returned. In this case the consumer will not call any other methods
* including that to close the audio source.
* @return 0 indicates initialization was successful, non-zero otherwise.
*/
  public virtual uint SourceInit() {
    uint ret = gnsdk_csharp_marshalPINVOKE.IGnAudioSource_SourceInit(swigCPtr);
    return ret;
  }

/**
* Close the audio source. The consumer will not call any other methods after the source has
* been closed
*/
  public virtual void SourceClose() {
    gnsdk_csharp_marshalPINVOKE.IGnAudioSource_SourceClose(swigCPtr);
  }

/**
* Return the source audio format's samples per second. Return zero if called
* prior to SourceInit.
* @return Samples per second
*/
  public virtual uint SamplesPerSecond() {
    uint ret = gnsdk_csharp_marshalPINVOKE.IGnAudioSource_SamplesPerSecond(swigCPtr);
    return ret;
  }

/**
* Return the source audio format's number of bits in a sample. Return zero if called
* prior to SourceInit.
* @return Sample size in bits
*/
  public virtual uint SampleSizeInBits() {
    uint ret = gnsdk_csharp_marshalPINVOKE.IGnAudioSource_SampleSizeInBits(swigCPtr);
    return ret;
  }

/**
* Return the source audio format's number of channels. Return zero if called
* prior to SourceInit.
* @return Number of channels
*/
  public virtual uint NumberOfChannels() {
    uint ret = gnsdk_csharp_marshalPINVOKE.IGnAudioSource_NumberOfChannels(swigCPtr);
    return ret;
  }

/**
* Get audio data from the audio source. This is a blocking call that does
* not return until data is available.
* When data is available, this method must
* copy data to the provided buffer ensuring not to overflow it. The number of bytes
* copied to the buffer is returned.
* To signal the audio source is unable to deliver any more data return zero. The
* consumer will then stop requesting data and close the audio source.
* @param dataBuffer 	[out] Buffer to receive audio data
* @param dataSize 		[in]  Size in bytes of buffer
* @return Number of bytes copied to the buffer. Return zero to indicate
* 		   no more data can be delivered via the audio source.
*/
  public virtual uint GetData(byte[] dataBuffer, uint dataSize) {
    uint ret = gnsdk_csharp_marshalPINVOKE.IGnAudioSource_GetData(swigCPtr, dataBuffer, dataSize);
    return ret;
  }

  public IGnAudioSource() : this(gnsdk_csharp_marshalPINVOKE.new_IGnAudioSource(), true) {
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("SourceInit", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateIGnAudioSource_0(SwigDirectorSourceInit);
    if (SwigDerivedClassHasMethod("SourceClose", swigMethodTypes1))
      swigDelegate1 = new SwigDelegateIGnAudioSource_1(SwigDirectorSourceClose);
    if (SwigDerivedClassHasMethod("SamplesPerSecond", swigMethodTypes2))
      swigDelegate2 = new SwigDelegateIGnAudioSource_2(SwigDirectorSamplesPerSecond);
    if (SwigDerivedClassHasMethod("SampleSizeInBits", swigMethodTypes3))
      swigDelegate3 = new SwigDelegateIGnAudioSource_3(SwigDirectorSampleSizeInBits);
    if (SwigDerivedClassHasMethod("NumberOfChannels", swigMethodTypes4))
      swigDelegate4 = new SwigDelegateIGnAudioSource_4(SwigDirectorNumberOfChannels);
    if (SwigDerivedClassHasMethod("GetData", swigMethodTypes5))
      swigDelegate5 = new SwigDelegateIGnAudioSource_5(SwigDirectorGetData);
    gnsdk_csharp_marshalPINVOKE.IGnAudioSource_director_connect(swigCPtr, swigDelegate0, swigDelegate1, swigDelegate2, swigDelegate3, swigDelegate4, swigDelegate5);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(IGnAudioSource));
    return hasDerivedMethod;
  }

  private uint SwigDirectorSourceInit() {
    return SourceInit();
  }

  private void SwigDirectorSourceClose() {
    SourceClose();
  }

  private uint SwigDirectorSamplesPerSecond() {
    return SamplesPerSecond();
  }

  private uint SwigDirectorSampleSizeInBits() {
    return SampleSizeInBits();
  }

  private uint SwigDirectorNumberOfChannels() {
    return NumberOfChannels();
  }

  private uint SwigDirectorGetData(byte[] dataBuffer, uint dataSize) {
 byte[] tempdataBuffer = dataBuffer;
    try {
      return GetData(tempdataBuffer, dataSize);
    } finally {
 
    }
  }

  public delegate uint SwigDelegateIGnAudioSource_0();
  public delegate void SwigDelegateIGnAudioSource_1();
  public delegate uint SwigDelegateIGnAudioSource_2();
  public delegate uint SwigDelegateIGnAudioSource_3();
  public delegate uint SwigDelegateIGnAudioSource_4();
  public delegate uint SwigDelegateIGnAudioSource_5(byte[] dataBuffer, uint dataSize);

  private SwigDelegateIGnAudioSource_0 swigDelegate0;
  private SwigDelegateIGnAudioSource_1 swigDelegate1;
  private SwigDelegateIGnAudioSource_2 swigDelegate2;
  private SwigDelegateIGnAudioSource_3 swigDelegate3;
  private SwigDelegateIGnAudioSource_4 swigDelegate4;
  private SwigDelegateIGnAudioSource_5 swigDelegate5;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes1 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes2 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes3 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes4 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes5 = new global::System.Type[] { typeof(byte[]), typeof(uint) };
}

}
