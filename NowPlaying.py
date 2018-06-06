from record import record
import os
import subprocess
import csv
from recognize2 import recognize, Track, printTrack
import datetime
from pylastfm import LastFM
import time
# gnsdk-3.08.6.5437o-20170914/wrappers/gnsdk_java/samples/musicid_lookup_album_fpx/
#
def run():
    client = LastFM('163804c34c7744d714819cfc6c000ad0', '227fdf084e9f7b75e2902343efacf03f', 'jsook', 'windystar3985!')
    startingVolume = 15
    timer = datetime.datetime.now()
    while True:
        print("Recording")
        (dbAvg, ret) = record("RECORDING.wav")
        # print ("Stereo Volume: " + str(startingVolume) + "DbAvg: " + str(dbAvg))
        # track = recognize()
        # if (track is not None):
        #     printTrack(track)
        if (timer < datetime.datetime.now()):
            track = recognize()
        else:
            print ("Time Left: " + str(timer - datetime.datetime.now()))
        if (track != -1 and track is not None):
            print ("Timer Set")
            printTrack(track)
            client.track.scrobble(artist=track.artist, track=track.title, album=track.album, timestamp=(datetime.datetime.now() - datetime.timedelta(milliseconds=long(track.offset)) + datetime.timedelta(hours=7)))

            timer = datetime.datetime.now() + datetime.timedelta(milliseconds=(long(track.duration) - (long(track.offset) + 5000)))
            track = None
        startingVolume += 2

run()