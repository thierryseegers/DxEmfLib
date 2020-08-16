# DxEmfLib

Dll project that wraps `Emf2Pdf` and `libharu` in a simple API to convert EMF files into PDF files.
The purpose is to be used from C# code.

The `libharu` library was cloned from https://github.com/libharu/libharu, commit d84867e on Jun 28, 2015 and compiled for Win32/x64 and Debug/Release.
The binaries of `libharu` are checked in for convenience, not the source code.
The files `Emf2Pdf.[h/cpp]` were copied directly from https://github.com/APerricone/emf2pdf, commit 35fc130 on Nov 4, 2019.

## API

```
// Resets the converter to an empty state.
void DxEmfLibReset()
```

```
// Appends an EMF file to the converter.
void DxEmfLibAddFile(const char* filename);
```

```
// Produces a PDF file from the current state.
void DxEmfLibPersist(const char* filename);
```

## Sample C# code

```
using System;
using System.Runtime.InteropServices;

namespace DxEmfLibTest
{
    class Program
    {
        [DllImport("DxEmfLib.dll")]
        static public extern IntPtr DxEmfLibReset();

        [DllImport("DxEmfLib.dll")]
        static public extern void DxEmfLibAddFile(String filename);

        [DllImport("DxEmfLib.dll")]
        static public extern void DxEmfLibPersist(String filename);

        static void Main(string[] args)
        {
            DxEmfLibReset();

            DxEmfLibAddFile("emfFile1.emf");
            DxEmfLibAddFile("emfFile2.emf");

            DxEmfLibPersist("pdfFile1.pdf");


            DxEmfLibReset();

            DxEmfLibAddFile("emfFile3.emf");
            DxEmfLibAddFile("emfFile4.emf");

            DxEmfLibPersist("pdfFile2.pdf");
        }
    }
}
```