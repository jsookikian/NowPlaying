from record import record
import os
import subprocess
import csv
from recognize import recognize, Track
import datetime
from lastfm import get_lastFM_client, scrobble
import time
# gnsdk-3.08.6.5437o-20170914/wrappers/gnsdk_java/samples/musicid_lookup_album_fpx/
#

def set_timer(duration, offset):
    timer = datetime.datetime.now() + datetime.timedelta(milliseconds=((duration) - (offset) + 5000))

def show_time_left(timer):
    print("Time Left: " + str(timer - datetime.datetime.now()))


def run():
    client = get_lastFM_client()
    timer = datetime.datetime.now()
    while True:
        print("Recording")
        (dbAvg, ret) = record("RECORDING.wav")
        # print ("DbAvg: " + str(dbAvg))
        # track = recognize()
        # if (track is not None):
        #     printTrack(track)
        if (timer < datetime.datetime.now()):
            # track = recognize()
            pass
        else:
            show_time_left()
        if (track != -1 and track is not None):
            print ("Timer Set")
            track.printTrack()
            scrobble(client,track)
            timer = set_timer(track.duration, track.offset)
            track = None


if __name__ == "__main__":
    run()