
package com.gracenote.gnsdk;

/** 
* <b>Experimental</b>: Playlist Collection Summary that represents 
* the media in a user's collection and can be used to generate 
* playlists from that media. A Collection Summary is not intended to be 
* used as a general database of the user's media collection. 
* <p> 
* <b>SDK Documentation</b> 
* <p> 
* Topic: Implementing Applications (All Platforms) > Discovery Features > Generating a Playlist 
* <p> 
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
* <p> 
* <b>Sample App</b> 
* <p> 
*     - .../samples/playlist 
* <p> 
* <b>Overview</b> 
* <p> 
* Topic:  Concepts > Discovery Features > Playlist 
* <p> 
*/ 
 
public class GnPlaylistCollection {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylistCollection(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistCollection obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistCollection(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  private IGnPlaylistCollectionSyncEvents elementReference;
  private IGnPlaylistCollectionSyncEventsProxyU syncEventsProxy;
  private long getNewSyncEventsCPtr(IGnPlaylistCollectionSyncEvents element) {
    elementReference = element;
    syncEventsProxy = new IGnPlaylistCollectionSyncEventsProxyU(element);
    return IGnPlaylistCollectionSyncEventsProxyL.getCPtr(syncEventsProxy);
  }

/** 
* Constructor for {@link GnPlaylistCollection} using char* string name. This creates the collection with the name that is passed in. 
* @param name   The name to be used to construct the colleciton. 
*/ 
 
  public GnPlaylistCollection(String name) {
    this(gnsdk_javaJNI.new_GnPlaylistCollection__SWIG_0(name), true);
  }

  public GnPlaylistCollection(byte[] collData, long dataSize) {
    this(gnsdk_javaJNI.new_GnPlaylistCollection__SWIG_1(collData, dataSize), true);
  }

/** 
* Copy Constructor for {@link GnPlaylistCollection}. 
* @param other  [in] Reference to {@link GnPlaylistCollection} that is to be copied. 
*/ 
 
  public GnPlaylistCollection(GnPlaylistCollection other) {
    this(gnsdk_javaJNI.new_GnPlaylistCollection__SWIG_2(GnPlaylistCollection.getCPtr(other), other), true);
  }

/** 
* Get the collection name 
* @return Name 
*/ 
 
  public String name() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_name__SWIG_0(swigCPtr, this);
  }

/** 
* Change the collection name 
* @param updatedName	New collection name 
*/ 
 
  public void name(String updatedName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_name__SWIG_1(swigCPtr, this, updatedName);
  }

/** 
* Add a identifier with no metadata to a Collection Summary. 
* <p> 
* @param mediaIdentifier   [in] Media identifier 
*/ 
 
  public void add(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_0(swigCPtr, this, mediaIdentifier);
  }

/** 
* Add a {@link GnAlbum} object and its metadata to a Collection Summary. 
* <p> 
* @param mediaIdentifier   [in] Media identifier 
* @param album             [in] {@link GnAlbum} object 
*/ 
 
  public void add(String mediaIdentifier, GnAlbum album) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_1(swigCPtr, this, mediaIdentifier, GnAlbum.getCPtr(album), album);
  }

/** 
* Add a {@link GnTrack} object and its metadata to a Collection Summary. 
* <p> 
* @param mediaIdentifier   [in] Media identifier 
* @param track             [in] {@link GnTrack} object 
*/ 
 
  public void add(String mediaIdentifier, GnTrack track) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_2(swigCPtr, this, mediaIdentifier, GnTrack.getCPtr(track), track);
  }

/** 
* Add a {@link GnContributor} object and its metadata to a Collection Summary. 
* <p> 
* @param mediaIdentifier   [in] Media identifier 
* @param contributor       [in] {@link GnContributor} object 
*/ 
 
  public void add(String mediaIdentifier, GnContributor contributor) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_3(swigCPtr, this, mediaIdentifier, GnContributor.getCPtr(contributor), contributor);
  }

/** 
* Add a {@link GnPlaylistAttributes} object to a Collection Summary. 
* <p> 
* @param mediaIdentifier       [in] Media identifier 
* @param playlistAttributes	[in] Playlist attributes 
*/ 
 
  public void add(String mediaIdentifier, GnPlaylistAttributes playlistAttributes) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_4(swigCPtr, this, mediaIdentifier, GnPlaylistAttributes.getCPtr(playlistAttributes), playlistAttributes);
  }

/** 
* Add a {@link GnListElement} object to a Collection Summary. 
* <p> 
* @param mediaIdentifier   [in] Media identifier 
* @param listElement       [in] {@link GnListElement} object 
*/ 
 
  public void add(String mediaIdentifier, GnListElement listElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_5(swigCPtr, this, mediaIdentifier, GnListElement.getCPtr(listElement), listElement);
  }

/** 
* Remove a media element from a Collection Summary. 
* <p> 
* @param mediaIdentifier  [in] Media identifier 
*/ 
 
  public void remove(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_remove(swigCPtr, this, mediaIdentifier);
  }

/** 
* Test if a media element is in a Collection Summary. 
* <p> 
* @param mediaIdentifier  [in] Media identifier 
*/ 
 
  public boolean contains(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_contains(swigCPtr, this, mediaIdentifier);
  }

/** 
* Find a media element in a Collection Summary. 
* <p> 
* @param mediaIdentifier   [in] Media identifier 
* @param start				[in] Start ordinal 
*/ 
 
  public GnPlaylistCollectionIdentIterator find(String mediaIdentifier, long start) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistCollectionIdentIterator(gnsdk_javaJNI.GnPlaylistCollection_find(swigCPtr, this, mediaIdentifier, start), true);
  }

/** 
* Return metadata from a playlist using a playlist identifier 
* <p> 
* @param user             [in] GN User object 
* @param mediaIdentifier  [in] Playlist identifier 
*/ 
 
  public GnPlaylistAttributes attributes(GnUser user, GnPlaylistIdentifier mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistAttributes(gnsdk_javaJNI.GnPlaylistCollection_attributes__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, GnPlaylistIdentifier.getCPtr(mediaIdentifier), mediaIdentifier), true);
  }

/** 
* Return attributes from a playlist using a Collection Summary name 
* <p> 
* @param user             [in] GN User object 
* @param mediaIdentifier  [in] Playlist identifier 
*/ 
 
  public GnPlaylistAttributes attributes(GnUser user, String mediaIdentifier, String joinedCollectionName) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistAttributes(gnsdk_javaJNI.GnPlaylistCollection_attributes__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user, mediaIdentifier, joinedCollectionName), true);
  }

  public GnPlaylistAttributes attributes(GnUser user, String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistAttributes(gnsdk_javaJNI.GnPlaylistCollection_attributes__SWIG_2(swigCPtr, this, GnUser.getCPtr(user), user, mediaIdentifier), true);
  }

/** 
* Validate a Playlist Definitioon Statement 
* @param pdlStatement	Playlist Definition Statment 
* @return Validation result 
*/ 
 
  public GnError statementValidate(String pdlStatement) {
    return new GnError(gnsdk_javaJNI.GnPlaylistCollection_statementValidate(swigCPtr, this, pdlStatement), true);
  }

/** 
* Determine if a Playlist Definition Statement requires a seed 
* to generate a playlist 
* @param pdlStatement	Playlist Definition Statment 
* @return True if a seed is required, false otherwise 
*/ 
 
  public boolean statementRequiresSeed(String pdlStatement) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_statementRequiresSeed(swigCPtr, this, pdlStatement);
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
 
  public GnString statementAnalyzeIdent(String pdlStatement, String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnPlaylistCollection_statementAnalyzeIdent(swigCPtr, this, pdlStatement, mediaIdentifier), true);
  }

/** 
* Generate a playlist from a {@link GnDataObject} 
* <p> 
* @param user             [in] Gracenote user 
* @param pdlStatement     [in] Playlist Description Language statement 
* @param playlistSeed     [in] GN data object to use as seed for playlist 
*/ 
 
  public GnPlaylistResults generatePlaylist(GnUser user, String pdlStatement, GnDataObject playlistSeed) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistResults(gnsdk_javaJNI.GnPlaylistCollection_generatePlaylist__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, pdlStatement, GnDataObject.getCPtr(playlistSeed), playlistSeed), true);
  }

/** 
* Generate a playlist using a Playlist Definition Language (PDL) Statement from this object's Collection Summary. 
* For more information on creating PDL Statements consult the PDL Specification. 
* <p> 
* @param user             [in] Gracenote user 
* @param pdlStatement     [in] Playlist Description Language statement 
* <p> 
*/ 
 
  public GnPlaylistResults generatePlaylist(GnUser user, String pdlStatement) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistResults(gnsdk_javaJNI.GnPlaylistCollection_generatePlaylist__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user, pdlStatement), true);
  }

/** 
* Generate a playlist from a {@link GnDataObject} 
* <p> 
* @param user             [in] Gracenote user 
* @param musicDataObj     [in] Gracenote data object 
* <p> 
*/ 
 
  public GnPlaylistResults generateMoreLikeThis(GnUser user, GnDataObject musicDataObj) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistResults(gnsdk_javaJNI.GnPlaylistCollection_generateMoreLikeThis(swigCPtr, this, GnUser.getCPtr(user), user, GnDataObject.getCPtr(musicDataObj), musicDataObj), true);
  }

/** 
*  Returns an iterable container for all the playlist attributes this collection supports. 
* <p> 
*/ 
 
  public GnPlaylistAttributeIterable attributesSupported() {
    return new GnPlaylistAttributeIterable(gnsdk_javaJNI.GnPlaylistCollection_attributesSupported(swigCPtr, this), true);
  }

  public GnPlaylistCollectionIdentIterable mediaIdentifiers() {
    return new GnPlaylistCollectionIdentIterable(gnsdk_javaJNI.GnPlaylistCollection_mediaIdentifiers(swigCPtr, this), true);
  }

/** 
*  Returns an iterable container for all the joined collections. 
* <p> 
*/ 
 
  public GnPlaylistJoinIterable joins() {
    return new GnPlaylistJoinIterable(gnsdk_javaJNI.GnPlaylistCollection_joins(swigCPtr, this), true);
  }

/** 
* Join a playlist collection by collection name. 
* <p> 
* @param collectionName   [in] Collection Summary name 
*/ 
 
  public GnPlaylistCollection joinFindByName(String collectionName) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistCollection(gnsdk_javaJNI.GnPlaylistCollection_joinFindByName(swigCPtr, this, collectionName), true);
  }

/** 
* Join a playlist collection by playlist collection object. 
* <p> 
* @param toJoin   [in] {@link GnPlaylistCollection} object for join 
*/ 
 
  public void join(GnPlaylistCollection toJoin) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_join(swigCPtr, this, GnPlaylistCollection.getCPtr(toJoin), toJoin);
  }

/** 
* Remove a join with another playlist 
* <p> 
* @param toRemove   [in] {@link GnPlaylistCollection} object to remove join 
*/ 
 
  public void joinRemove(GnPlaylistCollection toRemove) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_joinRemove(swigCPtr, this, GnPlaylistCollection.getCPtr(toRemove), toRemove);
  }

  public long serialize(byte[] serializedData, long dataSize) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_serialize(swigCPtr, this, serializedData, dataSize);
  }

/** 
* Returns the size of a serialized playlist collection object 
* @return serialized buffer size 
*/ 
 
  public long serializeSize() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_serializeSize(swigCPtr, this);
  }

/** 
* Add an identifier as part of synchronizing a user's media collection with the 
* corresponding Collection Summary. 
* <p> 
* Collection sychronization is a two step process: 
*     1)Use this method to add all unique identifiers that currently exist in the user's collection. 
*     2) Execute the synchronization process. 
* @param mediaIdentifier [in] unique media identifier used in you application e.g. file path 
*/ 
 
  public void syncProcessAdd(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_syncProcessAdd(swigCPtr, this, mediaIdentifier);
  }

/** 
* Process synchronize identifiers previously added to the Collection Summary to complete 
* synchronizing a user's media collection with the corresponding Collection Summary. 
* <p> 
* As step two of the synchronization process call this method after adding all unique 
* identifiers using SyncProcessAdd. This call will determine which identifiers added for 
* synchronization need to be also be added to the Collection Summary; and those that need to be 
* removed from the Collection Summary because they no longer exist in the user's collection. 
* This information is delivered via the synchronization delegate. 
* @param syncEvents [in] Synchronizations events delegate 
*/ 
 
  public void syncProcessExecute(IGnPlaylistCollectionSyncEvents syncEvents) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_syncProcessExecute(swigCPtr, this, getNewSyncEventsCPtr(syncEvents), syncEventsProxy);
  }

/** 
* Get object for setting "more like this" options 
* @return	More like this options object 
*/ 
 
  public GnPlaylistMoreLikeThisOptions moreLikeThisOptions() {
    return new GnPlaylistMoreLikeThisOptions(gnsdk_javaJNI.GnPlaylistCollection_moreLikeThisOptions(swigCPtr, this), false);
  }

}
