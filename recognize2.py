import os
import subprocess
import csv

class Track:
    def __init__(self, title, artist, album, offset, duration, trackNumber):
        self.title = title
        self.artist = artist
        self.album = album
        self.offset = offset
        self.duration = duration
        self.trackNumber = trackNumber

def recognize():
    curdir = os.getcwd()
    print ("Recognizing...")
    os.chdir("gnsdk-3.08.6.5437o-20170914/wrappers/gnsdk_java/samples/musicid_lookup_album_fpx/");
    # os.system('java -cp "../../../../wrappers/gnsdk_java/jar/j2se/gnsdk.jar:../../../../wrappers/gnsdk_java/jar/j2se/gnsdk_helpers.jar:../../../../xtralibs/:." -Djava.library.path=. musicid_lookup_album_fpx/MusicIDLookupAlbumFPX    ../../../../lib/mac_x86-64 ')
    os.system("make run")
    os.chdir(curdir)
    ret = None
    artist = track = album = duration = offset = trackNumber = None
    with open("./gnsdk-3.08.6.5437o-20170914/wrappers/gnsdk_java/samples/musicid_lookup_album_fpx/metadata.csv", 'r') as csvfile:
        csvreader = csv.reader(csvfile, delimiter=";")
        for row in csvreader:
            artist = row[0]
            track = row[1]
            album = row[2]
            offset = row[3]
            duration = row[4]
            trackNumber = row[5]

    if artist != "None":

        return Track(track, artist, album, offset, duration, trackNumber)
    else:
        return ret


    print ("Current directory: " + os.getcwd())

#
    #  recognize()

def printTrack(track):
    print ("Track Number: " + track.trackNumber)
    print ("Title: " + track.title)
    print ("Artist: " + track.artist)
    print ("Album: " + track.album)
    print ("Offset " + track.offset)
    print ("Duration: " + track.duration)