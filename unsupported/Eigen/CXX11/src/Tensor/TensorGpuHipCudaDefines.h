// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2014 Benoit Steiner <benoit.steiner.goog@gmail.com>
// Copyright (C) 2018 Deven Desai <deven.desai.amd@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#if defined(EIGEN_USE_GPU) && !defined(EIGEN_CXX11_TENSOR_GPU_HIP_CUDA_DEFINES_H)
#define EIGEN_CXX11_TENSOR_GPU_HIP_CUDA_DEFINES_H

#if defined(EIGEN_HIPCC)

#define gpuStream_t hipStream_t
#define gpuDeviceProp_t hipDeviceProp_t
#define gpuError_t hipError_t
#define gpuSuccess hipSuccess
#define gpuErrorNotReady hipErrorNotReady
#define gpuGetDeviceCount hipGetDeviceCount
#define gpuGetErrorString hipGetErrorString
#define gpuGetDeviceProperties hipGetDeviceProperties
// FIXME : use hipStreamDefault instead of 0x00
#define gpuStreamDefault 0x00
#define gpuGetDevice hipGetDevice
#define gpuSetDevice hipSetDevice
#define gpuMalloc hipMalloc
#define gpuFree hipFree
#define gpuMemsetAsync hipMemsetAsync
#define gpuMemcpyAsync hipMemcpyAsync
#define gpuMemcpyDeviceToDevice hipMemcpyDeviceToDevice
#define gpuMemcpyDeviceToHost hipMemcpyDeviceToHost
#define gpuMemcpyHostToDevice hipMemcpyHostToDevice
#define gpuStreamQuery hipStreamQuery
#define gpuSharedMemConfig hipSharedMemConfig
#define gpuDeviceSetSharedMemConfig hipDeviceSetSharedMemConfig
#define gpuStreamSynchronize hipStreamSynchronize

#else

#define gpuStream_t cudaStream_t
#define gpuDeviceProp_t cudaDeviceProp
#define gpuError_t cudaError_t
#define gpuSuccess cudaSuccess
#define gpuErrorNotReady cudaErrorNotReady
#define gpuGetDeviceCount cudaGetDeviceCount
#define gpuGetErrorString cudaGetErrorString
#define gpuGetDeviceProperties cudaGetDeviceProperties
#define gpuStreamDefault cudaStreamDefault
#define gpuGetDevice cudaGetDevice
#define gpuSetDevice cudaSetDevice
#define gpuMalloc cudaMalloc
#define gpuFree cudaFree
#define gpuMemsetAsync cudaMemsetAsync
#define gpuMemcpyAsync cudaMemcpyAsync
#define gpuMemcpyDeviceToDevice cudaMemcpyDeviceToDevice
#define gpuMemcpyDeviceToHost cudaMemcpyDeviceToHost
#define gpuMemcpyHostToDevice cudaMemcpyHostToDevice
#define gpuStreamQuery cudaStreamQuery
#define gpuSharedMemConfig cudaSharedMemConfig
#define gpuDeviceSetSharedMemConfig cudaDeviceSetSharedMemConfig
#define gpuStreamSynchronize cudaStreamSynchronize

#endif

#if defined(EIGEN_HIP_DEVICE_COMPILE)
// HIPCC does not support the use of assert on the GPU side.
#undef assert
#define assert(COND)
#endif

#endif  // EIGEN_CXX11_TENSOR_GPU_HIP_CUDA_DEFINES_H
