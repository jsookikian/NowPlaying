from pylastfm import LastFM
import datetime

def get_lastFM_client():
    return LastFM('163804c34c7744d714819cfc6c000ad0', '227fdf084e9f7b75e2902343efacf03f', 'jsook', 'windystar3985!')


def scrobble(client, track):
    client.track.scrobble(artist=track.artist, track=track.title, album=track.album, timestamp=(datetime.datetime.now() - datetime.timedelta(milliseconds=(track.offset)) + datetime.timedelta(hours=7)))
