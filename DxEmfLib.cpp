// DxEmfLib.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "DxEmfLib.h"

typedef bool boolean;	// Emf2Pdf class has one member of type "boolean". Just give it to it like this.
#include <Emf2Pdf.h>
#include <hpdf.h>

HPDF_Doc pdf = nullptr;
Emf2Pdf* emf2pdf = nullptr;

void DxEmfLibReset()
{
	if(pdf)
	{
		HPDF_Free(pdf);
		pdf = nullptr;
	}

	if(emf2pdf)
	{
		delete emf2pdf;
	}

	pdf = HPDF_New(0, 0);
	emf2pdf = new Emf2Pdf(pdf);
}

void DxEmfLibAddFile(const char* filename)
{
	if(emf2pdf)
	{
		emf2pdf->AddEMF(filename);
	}
}

void DxEmfLibPersist(const char* filename)
{
	if(pdf)
	{
		HPDF_SaveToFile(pdf, filename);
	}
}
