/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef GNSDK_EVENT_TYPES_H_
#define GNSDK_EVENT_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif



#include "gnsdk_manager.h"
#include "gnsdk_manager_gdo.h"
/******************************************************************************
 * Typedefs
 ******************************************************************************/


GNSDK_DECLARE_HANDLE( gnsdk_event_handle_t );

/******************************************************************************
 * SDK Manager Event Group
 ******************************************************************************/
/*
 * ACR Browser Related Events
 */

/** @internal GNSDK_EVENT_ACR_GROUP @endinternal
*  Event allows subscription of browser events for acr.
* @hideinitializer
* @ingroup EventGroups
*/
#define GNSDK_EVENT_ACR_GROUP     			"gnsdk_event_acr_group"



/******************************************************************************
 * SDK Manager Event Types
 ******************************************************************************/

/** @internal GNSDK_EVENT_ACR_CONTENT @endinternal
*  This event type notifies subscriber to start Browser with the provided URL
* @hideinitializer
* @ingroup EventTypes
*/
#define GNSDK_EVENT_ACR_CONTENT			"gnsdk_event_acr_content"


/******************************************************************************
 * SDK Manager Event Data Types
 ******************************************************************************/

 /** @internal gnsdk_events_datatype_t @endinternal
	*  Event data types.
        * @hideinitializer
	* @ingroup Event_DataType_Enums
*/
typedef enum{

	/** @internal gnsdk_event_datatype_default @endinternal
	*  The type is used to inform that data received is not in any particular order but a plain string
	*/
	gnsdk_event_datatype_default,

	/** @internal gnsdk_event_datatype_xml @endinternal
	*  The type is used to inform that data received is in form of xml
	*/
	gnsdk_event_datatype_xml,

	/** @internal gnsdk_event_datatype_json @endinternal
	* The type is used to inform that data received is in form of json
	*/
	gnsdk_event_datatype_json,

	/** @internal gnsdk_event_datatype_gdo @endinternal
	*  The type is used to inform  that data received is in form of gdo
	*/
	gnsdk_event_datatype_gdo
}gnsdk_events_datatype_t;


/*****************************************************************************
 * SDK Manager Event Manager API
 ******************************************************************************/


/** @internal gnsdk_eventdata_interface_t @endinternal
* Data Interface that allows to access event data
* @hideinitializer
* @ingroup EventManager_Data_Interface
*/

typedef struct gnsdk_event_interface{

	gnsdk_error_t  	(GNSDK_CALLBACK_API *gnsdk_events_get_eventinfo) (
		gnsdk_event_handle_t 			event_handle,
		gnsdk_cstr_t* 					p_event_group,
		gnsdk_cstr_t* 					p_event_type,
		gnsdk_events_datatype_t* 		data_type);

	gnsdk_error_t 	(GNSDK_CALLBACK_API *gnsdk_events_get_eventdata_default) (
		gnsdk_event_handle_t 			event_handle,
		gnsdk_cstr_t* 					data_str, 
		gnsdk_size_t* 					size);

	gnsdk_error_t 	(GNSDK_CALLBACK_API *gnsdk_events_get_eventdata_xml) (
		gnsdk_event_handle_t 			event_handle,
		gnsdk_cstr_t* 					data_xml, 
		gnsdk_size_t* 					size);

	gnsdk_error_t 	(GNSDK_CALLBACK_API *gnsdk_events_get_eventdata_json) (
		gnsdk_event_handle_t 			event_handle,
		gnsdk_cstr_t* 					data_json, 
		gnsdk_size_t* 					size);

	gnsdk_error_t 	(GNSDK_CALLBACK_API *gnsdk_events_get_eventdata_gdo) (
		gnsdk_event_handle_t			event_handle,
		gnsdk_gdo_handle_t* 			data_gdo, 
		gnsdk_size_t* 					size);

}gnsdk_eventdata_interface_t;

/** @internal gnsdk_events_callback_fn @endinternal
* Callback function to receive event notification for subscriber
* @param callback_data [in] callback data for subscriber
* @param event_handle [in] handle to the event data
*  @param event_data_intf [in]interface handle to access event data
* @hideinitializer
* @ingroup EventManager_Subscriber_Functions
*/
typedef gnsdk_void_t (GNSDK_CALLBACK_API *gnsdk_events_callback_fn) (
	gnsdk_void_t*          				callback_data,
	gnsdk_event_handle_t  				event_handle,
	gnsdk_eventdata_interface_t* 		event_data_intf
   );


/** @internal gnsdk_event_add_subscriber @endinternal
* Add Subscriber to the gnsdk manager
*  @param p_subscriber_id [in] string to populate the subscriber id
* @hideinitializer
* @ingroup EventManager_Subscriber_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 	gnsdk_events_add_subscriber(
	gnsdk_cstr_t* 						p_subscriber_id);

/** @internal gnsdk_event_subscribe @endinternal
* Subscribe for a event
*  @param event_group [in] event group that subscriber want to subscribe to
*  @param callback [in] callback that subscriber wants sdk to call on notification
*  @param callback_data [in] callback data for subscriber
*  @param p_subscriber_id [in] subscriber id
* @hideinitializer
* @ingroup EventManager_Subscriber_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API	gnsdk_events_subscribe(
	gnsdk_cstr_t 						event_group,
	gnsdk_events_callback_fn 			callback,
	gnsdk_void_t*						callback_data,
	gnsdk_cstr_t 						p_subscriber_id);

/** @internal gnsdk_event_unsubscribe @endinternal
* Unsubscribe for a event
*  @param event_group [in] event group that subscriber want to unsubscribe from
*  @param p_subscriber_id [in] subscriber id
* @hideinitializer
* @ingroup EventManager_Subscriber_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API	gnsdk_events_unsubscribe(
	gnsdk_cstr_t 						event_group, 
	gnsdk_cstr_t 						p_subscriber_id );

/** @internal gnsdk_event_remove_subscriber @endinternal
* remove the subscriber from gnsdk manager
*  @param p_subscriber_id [in] subscriber id
* @hideinitializer
* @ingroup EventManager_Subscriber_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 	gnsdk_events_remove_subscriber(
	gnsdk_cstr_t 						p_subscriber_id);

/** @internal gnsdk_event_notify @endinternal
* This API acts as a means of feedback loop for the subscriber to notify the publisher about the event he just received .
*  @param event_group [in] event group that subscriber want to notify publisher about
*  @param data [in] string data that subscriber likes to send to the publisher
*  @param data_size [in] size of the data being sent
*  @param data_type [in] type of data that is being sent
* @hideinitializer
* @ingroup EventManager_Subscriber_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API gnsdk_events_notify(
	gnsdk_cstr_t 						event_group,
	gnsdk_cstr_t 						data, 
	gnsdk_size_t 						data_size,
	gnsdk_events_datatype_t 			data_type);

#ifdef __cplusplus
}
#endif

#endif /* GNSDK_EVENT_TYPES_H_ */
