// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DXEMFLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DXEMFLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DXEMFLIB_EXPORTS
#define DXEMFLIB_API __declspec(dllexport)
#else
#define DXEMFLIB_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	// Resets the converter to an empty state.
	extern DXEMFLIB_API void DxEmfLibReset();

	// Appends an EMF file to the converter.
	extern DXEMFLIB_API void DxEmfLibAddFile(const char* filename);

	// Produces a PDF file from the current state.
	extern DXEMFLIB_API void DxEmfLibPersist(const char* filename);

#ifdef __cplusplus
}
#endif
