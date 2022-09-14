// This file contains a composite of the different types of CUDA error check wrappers I have seen over the years. 
#pragma once

#include <cuda.h>
#include <cuda_runtime.h>
#include <nvrtc.h>
#include <cstdio>


#define NVRTC_SAFE_CALL(x) \
        do { \
            nvrtcResult result = x; \
            if (result != NVRTC_SUCCESS) { \
                std::cerr << "\nerror: " #x " failed with error " \
                << nvrtcGetErrorString(result) << '\n'; \
            } \
         } while(0)

#define CUDA_SAFE_CALL(x) \
        do { \
            CUresult result = x; \
            if (result != CUDA_SUCCESS) { \
                const char *msg; \
                cuGetErrorName(result, &msg); \
                std::cerr << "\nerror: " #x " failed with error " \
                << msg << '\n'; \
                exit(1);\
            } \
        } while(0) 

#define CUDA_CHECK(status) \
  if (status != cudaSuccess) \
    { \
        printf("%s:%d CudaError: %s\n", __FILE__, __LINE__, cudaGetErrorString(status)); \
        assert(0); \
    }


#define CHECK_CUDA_ERROR()                                                    \
{                                                                             \
    cudaError_t err = cudaGetLastError();                                     \
    if (err != cudaSuccess)                                                   \
    {                                                                         \
        printf("error=%d name=%s at "                                         \
               "ln: %d\n  ",err,cudaGetErrorString(err),__LINE__);            \
        exit(1);\
    }                                                                         \
}
