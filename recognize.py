import os
import subprocess
import csv
import xmltodict

class Track:
    def __init__(self, title, artist, album, offset, duration, trackNumber):
        self.title = title
        self.artist = artist
        self.album = album
        self.offset = offset
        self.duration = duration
        self.trackNumber = trackNumber

    def printTrack(self):
        print("Track Number: " + str(self.trackNumber))
        print("Title: " + self.title)
        print("Artist: " + self.artist)
        print("Album: " + self.album)
        print("Offset " + str(self.offset))
        print("Duration: " + str(self.duration))

def run_gracenote_recognize():
    curdir = os.getcwd()
    os.chdir("gnsdk-3.08.6.5437o-20170914/samples/musicid_lookup_album_fpx/");
    os.system("make");
    os.system("./sample licfile.txt");
    os.chdir(curdir)

def get_track_from_xml():
    ret = None

    with open("./gnsdk-3.08.6.5437o-20170914/samples/musicid_lookup_album_fpx/track.xml", "r") as trackFile:
        content = trackFile.read()
        xml = xmltodict.parse(content)
        track_ord = int(xml['ALBUM_RESPONSE']['ALBUM'][0]['TRACK_MATCHED'])
        artist = xml['ALBUM_RESPONSE']['ALBUM'][0]['ARTIST']['NAME_OFFICIAL']['DISPLAY']
        track = xml['ALBUM_RESPONSE']['ALBUM'][0]['TRACK'][track_ord-1]['TITLE_OFFICIAL']['DISPLAY']
        offset = int(xml['ALBUM_RESPONSE']['ALBUM'][0]['TRACK'][track_ord- 1]['MATCH_DURATION'])  + \
                 int(xml['ALBUM_RESPONSE']['ALBUM'][0]['TRACK'][track_ord - 1]['MATCH_POSITION'])
        duration = int(xml['ALBUM_RESPONSE']['ALBUM'][0]['TRACK'][track_ord- 1]['DURATION']['#text'])
        album =  xml['ALBUM_RESPONSE']['ALBUM'][0]['TITLE_OFFICIAL']['DISPLAY']
    if artist != "None":
        return Track(track, artist, album, offset, duration, track_ord)
    else:
        return ret


def recognize():
    print ("Recognizing...")
    run_gracenote_recognize()
    return get_track_from_xml()


