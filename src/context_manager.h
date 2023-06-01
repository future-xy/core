#include <vector>

#ifdef TRITON_ENABLE_GPU
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#endif  // TRITON_ENABLE_GPU

namespace triton {
namespace core {

class ContextManager {
 public:
  ContextManager() : initialized_(false) {}
  ~ContextManager();

  // Init
  int Init();

 private:
  // initialized
  bool initialized_;
  // number of devices
  int num_devices_;
  // cuda stream
  std::vector<cudaStream_t> streams_;
  // cublas handle
  std::vector<cublasHandle_t> cublas_handles_;
};

}  // namespace core
}  // namespace triton