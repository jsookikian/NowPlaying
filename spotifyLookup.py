import sys
import spotipy
import spotipy.util as util

# scope = 'user-library-read playlist-read-private playlist-modify-public playlist-modify-private playlist-modify'
# username = ""
# if len(sys.argv) > 1:
#     username = sys.argv[1]
# else:
#     print ("Usage: username search")
#     sys.exit()
# token = util.prompt_for_user_token(username, scope)

scope = 'user-library-read playlist-read-private playlist-modify-public playlist-modify-private playlist-modify'
token = util.prompt_for_user_token('jsookikian', scope)
sp = spotipy.Spotify(auth=token)

x = sp.current_user_recently_played(limit=100000)
y = 1



