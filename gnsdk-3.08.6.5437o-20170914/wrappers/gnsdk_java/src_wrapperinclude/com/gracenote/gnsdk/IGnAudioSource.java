package com.gracenote.gnsdk;

/** 
* Delegate interface for retrieving audio data from a raw audio source such as a microphone, audio file, 
* or Internet stream. 
* <p> 
* A number of Gracenote methods consume audio data from audio sources without requiring your application to 
* manually pass the data. Using these can simplify your application's implementation. They also allow for 
* hot fixes that don't require an entire release cycle. 
* <p> 
* These methods/consumers currently include: 
* <p> 
*  <p>// Generate a fingerprint using the audio from a raw audio source</p> 
*  void GnMusicId::FingerprintFromSource(IGnAudioSource& audioSource, {@link GnFingerprintType} fpType) throw (GnError); 
* <p> 
*  <p>// Find albums using the audio from a raw audio source</p> 
*  metadata::GnResponseAlbums GnMusicId::FindAlbums(IGnAudioSource& audioSource, {@link GnFingerprintType} fpType) throw (GnError); 
* <p> 
* <p>// Add a fingerprint to the file information used to identify a track, album, or library</p> 
*  void GnMusicIdFileInfo::FingerprintFromSource(IGnAudioSource& audioSource) throw (GnError); 
* <p> 
*  <p>// Process the audio stream provided by the raw audio source for identification</p> 
*  void GnMusicIdStream::AudioProcessStart(IGnAudioSource& audioSource) throw (GnError); 
* <p> 
* You are encouraged to implement your own audio source object if, for example, your application 
* requires a custom audio file format. 
* <p> 
* Note that for some platforms (e.g., iOS and Android), Gracenote provides the {@link GnMic} helper class 
* that implements the {@link IGnAudioSource} interface to retrive audio. If available, your application can use this class to process 
* streaming audio from a device microphone. Gracenote for Mobile also provides a {@link GnAudioFile} delegate for reading raw 
* audio from encoded audio files. 
* <p> 
* <b>SDK Documentation</b> 
* <p> 
* Topic: .../docs/html-oo > start_here.html > "Implementing Applications..." > Identifying Music > Identifying Streaming Music (MusicID-Stream ) 
* <p> 
* See this topic for more information on implementing an {@link IGnAudioSource} interface. 
*/ 
 
public interface IGnAudioSource {

/** 
* Initialize the audio source. This is invoked prior to any other methods. If initialization 
* fails a non-zero value is returned. In this case the consumer will not call any other methods 
* including that to close the audio source. 
* @return 0 indicates initialization was successful, non-zero otherwise. 
*/ 
 
  	public long sourceInit();

/** 
* Close the audio source. The consumer will not call any other methods after the source has 
* been closed 
*/ 
 
  	public void sourceClose();

/** 
* Return the source audio format's samples per second. Return zero if called 
* prior to SourceInit. 
* @return Samples per second 
*/ 
 
  	public long samplesPerSecond();

/** 
* Return the source audio format's number of bits in a sample. Return zero if called 
* prior to SourceInit. 
* @return Sample size in bits 
*/ 
 
  	public long sampleSizeInBits();

/** 
* Return the source audio format's number of channels. Return zero if called 
* prior to SourceInit. 
* @return Number of channels 
*/ 
 
  	public long numberOfChannels();

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
 
  	public long getData(java.nio.ByteBuffer dataBuffer, long dataSize);
  	
}
