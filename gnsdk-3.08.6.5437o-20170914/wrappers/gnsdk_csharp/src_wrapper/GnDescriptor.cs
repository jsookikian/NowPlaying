
namespace GracenoteSDK {

/**
* @enum GnDescriptor
*
* Verbosity, or granularity, of returned Gracenote metadata. This only applies to genres.
* If you want more, finer-grained genres, then use <code>kDescriptorDetailed</code>;
* otherwise, if storage and bandwidth need to be minimized and/or you can live with
* less granular genres, use <code>kDescriptorSimplified</code>.
*
*/
public enum GnDescriptor {

  kDescriptorDefault = 0,

  kDescriptorSimplified,

  kDescriptorDetailed
}

}
