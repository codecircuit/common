// I use this header for common programming
// patterns and rapid developement
#pragma once
#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <curand.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double>;
using std::cout;
using std::endl;
using std::flush;

#ifdef DEBUGMODE
#define DEBUG(...) __VA_ARGS__
#else
#define DEBUG(...) do {} while (0);
#endif

std::string gethostname() {
	char name[256];
	gethostname(name, 256);
	return std::string(name);
}

std::string getdevicename() {
	cudaDeviceProp dp;
	cudaGetDeviceProperties(&dp, 0);
	return '"' + std::string(dp.name) + '"';
}

std::string getdate() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
	return buf;
}

#define checkCudaError(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

#define checkCurandError(ans) { curandAssert((ans), __FILE__, __LINE__); }
inline void curandAssert(curandStatus_t status, const char *file, int line, bool abort=true)
{
   if (status != CURAND_STATUS_SUCCESS) 
   {
      fprintf(stderr,"curand error: %s %d\n", file, line);
      if (abort) exit(EXIT_FAILURE);
   }
}
