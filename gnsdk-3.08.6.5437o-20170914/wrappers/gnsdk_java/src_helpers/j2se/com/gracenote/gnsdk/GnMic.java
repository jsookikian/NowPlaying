/*
 * Copyright (c) 2000-2017 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

package com.gracenote.gnsdk;

import java.nio.ByteBuffer;

import javax.sound.sampled.*;

/**
 * Uses Java audio system to retrieve raw audio from the microphone. 
 * Warning! JVM support for microphones is spotty across operating systems, so the Java 
 * audio system, and therefore GnMic, are not a reliable ways to access the microphone in 
 * an application intended to support multiple platforms. Gracenote does not recommend
 * using this class in such applications.
 * If you have a custom solution for accessing the microphone, such as a custom native
 * library with JNI interface, you can create your own GnMic equivalent that can plug
 * directly in to GNSDK APIs. To do this simply have your microphone class implement 
 * the IGnAudioSource interface.
 */
public class GnMic implements IGnAudioSource {

	TargetDataLine 	microphone;
	
	public GnMic(){
		
	}

	/**
	 * Initializes the microphone by first checking if a microphone line is supported and
	 * if it is obtaining its target data line.
	 * @return Zero if successful, non-zero otherwise
	 */
	@Override
	public long sourceInit() {
		
		// check if microphone is supported at all
		// Note: check your platforms for appropriate method
		// of checking microphone
		if (AudioSystem.isLineSupported(Port.Info.MICROPHONE) == false) {
		    System.err.println("Microphone not supported");
		    return 1;
		}
		
		// find the mixer that has microphone, save its info
		Mixer.Info microphoneMixerInfo = null;
		Mixer.Info[] mixerInfos = AudioSystem.getMixerInfo();
		for (Mixer.Info info: mixerInfos){
			if ( AudioSystem.getMixer(info).isLineSupported(Port.Info.MICROPHONE) ) {
				microphoneMixerInfo = info;
				break;
			}
		}
		if ( microphoneMixerInfo == null ) {
			System.err.println("Microphone mixer not found");
			return 1;
		}
		
		AudioFormat format = new AudioFormat(8000.0f, 16, 1, true, true);
		try {
			microphone = AudioSystem.getTargetDataLine(format, microphoneMixerInfo);
			microphone.open();
			microphone.start();
		} catch (LineUnavailableException e) {
			System.err.println("Error opening microphone mixer target data line: " + e.getMessage());
			e.printStackTrace();
			return 1;
		}
		
		return 0;
	}

	/**
	 * Closes the microphone target data line
	 */
	@Override
	public void sourceClose() {
		microphone.stop();
		microphone.close();
		microphone = null;
	}

	@Override
	public long samplesPerSecond() {
		return (long)microphone.getFormat().getSampleRate();
	}

	@Override
	public long sampleSizeInBits() {
		return (long)microphone.getFormat().getSampleSizeInBits();
	}

	@Override
	public long numberOfChannels() {
		return (long)microphone.getFormat().getChannels();
	}

	/**
	 * Reads data from the microphone target data line and copies it to the provided
	 * buffer
	 * @param dataBuffer	Buffer to copy raw audio data ti
	 * @param datSize		Size of dataBuffer
	 * @return Number of bytes copied in to dataBuffer
	 */
	@Override
	public long getData(ByteBuffer dataBuffer, long dataSize) {
		
		byte[] buffer = new byte[(int)dataSize];
		int bytesRead = 0;
		
		bytesRead = microphone.read(buffer, 0, (int)dataSize);
		
		dataBuffer.put(buffer);
		
		System.out.println("bytesRead = " + bytesRead);
		return bytesRead;
	}
	
}
