#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os, sys
import pprint
import json
import spotifyLookup
from acrcloud.recognizer import ACRCloudRecognizer
pp = pprint.PrettyPrinter(indent=2)
class Track:
    def __init__(self, title, artist, album, offset, duration):
        self.title = title
        self.artist = artist
        self.album = album
        self.offset = offset
        self.duration = duration


def recognize(file):
    config = {
        'host':'identify-us-west-2.acrcloud.com',
        'access_key':'4dcc4050a44fd6bc03e72ccd90cc0393',
        'access_secret':'Hb8FxFc6Kdj5VaW6DS2SemiCe49lLAN3MXTR4k2A',
        'timeout':10 # seconds
    }

    '''This module can recognize ACRCloud by most of audio/video file.
        Audio: mp3, wav, m4a, flac, aac, amr, ape, ogg ...
        Video: mp4, mkv, wmv, flv, ts, avi ...'''
    re = ACRCloudRecognizer(config)

    #recognize by file path, and skip 0 seconds from from the beginning of sys.argv[1].
    # re.recognize_by_file(sys.argv[1], 0)

    buf = open(file, 'rb').read()
    #recognize by file_audio_buffer that read from file path, and skip 0 seconds from from the beginning of sys.argv[1].
    result = json.loads(re.recognize_by_filebuffer(buf, 0))
    if (result['status']['code'] != 1001):
        data = result['metadata']['music'][0]

        play_offset_ms = data['play_offset_ms']
        duration_ms = data['duration_ms']
        title = data['title']
        artist = data['artists'][0]['name']
        album = data['album']['name']

        print('Title: ' + data['title'])
        print('Artist: ' + data['artists'][0]['name'])
        print("Time Left: " + str((duration_ms - play_offset_ms) *1.0 / 1000.0))
        if ('spotify' in data['external_metadata']):
            if  ('name' in data['external_metadata']['spotify']['album']):
                album = data['external_metadata']['spotify']['album']['name']
            if ('id' in data['external_metadata']['spotify']['album']):
                spotifyId = data['external_metadata']['spotify']['album']['id']
            remasterIndex = data['album']['name'].find('[')
        # if (remasterIndex > 0):
        #     print('Album: ' + data['album']['name'][:remasterIndex])
        # else:
        #     print('Album: ' + data['album']['name'])
        print('Album: ' + album)
        return Track(title, artist, album, play_offset_ms, duration_ms)

    else:
        print ("Music not playing")
    # spotifyLookup.search(spotifyId)

# recognize("RECORDING.wav")