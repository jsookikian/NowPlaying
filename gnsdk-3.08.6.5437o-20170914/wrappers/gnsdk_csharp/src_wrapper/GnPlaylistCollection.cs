
namespace GracenoteSDK {

/**
* <b>Experimental</b>: Playlist Collection Summary that represents
* the media in a user's collection and can be used to generate
* playlists from that media. A Collection Summary is not intended to be
* used as a general database of the user's media collection.
*
* <b>SDK Documentation</b>
*
* Topic: Implementing Applications (All Platforms) > Discovery Features > Generating a Playlist
*
* For more information on playlist collections, see the above topic which covers:
* <ul>
*     <li>How to generate a playlist</li>
*     <li>Creating a collection summary<ul>
*        <li>Creating a collection summary code samples</li></ul></li>
*     <li>Populating a collection summary<ul>
*         <li>Populating a collection summary code samples</li></ul></li>
*     <li>Retrieving playlist attributes in queries</li>
*     <li>How playlist gathers data</li>
*     <li>Working with local storage<ul>
*         <li>Local storage code samples</li></ul></li>
*    <li>Generating a playlist using 'More Like This'<ul>
*         <li>'More Like This' code samples</li></ul></li>
*    <li>Generating a playlist using PDL (Playlist Description Language)</li>
*    <li>Accessing playlist results<ul>
*         <li>Accessing playlist results code samples</li></ul></li>
*     <li>Working with multiple collection summaries</li>
*     <li>Synchronizing collection summaries</li>
* </ul>
*
* <b>Sample App</b>
*
*     - .../samples/playlist
*
* <b>Overview</b>
*
* Topic:  Concepts > Discovery Features > Playlist
*
*/
public class GnPlaylistCollection : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnPlaylistCollection(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnPlaylistCollection obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnPlaylistCollection() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnPlaylistCollection(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  static private global::System.IntPtr SwigConstructGnPlaylistCollection(string name) {
  System.IntPtr tempname = GnMarshalUTF8.NativeUtf8FromString(name);
    try {
      return gnsdk_csharp_marshalPINVOKE.new_GnPlaylistCollection__SWIG_0(tempname);
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempname);
    }
  }

/**
* Constructor for GnPlaylistCollection using char* string name. This creates the collection with the name that is passed in.
* @param name   The name to be used to construct the colleciton.
*/
  public GnPlaylistCollection(string name) : this(GnPlaylistCollection.SwigConstructGnPlaylistCollection(name), true) {
  }

/**
* Constructor for GnPlaylistCollection using a buffer to deserialize it from  and the corresponding buffer size.
* The collection is created from the passed buffer if it is successfully deserialized.
* @param collData  [in] Buffer that contains the serialized data.
* @param dataSize	[in] Buffer size.
*/
  public GnPlaylistCollection(byte[] collData, uint dataSize) : this(gnsdk_csharp_marshalPINVOKE.new_GnPlaylistCollection__SWIG_1(collData, dataSize), true) {
  }

/**
* Copy Constructor for GnPlaylistCollection.
* @param other  [in] Reference to GnPlaylistCollection that is to be copied.
*/
  public GnPlaylistCollection(GnPlaylistCollection other) : this(gnsdk_csharp_marshalPINVOKE.new_GnPlaylistCollection__SWIG_2(GnPlaylistCollection.getCPtr(other)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Add a identifier with no metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
*/
  public void Add(string mediaIdentifier) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Add__SWIG_0(swigCPtr, tempmediaIdentifier);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Add a GnAlbum object and its metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param album             [in] GnAlbum object
*/
  public void Add(string mediaIdentifier, GnAlbum album) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Add__SWIG_1(swigCPtr, tempmediaIdentifier, GnAlbum.getCPtr(album));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Add a GnTrack object and its metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param track             [in] GnTrack object
*/
  public void Add(string mediaIdentifier, GnTrack track) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Add__SWIG_2(swigCPtr, tempmediaIdentifier, GnTrack.getCPtr(track));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Add a GnContributor object and its metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param contributor       [in] GnContributor object
*/
  public void Add(string mediaIdentifier, GnContributor contributor) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Add__SWIG_3(swigCPtr, tempmediaIdentifier, GnContributor.getCPtr(contributor));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Add a GnPlaylistAttributes object to a Collection Summary.
*
* @param mediaIdentifier       [in] Media identifier
* @param playlistAttributes	[in] Playlist attributes
*/
  public void Add(string mediaIdentifier, GnPlaylistAttributes playlistAttributes) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Add__SWIG_4(swigCPtr, tempmediaIdentifier, GnPlaylistAttributes.getCPtr(playlistAttributes));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Add a GnListElement object to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param listElement       [in] GnListElement object
*/
  public void Add(string mediaIdentifier, GnListElement listElement) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Add__SWIG_5(swigCPtr, tempmediaIdentifier, GnListElement.getCPtr(listElement));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Remove a media element from a Collection Summary.
*
* @param mediaIdentifier  [in] Media identifier
*/
  public void Remove(string mediaIdentifier) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Remove(swigCPtr, tempmediaIdentifier);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Test if a media element is in a Collection Summary.
*
* @param mediaIdentifier  [in] Media identifier
*/
  public bool Contains(string mediaIdentifier) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      bool ret = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Contains(swigCPtr, tempmediaIdentifier);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Find a media element in a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param start				[in] Start ordinal
*/
  public GnPlaylistCollectionIdentEnumerator Find(string mediaIdentifier, uint start) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      GnPlaylistCollectionIdentEnumerator ret = new GnPlaylistCollectionIdentEnumerator(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Find(swigCPtr, tempmediaIdentifier, start), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Return metadata from a playlist using a playlist identifier
*
* @param user             [in] GN User object
* @param mediaIdentifier  [in] Playlist identifier
*/
  public GnPlaylistAttributes Attributes(GnUser user, GnPlaylistIdentifier mediaIdentifier) {
    GnPlaylistAttributes ret = new GnPlaylistAttributes(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Attributes__SWIG_0(swigCPtr, GnUser.getCPtr(user), GnPlaylistIdentifier.getCPtr(mediaIdentifier)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Return attributes from a playlist using a Collection Summary name
*
* @param user             [in] GN User object
* @param mediaIdentifier  [in] Playlist identifier
*/
  public GnPlaylistAttributes Attributes(GnUser user, string mediaIdentifier, string joinedCollectionName) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      GnPlaylistAttributes ret = new GnPlaylistAttributes(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Attributes__SWIG_1(swigCPtr, GnUser.getCPtr(user), tempmediaIdentifier, joinedCollectionName), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

  public GnPlaylistAttributes Attributes(GnUser user, string mediaIdentifier) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      GnPlaylistAttributes ret = new GnPlaylistAttributes(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Attributes__SWIG_2(swigCPtr, GnUser.getCPtr(user), tempmediaIdentifier), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Validate a Playlist Definitioon Statement
* @param pdlStatement	Playlist Definition Statment
* @return Validation result
*/
  public GnError StatementValidate(string pdlStatement) {
  System.IntPtr temppdlStatement = GnMarshalUTF8.NativeUtf8FromString(pdlStatement);
    try {
      GnError ret = new GnError(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_StatementValidate(swigCPtr, temppdlStatement), true);
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temppdlStatement);
    }
  }

/**
* Determine if a Playlist Definition Statement requires a seed
* to generate a playlist
* @param pdlStatement	Playlist Definition Statment
* @return True if a seed is required, false otherwise
*/
  public bool StatementRequiresSeed(string pdlStatement) {
  System.IntPtr temppdlStatement = GnMarshalUTF8.NativeUtf8FromString(pdlStatement);
    try {
      bool ret = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_StatementRequiresSeed(swigCPtr, temppdlStatement);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temppdlStatement);
    }
  }

/**
* <b>Experimental</b>. Analyzes the given PDL Statement as applied to the given media identifier.
* Used for debugging and analyzing playlist generation with PDL statements, this method
* analyzes the given PDL as applied to the given media identifier.
* The output is a formatted logical tree of the PDL statement and the outcome applied
* for each operation.
* For more information on creating PDL Statements consult the PDL Specification.
* @param pdlStatment		PDL Statment being debugged
* @param mediaIdentifier	Unique identifier of a media item within the collection summary
*/
  public GnString StatementAnalyzeIdent(string pdlStatement, string mediaIdentifier) {
  System.IntPtr temppdlStatement = GnMarshalUTF8.NativeUtf8FromString(pdlStatement);
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      GnString ret = new GnString(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_StatementAnalyzeIdent(swigCPtr, temppdlStatement, tempmediaIdentifier), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temppdlStatement);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

/**
* Generate a playlist from a GnDataObject
*
* @param user             [in] Gracenote user
* @param pdlStatement     [in] Playlist Description Language statement
* @param playlistSeed     [in] GN data object to use as seed for playlist
*/
  public GnPlaylistResults GeneratePlaylist(GnUser user, string pdlStatement, GnDataObject playlistSeed) {
  System.IntPtr temppdlStatement = GnMarshalUTF8.NativeUtf8FromString(pdlStatement);
    try {
      GnPlaylistResults ret = new GnPlaylistResults(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_GeneratePlaylist__SWIG_0(swigCPtr, GnUser.getCPtr(user), temppdlStatement, GnDataObject.getCPtr(playlistSeed)), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temppdlStatement);
    }
  }

/**
* Generate a playlist using a Playlist Definition Language (PDL) Statement from this object's Collection Summary.
* For more information on creating PDL Statements consult the PDL Specification.
*
* @param user             [in] Gracenote user
* @param pdlStatement     [in] Playlist Description Language statement
*
*/
  public GnPlaylistResults GeneratePlaylist(GnUser user, string pdlStatement) {
  System.IntPtr temppdlStatement = GnMarshalUTF8.NativeUtf8FromString(pdlStatement);
    try {
      GnPlaylistResults ret = new GnPlaylistResults(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_GeneratePlaylist__SWIG_1(swigCPtr, GnUser.getCPtr(user), temppdlStatement), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temppdlStatement);
    }
  }

/**
* Generate a playlist from a GnDataObject
*
* @param user             [in] Gracenote user
* @param musicDataObj     [in] Gracenote data object
*
*/
  public GnPlaylistResults GenerateMoreLikeThis(GnUser user, GnDataObject musicDataObj) {
    GnPlaylistResults ret = new GnPlaylistResults(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_GenerateMoreLikeThis(swigCPtr, GnUser.getCPtr(user), GnDataObject.getCPtr(musicDataObj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Join a playlist collection by collection name.
*
* @param collectionName   [in] Collection Summary name
*/
  public GnPlaylistCollection JoinFindByName(string collectionName) {
    GnPlaylistCollection ret = new GnPlaylistCollection(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_JoinFindByName(swigCPtr, collectionName), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Join a playlist collection by playlist collection object.
*
* @param toJoin   [in] GnPlaylistCollection object for join
*/
  public void Join(GnPlaylistCollection toJoin) {
    gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Join(swigCPtr, GnPlaylistCollection.getCPtr(toJoin));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Remove a join with another playlist
*
* @param toRemove   [in] GnPlaylistCollection object to remove join
*/
  public void JoinRemove(GnPlaylistCollection toRemove) {
    gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_JoinRemove(swigCPtr, GnPlaylistCollection.getCPtr(toRemove));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Serialize a Collection Summary into buffer
*
* @param serializedData    [out] Buffer to receive serialized data
* @param dataSize          [in]  Buffer size
* @return buffer size
*/
  public uint Serialize(byte[] serializedData, uint dataSize) {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Serialize(swigCPtr, serializedData, dataSize);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Returns the size of a serialized playlist collection object
* @return serialized buffer size
*/
  public uint SerializeSize() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_SerializeSize(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Add an identifier as part of synchronizing a user's media collection with the
* corresponding Collection Summary.
*
* Collection sychronization is a two step process:
*     1)Use this method to add all unique identifiers that currently exist in the user's collection.
*     2) Execute the synchronization process.
* @param mediaIdentifier [in] unique media identifier used in you application e.g. file path
*/
  public void SyncProcessAdd(string mediaIdentifier) {
  System.IntPtr tempmediaIdentifier = GnMarshalUTF8.NativeUtf8FromString(mediaIdentifier);
    try {
      gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_SyncProcessAdd(swigCPtr, tempmediaIdentifier);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempmediaIdentifier);
    }
  }

  public void SyncProcessExecute(GnPlaylistCollectionSyncEventsDelegate syncEvents) {
    gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_SyncProcessExecute(swigCPtr, GnPlaylistCollectionSyncEventsDelegate.getCPtr(syncEvents));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Get object for setting "more like this" options
* @return	More like this options object
*/
  public GnPlaylistMoreLikeThisOptions MoreLikeThisOptions() {
    GnPlaylistMoreLikeThisOptions ret = new GnPlaylistMoreLikeThisOptions(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_MoreLikeThisOptions(swigCPtr), false);
    return ret;
  }

/**
* Get the collection name
* @return Name
*/
  public string Name {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Name_get(swigCPtr) );
	} 

  }

  public GnPlaylistJoinEnumerable Joins {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_Joins_get(swigCPtr);
      GnPlaylistJoinEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnPlaylistJoinEnumerable(cPtr, true);
      return ret;
    } 
  }

  public GnPlaylistCollectionIdentEnumerable MediaIdentifiers {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_MediaIdentifiers_get(swigCPtr);
      GnPlaylistCollectionIdentEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnPlaylistCollectionIdentEnumerable(cPtr, true);
      return ret;
    } 
  }

  public GnPlaylistAttributeEnumerable AttributesSupported {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollection_AttributesSupported_get(swigCPtr);
      GnPlaylistAttributeEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnPlaylistAttributeEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
