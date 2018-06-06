
namespace GracenoteSDK {

/**
* Only use the CPU for local fingerprint comparison.
*/
public enum GnLocalStreamFingerprintProcessingMethod {
/**
* Use the GPU (if available) for local fingerprint comparison. The GPU is likely
* faster than using the CPU, but if your app is doing lots of intense graphics it
* may cause a "stutter" in displayed graphics.
*/
  kLocalStreamFingeprintProcessingInvalid = 0,
/**
* Use CUDA on the GPU (if available) for local fingerprint comparison. The GPU is likely
* faster than using the CPU, but if your app is doing lots of intense graphics it
* may cause a "stutter" in displayed graphics.
*/
  kLocalStreamFingeprintProcessingUseCPU,

  kLocalStreamFingeprintProcessingUseGPU,

  kLocalStreamFingeprintProcessingUseGPU_CUDA
}

}
