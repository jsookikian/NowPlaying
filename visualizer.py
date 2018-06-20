import struct
import numpy as np
import pyaudio

FORMAT=pyaudio.paInt16
CHANNELS=1
SAMPLE_RATE=44100
CHUNK=1024
RECORD_SECONDS=15
BINS=8
SCALE=200
EXPONENT=.5

def analyze(data, width, sample_rate, bins):
    # Convert raw sound data to Numpy array
    fmt = "%dH" % (len(data) / 2)
    data2 = struct.unpack(fmt, data)
    data2 = np.array(data2, dtype='h')

    # FFT black magic
    fourier = np.fft.fft(data2)
    ffty = np.abs(fourier[0:len(fourier) / 2]) / 1000
    ffty1 = ffty[:len(ffty) / 2]
    ffty2 = ffty[len(ffty) / 2::] + 2
    ffty2 = ffty2[::-1]
    ffty = ffty1 + ffty2
    ffty = np.log(ffty) - 2

    fourier = list(ffty)[4:-4]
    fourier = fourier[:len(fourier) / 2]

    size = len(fourier)

    # Split into desired number of frequency bins
    levels = [sum(fourier[i:(i + size / bins)]) for i in xrange(0, size, size / bins)][:bins]

    return levels

p = pyaudio.PyAudio()
stream = p.open(format=FORMAT,
                 channels=CHANNELS,
                 rate=SAMPLE_RATE,
                 input=True,
                 frames_per_buffer=CHUNK)



def step(amt=1):
        data = stream.read(CHUNK)
        levels = analyze(data, CHUNK, SAMPLE_RATE, BINS)
        # scale to [0,100]
        for i in range(self.bins):
                levels[i] = max(min((levels[i] * 1.0) / SCALE, 1.0), 0.0)
                levels[i] = levels[i] ** EXPONENT
                levels[i] = int(levels[i] * 255)
        print
        levels
        for i in range(self._led.numLEDs):
                self._led.set(i, (levels[0], levels[0], levels[0]))

                # Increment the internal step by the given amount
        self._step += amt