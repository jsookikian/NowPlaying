/*
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_PLAYLIST_HPP_
#define _GNSDK_PLAYLIST_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"
#include "gnsdk_list.hpp"
#include "metadata_music.hpp"


#if GNSDK_PLAYLIST
namespace gracenote
{
	namespace playlist
	{
		class IGnPlaylistCollectionSyncEvents;
		class GnPlaylistCollectionOptions;
		class GnPlaylistCollection;
		class GnPlaylistResults;

		/**
	 		* @deprecated
			* This will be removed in a future release
			* Use 'GnPlaylistResults' instead.
			*/
		GNSDK_CPP_CLASS_DEPRECATED(GnPlaylistResults,GnPlaylistResult);

		/**
		 * <b>Experimental</b>: GnPlaylistIdentifier
		 */
		class GnPlaylistIdentifier
		{
		public:
			GNWRAPPER_ANNOTATE
			/* Constructors */
			GnPlaylistIdentifier() : ident_(GNSDK_NULL), collection_(GNSDK_NULL) { }


			/*-----------------------------------------------------------------------------
			 *  MediaIdentifier
			 */
			gnsdk_cstr_t
			MediaIdentifier() const
			{
				return ident_;
			}

			/*-----------------------------------------------------------------------------
			 *  CollectionName
			 */
			gnsdk_cstr_t
			CollectionName() const
			{
				return collection_;
			}

			/*-----------------------------------------------------------------------------
			 *  operator ==
			 */
			bool
			operator == (const GnPlaylistIdentifier& rhs) const
			{
				return ( ident_ == rhs.ident_ ) && ( collection_ == rhs.collection_ );
			}

		protected:
			GnPlaylistIdentifier(gnsdk_cstr_t media_identifier, gnsdk_cstr_t collection_name) : ident_(media_identifier), collection_(collection_name) { }
			friend class result_provider;
			friend class collection_ident_provider;
			friend class IGnPlaylistCollectionSyncEvents;


		private:
			gnsdk_cstr_t ident_;
			gnsdk_cstr_t collection_;
		};


		/**
		 * <b>Experimental</b>: GnPlaylistAttributes
		 */
		class GnPlaylistAttributes : public metadata::GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE

			GnPlaylistAttributes() { }
			GnPlaylistAttributes(gnsdk_gdo_handle_t gdo_handle) :     metadata::GnDataObject(gdo_handle) { }
			GnPlaylistAttributes(const GnPlaylistAttributes& other) : metadata::GnDataObject(other) { }

			virtual
			~GnPlaylistAttributes() { }

			/**
			 *  Retrieves the AlbumName value as a string for this attribute.
			 *  @return album name string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			AlbumName() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_ALBUM);
			}

			/**
			 *  Retrieves the ArtistName value as a string for this attribute.
			 *  @return artist name string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			ArtistName() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_ARTIST);
			}

			/**
			 *  Retrieves the ArtistType value as a string for this attribute.
			 *  @return artist type string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			ArtistType() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_ARTTYPE);
			}

			/**
			 *  Retrieves the Era value as a string for this attribute.
			 *  @return era string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			Era() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_ERA);
			}

			/**
			 *  Retrieves the Genre value as a string for this attribute.
			 *  @return genre string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			Genre() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_GENRE);
			}

			/**
			 *  Retrieves the Origin value as a string for this attribute.
			 *  @return origin string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			Origin() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_ORIGIN);
			}

			/**
			 *  Retrieves the Mood value as a string for this attribute.
			 *  @return mood string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			Mood() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_MOOD);
			}

			/**
			 *  Retrieves the Tempo value as a string for this attribute.
			 *  @return tempo string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			Tempo() const
			{
				return StringValue(GNSDK_PLAYLIST_ATTRIBUTE_NAME_TEMPO);
			}

			/**
			 *  Retrieves attribute value by given attribute name.
			 *  @return attribute string value if it exists else an empty string.
			 *
			 **/
			gnsdk_cstr_t
			Value(gnsdk_cstr_t attrName) const
			{
				return StringValue(attrName);
			}
		};


		/*---------------------------------------------------------------------------
		** internal result_provider
		*/
		class result_provider
		{
		public:
			result_provider() : weak_handle_(GNSDK_NULL) { }
			result_provider(gnsdk_playlist_results_handle_t results) : weak_handle_(results) { }
			~result_provider() { }

			/* Required. */
			GnPlaylistIdentifier
			get_data(gnsdk_uint32_t pos) const;

			/* optional */
			gnsdk_uint32_t
			count() const;


		private:
			gnsdk_playlist_results_handle_t weak_handle_;
		};


		/*---------------------------------------------------------------------------
		** internal collection_ident_provider class
		*/
		class collection_ident_provider
		{
		public:
			collection_ident_provider() : weak_handle_(GNSDK_NULL) { }
			collection_ident_provider(gnsdk_playlist_collection_handle_t coll_handle) : weak_handle_(coll_handle) { }

			GnPlaylistIdentifier
			get_data(gnsdk_uint32_t pos) const;

			gnsdk_uint32_t
			count() const;


		private:
			gnsdk_playlist_collection_handle_t weak_handle_;
		};


		/*---------------------------------------------------------------------------
		** internal collection_join_provider
		*/
		class collection_join_provider
		{
		public:
			collection_join_provider() : weak_handle_(GNSDK_NULL) { }
			collection_join_provider(gnsdk_playlist_collection_handle_t coll_handle) : weak_handle_(coll_handle) { }

			GnPlaylistCollection
			get_data(gnsdk_uint32_t pos) const;

			gnsdk_uint32_t
			count() const;


		private:
			gnsdk_playlist_collection_handle_t weak_handle_;
		};


		/*---------------------------------------------------------------------------
		** Internal : collection_storage_provider
		*/
		class collection_storage_provider
		{
		public:
			collection_storage_provider();

			/* Default method required . */
			gnsdk_cstr_t
			get_data(gnsdk_uint32_t pos);

			gnsdk_uint32_t
			count() const;
		};


		/*---------------------------------------------------------------------------
		** Internal : attribute_provider
		*/
		class attribute_provider
		{
		public:
			attribute_provider() : weak_handle_(GNSDK_NULL) { };
			attribute_provider(gnsdk_playlist_collection_handle_t coll_handle) : weak_handle_(coll_handle) { }

			~attribute_provider() { };

			/* Default method required . */
			gnsdk_cstr_t
			get_data(gnsdk_uint32_t pos) const;

			/*required */
			gnsdk_uint32_t
			count() const;


		private:
			gnsdk_playlist_collection_handle_t weak_handle_;
		};


		typedef gn_facade_range_iterator<GnPlaylistIdentifier, collection_ident_provider>   ident_iterator;
		typedef gn_facade_range_iterator<GnPlaylistCollection, collection_join_provider>    join_iterator;
		typedef gn_facade_range_iterator<gnsdk_cstr_t, collection_storage_provider>         storage_iterator;
		typedef gn_facade_range_iterator<GnPlaylistIdentifier, result_provider>             result_iterator;
		typedef gn_facade_range_iterator<gnsdk_cstr_t, attribute_provider>                  attribute_iterator;

		typedef gn_iterable_container<GnPlaylistIdentifier, collection_ident_provider>   ident_iterable;
		typedef gn_iterable_container<GnPlaylistCollection, collection_join_provider>    join_iterable;
		typedef gn_iterable_container<gnsdk_cstr_t, collection_storage_provider>         storage_iterable;
		typedef gn_iterable_container<GnPlaylistIdentifier, result_provider>             result_iterable;
		typedef gn_iterable_container<gnsdk_cstr_t, attribute_provider>                  attribute_iterable;

		/**
		 * <b>Experimental</b>: GnPlaylistResults
		 */
		class GnPlaylistResults : public GnObject<gnsdk_playlist_results_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			GnPlaylistResults() { }
			explicit
			GnPlaylistResults(gnsdk_playlist_results_handle_t handle) : GnObject<gnsdk_playlist_results_handle_t>(handle)  { }

			/*-----------------------------------------------------------------------------
			 *  Identifiers
			 */
			result_iterable
			Identifiers() const
			{
				return result_iterable(result_provider(native()), GN_BASE_START);
			}

		};


		/**
		 * <b>Experimental</b>: Playlist "more like this" options.
		 */
		class GnPlaylistMoreLikeThisOptions
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Retrieves an option for Maximum number of Tracks for MoreLikeThis queries on a given collection.
			 *  Please note that these options are not serialized or stored.
			 *  Option for querying/specifying the maximum number of tracks in the result to be returned.
			 *  0 is not a valid value
			 *  @return Maximum tracks
			 *
			 **/
			gnsdk_uint32_t
			MaxTracks() const throw (GnError);

			/**
			 * Sets an option for Maximum number of Tracks for MoreLikeThis queries on a given collection.
			 * Please note that these options are not serialized or stored.
			 * @param  value [in] The maximum number of tracks to be returned. 0 is not a valid value.
			 **/
			void
			MaxTracks(gnsdk_uint32_t value) throw (GnError);
			/**
			 * Retrieves an option for maximum number of tracks Per artist for MoreLikeThis queries on a given collection.
			 * Please note that these options are not serialized or stored.
			 * 0 is not a valid value
			 * @return Maximum tracks per artist
			 *
			 **/
			gnsdk_uint32_t
			MaxPerArtist() const throw (GnError);

			/**
			 * Sets an option for maximum number of tracks per artist for MoreLikeThis queries on a given collection.
			 * Please note that these options are not serialized or stored.
			 * @param  value [in] The maximum number of tracks per artist to be returned. 0 is not a valid value.
			 *
			 **/
			void
			MaxPerArtist(gnsdk_uint32_t value) throw (GnError);

			/**
			 * Retrieves an option for maximum number of tracks per album for MoreLikeThis queries on a given collection.
			 * Please note that these options are not serialized or stored.
			 * 0 is not a valid value
			 * @return Maximum tracks per album
			 *
			 **/
			gnsdk_uint32_t
			MaxPerAlbum() const throw (GnError);

			/**
			 * Sets an option for maximum number of tracks per album for MoreLikeThis queries on a given collection.
			 * Please note that these options are not serialized or stored.
			 * @param  value    [in] The maximum number of tracks per album to be returned. 0 is not a valid value.
			 **/
			void
			MaxPerAlbum(gnsdk_uint32_t value) throw (GnError);


			/**
			 * Retrieves the RandomSeed option for "More Like This" for a given collection.
			 * Please note that these options are not serialized or stored.
			 * Option for querying/specifying the seed value for the random number generator used in calculating a
			 * "More Like This" playlist.
			 * @return Seed value
			 */
			gnsdk_uint32_t
			RandomSeed() const throw (GnError);

			/**
			 * Sets the RandomSeed option for "More Like This" for a given collection.
			 * Please note that these options are not serialized or stored.
			 * Option for querying/specifying the seed value for the random number generator used in calculating a
			 * "More Like This" playlist. Using the same number for a seed will generate the same 'random' sequence, thus allowing
			 * the same playlist ordering to be recreated. Choosing different numbers will create different playlists. Setting
			 * this value to "0" will disable using a random seed.
			 * @param value		[in] An unsigned int random seed .
			 */
			void
			RandomSeed(gnsdk_uint32_t value) throw (GnError);


		protected:
			GnPlaylistMoreLikeThisOptions() : weakhandle_(GNSDK_NULL) { }


		private:
			DISALLOW_COPY_AND_ASSIGN(GnPlaylistMoreLikeThisOptions);
			friend class GnPlaylistCollection;
			gnsdk_playlist_collection_handle_t weakhandle_;
		};


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
		class GnPlaylistCollection : public GnObject<gnsdk_playlist_collection_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Default Constructor for GnPlaylistCollection
			 */
			 GnPlaylistCollection() {;}

			/**
			 * Constructor for GnPlaylistCollection using a C native playlist collection handle.
			 * Caution - for advanced users only. Please note that the native handle will be addref'd when consumed by this class and it is up to
			 * the user to ensure that native handle is properly released ( depending on which C API gave access to the handle).
			 * @param handle   The gnsdk_playlist_collection_handle_t handle
			 */
			explicit
			GnPlaylistCollection(gnsdk_playlist_collection_handle_t handle);

			/**
			 * Constructor for GnPlaylistCollection using char* string name. This creates the collection with the name that is passed in.
			 * @param name   The name to be used to construct the colleciton.
			 */
			explicit
			GnPlaylistCollection(gnsdk_cstr_t name);

			/**
			 * Constructor for GnPlaylistCollection using a buffer to deserialize it from  and the corresponding buffer size.
			 * The collection is created from the passed buffer if it is successfully deserialized.
			 * @param collData  [in] Buffer that contains the serialized data.
			 * @param dataSize	[in] Buffer size.
			 */
			GnPlaylistCollection(gnsdk_byte_t* collData, gnsdk_size_t dataSize);

			/**
			 * Copy Constructor for GnPlaylistCollection.
			 * @param other  [in] Reference to GnPlaylistCollection that is to be copied.
			 */
			GnPlaylistCollection(const GnPlaylistCollection& other);

			/**
			 * Assignment operator for GnPlaylistCollection.
			 * @param other  [in] Reference to GnPlaylistCollection that is assigned to this GnPlaylistCollection.
			 */
			GnPlaylistCollection&
			operator =(const GnPlaylistCollection& other);

			/**
			 * Get the collection name
			 * @return Name
			 */
			gnsdk_cstr_t
			Name() const throw (GnError);

			/**
			 * Change the collection name
			 * @param updatedName	New collection name
			 */
			void
			Name(gnsdk_cstr_t updatedName) throw (GnError);

			/**
			 * Add a identifier with no metadata to a Collection Summary.
			 *
			 * @param mediaIdentifier   [in] Media identifier
			 */
			void
			Add(gnsdk_cstr_t mediaIdentifier) throw (GnError);

			/**
			 * Add a GnAlbum object and its metadata to a Collection Summary.
			 *
			 * @param mediaIdentifier   [in] Media identifier
			 * @param album             [in] GnAlbum object
			 */
			void
			Add(gnsdk_cstr_t mediaIdentifier, const metadata::GnAlbum& album) throw (GnError);

			/**
			 * Add a GnTrack object and its metadata to a Collection Summary.
			 *
			 * @param mediaIdentifier   [in] Media identifier
			 * @param track             [in] GnTrack object
			 */
			void
			Add(gnsdk_cstr_t mediaIdentifier, const metadata::GnTrack& track) throw (GnError);

			/**
			 * Add a GnContributor object and its metadata to a Collection Summary.
			 *
			 * @param mediaIdentifier   [in] Media identifier
			 * @param contributor       [in] GnContributor object
			 */
			void
			Add(gnsdk_cstr_t mediaIdentifier, const metadata::GnContributor& contributor) throw (GnError);


			/**
			 * Add a GnPlaylistAttributes object to a Collection Summary.
			 *
			 * @param mediaIdentifier       [in] Media identifier
			 * @param playlistAttributes	[in] Playlist attributes
			 */
			void
			Add(gnsdk_cstr_t mediaIdentifier, const GnPlaylistAttributes& playlistAttributes) throw (GnError);

			/**
			 * Add a GnListElement object to a Collection Summary.
			 *
			 * @param mediaIdentifier   [in] Media identifier
			 * @param listElement       [in] GnListElement object
			 */
			void
			Add(gnsdk_cstr_t mediaIdentifier, const GnListElement& listElement) throw (GnError);

			/**
			 * Remove a media element from a Collection Summary.
			 *
			 * @param mediaIdentifier  [in] Media identifier
			 */
			void
			Remove(gnsdk_cstr_t mediaIdentifier) throw (GnError);

			/* TBD */
			/* void Remove(iterator begin, iterator end) {} */

			/**
			 * Test if a media element is in a Collection Summary.
			 *
			 * @param mediaIdentifier  [in] Media identifier
			 */
			bool
			Contains(gnsdk_cstr_t mediaIdentifier) const throw (GnError);

			/**
			 * Find a media element in a Collection Summary.
			 *
			 * @param mediaIdentifier   [in] Media identifier
			 * @param start				[in] Start ordinal
			 */
			ident_iterator
			Find(gnsdk_cstr_t mediaIdentifier, gnsdk_uint32_t start) const throw (GnError);

			/**
			 * Return metadata from a playlist using a playlist identifier
			 *
			 * @param user             [in] GN User object
			 * @param mediaIdentifier  [in] Playlist identifier
			 */
			GnPlaylistAttributes
			Attributes(const GnUser& user, const GnPlaylistIdentifier& mediaIdentifier) const throw (GnError);

			/**
			 * Return attributes from a playlist using a Collection Summary name
			 *
			 * @param user             [in] GN User object
			 * @param mediaIdentifier  [in] Playlist identifier
			 */
			GnPlaylistAttributes
			Attributes(const GnUser& user, gnsdk_cstr_t mediaIdentifier, gnsdk_cstr_t joinedCollectionName = GNSDK_NULL) const throw (GnError);

			/**
			 * Validate a Playlist Definitioon Statement
			 * @param pdlStatement	Playlist Definition Statment
			 * @return Validation result
			 */
			GnError
			StatementValidate(gnsdk_cstr_t pdlStatement);

			/**
			 * Determine if a Playlist Definition Statement requires a seed
			 * to generate a playlist
			 * @param pdlStatement	Playlist Definition Statment
			 * @return True if a seed is required, false otherwise
			 */
			bool
			StatementRequiresSeed(gnsdk_cstr_t pdlStatement) const throw (GnError);

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
			GnString
			StatementAnalyzeIdent(gnsdk_cstr_t pdlStatement, gnsdk_cstr_t mediaIdentifier) const throw (GnError);

			/**
			 * Generate a playlist from a GnDataObject
			 *
			 * @param user             [in] Gracenote user
			 * @param pdlStatement     [in] Playlist Description Language statement
			 * @param playlistSeed     [in] GN data object to use as seed for playlist
			 */
			GnPlaylistResults
			GeneratePlaylist(const GnUser& user, gnsdk_cstr_t pdlStatement, const metadata::GnDataObject& playlistSeed) throw (GnError);

			/**
			 * Generate a playlist using a Playlist Definition Language (PDL) Statement from this object's Collection Summary.
			 * For more information on creating PDL Statements consult the PDL Specification.
			 *
			 * @param user             [in] Gracenote user
			 * @param pdlStatement     [in] Playlist Description Language statement
			 *
			 */
			GnPlaylistResults
			GeneratePlaylist(const GnUser& user, gnsdk_cstr_t pdlStatement) throw (GnError);

			/**
			 * Generate a playlist from a GnDataObject
			 *
			 * @param user             [in] Gracenote user
			 * @param musicDataObj     [in] Gracenote data object
			 *
			 */
			GnPlaylistResults
			GenerateMoreLikeThis(const GnUser& user, const metadata::GnDataObject& musicDataObj) throw (GnError);

			/**
			 *  Returns an iterable container for all the playlist attributes this collection supports.
			 *
			 */
			attribute_iterable
			AttributesSupported() const
			{
				return attribute_iterable(attribute_provider(), GN_BASE_START);
			}

			/**
			 * Returns an iterable container for all the media identifiers in the collection.
			 */
			ident_iterable
			MediaIdentifiers() const
			{
				return ident_iterable(collection_ident_provider(native()), GN_BASE_START);
			}

			/**
			 *  Returns an iterable container for all the joined collections.
			 *
			 */
			join_iterable
			Joins() const
			{
				return join_iterable(collection_join_provider(native()), GN_BASE_START);
			}

			/**
			 * Join a playlist collection by collection name.
			 *
			 * @param collectionName   [in] Collection Summary name
			 */
			GnPlaylistCollection
			JoinFindByName(gnsdk_cstr_t collectionName) const throw (GnError);

			/**
			 * Join a playlist collection by playlist collection object.
			 *
			 * @param toJoin   [in] GnPlaylistCollection object for join
			 */
			void
			Join(const GnPlaylistCollection& toJoin) throw (GnError);

			/**
			 * Remove a join with another playlist
			 *
			 * @param toRemove   [in] GnPlaylistCollection object to remove join
			 */
			void
			JoinRemove(const GnPlaylistCollection& toRemove) throw (GnError);

			/**
			 * Serialize a Collection Summary into buffer
			 *
			 * @param serializedData    [out] Buffer to receive serialized data
			 * @param dataSize          [in]  Buffer size
			 * @return buffer size
			 */
			gnsdk_size_t
			Serialize(gnsdk_byte_t* serializedData, gnsdk_size_t dataSize) const throw (GnError);

			/**
			 * Returns the size of a serialized playlist collection object
			 * @return serialized buffer size
			 */
			gnsdk_size_t
			SerializeSize() const throw (GnError);

			/**
			 * Add an identifier as part of synchronizing a user's media collection with the
			 * corresponding Collection Summary.
			 *
			 * Collection sychronization is a two step process:
			 *     1)Use this method to add all unique identifiers that currently exist in the user's collection.
			 *     2) Execute the synchronization process.
			 * @param mediaIdentifier [in] unique media identifier used in you application e.g. file path
			 */
			void
			SyncProcessAdd(gnsdk_cstr_t mediaIdentifier) throw (GnError);

			/**
			 * Process synchronize identifiers previously added to the Collection Summary to complete
			 * synchronizing a user's media collection with the corresponding Collection Summary.
			 *
			 * As step two of the synchronization process call this method after adding all unique
			 * identifiers using SyncProcessAdd. This call will determine which identifiers added for
			 * synchronization need to be also be added to the Collection Summary; and those that need to be
			 * removed from the Collection Summary because they no longer exist in the user's collection.
			 * This information is delivered via the synchronization delegate.
			 * @param syncEvents [in] Synchronizations events delegate
			 */
			void
			SyncProcessExecute(IGnPlaylistCollectionSyncEvents& syncEvents) throw (GnError);

			/**
			 * Get object for setting "more like this" options
			 * @return	More like this options object
			 */
			GnPlaylistMoreLikeThisOptions&
			MoreLikeThisOptions() { return options_; }


		protected:
			/* friend class definition */
			friend class GnPlaylist;
			friend class GnPlaylistStorage;

			GnPlaylistMoreLikeThisOptions options_;
		};


		/**
		 * @enum GnPlaylistEventsIdentiferStatus
		 * Specifies the status of a unique identifier when synchronizing
		 * a Playlist Collection Summary with a user's collection.
		 */
		enum GnPlaylistEventsIdentiferStatus
		{
			/**
			 * The corresponding identifier's status is unknown, the default state
			 */
			kIdentifierStatusUnknown = 0,

			/**
			 * The corresponding identifier is new, meaning it has been added to the
			 * user's media collection and needs to be added to the Collection Summary
			 */
			kIdentifierStatusNew     = 10,

			/**
			 * The corresponding identifier is old, meaning it has been deleted from
			 * the user's media collection and needs to be removed from the
			 * Collection Summary
			 */
			kIdentifierStatusOld     = 20

		};

		/**
		 * <b>Experimental</b>: Delegate interface for receiving playlist synchronization events
		 *
		 * Synchronization events are generated when a synchronization process is
		 * executed.
		 */
		class IGnPlaylistCollectionSyncEvents
		{
		public:
			GNWRAPPER_ANNOTATE

			virtual
			~IGnPlaylistCollectionSyncEvents() { }

			/* Methods to Override. */
			virtual void
			OnUpdate(GnPlaylistCollection collection, GnPlaylistIdentifier identifier, GnPlaylistEventsIdentiferStatus status, IGnCancellable& canceller) = 0;


		protected:
			friend class GnPlaylistCollection;
			static void _collection_sync(gnsdk_void_t*, gnsdk_playlist_collection_handle_t, gnsdk_cstr_t, gnsdk_playlist_status_t, gnsdk_bool_t*);
		};


		/**
		 * <b>Experimental</b>: Playlist Collection Summary storage management
		 *
		 * Provides services for managing the Playlist Collection Summary storage including
		 * adding, loading and removing collection summaries from persistent storage.
		 *
		 * Once a Collection Summary is created your application can store it persistently
		 * by adding it to the Playlist Collection Summary storage. When your application
		 * is initialized it can load the Collection Summary into heap memory from storage.
		 *
		 * Note: Once a Collection Summary is loaded from persistent storage your application
		 * should synchronize the summary with the media available for playlist generation as
		 * the user may have added or removed such media while your appication was not active.
		 *
		 * Collection Summaries can be removed from Playlist Collection Summary storage when
		 * no longer needed. The Playlist Collection Summary storage will retain persistent
		 * storage resources (file space) used by the removed Collection Summary. To return
		 * these resources to the operating system your application should compact the
		 * storage soon after removing a Collection Summary.
		 *
		 * A Gracenote storage provider must be enabled, such as GnStorageSqlite, for
		 * GnPlalistStorage to access persistent storage.
		 *
		 */
		class GnPlaylistStorage
		{
		public:
			GNWRAPPER_ANNOTATE

			GnPlaylistStorage();

			virtual
			~GnPlaylistStorage() { }


			/**
			 * Performs validation on playlist storage.
			 * @return Error information from storage validation
			 * Long Running Potential: File system I/O, database size affects running time
			 */
			GnError
			IsValid() const;


			/**
			 * Compact Collection Summary storage
			 */
			void
			Compact() throw (GnError);


			/**
			 * Stores a Collection Summary in local storage
			 *
			 * @param collection [in] Playlist collection
			 */
			void
			Store(const GnPlaylistCollection& collection) throw (GnError);


			/**
			 * Loads a Collection Summary from local storage using storage iterator
			 *
			 * @param itr [in] Storage iterator at the position you want to load.
			 * @return Playlist collection
			 */
			GnPlaylistCollection
			Load(storage_iterator itr)  throw (GnError);


			/**
			 * Loads a Collection Summary from local storage using storage name
			 *
			 * @param collectionName [in] explicit name of the collection you want to load.
			 * @return Playlist collection
			 */
			GnPlaylistCollection
			Load(gnsdk_cstr_t collectionName) throw (GnError);


			/**
			 * Removes a Collection Summary from local storage
			 *
			 * @param collection [in] Playlist collection object
			 */
			void
			Remove(const GnPlaylistCollection& collection) throw (GnError);


			/**
			 * Removes a Collection Summary from local storage using storage name
			 *
			 * @param collectionName [in] Playlist collection name
			 */
			void
			Remove(gnsdk_cstr_t collectionName) throw (GnError);


			/**
			 * Sets location for Collection Summary storage
			 *
			 * @param location [in] Location path
			 */
			void
			Location(gnsdk_cstr_t location) throw (GnError);


			/**
			 * Get an iterator for names of all stored Collection Summaries.
			 *
			 * The iterator or the name can be used to explicitly load the
			 * Collection Summary from storage.
			 *
			 * @return Playist Collection Summary Name iterator
			 */
			storage_iterable
			Names() const
			{
				return storage_iterable(collection_storage_provider(), GN_BASE_START);
			}

		};


		/**
		 * <b>Experimental</b>: Provides access to information regarding the underlying
		 * GNSDK playlist library. For working with user collections to create playlists
		 * see GnPlaylistCollection.
		 */
		class GnPlaylist
		{
		public:
			GnPlaylist() throw (GnError);

			GNWRAPPER_ANNOTATE
			/** @internal Version @endinternal
			 *  Retrieves the Playlist SDK version string.
			 *  @return version string if successful
			 *  @return GNSDK_NULL if not successful
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully getting a GnManager instance. The returned
			 *   string is a constant. Do not attempt to modify or delete.
			 *  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
			 *  Major: New functionality
			 *  Minor: New or changed features
			 *  Improvement: Improvements and fixes
			 *  Build: Internal build number
			 * @ingroup Music_Playlist_InitializationFunctions
			 */
			static gnsdk_cstr_t
			Version();

			/** @internal BuildDate @endinternal
			 *  Retrieves the Playlist SDK's build date string.
			 *  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully getting a GnManager instance. The returned
			 *   string is a constant. Do not attempt to modify or delete.
			 *  Example build date string: 2008-02-12 00:41 UTC
			 * @ingroup Music_Playlist_InitializationFunctions
			 */
			static gnsdk_cstr_t
			BuildDate();

			/**
			 *  Media attributes support for playlist generation such as album title,
			 *  artist name, and artist type.
			 *  @return Playlist attribute iterator
			 */
			attribute_iterable
			AttributesSupported() const
			{
				return attribute_iterable(attribute_provider(), GN_BASE_START);
			}

		};
	} /* namespace Playlist */

}     /* namespace GracenoteSDK */


#endif /* GNSDK_PLAYLIST */

#endif /* _GNSDK_PLAYLIST_HPP_ */

