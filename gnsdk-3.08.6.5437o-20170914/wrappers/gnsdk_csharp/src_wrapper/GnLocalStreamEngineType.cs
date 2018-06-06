
namespace GracenoteSDK {

/**
* Possible values for <code>EngineType</code>
*/
public enum GnLocalStreamEngineType {
/**
* Sets lookup local stream library to operate in memory-mapped mode.
* Memory-mapped mode uses a memory-mapped file - the OS loads a portion of this file
* into memory as it is accessed by an  application, which leads to overall lower peak memory
* usage than in-memory mode.
*/
  kLocalStreamEngineInvalid = 0,
/**
* Sets lookup local stream library to operate in in-memory mode. This is faster, but
* for mobile devices the amount of memory needed may be prohibitive.
*/
  kLocalStreamEngineMMap,

  kLocalStreamEngineInMemory
}

}
