import pyaudio
import wave
import audioop
from array import array
import math
import struct
FORMAT=pyaudio.paInt16
CHANNELS=1
SAMPLE_RATE=44100
CHUNK=1024
RECORD_SECONDS=15
FILE_NAME="RECORDING.wav"

def rms(data):
    count = len(data)/2
    format = "%dh" %(count)
    shorts = struct.unpack(format, data)
    sum_squares = 0.0
    for sample in shorts:
        n = sample * (1.0/32764)
        sum_squares += n*n
    return math.sqrt(sum_squares / count)


def record(filename):
    audio=pyaudio.PyAudio() #instantiate the pyaudio

    #recording prerequisites
    stream=audio.open(format=FORMAT,
                      channels=CHANNELS,
                      rate=SAMPLE_RATE,
                      input=True,
                      frames_per_buffer=CHUNK)

    #starting recording
    frames=[]
    volCount = 0
    dbVal = 0
    for i in range(0,int(RATE/CHUNK*RECORD_SECONDS)):
        data=stream.read(CHUNK)
        data_chunk=array('h',data)
        vol=max(data_chunk)
        rms = audioop.rms(data, 2)
        dbs = 20 * math.log10(rms)
        dbVal += dbs

        # print ("volume: " + str(vol) + "\t" + str(dbs) + " dbs")
        # if(vol>=1500):
        if (dbs > 40):
            volCount += 1
            # print("something said")
            frames.append(data)
        else:
            continue
            # print("nothing")
        # print("\n")
    dbAvg = dbVal / (i+1)
    # print ("volCount: " + str(volCount) + "\tof " + str(i) +"\t" + str((volCount*1.0 // i)) + "%" \
    #        + "\tAvg Db: " + str(dbAvg))
    # if ((volCount // i) > .75):
        # print ("audible noise")
    stream.stop_stream()
    stream.close()
    audio.terminate()
    # writing to file
    wavfile = wave.open(filename, 'wb')
    wavfile.setnchannels(CHANNELS)
    wavfile.setsampwidth(audio.get_sample_size(FORMAT))
    wavfile.setframerate(SAMPLE_RATE)
    wavfile.writeframes(b''.join(frames))  # append frames recorded to file
    wavfile.close()
    return (dbAvg, 1)

    #end of recording


# record("RECORDING.wav")