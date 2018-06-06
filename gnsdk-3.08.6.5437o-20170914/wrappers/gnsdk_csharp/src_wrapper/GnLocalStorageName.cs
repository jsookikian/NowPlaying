
namespace GracenoteSDK {

/**
* Gracenote local database names
* Gracenote supports local lookup for various types of identification
* and content, each is provided in its own Gracenote database. Each name
* represents a specific local Gracenote database.
* @ingroup Setup_StorageIDs
*/
public enum GnLocalStorageName {
/**
* Local storage used for querying Gracenote content.
* @ingroup Setup_StorageIDs
*/
  kLocalStorageInvalid = 0,
/**
* Local storage used for querying Gracenote metadata.
* @ingroup Setup_StorageIDs
*/
  kLocalStorageContent,
/**
* Local storage used for CD TOC searching.
* @ingroup Setup_StorageIDs
*/
  kLocalStorageMetadata,
/**
* Local storage used for text searching.
* @ingroup Setup_StorageIDs
*/
  kLocalStorageTOCIndex,
/**
* For referencing all the above storages that make up the local storage.
* @ingroup Setup_StorageIDs
*/
  kLocalStorageTextIndex,

  kLocalStorageAll
}

}
