#include "safecuda.h"

void * operator new(std::size_t n) //throw(std::bad_alloc)
{
    void* p;
    cudaMallocManaged(&p, n);
    CHECK_CUDA_ERROR();
    return p;
}


void operator delete(void* p) //throw()
{
    cudaFree(p);
    CHECK_CUDA_ERROR();
}


void * operator new[](std::size_t n) //throw(std::bad_alloc)
{
    void* p;
    cudaMallocManaged(&p, n);
    CHECK_CUDA_ERROR();
    return p;
}


void operator delete[](void* p) //throw()
{
    cudaFree(p);
    CHECK_CUDA_ERROR();
}
