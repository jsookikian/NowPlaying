
namespace GracenoteSDK {

/**
* @enum GnRhythmEvent
* Used with the GnRhythmStation::Event method to influence to contents of Rhythm Playlists
*/
public enum GnRhythmEvent {
/** @internal GNSDK_RHYTHM_EVENT_TRACK_PLAYED @endinternal
*
*  Indicate that the track should be marked as played.
*  Moves the play queue (drops track being played and adds additional track to end of queue)
* @ingroup Music_Rhythm_TypesEnums
*/
  kRhythmEventTrackPlayed = 1,
/** @internal GNSDK_RHYTHM_EVENT_TRACK_SKIPPED @endinternal
*
*  Indicate that the track should be marked as skipped.
*  Moves the play queue (drops track being played and adds additional track to end of queue)
* @ingroup Music_Rhythm_TypesEnums
*/
  kRhythmEventTrackSkipped,
/** @internal GNSDK_RHYTHM_EVENT_TRACK_LIKE @endinternal
*
*  Indicate that the track should be marked as liked
*  Does not move the playlist queue.
* @ingroup Music_Rhythm_TypesEnums
*/
  kRhythmEventTrackLike,
/** @internal GNSDK_RHYTHM_EVENT_TRACK_DISLIKE @endinternal
*
*  Indicate that the track should be marked as disliked
*  Refreshes the playlist queue.
* @ingroup Music_Rhythm_TypesEnums
*/
  kRhythmEventTrackDislike,
/** @internal GNSDK_RHYTHM_EVENT_ARTIST_LIKE @endinternal
*
*  Indicate that the artist should be marked as like
*  Does not move the playlist queue.
* @ingroup Music_Rhythm_TypesEnums
*/
  kRhythmEventArtistLike,
/** @internal GNSDK_RHYTHM_EVENT_ARTIST_DISLIKE @endinternal
*
*  Indicate that the artist should be marked as disliked
*  Refreshes the playlist queue.
* @ingroup Music_Rhythm_TypesEnums
*/
  kRhythmEventArtistDislike
}

}
