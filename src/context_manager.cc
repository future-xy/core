#include "context_manager.h"

namespace triton { namespace core {

ContextManager::~ContextManager()
{
  if (initialized_) {
    for (int i = 0; i < num_devices_; i++) {
      cudaStreamDestroy(streams_[i]);
      cublasDestroy(cublas_handles_[i]);
    }
  }
}

int
ContextManager::Init()
{
  if (initialized_) {
    return 0;
  }
  // Get number of devices
  cudaGetDeviceCount(&num_devices_);
  for (int i = 0; i < num_devices_; i++) {
    cudaSetDevice(i);
    cudaStream_t stream;
    cublasHandle_t cublas_handle;
    // Create cuda stream
    cudaStreamCreate(&stream);
    // Create cublas handle
    cublasCreate(&cublas_handle);
    streams_.push_back(stream);
    cublas_handles_.push_back(cublas_handle);
  }
  initialized_ = true;
  return 0;
}

}  // namespace core
}  // namespace triton