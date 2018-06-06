/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

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

  public GnPlaylistCollection(String name) {
    this(gnsdk_javaJNI.new_GnPlaylistCollection__SWIG_0(name), true);
  }

  public GnPlaylistCollection(byte[] collData, long dataSize) {
    this(gnsdk_javaJNI.new_GnPlaylistCollection__SWIG_1(collData, dataSize), true);
  }

  public GnPlaylistCollection(GnPlaylistCollection other) {
    this(gnsdk_javaJNI.new_GnPlaylistCollection__SWIG_2(GnPlaylistCollection.getCPtr(other), other), true);
  }

  public String name() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_name__SWIG_0(swigCPtr, this);
  }

  public void name(String updatedName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_name__SWIG_1(swigCPtr, this, updatedName);
  }

  public void add(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_0(swigCPtr, this, mediaIdentifier);
  }

  public void add(String mediaIdentifier, GnAlbum album) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_1(swigCPtr, this, mediaIdentifier, GnAlbum.getCPtr(album), album);
  }

  public void add(String mediaIdentifier, GnTrack track) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_2(swigCPtr, this, mediaIdentifier, GnTrack.getCPtr(track), track);
  }

  public void add(String mediaIdentifier, GnContributor contributor) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_3(swigCPtr, this, mediaIdentifier, GnContributor.getCPtr(contributor), contributor);
  }

  public void add(String mediaIdentifier, GnPlaylistAttributes playlistAttributes) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_4(swigCPtr, this, mediaIdentifier, GnPlaylistAttributes.getCPtr(playlistAttributes), playlistAttributes);
  }

  public void add(String mediaIdentifier, GnListElement listElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_add__SWIG_5(swigCPtr, this, mediaIdentifier, GnListElement.getCPtr(listElement), listElement);
  }

  public void remove(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_remove(swigCPtr, this, mediaIdentifier);
  }

  public boolean contains(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_contains(swigCPtr, this, mediaIdentifier);
  }

  public GnPlaylistCollectionIdentIterator find(String mediaIdentifier, long start) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistCollectionIdentIterator(gnsdk_javaJNI.GnPlaylistCollection_find(swigCPtr, this, mediaIdentifier, start), true);
  }

  public GnPlaylistAttributes attributes(GnUser user, GnPlaylistIdentifier mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistAttributes(gnsdk_javaJNI.GnPlaylistCollection_attributes__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, GnPlaylistIdentifier.getCPtr(mediaIdentifier), mediaIdentifier), true);
  }

  public GnPlaylistAttributes attributes(GnUser user, String mediaIdentifier, String joinedCollectionName) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistAttributes(gnsdk_javaJNI.GnPlaylistCollection_attributes__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user, mediaIdentifier, joinedCollectionName), true);
  }

  public GnPlaylistAttributes attributes(GnUser user, String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistAttributes(gnsdk_javaJNI.GnPlaylistCollection_attributes__SWIG_2(swigCPtr, this, GnUser.getCPtr(user), user, mediaIdentifier), true);
  }

  public GnError statementValidate(String pdlStatement) {
    return new GnError(gnsdk_javaJNI.GnPlaylistCollection_statementValidate(swigCPtr, this, pdlStatement), true);
  }

  public boolean statementRequiresSeed(String pdlStatement) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_statementRequiresSeed(swigCPtr, this, pdlStatement);
  }

  public GnString statementAnalyzeIdent(String pdlStatement, String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnPlaylistCollection_statementAnalyzeIdent(swigCPtr, this, pdlStatement, mediaIdentifier), true);
  }

  public GnPlaylistResults generatePlaylist(GnUser user, String pdlStatement, GnDataObject playlistSeed) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistResults(gnsdk_javaJNI.GnPlaylistCollection_generatePlaylist__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, pdlStatement, GnDataObject.getCPtr(playlistSeed), playlistSeed), true);
  }

  public GnPlaylistResults generatePlaylist(GnUser user, String pdlStatement) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistResults(gnsdk_javaJNI.GnPlaylistCollection_generatePlaylist__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user, pdlStatement), true);
  }

  public GnPlaylistResults generateMoreLikeThis(GnUser user, GnDataObject musicDataObj) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistResults(gnsdk_javaJNI.GnPlaylistCollection_generateMoreLikeThis(swigCPtr, this, GnUser.getCPtr(user), user, GnDataObject.getCPtr(musicDataObj), musicDataObj), true);
  }

  public GnPlaylistAttributeIterable attributesSupported() {
    return new GnPlaylistAttributeIterable(gnsdk_javaJNI.GnPlaylistCollection_attributesSupported(swigCPtr, this), true);
  }

  public GnPlaylistCollectionIdentIterable mediaIdentifiers() {
    return new GnPlaylistCollectionIdentIterable(gnsdk_javaJNI.GnPlaylistCollection_mediaIdentifiers(swigCPtr, this), true);
  }

  public GnPlaylistJoinIterable joins() {
    return new GnPlaylistJoinIterable(gnsdk_javaJNI.GnPlaylistCollection_joins(swigCPtr, this), true);
  }

  public GnPlaylistCollection joinFindByName(String collectionName) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistCollection(gnsdk_javaJNI.GnPlaylistCollection_joinFindByName(swigCPtr, this, collectionName), true);
  }

  public void join(GnPlaylistCollection toJoin) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_join(swigCPtr, this, GnPlaylistCollection.getCPtr(toJoin), toJoin);
  }

  public void joinRemove(GnPlaylistCollection toRemove) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_joinRemove(swigCPtr, this, GnPlaylistCollection.getCPtr(toRemove), toRemove);
  }

  public long serialize(byte[] serializedData, long dataSize) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_serialize(swigCPtr, this, serializedData, dataSize);
  }

  public long serializeSize() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistCollection_serializeSize(swigCPtr, this);
  }

  public void syncProcessAdd(String mediaIdentifier) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_syncProcessAdd(swigCPtr, this, mediaIdentifier);
  }

  public void syncProcessExecute(IGnPlaylistCollectionSyncEvents syncEvents) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistCollection_syncProcessExecute(swigCPtr, this, getNewSyncEventsCPtr(syncEvents), syncEventsProxy);
  }

  public GnPlaylistMoreLikeThisOptions moreLikeThisOptions() {
    return new GnPlaylistMoreLikeThisOptions(gnsdk_javaJNI.GnPlaylistCollection_moreLikeThisOptions(swigCPtr, this), false);
  }

}
